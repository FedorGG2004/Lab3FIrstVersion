%{
#include "scanner.hh"
#include <sstream>
using namespace std;
%}

%option noyywrap c++
%option yyclass="Scanner"
%option caseless

%%

true     { return yy::parser::make_BOOL(true); }
false     { return yy::parser::make_BOOL(false); }
undefined     { return yy::parser::make_BOOL(false); }
bool     { return yy::parser::make_TYPE(); }
int { return yy::parser::make_TYPE(); }
short { return yy::parser::make_TYPE(); }
vector_of { return yy::parser::make_ARRAY(); }
set { return yy::parser::make_SET(); }

sizeof { return yy::parser::make_SIZEOF(); }

add { return yy::parser::make_PLUS(); }
sub { return yy::parser::make_MINUS(); }
smaller { return yy::parser::make_L(); }
larger { return yy::parser::make_G(); }
not { return yy::parser::make_UMINUS(); }
or { return yy::parser::make_OR(); }
and { return yy::parser::make_AND(); }
begin { return yy::parser::make_BEG(); }
end { return yy::parser::make_ENDL(); }

"do" { return yy::parser::make_DO(); }
"while" { return yy::parser::make_WHILE(); }
"if" { return yy::parser::make_IF(); }
"then" { return yy::parser::make_THEN(); }
"else" { return yy::parser::make_ELSE(); }
"print" { return yy::parser::make_PRINT(); }
"function" { return yy::parser::make_FUNCTION(); }

[a-zA-Z][a-zA-Z0-9]*  { 
                    return yy::parser::make_VARIABLE(yytext);
                }
[0-9]+ {  
                    return yy::parser::make_INTEGER(atoi(yytext));  
                }  
[-()<>=+*/;:{}.] {
 return *yytext;
 }
">=" { return yy::parser::make_GE(); }
"<=" { return yy::parser::make_LE(); }
"==" { return yy::parser::make_EQ(); }
"!=" { return yy::parser::make_NE(); }

[ \t\n\r]+ ; /* ignore whitespace */

