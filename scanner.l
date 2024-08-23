%{
#include "scanner.h"
#include <sstream>
#include "genericType.h"
using namespace std;
%}

%option noyywrap c++
%option yyclass="Scanner"
%option caseless

%%

<<EOF>>     {   yyterminate();  }

[\n]+       { return yytext[0]; }

[ \t\r]+    /* skip whitespace */


true        { return yy::parser::make_NUMBER(BoolBase::TRUE);}
false       { return yy::parser::make_NUMBER(BoolBase::FALSE);}
undef       { return yy::parser::make_NUMBER(BoolBase::UNDEF);}

"set"       { return yy::parser::make_SET(); }

"int"       { return yy::parser::make_TYPE(CurType::INT); }
"bool"      { return yy::parser::make_TYPE(CurType::BOOL); }
"short"     { return yy::parser::make_TYPE(CurType::SHORT); }

"vector"    { return yy::parser::make_VECTOR(); }
"of"        { return yy::parser::make_OF(); }

"sizeof"    { return yy::parser::make_SIZEOF(); }

"do"        { return yy::parser::make_DO(); }
"while"     { return yy::parser::make_WHILE(); }
"if"        { return yy::parser::make_IF(); }
"then"      { return yy::parser::make_THEN(); }
"else"      { return yy::parser::make_ELSE(); }
"return"    { return yy::parser::make_RET(); }

"begin"     { return yy::parser::make_BEG(); }
"end"       { return yy::parser::make_ENDL(); }
"or"        { return yy::parser::make_OR(); }
"and"       { return yy::parser::make_AND(); }

"smaller"   { return yy::parser::make_SMALLER(); }
"larger"    { return yy::parser::make_LARGER(); }
"="         { return yy::parser::make_EQUAL(); }

"add"       { return yy::parser::make_ADD(); }
"sub"       { return yy::parser::make_SUB(); }

"not"       { return yy::parser::make_UMINUS(); }

"left"       { return yy::parser::make_LEFT(); }
"right"      { return yy::parser::make_RIGHT(); }
"move"       { return yy::parser::make_MOVE(); }

[-]*[0-9]+  { return yy::parser::make_NUMBER(atoi(yytext)); }

[a-zA-Z][a-zA-Z0-9]* { return yy::parser::make_IDENTIFIER(yytext); }

[(){};\[\]]     { return yytext[0]; }

.           { cerr << "Non legal character: " << yytext << endl; }

%%

