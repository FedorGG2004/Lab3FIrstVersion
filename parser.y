%defines
%define parse.error detailed
%define api.token.constructor
%define api.value.type variant

%language "c++"

%code requires {
#include <iostream>
#include <vector>
#include <string>
#include <map>

#include "tree.h"
class Scanner;
}

%code {
    #include "scanner.h"

    extern "C" int yyerror(const char *s) { 
        std::cout << s << std::endl;
        return 0;
    };

    void yy::parser::error (const std::string& msg) {
        std::cout << msg << std::endl;
    };

    static yy::parser::symbol_type yylex(Scanner &scanner) {
        return scanner.ScanToken();
    }

    funcTable global_table;
}


%lex-param { Scanner &scanner }
%parse-param { Scanner &scanner }

%token <Value> NUMBER
%token <std::string> IDENTIFIER
%token SET
%token <CurType> TYPE
%token VECTOR OF
%token SIZEOF
%token BEG ENDL
%token DO WHILE IF THEN ELSE RET
%token SMALLER LARGER OR AND EQUAL
%token ADD SUB
%token LEFT RIGHT MOVE
%left SMALLER LARGER EQUAL
%left ADD SUB

%nonassoc ELSE
%nonassoc UMINUS

%type <Node*> expr
%type <Node*> set_stmt
%type <Node*> while_stmt
%type <Node*> if_stmt
%type <Node*> decl_stmt
%type <Node*> statement
%type <Node*> sizeof_stmt
%type <Node*> decl_vector_stmt
// %type <Node*> set_vector_stmt
%type <nodeList> statements
%type <std::string> func_start


%%

program:
    function_defs {
        varTable main_table;
        auto main_node = new FunctionCallNode("work", new NumberNode(GenericType(), "void"), global_table);
        main_node->eval(main_table);
};

function_defs:
    function_defs function_def '\n'
    | function_def '\n'
    ;

function_def:
    func_start statements ENDL
    {
        // Storing lambda to be called 
        FuncLambda func = [=](GenericType arg, nodeList& body, Signature sign) {
            global_table.print();
            varTable localVars;
            // Assign the parameter to the local variable
            localVars.setVar(sign.second, arg); 
            // Evaluate the function body
            GenericType result;
            for (auto stmt : body) {
                if (stmt->eval(localVars).getRet()) break;
                localVars.print();
            }

            result = localVars.getVar(sign.second);
            result.setType(sign.first);
            localVars.setVar(sign.second, result);

            std::cout << "Result: " << result << std::endl;
            return result;
        };
        
        global_table.setFuncBody($1, std::make_pair(func, $2));
    }
;

func_start: TYPE IDENTIFIER '(' IDENTIFIER ')' BEG '\n' {
    global_table.setFuncSign($2, std::make_pair($1, $4));
    $$ = $2;
}

statements:
    statements statement '\n' { $1.push_back($2); $$=$1; }
    | statement '\n' { $$ = nodeList({$1}); }
    ;

statement:
    set_stmt         { $$ = $1; }
    | decl_vector_stmt  { $$ = $1; }
 //   | set_vector_stmt   { $$ = $1; }
    | expr              { $$ = $1; }
    | while_stmt ';'    { $$ = $1; }
    | if_stmt           { $$ = $1; }
    | decl_stmt         { $$ = $1; }
    | RET expr ';'      { $$ = new RetNode(); }
    | sizeof_stmt     { $$ = $1; }
;

decl_vector_stmt:
    VECTOR OF TYPE IDENTIFIER ';' {
        $$ = new VectorNode(GenericType($3), $4);      
    }
// set_vector_stmt:
   // VECTOR OF TYPE IDENTIFIER ';' {
     //   $$ = new SetNode($1, $3);   
   // }

sizeof_stmt:
    SIZEOF IDENTIFIER ';' {
        $$ = new SizeofNode($2);
    }
  //  | SIZEOF TYPE ';' {
  //      $$ = new SizeofNode($2);
  //  }
;

while_stmt:
    DO BEG '\n' statements ENDL WHILE '(' expr ')' {
        $$ = new DoWhileNode($8, $4);
    }
;

if_stmt:
    IF '(' expr ')' '\n' THEN BEG '\n' statements ENDL 
    {
        $$ = new IfNode($3, $9);
    }
    | IF '(' expr ')' '\n' THEN BEG '\n' statements ENDL ELSE BEG '\n' statements ENDL {
        $$ = new IfNode($3, $9, $14);
    }
;

set_stmt
: IDENTIFIER SET expr ';' {
    $$ = new SetNode($1, $3);
}

decl_stmt
: TYPE IDENTIFIER ';' {
    $$ = new NumberNode(GenericType($1), $2);
} 

expr:
    IDENTIFIER '(' expr ')'
    {
        $$ = new FunctionCallNode($1, $3, global_table);
    }
    | IDENTIFIER '[' NUMBER ']'
    {
        $$ = new VectorIndexNode($3, $1);
    }
    | UMINUS expr 
    {
        $$ = new UnaryMinusNode($2);
    }
    | expr ADD expr
    {
        $$ = new BinaryOpNode('+', $1, $3);
    }
    | expr SUB expr
    {
        $$ = new BinaryOpNode('-', $1, $3);
    }
    | expr SMALLER expr
    {
        $$ = new BinaryOpNode('<', $1, $3);
    }
    | expr LARGER expr
    {
        $$ = new BinaryOpNode('>', $1, $3);
    }
    | expr EQUAL expr
    {
        $$ = new BinaryOpNode('=', $1, $3);
    }
    |   NUMBER
    {
        $$ = new NumberNode($1);
    }
    | IDENTIFIER
    {
        $$ = new NumberNode(GenericType(), $1);
    }
;



%%
