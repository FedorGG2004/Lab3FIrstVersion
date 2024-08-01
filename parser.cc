#include "scanner.hh" 
#include <iostream>

using Parser = yy::parser;

int main(int argc, char ** argv)
{
    Scanner scanner;
    Parser parser(scanner);

    scanner.yyrestart(&std::cin);
    int res = parser();
    return res;
}