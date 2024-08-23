
#include "scanner.h"
#include <cstdio>
#include <fstream>
#include <iostream>

using Parser = yy::parser;

int main(int argc, char ** argv)
{
    Scanner scanner;
    Parser parser(scanner);

    std::ifstream file (argv[1]);
    if (file.is_open())
        scanner.yyrestart(&file);
    int res = parser();
    return res;
}