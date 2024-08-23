// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.





#include "parser.hpp"


// Unqualified %code blocks.
#line 18 "parser.y"

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

#line 65 "parser.tab.cc"


#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yy_stack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

namespace yy {
#line 138 "parser.tab.cc"

  /// Build a parser object.
  parser::parser (Scanner &scanner_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_TYPE: // TYPE
        value.YY_MOVE_OR_COPY< CurType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_decl_vector_stmt: // decl_vector_stmt
      case symbol_kind::S_sizeof_stmt: // sizeof_stmt
      case symbol_kind::S_while_stmt: // while_stmt
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_set_stmt: // set_stmt
      case symbol_kind::S_decl_stmt: // decl_stmt
      case symbol_kind::S_expr: // expr
        value.YY_MOVE_OR_COPY< Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.YY_MOVE_OR_COPY< Value > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statements: // statements
        value.YY_MOVE_OR_COPY< nodeList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_func_start: // func_start
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_TYPE: // TYPE
        value.move< CurType > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_decl_vector_stmt: // decl_vector_stmt
      case symbol_kind::S_sizeof_stmt: // sizeof_stmt
      case symbol_kind::S_while_stmt: // while_stmt
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_set_stmt: // set_stmt
      case symbol_kind::S_decl_stmt: // decl_stmt
      case symbol_kind::S_expr: // expr
        value.move< Node* > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.move< Value > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_statements: // statements
        value.move< nodeList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_func_start: // func_start
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_TYPE: // TYPE
        value.copy< CurType > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_decl_vector_stmt: // decl_vector_stmt
      case symbol_kind::S_sizeof_stmt: // sizeof_stmt
      case symbol_kind::S_while_stmt: // while_stmt
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_set_stmt: // set_stmt
      case symbol_kind::S_decl_stmt: // decl_stmt
      case symbol_kind::S_expr: // expr
        value.copy< Node* > (that.value);
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.copy< Value > (that.value);
        break;

      case symbol_kind::S_statements: // statements
        value.copy< nodeList > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_func_start: // func_start
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_TYPE: // TYPE
        value.move< CurType > (that.value);
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_decl_vector_stmt: // decl_vector_stmt
      case symbol_kind::S_sizeof_stmt: // sizeof_stmt
      case symbol_kind::S_while_stmt: // while_stmt
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_set_stmt: // set_stmt
      case symbol_kind::S_decl_stmt: // decl_stmt
      case symbol_kind::S_expr: // expr
        value.move< Node* > (that.value);
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.move< Value > (that.value);
        break;

      case symbol_kind::S_statements: // statements
        value.move< nodeList > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_func_start: // func_start
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (scanner));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_TYPE: // TYPE
        yylhs.value.emplace< CurType > ();
        break;

      case symbol_kind::S_statement: // statement
      case symbol_kind::S_decl_vector_stmt: // decl_vector_stmt
      case symbol_kind::S_sizeof_stmt: // sizeof_stmt
      case symbol_kind::S_while_stmt: // while_stmt
      case symbol_kind::S_if_stmt: // if_stmt
      case symbol_kind::S_set_stmt: // set_stmt
      case symbol_kind::S_decl_stmt: // decl_stmt
      case symbol_kind::S_expr: // expr
        yylhs.value.emplace< Node* > ();
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        yylhs.value.emplace< Value > ();
        break;

      case symbol_kind::S_statements: // statements
        yylhs.value.emplace< nodeList > ();
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_func_start: // func_start
        yylhs.value.emplace< std::string > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // program: function_defs
#line 74 "parser.y"
                  {
        varTable main_table;
        auto main_node = new FunctionCallNode("work", new NumberNode(GenericType(), "void"), global_table);
        main_node->eval(main_table);
}
#line 664 "parser.tab.cc"
    break;

  case 5: // function_def: func_start statements ENDL
#line 87 "parser.y"
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
        
        global_table.setFuncBody(yystack_[2].value.as < std::string > (), std::make_pair(func, yystack_[1].value.as < nodeList > ()));
    }
#line 693 "parser.tab.cc"
    break;

  case 6: // func_start: TYPE IDENTIFIER '(' IDENTIFIER ')' BEG '\n'
#line 113 "parser.y"
                                                        {
    global_table.setFuncSign(yystack_[5].value.as < std::string > (), std::make_pair(yystack_[6].value.as < CurType > (), yystack_[3].value.as < std::string > ()));
    yylhs.value.as < std::string > () = yystack_[5].value.as < std::string > ();
}
#line 702 "parser.tab.cc"
    break;

  case 7: // statements: statements statement '\n'
#line 119 "parser.y"
                              { yystack_[2].value.as < nodeList > ().push_back(yystack_[1].value.as < Node* > ()); yylhs.value.as < nodeList > ()=yystack_[2].value.as < nodeList > (); }
#line 708 "parser.tab.cc"
    break;

  case 8: // statements: statement '\n'
#line 120 "parser.y"
                     { yylhs.value.as < nodeList > () = nodeList({yystack_[1].value.as < Node* > ()}); }
#line 714 "parser.tab.cc"
    break;

  case 9: // statement: set_stmt
#line 124 "parser.y"
                     { yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > (); }
#line 720 "parser.tab.cc"
    break;

  case 10: // statement: decl_vector_stmt
#line 125 "parser.y"
                        { yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > (); }
#line 726 "parser.tab.cc"
    break;

  case 11: // statement: expr
#line 127 "parser.y"
                        { yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > (); }
#line 732 "parser.tab.cc"
    break;

  case 12: // statement: while_stmt ';'
#line 128 "parser.y"
                        { yylhs.value.as < Node* > () = yystack_[1].value.as < Node* > (); }
#line 738 "parser.tab.cc"
    break;

  case 13: // statement: if_stmt
#line 129 "parser.y"
                        { yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > (); }
#line 744 "parser.tab.cc"
    break;

  case 14: // statement: decl_stmt
#line 130 "parser.y"
                        { yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > (); }
#line 750 "parser.tab.cc"
    break;

  case 15: // statement: RET expr ';'
#line 131 "parser.y"
                        { yylhs.value.as < Node* > () = new RetNode(); }
#line 756 "parser.tab.cc"
    break;

  case 16: // statement: sizeof_stmt
#line 132 "parser.y"
                      { yylhs.value.as < Node* > () = yystack_[0].value.as < Node* > (); }
#line 762 "parser.tab.cc"
    break;

  case 17: // decl_vector_stmt: VECTOR OF TYPE IDENTIFIER ';'
#line 136 "parser.y"
                                  {
        yylhs.value.as < Node* > () = new VectorNode(GenericType(yystack_[2].value.as < CurType > ()), yystack_[1].value.as < std::string > ());      
    }
#line 770 "parser.tab.cc"
    break;

  case 18: // sizeof_stmt: SIZEOF IDENTIFIER ';'
#line 145 "parser.y"
                          {
        yylhs.value.as < Node* > () = new SizeofNode(yystack_[1].value.as < std::string > ());
    }
#line 778 "parser.tab.cc"
    break;

  case 19: // while_stmt: DO BEG '\n' statements ENDL WHILE '(' expr ')'
#line 154 "parser.y"
                                                   {
        yylhs.value.as < Node* > () = new DoWhileNode(yystack_[1].value.as < Node* > (), yystack_[5].value.as < nodeList > ());
    }
#line 786 "parser.tab.cc"
    break;

  case 20: // if_stmt: IF '(' expr ')' '\n' THEN BEG '\n' statements ENDL
#line 161 "parser.y"
    {
        yylhs.value.as < Node* > () = new IfNode(yystack_[7].value.as < Node* > (), yystack_[1].value.as < nodeList > ());
    }
#line 794 "parser.tab.cc"
    break;

  case 21: // if_stmt: IF '(' expr ')' '\n' THEN BEG '\n' statements ENDL ELSE BEG '\n' statements ENDL
#line 164 "parser.y"
                                                                                       {
        yylhs.value.as < Node* > () = new IfNode(yystack_[12].value.as < Node* > (), yystack_[6].value.as < nodeList > (), yystack_[1].value.as < nodeList > ());
    }
#line 802 "parser.tab.cc"
    break;

  case 22: // set_stmt: IDENTIFIER SET expr ';'
#line 170 "parser.y"
                          {
    yylhs.value.as < Node* > () = new SetNode(yystack_[3].value.as < std::string > (), yystack_[1].value.as < Node* > ());
}
#line 810 "parser.tab.cc"
    break;

  case 23: // decl_stmt: TYPE IDENTIFIER ';'
#line 175 "parser.y"
                      {
    yylhs.value.as < Node* > () = new NumberNode(GenericType(yystack_[2].value.as < CurType > ()), yystack_[1].value.as < std::string > ());
}
#line 818 "parser.tab.cc"
    break;

  case 24: // expr: IDENTIFIER '(' expr ')'
#line 181 "parser.y"
    {
        yylhs.value.as < Node* > () = new FunctionCallNode(yystack_[3].value.as < std::string > (), yystack_[1].value.as < Node* > (), global_table);
    }
#line 826 "parser.tab.cc"
    break;

  case 25: // expr: IDENTIFIER '[' NUMBER ']'
#line 185 "parser.y"
    {
        yylhs.value.as < Node* > () = new VectorIndexNode(yystack_[1].value.as < Value > (), yystack_[3].value.as < std::string > ());
    }
#line 834 "parser.tab.cc"
    break;

  case 26: // expr: UMINUS expr
#line 189 "parser.y"
    {
        yylhs.value.as < Node* > () = new UnaryMinusNode(yystack_[0].value.as < Node* > ());
    }
#line 842 "parser.tab.cc"
    break;

  case 27: // expr: expr ADD expr
#line 193 "parser.y"
    {
        yylhs.value.as < Node* > () = new BinaryOpNode('+', yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > ());
    }
#line 850 "parser.tab.cc"
    break;

  case 28: // expr: expr SUB expr
#line 197 "parser.y"
    {
        yylhs.value.as < Node* > () = new BinaryOpNode('-', yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > ());
    }
#line 858 "parser.tab.cc"
    break;

  case 29: // expr: expr SMALLER expr
#line 201 "parser.y"
    {
        yylhs.value.as < Node* > () = new BinaryOpNode('<', yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > ());
    }
#line 866 "parser.tab.cc"
    break;

  case 30: // expr: expr LARGER expr
#line 205 "parser.y"
    {
        yylhs.value.as < Node* > () = new BinaryOpNode('>', yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > ());
    }
#line 874 "parser.tab.cc"
    break;

  case 31: // expr: expr EQUAL expr
#line 209 "parser.y"
    {
        yylhs.value.as < Node* > () = new BinaryOpNode('=', yystack_[2].value.as < Node* > (), yystack_[0].value.as < Node* > ());
    }
#line 882 "parser.tab.cc"
    break;

  case 32: // expr: NUMBER
#line 213 "parser.y"
    {
        yylhs.value.as < Node* > () = new NumberNode(yystack_[0].value.as < Value > ());
    }
#line 890 "parser.tab.cc"
    break;

  case 33: // expr: IDENTIFIER
#line 217 "parser.y"
    {
        yylhs.value.as < Node* > () = new NumberNode(GenericType(), yystack_[0].value.as < std::string > ());
    }
#line 898 "parser.tab.cc"
    break;


#line 902 "parser.tab.cc"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
    }
    goto yynewstate;


  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  const char *
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    static const char *const yy_sname[] =
    {
    "end of file", "error", "invalid token", "NUMBER", "IDENTIFIER", "SET",
  "TYPE", "VECTOR", "OF", "SIZEOF", "BEG", "ENDL", "DO", "WHILE", "IF",
  "THEN", "ELSE", "RET", "SMALLER", "LARGER", "OR", "AND", "EQUAL", "ADD",
  "SUB", "LEFT", "RIGHT", "MOVE", "UMINUS", "'\\n'", "'('", "')'", "';'",
  "'['", "']'", "$accept", "program", "function_defs", "function_def",
  "func_start", "statements", "statement", "decl_vector_stmt",
  "sizeof_stmt", "while_stmt", "if_stmt", "set_stmt", "decl_stmt", "expr", YY_NULLPTR
    };
    return yy_sname[yysymbol];
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -50;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      -1,     3,    11,    -1,    -7,    93,    -3,   -50,    10,   -50,
     -50,     5,    37,    36,    43,    49,    19,     0,     0,    39,
      32,   -50,   -50,    42,   -50,   -50,   -50,     1,    72,   -50,
       0,     0,    83,    56,    85,    61,    69,     0,   -24,    -6,
     -50,   -50,    74,   -50,   -50,     0,     0,     0,     0,     0,
      70,    90,   101,    77,   -50,   100,   -50,    93,   111,   -50,
     -50,    13,    13,    13,   -50,   -50,   105,   -50,   -50,   -50,
      84,    51,    88,    89,   -50,   113,   112,   -50,    98,   126,
       0,   102,   121,    93,   -50,    66,   122,   127,   117,    93,
      78,   -50
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     2,     0,     0,     0,     1,     0,     4,
      32,    33,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,    16,     0,    13,     9,    14,    11,     0,     3,
       0,     0,     0,     0,     0,     0,     0,     0,    33,     0,
      26,     5,     0,     8,    12,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    23,     0,    18,     0,     0,    15,
       7,    29,    30,    31,    27,    28,     0,    22,    24,    25,
       0,     0,     0,     0,    17,     0,     0,     6,     0,     0,
       0,     0,     0,     0,    19,     0,    20,     0,     0,     0,
       0,    21
  };

  const short
  parser::yypgoto_[] =
  {
     -50,   -50,   -50,   138,   -50,   -49,   -19,   -50,   -50,   -50,
     -50,   -50,   -50,   -16
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     2,     3,     4,     5,    19,    20,    21,    22,    23,
      24,    25,    26,    27
  };

  const signed char
  parser::yytable_[] =
  {
      42,    39,    40,    10,    38,     1,    31,     6,    71,    32,
      30,     7,    45,    46,    51,    52,    47,    48,    49,    45,
      46,    58,     9,    47,    48,    49,    59,    28,    18,    61,
      62,    63,    64,    65,    85,    31,    48,    49,    32,    29,
      90,    33,    10,    11,    34,    12,    13,    35,    14,    37,
      41,    15,    42,    16,    10,    11,    17,    12,    13,    36,
      14,    43,    75,    15,    82,    16,    42,    18,    17,    10,
      11,    42,    12,    13,    44,    14,    50,    86,    15,    18,
      16,    10,    11,    17,    12,    13,    53,    14,    54,    91,
      15,    55,    16,    56,    18,    17,    10,    11,    57,    12,
      13,    66,    14,    60,    70,    15,    18,    16,    45,    46,
      17,    69,    47,    48,    49,    73,    74,    76,    77,    45,
      46,    18,    67,    47,    48,    49,    78,    79,    80,    45,
      46,    83,    68,    47,    48,    49,    81,    88,    87,    45,
      46,     8,    72,    47,    48,    49,    89,     0,     0,     0,
       0,     0,    84
  };

  const signed char
  parser::yycheck_[] =
  {
      19,    17,    18,     3,     4,     6,    30,     4,    57,    33,
       5,     0,    18,    19,    30,    31,    22,    23,    24,    18,
      19,    37,    29,    22,    23,    24,    32,    30,    28,    45,
      46,    47,    48,    49,    83,    30,    23,    24,    33,    29,
      89,     4,     3,     4,     8,     6,     7,     4,     9,    30,
      11,    12,    71,    14,     3,     4,    17,     6,     7,    10,
       9,    29,    11,    12,    80,    14,    85,    28,    17,     3,
       4,    90,     6,     7,    32,     9,     4,    11,    12,    28,
      14,     3,     4,    17,     6,     7,     3,     9,    32,    11,
      12,     6,    14,    32,    28,    17,     3,     4,    29,     6,
       7,    31,     9,    29,     4,    12,    28,    14,    18,    19,
      17,    34,    22,    23,    24,    10,    32,    29,    29,    18,
      19,    28,    32,    22,    23,    24,    13,    15,    30,    18,
      19,    29,    31,    22,    23,    24,    10,    10,    16,    18,
      19,     3,    31,    22,    23,    24,    29,    -1,    -1,    -1,
      -1,    -1,    31
  };

  const signed char
  parser::yystos_[] =
  {
       0,     6,    36,    37,    38,    39,     4,     0,    38,    29,
       3,     4,     6,     7,     9,    12,    14,    17,    28,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    30,    29,
       5,    30,    33,     4,     8,     4,    10,    30,     4,    48,
      48,    11,    41,    29,    32,    18,    19,    22,    23,    24,
       4,    48,    48,     3,    32,     6,    32,    29,    48,    32,
      29,    48,    48,    48,    48,    48,    31,    32,    31,    34,
       4,    40,    31,    10,    32,    11,    29,    29,    13,    15,
      30,    10,    48,    29,    31,    40,    11,    16,    10,    29,
      40,    11
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    35,    36,    37,    37,    38,    39,    40,    40,    41,
      41,    41,    41,    41,    41,    41,    41,    42,    43,    44,
      45,    45,    46,    47,    48,    48,    48,    48,    48,    48,
      48,    48,    48,    48
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     3,     2,     3,     7,     3,     2,     1,
       1,     1,     2,     1,     1,     3,     1,     5,     3,     9,
      10,    15,     4,     3,     4,     4,     2,     3,     3,     3,
       3,     3,     1,     1
  };




#if YYDEBUG
  const unsigned char
  parser::yyrline_[] =
  {
       0,    74,    74,    81,    82,    86,   113,   119,   120,   124,
     125,   127,   128,   129,   130,   131,   132,   136,   145,   154,
     160,   164,   170,   175,   180,   184,   188,   192,   196,   200,
     204,   208,   212,   216
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG


} // yy
#line 1385 "parser.tab.cc"

#line 224 "parser.y"

