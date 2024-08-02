%defines
%define parse.assert
%define api.token.constructor
%define api.value.type variant
%define parse.error detailed

%language "c++"
%require "3.5"
%code requires {
    #include <stdio.h>
    #include <stdlib.h>
    #include <stdarg.h>
    #include "tree.hh"
class Scanner;
}

%code{
#include "scanner.hh"
#include <iostream>
#include <fstream>
#include <cstdio>


extern "C" int yyerror(const char *s) {
	std::cout << s << std::endl;
};

static yy::parser::symbol_type yylex(Scanner &scanner) {
    return scanner.ScanToken();
}

    /* prototypes */
    nodeType *opr(int oper, int nops, ...);
    nodeType *id(int i);
    nodeType *con(int value);
    void setlabel (int i ,nodeType *p);
    void freeNode(nodeType *p);
    int exec(nodeType *p);
    int yylex(void);
    void init (void);
    int sym[26]; /* symbol table */
    nodeType* addr[26];
}

%lex-param { Scanner &scanner }
%parse-param { Scanner &scanner }


%nonassoc END
%token TYPE
%token SET
%token ARRAY
%token SIZEOF
%token BEG
%token ENDL

%token <int> INTEGER
%token <char> VARIABLE
%token <bool> BOOL

%token DO WHILE IF THEN ELSE PRINT FUNCTION
%nonassoc IFX
%nonassoc ELSE
%left GE LE EQ NE G L
%left PLUS MINUS
%left AND OR
%nonassoc UMINUS
%type <nodeType*> stmt expr stmt_list function

%%
program:
 function {exec($1); freeNode($1); exit(0); }
 ;
function:
 function stmt { $$ = opr(';', 2, $1, $2);/*ex($2); freeNode($2);*/ }
 | /* NULL */ { init(); $$ = 0;}
 ;
stmt:
 ';' { $$ = opr(';', 2, NULL, NULL); }
 | expr ';' { $$ = $1; }
 | PRINT expr ';' { $$ = opr(yy::parser::token::PRINT, 1, $2); }
 | TYPE VARIABLE SET expr ';' { $$ = opr(yy::parser::token::SET, 2, id($2), $4); }
 | VARIABLE SET expr ';' { $$ = opr(yy::parser::token::SET, 2, id($1), $3); }
 | DO stmt WHILE '(' expr ')' { $$ = opr(yy::parser::token::DO, 2, $2, $5); }
 | IF '(' expr ')' THEN stmt %prec IFX { $$ = opr(yy::parser::token::IF, 2, $3, $6); }
 | IF '(' expr ')' THEN stmt ELSE stmt { $$ = opr(yy::parser::token::IF, 3, $3, $6, $8); }
 | BEG stmt_list ENDL { $$ = $2; }
 | VARIABLE ':' stmt { setlabel ($1, $3); $$ = $3;}
 | FUNCTION VARIABLE ';' { $$ = opr(yy::parser::token::FUNCTION, 1, id($2));}
 ;
stmt_list:
 stmt { $$ = $1; }
 | stmt_list stmt { $$ = opr(';', 2, $1, $2); }
 ;
expr:
 INTEGER { $$ = con($1); }
 | VARIABLE { $$ = id($1); }
 | UMINUS expr %prec UMINUS { $$ = opr(yy::parser::token::UMINUS, 1, $2); }
 | expr PLUS expr { $$ = opr(yy::parser::token::PLUS, 2, $1, $3); }
 | expr MINUS expr { $$ = opr(yy::parser::token::MINUS, 2, $1, $3); }
 | expr OR expr { $$ = opr(yy::parser::token::OR, 2, $1, $3); }
 | expr AND expr { $$ = opr(yy::parser::token::AND, 2, $1, $3); }
 | expr L expr { $$ = opr(yy::parser::token::L, 2, $1, $3); }
 | expr G expr { $$ = opr(yy::parser::token::G, 2, $1, $3); }
 | expr GE expr { $$ = opr(yy::parser::token::GE, 2, $1, $3); }
 | expr LE expr { $$ = opr(yy::parser::token::LE, 2, $1, $3); }
 | expr NE expr { $$ = opr(yy::parser::token::NE, 2, $1, $3); }
 | expr EQ expr { $$ = opr(yy::parser::token::EQ, 2, $1, $3); }
 | '(' expr ')' { $$ = $2; }
 ;
%%
void
yy::parser::error(const std::string& m)
{
	std::cerr << m << std::endl;
}


#define SIZEOF_NODETYPE ((char *)&p->con - (char *)p)
nodeType *con(int value) {
    nodeType *p;
    size_t nodeSize;
    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(conNodeType);
    if ((p = (nodeType*) malloc(nodeSize)) == NULL)
        yyerror("out of memory");
    /* copy information */
    p->type = typeCon;
    p->con.value = value;
    return p;
}
nodeType *id(int i) {
    nodeType *p;
    size_t nodeSize;
    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(idNodeType);
    if ((p = (nodeType*) malloc(nodeSize)) == NULL)
        yyerror("out of memory");
    /* copy information */
    p->type = typeId;
    p->id.i = i;
    return p;
}
nodeType *opr(int oper, int nops, ...) {
    va_list ap;
    nodeType *p;
    size_t nodeSize;
    int i;
    /* allocate node */
    nodeSize = SIZEOF_NODETYPE + sizeof(oprNodeType) + (nops - 1) * sizeof(nodeType*);
    if ((p = (nodeType*) malloc(nodeSize)) == NULL)
        yyerror("out of memory");
    /* copy information */
    p->type = typeOpr;
    p->opr.oper = oper;
    p->opr.nops = nops;
    va_start(ap, nops);
    for (i = 0; i < nops; i++)
        p->opr.op[i] = va_arg(ap, nodeType*);
    va_end(ap);
    return p;
}
void freeNode(nodeType *p) {
    int i;
    if (!p) return;
    if (p->type == typeOpr) {
        for (i = 0; i < p->opr.nops; i++)
            freeNode(p->opr.op[i]);
    }
    free (p);
}
void setlabel (int i,nodeType *p)
{
    p->label = i;
    addr[i] = p;
}
void init (void)
{
    int i;
    for (i = 0;i<26;++i)
    sym[i] = 0, addr[i] = 0;
}


