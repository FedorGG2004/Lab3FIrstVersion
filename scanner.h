#ifndef SCANNER_HH
#define SCANNER_HH

#if !defined (yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#undef YY_DECL
#define YY_DECL yy::parser::symbol_type Scanner::ScanToken()

#include "parser.hpp"


namespace yy {
    class location;
}

class Scanner: public yyFlexLexer {
public:

    Scanner() {}
	virtual ~Scanner() override {}
	virtual yy::parser::symbol_type ScanToken();
    

private:
};

#endif /* SCANNER_HH */
