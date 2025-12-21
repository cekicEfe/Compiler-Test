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



// First part of user prologue.
#line 1 "./Parser.yy"


// Thank you for saving my ass:
// https://learnmoderncpp.com/2020/12/18/generating-c-programs-with-flex-and-bison-3/

#include <iostream>
#include <string>
#include <cmath>
#include <FlexLexer.h>

#line 52 "Parser.cpp"


#include "Parser.hpp"


// Unqualified %code blocks.
#line 30 "./Parser.yy"

    #include "Scanner.hpp"
    #define yylex(x) scanner->lex(x)

#line 64 "Parser.cpp"


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

#line 18 "./Parser.yy"
namespace calc {
#line 138 "Parser.cpp"

  /// Build a parser object.
  Parser::Parser (Scanner* scanner_yyarg)
#if YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg)
  {}

  Parser::~Parser ()
  {}

  Parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/

  // basic_symbol.
  template <typename Base>
  Parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_T_FALSE: // T_FALSE
      case symbol_kind::S_T_TRUE: // T_TRUE
        value.copy< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_T_CHAR: // T_CHAR
        value.copy< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_T_FLOAT: // T_FLOAT
        value.copy< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_T_INT: // T_INT
        value.copy< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_T_ATOM: // T_ATOM
      case symbol_kind::S_T_KEYWORD: // T_KEYWORD
      case symbol_kind::S_T_STRING: // T_STRING
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  Parser::symbol_kind_type
  Parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  Parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  Parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_T_FALSE: // T_FALSE
      case symbol_kind::S_T_TRUE: // T_TRUE
        value.move< bool > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_T_CHAR: // T_CHAR
        value.move< char > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_T_FLOAT: // T_FLOAT
        value.move< float > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_T_INT: // T_INT
        value.move< int > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_T_ATOM: // T_ATOM
      case symbol_kind::S_T_KEYWORD: // T_KEYWORD
      case symbol_kind::S_T_STRING: // T_STRING
        value.move< std::string > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_kind.
  Parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  Parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  Parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  Parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  void
  Parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  void
  Parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  Parser::symbol_kind_type
  Parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  Parser::symbol_kind_type
  Parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }



  // by_state.
  Parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  Parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  Parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  Parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  Parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  Parser::symbol_kind_type
  Parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  Parser::stack_symbol_type::stack_symbol_type ()
  {}

  Parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_T_FALSE: // T_FALSE
      case symbol_kind::S_T_TRUE: // T_TRUE
        value.YY_MOVE_OR_COPY< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_T_CHAR: // T_CHAR
        value.YY_MOVE_OR_COPY< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_T_FLOAT: // T_FLOAT
        value.YY_MOVE_OR_COPY< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_T_INT: // T_INT
        value.YY_MOVE_OR_COPY< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_T_ATOM: // T_ATOM
      case symbol_kind::S_T_KEYWORD: // T_KEYWORD
      case symbol_kind::S_T_STRING: // T_STRING
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

  Parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_T_FALSE: // T_FALSE
      case symbol_kind::S_T_TRUE: // T_TRUE
        value.move< bool > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_T_CHAR: // T_CHAR
        value.move< char > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_T_FLOAT: // T_FLOAT
        value.move< float > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_T_INT: // T_INT
        value.move< int > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_T_ATOM: // T_ATOM
      case symbol_kind::S_T_KEYWORD: // T_KEYWORD
      case symbol_kind::S_T_STRING: // T_STRING
        value.move< std::string > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_T_FALSE: // T_FALSE
      case symbol_kind::S_T_TRUE: // T_TRUE
        value.copy< bool > (that.value);
        break;

      case symbol_kind::S_T_CHAR: // T_CHAR
        value.copy< char > (that.value);
        break;

      case symbol_kind::S_T_FLOAT: // T_FLOAT
        value.copy< float > (that.value);
        break;

      case symbol_kind::S_T_INT: // T_INT
        value.copy< int > (that.value);
        break;

      case symbol_kind::S_T_ATOM: // T_ATOM
      case symbol_kind::S_T_KEYWORD: // T_KEYWORD
      case symbol_kind::S_T_STRING: // T_STRING
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  Parser::stack_symbol_type&
  Parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_T_FALSE: // T_FALSE
      case symbol_kind::S_T_TRUE: // T_TRUE
        value.move< bool > (that.value);
        break;

      case symbol_kind::S_T_CHAR: // T_CHAR
        value.move< char > (that.value);
        break;

      case symbol_kind::S_T_FLOAT: // T_FLOAT
        value.move< float > (that.value);
        break;

      case symbol_kind::S_T_INT: // T_INT
        value.move< int > (that.value);
        break;

      case symbol_kind::S_T_ATOM: // T_ATOM
      case symbol_kind::S_T_KEYWORD: // T_KEYWORD
      case symbol_kind::S_T_STRING: // T_STRING
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
  Parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if YYDEBUG
  template <typename Base>
  void
  Parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
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
  Parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  Parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  Parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  Parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  Parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  Parser::debug_level_type
  Parser::debug_level () const
  {
    return yydebug_;
  }

  void
  Parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  Parser::state_type
  Parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  Parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  Parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  Parser::operator() ()
  {
    return parse ();
  }

  int
  Parser::parse ()
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
            yyla.kind_ = yytranslate_ (yylex (&yyla.value));
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
      case symbol_kind::S_T_FALSE: // T_FALSE
      case symbol_kind::S_T_TRUE: // T_TRUE
        yylhs.value.emplace< bool > ();
        break;

      case symbol_kind::S_T_CHAR: // T_CHAR
        yylhs.value.emplace< char > ();
        break;

      case symbol_kind::S_T_FLOAT: // T_FLOAT
        yylhs.value.emplace< float > ();
        break;

      case symbol_kind::S_T_INT: // T_INT
        yylhs.value.emplace< int > ();
        break;

      case symbol_kind::S_T_ATOM: // T_ATOM
      case symbol_kind::S_T_KEYWORD: // T_KEYWORD
      case symbol_kind::S_T_STRING: // T_STRING
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
  case 6: // define: T_L_PAREN1 T_DEFINE T_ATOM id T_R_PAREN1
#line 71 "./Parser.yy"
                                           {
    std::cout << "Found define id pr1" << std::endl;
  }
#line 776 "Parser.cpp"
    break;

  case 7: // define: T_L_PAREN2 T_DEFINE T_ATOM id T_R_PAREN2
#line 74 "./Parser.yy"
                                           {
    std::cout << "Found define id pr2" << std::endl;
  }
#line 784 "Parser.cpp"
    break;

  case 8: // define_class: T_L_PAREN1 T_DEFINE_CLASS T_ATOM T_AS T_ATOM define_class_method_list_pre T_R_PAREN1
#line 81 "./Parser.yy"
                                                                                       {
    std::cout << "Found : define typeclass" << std::endl;
  }
#line 792 "Parser.cpp"
    break;

  case 9: // define_class: T_L_PAREN2 T_DEFINE_CLASS T_ATOM T_AS T_ATOM define_class_method_list_pre T_R_PAREN2
#line 84 "./Parser.yy"
                                                                                       {
    std::cout << "Found : define typeclass" << std::endl;
  }
#line 800 "Parser.cpp"
    break;

  case 13: // define_class_method_list: define_class_method define_class_method_list
#line 93 "./Parser.yy"
                                               {
    std::cout << "Found : define typeclass method list" << std::endl;
  }
#line 808 "Parser.cpp"
    break;

  case 14: // define_class_method: T_L_PAREN1 T_DEFINE_METHOD T_ATOM define_class_method_args T_R_PAREN1
#line 98 "./Parser.yy"
                                                                        {
    std::cout << "Found : define typeclass method" << std::endl;
  }
#line 816 "Parser.cpp"
    break;

  case 15: // define_class_method: T_L_PAREN2 T_DEFINE_METHOD T_ATOM define_class_method_args T_R_PAREN2
#line 101 "./Parser.yy"
                                                                        {
    std::cout << "Found : define typeclass method" << std::endl;
  }
#line 824 "Parser.cpp"
    break;

  case 16: // define_class_method_args: T_L_PAREN1 args T_R_PAREN1
#line 106 "./Parser.yy"
                             {
    std::cout << "Found : define typeclass method args" << std::endl;
  }
#line 832 "Parser.cpp"
    break;

  case 17: // define_class_method_args: T_L_PAREN2 args T_R_PAREN2
#line 109 "./Parser.yy"
                             {
    std::cout << "Found : define typeclass method args" << std::endl;
  }
#line 840 "Parser.cpp"
    break;

  case 19: // args: T_ATOM args
#line 114 "./Parser.yy"
              {    
    std::cout << "Found : args" << std::endl;
}
#line 848 "Parser.cpp"
    break;

  case 20: // s_exp: T_L_PAREN1 s_exp_list T_R_PAREN1
#line 121 "./Parser.yy"
                                   {
    std::cout << "Found s_exp type1" << std::endl;  
  }
#line 856 "Parser.cpp"
    break;

  case 21: // s_exp: T_L_PAREN2 s_exp_list T_R_PAREN2
#line 124 "./Parser.yy"
                                   {
    std::cout << "Found s_exp type2" << std::endl;  
  }
#line 864 "Parser.cpp"
    break;

  case 22: // s_exp: T_L_BRACK s_exp_no_list s_exp_no_list s_exp_no_list T_R_BRACK
#line 127 "./Parser.yy"
                                                                {
    std::cout << "Found s_exp infix" << std::endl;  
  }
#line 872 "Parser.cpp"
    break;

  case 23: // s_exp_no_list: id
#line 132 "./Parser.yy"
        {}
#line 878 "Parser.cpp"
    break;

  case 24: // s_exp_no_list: s_exp
#line 133 "./Parser.yy"
        {}
#line 884 "Parser.cpp"
    break;

  case 26: // s_exp_list: s_exp s_exp_list
#line 136 "./Parser.yy"
                   {
    printf("Found s_exp in s_exp list \n");
  }
#line 892 "Parser.cpp"
    break;

  case 27: // s_exp_list: id s_exp_list
#line 139 "./Parser.yy"
                   {
    printf("Found id in s_exp list \n");
  }
#line 900 "Parser.cpp"
    break;

  case 28: // id: T_QUOTE s_exp
#line 146 "./Parser.yy"
                  {
    printf("Found id : Quoted s_exp \n");
  }
#line 908 "Parser.cpp"
    break;

  case 29: // id: T_QUOTE id
#line 149 "./Parser.yy"
                  {
    printf("Found id : Quoted id \n");
  }
#line 916 "Parser.cpp"
    break;

  case 30: // id: T_QUASI_Q id
#line 152 "./Parser.yy"
                  {
    printf("Found id : Quasiquoted id \n");
  }
#line 924 "Parser.cpp"
    break;

  case 31: // id: T_QUASI_Q s_exp
#line 155 "./Parser.yy"
                  {
    printf("Found id : Quasiquoted s_exp \n");
  }
#line 932 "Parser.cpp"
    break;

  case 32: // id: T_FALSE
#line 167 "./Parser.yy"
                  {
    printf("Found id : False \n");
    std::cout << "False" << std::endl;
  }
#line 941 "Parser.cpp"
    break;

  case 33: // id: T_TRUE
#line 171 "./Parser.yy"
                  {
    printf("Found id : True \n");
    std::cout << "True" << std::endl;
  }
#line 950 "Parser.cpp"
    break;

  case 34: // id: T_INT
#line 175 "./Parser.yy"
                  {
    printf("Found id : Int Const\n");
    std::cout << yystack_[0].value.as < int > () << std::endl;
  }
#line 959 "Parser.cpp"
    break;

  case 35: // id: T_FLOAT
#line 179 "./Parser.yy"
                  {
    printf("Found id : Float Const\n");
    std::cout << yystack_[0].value.as < float > () << std::endl;
  }
#line 968 "Parser.cpp"
    break;

  case 36: // id: T_CHAR
#line 183 "./Parser.yy"
                  {
    printf("Found id : Char Const\n");
  }
#line 976 "Parser.cpp"
    break;

  case 37: // id: T_STRING
#line 186 "./Parser.yy"
                  {
    printf("Found id : String Const\n");
    std::cout << yystack_[0].value.as < std::string > () << std::endl;
  }
#line 985 "Parser.cpp"
    break;

  case 38: // id: T_KEYWORD
#line 190 "./Parser.yy"
                  {
    printf("Found id : Keyword \n");
    std::cout << yystack_[0].value.as < std::string > () << std::endl;
  }
#line 994 "Parser.cpp"
    break;

  case 39: // id: T_ATOM
#line 194 "./Parser.yy"
                  {
    printf("Found id : Atom \n");
    std::cout << yystack_[0].value.as < std::string > () << std::endl;
  }
#line 1003 "Parser.cpp"
    break;

  case 40: // id: T_NIL
#line 198 "./Parser.yy"
                  {
    printf("Found id : Nil \n");
  }
#line 1011 "Parser.cpp"
    break;


#line 1015 "Parser.cpp"

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
        std::string msg = YY_("syntax error");
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
  Parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

#if YYDEBUG || 0
  const char *
  Parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytname_[yysymbol];
  }
#endif // #if YYDEBUG || 0









  const signed char Parser::yypact_ninf_ = -70;

  const signed char Parser::yytable_ninf_ = -1;

  const signed char
  Parser::yypact_[] =
  {
       4,    34,    57,    76,    11,     4,     4,     4,    -3,     1,
      76,    76,   -70,   -70,   -70,    76,    76,   -70,   -70,   -70,
     -70,   -70,   -70,    76,    16,    76,    15,    20,     9,   -70,
      76,   -70,   -70,   -70,   -70,   -70,    89,    35,   -70,   -70,
     -70,   -70,   -70,   -70,   -70,    89,    38,   -70,    76,    36,
      29,    42,    33,    49,   -70,    18,   -70,    18,   -70,    22,
      22,    54,    53,    61,    63,    67,    22,    59,   -70,   -70,
      71,    73,   -70,   -70,   -70,    25,    25,    75,    75,    68,
      84,    75,    87,    97,   -70,   -70,   -70,   -70,   -70
  };

  const signed char
  Parser::yydefact_[] =
  {
       2,    25,    25,     0,     0,     2,     2,     2,     0,     0,
      25,    25,    39,    38,    40,     0,     0,    32,    33,    35,
      34,    36,    37,    25,     0,    25,     0,     0,     0,    24,
       0,    23,     1,     4,     5,     3,     0,     0,    28,    29,
      31,    30,    26,    20,    27,     0,     0,    21,     0,     0,
       0,     0,     0,     0,     6,     0,     7,     0,    22,    12,
      12,     0,     0,     0,     0,     0,    12,     0,     8,     9,
       0,     0,    10,    13,    11,     0,     0,    18,    18,     0,
       0,    18,     0,     0,    14,    15,    19,    16,    17
  };

  const signed char
  Parser::yypgoto_[] =
  {
     -70,    19,   -70,   -70,    66,   -56,   -70,    40,   -69,     0,
     -28,     6,    -2
  };

  const signed char
  Parser::yydefgoto_[] =
  {
       0,     4,     5,     6,    61,    65,    66,    79,    82,    23,
      30,    24,    25
  };

  const signed char
  Parser::yytable_[] =
  {
       7,    31,    48,    29,    67,     7,     7,     7,    28,    83,
      73,    32,    86,    39,    41,    38,    40,    28,    36,     1,
      53,     2,    37,     3,    33,    34,    35,    47,    31,    42,
      29,    44,    43,    59,    49,    60,    45,    63,     8,    64,
      77,    46,    78,    51,    50,     9,    31,    52,    29,    10,
      55,    11,    54,     3,    57,    12,    13,    14,    15,    16,
      56,    26,    17,    18,    19,    20,    21,    22,    27,    58,
      68,    69,    10,    70,    11,    71,     3,    74,    12,    13,
      14,    15,    16,    72,    84,    17,    18,    19,    20,    21,
      22,    10,    75,    11,    76,     3,    81,    12,    13,    14,
      15,    16,    85,    87,    17,    18,    19,    20,    21,    22,
      12,    13,    14,    15,    16,    88,    80,    17,    18,    19,
      20,    21,    22,    62
  };

  const signed char
  Parser::yycheck_[] =
  {
       0,     3,    30,     3,    60,     5,     6,     7,     2,    78,
      66,     0,    81,    15,    16,    15,    16,    11,    21,    15,
      48,    17,    21,    19,     5,     6,     7,    18,    30,    23,
      30,    25,    16,    15,    36,    17,    21,    15,     4,    17,
      15,    21,    17,    45,     9,    11,    48,     9,    48,    15,
      21,    17,    16,    19,    21,    21,    22,    23,    24,    25,
      18,     4,    28,    29,    30,    31,    32,    33,    11,    20,
      16,    18,    15,    12,    17,    12,    19,    18,    21,    22,
      23,    24,    25,    16,    16,    28,    29,    30,    31,    32,
      33,    15,    21,    17,    21,    19,    21,    21,    22,    23,
      24,    25,    18,    16,    28,    29,    30,    31,    32,    33,
      21,    22,    23,    24,    25,    18,    76,    28,    29,    30,
      31,    32,    33,    57
  };

  const signed char
  Parser::yystos_[] =
  {
       0,    15,    17,    19,    35,    36,    37,    43,     4,    11,
      15,    17,    21,    22,    23,    24,    25,    28,    29,    30,
      31,    32,    33,    43,    45,    46,     4,    11,    45,    43,
      44,    46,     0,    35,    35,    35,    21,    21,    43,    46,
      43,    46,    45,    16,    45,    21,    21,    18,    44,    46,
       9,    46,     9,    44,    16,    21,    18,    21,    20,    15,
      17,    38,    38,    15,    17,    39,    40,    39,    16,    18,
      12,    12,    16,    39,    18,    21,    21,    15,    17,    41,
      41,    21,    42,    42,    16,    18,    42,    16,    18
  };

  const signed char
  Parser::yyr1_[] =
  {
       0,    34,    35,    35,    35,    35,    36,    36,    37,    37,
      38,    38,    39,    39,    40,    40,    41,    41,    42,    42,
      43,    43,    43,    44,    44,    45,    45,    45,    46,    46,
      46,    46,    46,    46,    46,    46,    46,    46,    46,    46,
      46
  };

  const signed char
  Parser::yyr2_[] =
  {
       0,     2,     0,     2,     2,     2,     5,     5,     7,     7,
       3,     3,     0,     2,     5,     5,     3,     3,     0,     2,
       3,     3,     5,     1,     1,     0,     2,     2,     2,     2,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1
  };


#if YYDEBUG
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const Parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "T_ERROR", "T_DEFINE",
  "T_COND", "T_EVAL", "T_READ", "T_LAMBDA", "T_AS", "T_ANY",
  "T_DEFINE_CLASS", "T_DEFINE_METHOD", "T_CLASS_INSTANCE",
  "T_METHOD_INSTANCE", "T_L_PAREN1", "T_R_PAREN1", "T_L_PAREN2",
  "T_R_PAREN2", "T_L_BRACK", "T_R_BRACK", "T_ATOM", "T_KEYWORD", "T_NIL",
  "T_QUOTE", "T_QUASI_Q", "T_UNQUOTE", "T_SPLICE", "T_FALSE", "T_TRUE",
  "T_FLOAT", "T_INT", "T_CHAR", "T_STRING", "$accept", "input", "define",
  "define_class", "define_class_method_list_pre",
  "define_class_method_list", "define_class_method",
  "define_class_method_args", "args", "s_exp", "s_exp_no_list",
  "s_exp_list", "id", YY_NULLPTR
  };
#endif


#if YYDEBUG
  const unsigned char
  Parser::yyrline_[] =
  {
       0,    63,    63,    64,    65,    66,    71,    74,    81,    84,
      89,    90,    92,    93,    98,   101,   106,   109,   113,   114,
     121,   124,   127,   132,   133,   135,   136,   139,   146,   149,
     152,   155,   167,   171,   175,   179,   183,   186,   190,   194,
     198
  };

  void
  Parser::yy_stack_print_ () const
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
  Parser::yy_reduce_print_ (int yyrule) const
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

  Parser::symbol_kind_type
  Parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    // YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to
    // TOKEN-NUM as returned by yylex.
    static
    const signed char
    translate_table[] =
    {
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33
    };
    // Last valid token kind.
    const int code_max = 288;

    if (t <= 0)
      return symbol_kind::S_YYEOF;
    else if (t <= code_max)
      return static_cast <symbol_kind_type> (translate_table[t]);
    else
      return symbol_kind::S_YYUNDEF;
  }

#line 18 "./Parser.yy"
} // calc
#line 1432 "Parser.cpp"

#line 203 "./Parser.yy"


void calc::Parser::error(const std::string& msg) {
    std::cerr << msg << '\n';
}
