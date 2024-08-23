rm -f dummy_parser.tab.cc parser.hpp lex.yy.cc stack.hh
bison -Wcounterexamples -Hparser.hpp parser.y 
flex scanner.l
g++ -g -Wno-register main.cpp tree.cpp parser.tab.cc lex.yy.cc 