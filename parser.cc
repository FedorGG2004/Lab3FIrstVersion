#include "scanner.hh" 
#include <iostream>

using Parser = yy::parser;

int main(int argc, char ** argv)
{
    Scanner scanner;
    Parser parser(scanner);
    FILE * yyin = fopen ("./test.txt", "r");

    scanner.yyrestart(&std::cin);
    int res = parser();
    fclose (yyin);
    return res;
}