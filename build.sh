rm *tab*
bison -d grammar.y && flex scanner.l
g++ -Wno-register lex.yy.cc grammar.tab.cc parser.cc exec.cc
