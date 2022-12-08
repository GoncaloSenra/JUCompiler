/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "jucompiler.y"


    //Gonçalo Senra   2020213750
    //Henrique Costa  2020214120
    
    #include <stdio.h>
    
    #include "SymTable.h"

    int yylex(void);
    

    char aux3[1024]; 
    char aux4[1024]; 

    int error;
    struct node * prog;
    int debug = false;

    void yyerror (const char *s);

#line 93 "y.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    ID = 258,                      /* ID  */
    INTLIT = 259,                  /* INTLIT  */
    STRLIT = 260,                  /* STRLIT  */
    REALLIT = 261,                 /* REALLIT  */
    BOOLLIT = 262,                 /* BOOLLIT  */
    AND = 263,                     /* AND  */
    ASSIGN = 264,                  /* ASSIGN  */
    STAR = 265,                    /* STAR  */
    COMMA = 266,                   /* COMMA  */
    DIV = 267,                     /* DIV  */
    EQ = 268,                      /* EQ  */
    GE = 269,                      /* GE  */
    GT = 270,                      /* GT  */
    LBRACE = 271,                  /* LBRACE  */
    LE = 272,                      /* LE  */
    LPAR = 273,                    /* LPAR  */
    LSQ = 274,                     /* LSQ  */
    LT = 275,                      /* LT  */
    MINUS = 276,                   /* MINUS  */
    MOD = 277,                     /* MOD  */
    NE = 278,                      /* NE  */
    NOT = 279,                     /* NOT  */
    OR = 280,                      /* OR  */
    PLUS = 281,                    /* PLUS  */
    RBRACE = 282,                  /* RBRACE  */
    RPAR = 283,                    /* RPAR  */
    RSQ = 284,                     /* RSQ  */
    SEMICOLON = 285,               /* SEMICOLON  */
    ARROW = 286,                   /* ARROW  */
    LSHIFT = 287,                  /* LSHIFT  */
    RSHIFT = 288,                  /* RSHIFT  */
    XOR = 289,                     /* XOR  */
    BOOL = 290,                    /* BOOL  */
    CLASS = 291,                   /* CLASS  */
    DOTLENGTH = 292,               /* DOTLENGTH  */
    DOUBLE = 293,                  /* DOUBLE  */
    ELSE = 294,                    /* ELSE  */
    IF = 295,                      /* IF  */
    INT = 296,                     /* INT  */
    PRINT = 297,                   /* PRINT  */
    PARSEINT = 298,                /* PARSEINT  */
    PUBLIC = 299,                  /* PUBLIC  */
    RETURN = 300,                  /* RETURN  */
    STATIC = 301,                  /* STATIC  */
    STRING = 302,                  /* STRING  */
    VOID = 303,                    /* VOID  */
    WHILE = 304,                   /* WHILE  */
    RESERVED = 305                 /* RESERVED  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define ID 258
#define INTLIT 259
#define STRLIT 260
#define REALLIT 261
#define BOOLLIT 262
#define AND 263
#define ASSIGN 264
#define STAR 265
#define COMMA 266
#define DIV 267
#define EQ 268
#define GE 269
#define GT 270
#define LBRACE 271
#define LE 272
#define LPAR 273
#define LSQ 274
#define LT 275
#define MINUS 276
#define MOD 277
#define NE 278
#define NOT 279
#define OR 280
#define PLUS 281
#define RBRACE 282
#define RPAR 283
#define RSQ 284
#define SEMICOLON 285
#define ARROW 286
#define LSHIFT 287
#define RSHIFT 288
#define XOR 289
#define BOOL 290
#define CLASS 291
#define DOTLENGTH 292
#define DOUBLE 293
#define ELSE 294
#define IF 295
#define INT 296
#define PRINT 297
#define PARSEINT 298
#define PUBLIC 299
#define RETURN 300
#define STATIC 301
#define STRING 302
#define VOID 303
#define WHILE 304
#define RESERVED 305

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "jucompiler.y"
  
    struct node * no;
    struct token{
        char* id;
        int line;
        int col;
    }tok;

#line 255 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_INTLIT = 4,                     /* INTLIT  */
  YYSYMBOL_STRLIT = 5,                     /* STRLIT  */
  YYSYMBOL_REALLIT = 6,                    /* REALLIT  */
  YYSYMBOL_BOOLLIT = 7,                    /* BOOLLIT  */
  YYSYMBOL_AND = 8,                        /* AND  */
  YYSYMBOL_ASSIGN = 9,                     /* ASSIGN  */
  YYSYMBOL_STAR = 10,                      /* STAR  */
  YYSYMBOL_COMMA = 11,                     /* COMMA  */
  YYSYMBOL_DIV = 12,                       /* DIV  */
  YYSYMBOL_EQ = 13,                        /* EQ  */
  YYSYMBOL_GE = 14,                        /* GE  */
  YYSYMBOL_GT = 15,                        /* GT  */
  YYSYMBOL_LBRACE = 16,                    /* LBRACE  */
  YYSYMBOL_LE = 17,                        /* LE  */
  YYSYMBOL_LPAR = 18,                      /* LPAR  */
  YYSYMBOL_LSQ = 19,                       /* LSQ  */
  YYSYMBOL_LT = 20,                        /* LT  */
  YYSYMBOL_MINUS = 21,                     /* MINUS  */
  YYSYMBOL_MOD = 22,                       /* MOD  */
  YYSYMBOL_NE = 23,                        /* NE  */
  YYSYMBOL_NOT = 24,                       /* NOT  */
  YYSYMBOL_OR = 25,                        /* OR  */
  YYSYMBOL_PLUS = 26,                      /* PLUS  */
  YYSYMBOL_RBRACE = 27,                    /* RBRACE  */
  YYSYMBOL_RPAR = 28,                      /* RPAR  */
  YYSYMBOL_RSQ = 29,                       /* RSQ  */
  YYSYMBOL_SEMICOLON = 30,                 /* SEMICOLON  */
  YYSYMBOL_ARROW = 31,                     /* ARROW  */
  YYSYMBOL_LSHIFT = 32,                    /* LSHIFT  */
  YYSYMBOL_RSHIFT = 33,                    /* RSHIFT  */
  YYSYMBOL_XOR = 34,                       /* XOR  */
  YYSYMBOL_BOOL = 35,                      /* BOOL  */
  YYSYMBOL_CLASS = 36,                     /* CLASS  */
  YYSYMBOL_DOTLENGTH = 37,                 /* DOTLENGTH  */
  YYSYMBOL_DOUBLE = 38,                    /* DOUBLE  */
  YYSYMBOL_ELSE = 39,                      /* ELSE  */
  YYSYMBOL_IF = 40,                        /* IF  */
  YYSYMBOL_INT = 41,                       /* INT  */
  YYSYMBOL_PRINT = 42,                     /* PRINT  */
  YYSYMBOL_PARSEINT = 43,                  /* PARSEINT  */
  YYSYMBOL_PUBLIC = 44,                    /* PUBLIC  */
  YYSYMBOL_RETURN = 45,                    /* RETURN  */
  YYSYMBOL_STATIC = 46,                    /* STATIC  */
  YYSYMBOL_STRING = 47,                    /* STRING  */
  YYSYMBOL_VOID = 48,                      /* VOID  */
  YYSYMBOL_WHILE = 49,                     /* WHILE  */
  YYSYMBOL_RESERVED = 50,                  /* RESERVED  */
  YYSYMBOL_YYACCEPT = 51,                  /* $accept  */
  YYSYMBOL_Program = 52,                   /* Program  */
  YYSYMBOL_recPR = 53,                     /* recPR  */
  YYSYMBOL_MethodDecl = 54,                /* MethodDecl  */
  YYSYMBOL_FieldDecl = 55,                 /* FieldDecl  */
  YYSYMBOL_recCOMMAID = 56,                /* recCOMMAID  */
  YYSYMBOL_Type = 57,                      /* Type  */
  YYSYMBOL_MethodHeader = 58,              /* MethodHeader  */
  YYSYMBOL_FormalParams = 59,              /* FormalParams  */
  YYSYMBOL_recFP = 60,                     /* recFP  */
  YYSYMBOL_MethodBody = 61,                /* MethodBody  */
  YYSYMBOL_recMD = 62,                     /* recMD  */
  YYSYMBOL_VarDecl = 63,                   /* VarDecl  */
  YYSYMBOL_recVAR = 64,                    /* recVAR  */
  YYSYMBOL_Statement = 65,                 /* Statement  */
  YYSYMBOL_recSTAT = 66,                   /* recSTAT  */
  YYSYMBOL_MethodInvocation = 67,          /* MethodInvocation  */
  YYSYMBOL_recCOMMAEXP = 68,               /* recCOMMAEXP  */
  YYSYMBOL_Assignment = 69,                /* Assignment  */
  YYSYMBOL_ParseArgs = 70,                 /* ParseArgs  */
  YYSYMBOL_Expr2 = 71,                     /* Expr2  */
  YYSYMBOL_Expr = 72                       /* Expr  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   420

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  82
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   126,   126,   129,   130,   131,   132,   135,   138,   148,
     151,   152,   155,   156,   157,   160,   161,   162,   163,   166,
     171,   174,   175,   178,   181,   182,   183,   186,   198,   199,
     202,   203,   225,   236,   244,   245,   246,   247,   248,   249,
     250,   251,   252,   255,   256,   259,   260,   261,   264,   265,
     268,   271,   272,   275,   276,   277,   278,   279,   280,   281,
     282,   283,   284,   285,   286,   287,   288,   289,   290,   291,
     292,   293,   294,   295,   296,   297,   298,   299,   300,   301,
     302,   305,   306
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ID", "INTLIT",
  "STRLIT", "REALLIT", "BOOLLIT", "AND", "ASSIGN", "STAR", "COMMA", "DIV",
  "EQ", "GE", "GT", "LBRACE", "LE", "LPAR", "LSQ", "LT", "MINUS", "MOD",
  "NE", "NOT", "OR", "PLUS", "RBRACE", "RPAR", "RSQ", "SEMICOLON", "ARROW",
  "LSHIFT", "RSHIFT", "XOR", "BOOL", "CLASS", "DOTLENGTH", "DOUBLE",
  "ELSE", "IF", "INT", "PRINT", "PARSEINT", "PUBLIC", "RETURN", "STATIC",
  "STRING", "VOID", "WHILE", "RESERVED", "$accept", "Program", "recPR",
  "MethodDecl", "FieldDecl", "recCOMMAID", "Type", "MethodHeader",
  "FormalParams", "recFP", "MethodBody", "recMD", "VarDecl", "recVAR",
  "Statement", "recSTAT", "MethodInvocation", "recCOMMAEXP", "Assignment",
  "ParseArgs", "Expr2", "Expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-42)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-45)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -23,    33,    53,    24,   -42,     4,    11,     4,     1,    38,
       4,     4,   -42,   -42,   -32,   -42,   -42,   -42,   -42,   -42,
     -42,    85,    87,    91,    83,    -4,    88,   -42,    58,   100,
      59,    78,    80,     6,   138,   -42,    94,    98,    99,   217,
     101,   118,    95,    88,    88,   105,   108,   112,   -42,   124,
     121,   116,   134,   -42,   120,   -42,   -42,   252,   201,   138,
     119,   252,   245,    60,    14,   -42,   -42,   -42,   210,   261,
     261,   261,   -42,   -42,   -42,   -42,   286,   123,   252,   145,
     -42,   -42,   -42,   -42,   -42,   -42,   129,   148,   -42,   -42,
     -42,   -42,   132,   -42,   152,   -42,   -42,   136,   139,   141,
     143,   153,   -42,   146,   147,    27,   -42,   -42,   -42,   261,
     261,   261,   261,   261,   261,   261,   261,   261,   261,   261,
     261,   261,   261,   261,   261,   -42,   149,   170,   155,   173,
      57,   -42,   -42,   252,   151,   154,   156,   158,   -42,   252,
     -42,   -42,   338,   -42,   -42,   387,    34,    34,    34,    34,
      40,   -42,   387,   313,    40,   140,   140,   363,   154,   145,
     -42,   -42,   179,   152,   -42,   150,   -42,   -42,   161,   -42,
     -42,   148,   -42,   154,   163,   -42,   -42,   -42
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     9,     5,     0,     2,     3,     4,    12,    14,
      13,     0,     0,     0,     0,    11,     0,     7,     0,     0,
       0,     0,     0,     0,     0,    39,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,     0,
       0,     0,    11,    16,     0,     8,    42,     0,     0,     0,
       0,     0,     0,     0,    75,    77,    78,    79,     0,     0,
       0,     0,    35,    73,    81,    74,    82,     0,     0,    29,
      23,    25,    24,    36,    37,    38,     0,    22,    17,    10,
      15,    50,     0,    46,    49,    43,    30,     0,     0,     0,
       0,     0,    76,     0,     0,    75,    69,    71,    70,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    34,     0,     0,     0,     0,
       0,    19,    47,     0,     0,     0,     0,     0,    52,     0,
      80,    72,    58,    55,    56,    63,    64,    65,    66,    67,
      54,    57,    68,    59,    53,    61,    62,    60,     0,    29,
      27,    20,     0,    49,    45,    32,    41,    40,     0,    33,
      28,    22,    48,     0,     0,    21,    31,    51
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -42,   -42,    47,   -42,   -42,   157,    -3,   -42,   162,    22,
     -42,    41,   -42,    36,   -33,   142,   -26,    35,   -24,   -22,
     -41,   -19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     9,    10,    11,    31,    41,    23,    51,   131,
      27,    42,    43,   128,    44,    60,    73,   134,    74,    75,
      76,    77
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      45,    59,    46,    18,    47,     6,    19,    29,    45,    20,
      46,    22,    47,     1,    30,    57,    21,    45,    45,    46,
      46,    47,    47,    57,    58,    50,    59,    50,   106,   107,
     108,    -6,    58,    45,     7,    46,     3,    47,    91,    94,
       5,    12,    97,    99,   110,    58,   111,    14,     8,   104,
     110,   102,   111,     4,    13,   117,   118,    16,    17,   126,
     121,   100,   118,   101,   102,    15,   122,   123,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,    81,    82,    48,    53,    24,    32,
      25,    33,    18,    18,    18,    19,    19,    19,    20,    20,
      20,    28,   165,    52,    34,    49,    49,    26,    55,    45,
      56,    46,    61,    47,   163,   -26,    62,    63,    35,    78,
     168,    79,    80,    18,    87,   169,    19,   162,    36,    20,
      37,    38,    45,    39,    46,    83,    47,    40,    84,    32,
     176,    33,    85,    86,    88,    29,    96,    45,    90,    46,
     110,    47,   111,   125,    34,    32,   127,    33,   129,   130,
     132,   117,   118,   133,   135,   -44,   121,   136,    35,   137,
      34,   138,   139,   159,   140,   141,   161,   158,    36,   164,
      37,    38,   171,    39,    35,   160,   166,    40,   167,   173,
     174,   177,    54,   175,    36,   170,    37,    38,   172,    39,
       0,    95,    92,    40,    64,    65,     0,    66,    67,    89,
       0,   103,     0,    64,    65,     0,    66,    67,     0,    68,
      64,    65,    69,    66,    67,    70,     0,    71,    68,    93,
       0,    69,     0,     0,    70,    68,    71,     0,    69,     0,
       0,    70,     0,    71,    38,     0,     0,    72,    64,    65,
      98,    66,    67,    38,     0,    64,    65,     0,    66,    67,
      38,     0,     0,    68,   105,    65,    69,    66,    67,    70,
      68,    71,     0,    69,     0,     0,    70,     0,    71,    68,
       0,     0,    69,     0,     0,    70,     0,    71,    38,     0,
       0,     0,     0,     0,   109,    38,   110,     0,   111,   112,
     113,   114,     0,   115,    38,     0,   116,   117,   118,   119,
       0,   120,   121,     0,     0,     0,     0,     0,   122,   123,
     124,   109,     0,   110,     0,   111,   112,   113,   114,     0,
     115,     0,     0,   116,   117,   118,   119,     0,     0,   121,
       0,     0,     0,     0,     0,   122,   123,   124,   110,     0,
     111,   112,   113,   114,     0,   115,     0,     0,   116,   117,
     118,   119,     0,     0,   121,     0,     0,     0,     0,     0,
     122,   123,   124,   110,     0,   111,   112,   113,   114,     0,
     115,     0,     0,   116,   117,   118,   119,     0,     0,   121,
       0,     0,     0,     0,     0,   122,   123,   110,     0,   111,
       0,   113,   114,     0,   115,     0,     0,   116,   117,   118,
       0,     0,     0,   121,     0,     0,     0,     0,     0,   122,
     123
};

static const yytype_int16 yycheck[] =
{
      26,    34,    26,    35,    26,     1,    38,    11,    34,    41,
      34,    14,    34,    36,    18,     9,    48,    43,    44,    43,
      44,    43,    44,     9,    18,    28,    59,    30,    69,    70,
      71,    27,    18,    59,    30,    59,     3,    59,    57,    58,
      16,    30,    61,    62,    10,    18,    12,    46,    44,    68,
      10,    37,    12,     0,     7,    21,    22,    10,    11,    78,
      26,     1,    22,     3,    37,    27,    32,    33,   109,   110,
     111,   112,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    43,    44,    28,    28,     3,     1,
       3,     3,    35,    35,    35,    38,    38,    38,    41,    41,
      41,    18,   135,     3,    16,    47,    47,    16,    30,   135,
      30,   135,    18,   135,   133,    27,    18,    18,    30,    18,
     139,     3,    27,    35,     3,   158,    38,   130,    40,    41,
      42,    43,   158,    45,   158,    30,   158,    49,    30,     1,
     173,     3,    30,    19,    28,    11,    27,   173,    28,   173,
      10,   173,    12,    30,    16,     1,    11,     3,    29,    11,
      28,    21,    22,    11,    28,    27,    26,    28,    30,    28,
      16,    28,    19,     3,    28,    28,     3,    28,    40,    28,
      42,    43,     3,    45,    30,    30,    30,    49,    30,    39,
      29,    28,    30,   171,    40,   159,    42,    43,   163,    45,
      -1,    59,     1,    49,     3,     4,    -1,     6,     7,    52,
      -1,     1,    -1,     3,     4,    -1,     6,     7,    -1,    18,
       3,     4,    21,     6,     7,    24,    -1,    26,    18,    28,
      -1,    21,    -1,    -1,    24,    18,    26,    -1,    21,    -1,
      -1,    24,    -1,    26,    43,    -1,    -1,    30,     3,     4,
       5,     6,     7,    43,    -1,     3,     4,    -1,     6,     7,
      43,    -1,    -1,    18,     3,     4,    21,     6,     7,    24,
      18,    26,    -1,    21,    -1,    -1,    24,    -1,    26,    18,
      -1,    -1,    21,    -1,    -1,    24,    -1,    26,    43,    -1,
      -1,    -1,    -1,    -1,     8,    43,    10,    -1,    12,    13,
      14,    15,    -1,    17,    43,    -1,    20,    21,    22,    23,
      -1,    25,    26,    -1,    -1,    -1,    -1,    -1,    32,    33,
      34,     8,    -1,    10,    -1,    12,    13,    14,    15,    -1,
      17,    -1,    -1,    20,    21,    22,    23,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    10,    -1,
      12,    13,    14,    15,    -1,    17,    -1,    -1,    20,    21,
      22,    23,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    10,    -1,    12,    13,    14,    15,    -1,
      17,    -1,    -1,    20,    21,    22,    23,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    32,    33,    10,    -1,    12,
      -1,    14,    15,    -1,    17,    -1,    -1,    20,    21,    22,
      -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,    32,
      33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,    52,     3,     0,    16,     1,    30,    44,    53,
      54,    55,    30,    53,    46,    27,    53,    53,    35,    38,
      41,    48,    57,    58,     3,     3,    16,    61,    18,    11,
      18,    56,     1,     3,    16,    30,    40,    42,    43,    45,
      49,    57,    62,    63,    65,    67,    69,    70,    28,    47,
      57,    59,     3,    28,    59,    30,    30,     9,    18,    65,
      66,    18,    18,    18,     3,     4,     6,     7,    18,    21,
      24,    26,    30,    67,    69,    70,    71,    72,    18,     3,
      27,    62,    62,    30,    30,    30,    19,     3,    28,    56,
      28,    72,     1,    28,    72,    66,    27,    72,     5,    72,
       1,     3,    37,     1,    72,     3,    71,    71,    71,     8,
      10,    12,    13,    14,    15,    17,    20,    21,    22,    23,
      25,    26,    32,    33,    34,    30,    72,    11,    64,    29,
      11,    60,    28,    11,    68,    28,    28,    28,    28,    19,
      28,    28,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    28,     3,
      30,     3,    57,    72,    28,    65,    30,    30,    72,    65,
      64,     3,    68,    39,    29,    60,    65,    28
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    54,    55,    55,
      56,    56,    57,    57,    57,    58,    58,    58,    58,    59,
      59,    60,    60,    61,    62,    62,    62,    63,    64,    64,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    66,    66,    67,    67,    67,    68,    68,
      69,    70,    70,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    72,    72
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     2,     2,     2,     0,     4,     6,     2,
       3,     0,     1,     1,     1,     5,     4,     5,     4,     3,
       4,     4,     0,     3,     2,     2,     0,     4,     3,     0,
       3,     7,     5,     5,     3,     2,     2,     2,     2,     1,
       5,     5,     2,     2,     0,     5,     3,     4,     3,     0,
       3,     7,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     3,     1,     1,     1,     2,     1,     1,     1,
       3,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2: /* Program: CLASS ID LBRACE recPR RBRACE  */
#line 126 "jucompiler.y"
                                                                                {(yyval.no) = prog = createNode(NULL,"Program", 0, 0); sprintf(aux3, "Id(%s)", (yyvsp[-3].tok).id); (yyval.no)->child = createNode((yyvsp[-3].tok).id, strdup(aux3), (yyvsp[-3].tok).line, (yyvsp[-3].tok).col); newBrother((yyval.no)->child, (yyvsp[-1].no)); if(debug)printf("Program\n");}
#line 1469 "y.tab.c"
    break;

  case 3: /* recPR: MethodDecl recPR  */
#line 129 "jucompiler.y"
                                                                               {(yyval.no) = (yyvsp[-1].no); newBrother((yyval.no), (yyvsp[0].no));if(debug)printf("recPR4\n");}
#line 1475 "y.tab.c"
    break;

  case 4: /* recPR: FieldDecl recPR  */
#line 130 "jucompiler.y"
                                                                               {(yyval.no) = (yyvsp[-1].no); newBrother((yyval.no), (yyvsp[0].no));if(debug)printf("recPR5\n");}
#line 1481 "y.tab.c"
    break;

  case 5: /* recPR: SEMICOLON recPR  */
#line 131 "jucompiler.y"
                                                                               {(yyval.no) = (yyvsp[0].no);if(debug)printf("recPR6\n");}
#line 1487 "y.tab.c"
    break;

  case 6: /* recPR: %empty  */
#line 132 "jucompiler.y"
                                                                               {(yyval.no) = NULL;}
#line 1493 "y.tab.c"
    break;

  case 7: /* MethodDecl: PUBLIC STATIC MethodHeader MethodBody  */
#line 135 "jucompiler.y"
                                                                                {(yyval.no) = createNode(NULL,"MethodDecl", 0, 0); (yyval.no)->child = (yyvsp[-1].no); newBrother((yyvsp[-1].no), (yyvsp[0].no));if(debug)printf("MethodDecl\n");}
#line 1499 "y.tab.c"
    break;

  case 8: /* FieldDecl: PUBLIC STATIC Type ID recCOMMAID SEMICOLON  */
#line 138 "jucompiler.y"
                                                                                {(yyval.no) = createNode(NULL,"FieldDecl", 0, 0); (yyval.no)->child = (yyvsp[-3].no); sprintf(aux3, "Id(%s)", (yyvsp[-2].tok).id); newBrother((yyvsp[-3].no), createNode((yyvsp[-2].tok).id, strdup(aux3), (yyvsp[-2].tok).line, (yyvsp[-2].tok).col)); newBrother((yyval.no), (yyvsp[-1].no));
                                                                                    struct node * auxnode = (yyvsp[-1].no), * auxnode2;
                                                                                    while(auxnode != NULL){
                                                                                        auxnode2 = auxnode->child;
                                                                                        auxnode->child = createNode(NULL,(yyvsp[-3].no)->var, 0, 0);
                                                                                        auxnode->child->brother = auxnode2;
                                                                                        auxnode = auxnode->brother;
                                                                                    }
                                                                                    if(debug)printf("FieldDecl\n");
                                                                                }
#line 1514 "y.tab.c"
    break;

  case 9: /* FieldDecl: error SEMICOLON  */
#line 148 "jucompiler.y"
                                                                                {(yyval.no)=createNode(NULL,NULL, 0, 0);error=true;if(debug)printf("FieldDecl3\n");}
#line 1520 "y.tab.c"
    break;

  case 10: /* recCOMMAID: COMMA ID recCOMMAID  */
#line 151 "jucompiler.y"
                                                                                {(yyval.no) = createNode(NULL,"FieldDecl", 0, 0); sprintf(aux3, "Id(%s)", (yyvsp[-1].tok).id); (yyval.no)->child = createNode((yyvsp[-1].tok).id, strdup(aux3), (yyvsp[-1].tok).line, (yyvsp[-1].tok).col); newBrother((yyval.no), (yyvsp[0].no));if(debug)printf("recCommaId2(%s)\n", aux3);}
#line 1526 "y.tab.c"
    break;

  case 11: /* recCOMMAID: %empty  */
#line 152 "jucompiler.y"
                                                                                {(yyval.no) = NULL;}
#line 1532 "y.tab.c"
    break;

  case 12: /* Type: BOOL  */
#line 155 "jucompiler.y"
                                                                                {(yyval.no) = createNode(NULL,"Bool", (yyvsp[0].tok).line, (yyvsp[0].tok).col);if(debug)printf("Bool\n");}
#line 1538 "y.tab.c"
    break;

  case 13: /* Type: INT  */
#line 156 "jucompiler.y"
                                                                                {(yyval.no) = createNode(NULL,"Int", (yyvsp[0].tok).line, (yyvsp[0].tok).col);if(debug)printf("Int\n");}
#line 1544 "y.tab.c"
    break;

  case 14: /* Type: DOUBLE  */
#line 157 "jucompiler.y"
                                                                                {(yyval.no) = createNode(NULL,"Double", (yyvsp[0].tok).line, (yyvsp[0].tok).col);if(debug)printf("Double\n");}
#line 1550 "y.tab.c"
    break;

  case 15: /* MethodHeader: Type ID LPAR FormalParams RPAR  */
#line 160 "jucompiler.y"
                                                                                {(yyval.no) = createNode(NULL,"MethodHeader", (yyvsp[-3].tok).line, (yyvsp[-3].tok).col); (yyval.no)->child = (yyvsp[-4].no); sprintf(aux3, "Id(%s)", (yyvsp[-3].tok).id); newBrother((yyvsp[-4].no), createNode((yyvsp[-3].tok).id, strdup(aux3), (yyvsp[-3].tok).line, (yyvsp[-3].tok).col)); newBrother((yyvsp[-4].no), (yyvsp[-1].no));if(debug)printf("MethodHeader\n");}
#line 1556 "y.tab.c"
    break;

  case 16: /* MethodHeader: Type ID LPAR RPAR  */
#line 161 "jucompiler.y"
                                                                                {(yyval.no) = createNode(NULL,"MethodHeader", (yyvsp[-2].tok).line, (yyvsp[-2].tok).col); (yyval.no)->child = (yyvsp[-3].no); sprintf(aux3, "Id(%s)", (yyvsp[-2].tok).id); newBrother((yyvsp[-3].no), createNode((yyvsp[-2].tok).id, strdup(aux3), (yyvsp[-2].tok).line, (yyvsp[-2].tok).col)); newBrother((yyvsp[-3].no), createNode(NULL,"MethodParams", 0, 0));if(debug)printf("MethodHeader2\n");}
#line 1562 "y.tab.c"
    break;

  case 17: /* MethodHeader: VOID ID LPAR FormalParams RPAR  */
#line 162 "jucompiler.y"
                                                                                {(yyval.no) = createNode(NULL,"MethodHeader", (yyvsp[-3].tok).line, (yyvsp[-3].tok).col); (yyval.no)->child = createNode(NULL,"Void", 0, 0); sprintf(aux3, "Id(%s)", (yyvsp[-3].tok).id); newBrother((yyval.no)->child, createNode((yyvsp[-3].tok).id, strdup(aux3), (yyvsp[-3].tok).line, (yyvsp[-3].tok).col)); newBrother((yyval.no)->child, (yyvsp[-1].no));if(debug)printf("MethodHeader3\n");}
#line 1568 "y.tab.c"
    break;

  case 18: /* MethodHeader: VOID ID LPAR RPAR  */
#line 163 "jucompiler.y"
                                                                                {(yyval.no) = createNode(NULL,"MethodHeader", (yyvsp[-2].tok).line, (yyvsp[-2].tok).col);(yyval.no)->child = createNode(NULL,"Void", 0, 0); sprintf(aux3, "Id(%s)", (yyvsp[-2].tok).id); newBrother((yyval.no)->child, createNode((yyvsp[-2].tok).id, strdup(aux3), (yyvsp[-2].tok).line, (yyvsp[-2].tok).col));newBrother((yyval.no)->child,createNode(NULL,"MethodParams", 0, 0));if(debug)printf("MethodHeader4\n");}
#line 1574 "y.tab.c"
    break;

  case 19: /* FormalParams: Type ID recFP  */
#line 166 "jucompiler.y"
                                                                                {(yyval.no) = createNode(NULL,"MethodParams", 0, 0); (yyval.no)->child = createNode(NULL,"ParamDecl", 0, 0); (yyval.no)->child->child = (yyvsp[-2].no); sprintf(aux3, "Id(%s)", (yyvsp[-1].tok).id); newBrother((yyvsp[-2].no), createNode((yyvsp[-1].tok).id, strdup(aux3), (yyvsp[-1].tok).line, (yyvsp[-1].tok).col)); newBrother((yyval.no)->child, (yyvsp[0].no));

                                                                                    if(debug)printf("FormalParams\n");
                                                                                }
#line 1583 "y.tab.c"
    break;

  case 20: /* FormalParams: STRING LSQ RSQ ID  */
#line 171 "jucompiler.y"
                                                                                {(yyval.no) = createNode(NULL,"MethodParams", 0, 0); (yyval.no)->child = createNode(NULL,"ParamDecl", 0, 0); (yyval.no)->child->child = createNode(NULL,"StringArray", 0, 0); sprintf(aux3, "Id(%s)", (yyvsp[0].tok).id); newBrother((yyval.no)->child->child, createNode((yyvsp[0].tok).id, strdup(aux3), (yyvsp[0].tok).line, (yyvsp[0].tok).col));if(debug)printf("FormalParams3\n");}
#line 1589 "y.tab.c"
    break;

  case 21: /* recFP: COMMA Type ID recFP  */
#line 174 "jucompiler.y"
                                                                                {(yyval.no) = createNode(NULL,"ParamDecl", 0, 0); newBrother((yyval.no), (yyvsp[0].no)); (yyval.no)->child = (yyvsp[-2].no); sprintf(aux3, "Id(%s)", (yyvsp[-1].tok).id); newBrother((yyvsp[-2].no), createNode((yyvsp[-1].tok).id, strdup(aux3), (yyvsp[-1].tok).line, (yyvsp[-1].tok).col));if(debug)printf("recFP\n");}
#line 1595 "y.tab.c"
    break;

  case 22: /* recFP: %empty  */
#line 175 "jucompiler.y"
                                                                                {(yyval.no) = NULL;if(debug)printf("recFP2\n");}
#line 1601 "y.tab.c"
    break;

  case 23: /* MethodBody: LBRACE recMD RBRACE  */
#line 178 "jucompiler.y"
                                                                                {(yyval.no) = createNode(NULL,"MethodBody", 0, 0); (yyval.no)->child = (yyvsp[-1].no);if(debug)printf("MethodBody\n");}
#line 1607 "y.tab.c"
    break;

  case 24: /* recMD: Statement recMD  */
#line 181 "jucompiler.y"
                                                                                {if((yyvsp[-1].no)) {(yyval.no) = (yyvsp[-1].no); newBrother((yyval.no), (yyvsp[0].no));}else{(yyval.no)=(yyvsp[0].no);}if(debug)printf("recMD3\n");}
#line 1613 "y.tab.c"
    break;

  case 25: /* recMD: VarDecl recMD  */
#line 182 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[-1].no); newBrother((yyval.no), (yyvsp[0].no));if(debug)printf("recMD4\n");}
#line 1619 "y.tab.c"
    break;

  case 26: /* recMD: %empty  */
#line 183 "jucompiler.y"
                                                                                {(yyval.no) = NULL;}
#line 1625 "y.tab.c"
    break;

  case 27: /* VarDecl: Type ID recVAR SEMICOLON  */
#line 186 "jucompiler.y"
                                                                                {(yyval.no) = createNode(NULL,"VarDecl", 0, 0); (yyval.no)->child = (yyvsp[-3].no); sprintf(aux3, "Id(%s)", (yyvsp[-2].tok).id); newBrother((yyval.no)->child, createNode((yyvsp[-2].tok).id, strdup(aux3), (yyvsp[-2].tok).line, (yyvsp[-2].tok).col)); newBrother((yyval.no), (yyvsp[-1].no));
                                                                                    struct node * auxnode = (yyvsp[-1].no), * auxnode2;
                                                                                    while(auxnode != NULL){
                                                                                        auxnode2 = auxnode->child;
                                                                                        auxnode->child = createNode(NULL,(yyvsp[-3].no)->var, 0, 0);
                                                                                        auxnode->child->brother = auxnode2;
                                                                                        auxnode = auxnode->brother;
                                                                                    }
                                                                                    if(debug)printf("VarDecl\n");
                                                                                }
#line 1640 "y.tab.c"
    break;

  case 28: /* recVAR: COMMA ID recVAR  */
#line 198 "jucompiler.y"
                                                                                {(yyval.no) = createNode(NULL,"VarDecl", 0, 0); newBrother((yyval.no), (yyvsp[0].no)); sprintf(aux3, "Id(%s)", (yyvsp[-1].tok).id); (yyval.no)->child = createNode((yyvsp[-1].tok).id, strdup(aux3), (yyvsp[-1].tok).line, (yyvsp[-1].tok).col);if(debug)printf("recVAR2\n");}
#line 1646 "y.tab.c"
    break;

  case 29: /* recVAR: %empty  */
#line 199 "jucompiler.y"
                                                                                {(yyval.no) = NULL;}
#line 1652 "y.tab.c"
    break;

  case 30: /* Statement: LBRACE recSTAT RBRACE  */
#line 202 "jucompiler.y"
                                                                                {if ((yyvsp[-1].no)!=NULL){if ((yyvsp[-1].no)->brother != NULL){(yyval.no) = createNode(NULL,"Block", 0, 0); (yyval.no)->child = (yyvsp[-1].no);} else {(yyval.no) = (yyvsp[-1].no);}} else {(yyval.no) = (yyvsp[-1].no);}; if(debug)printf("Statement\n");}
#line 1658 "y.tab.c"
    break;

  case 31: /* Statement: IF LPAR Expr RPAR Statement ELSE Statement  */
#line 203 "jucompiler.y"
                                                                                {(yyval.no) = createNode(NULL,"If", 0, 0); (yyval.no)->child = (yyvsp[-4].no);
                                                                                    if ((yyvsp[-2].no) != NULL && numBrothers((yyvsp[-2].no)) == 1) {
                                                                                        newBrother((yyvsp[-4].no), (yyvsp[-2].no));
                                                                                        if ((yyvsp[0].no) != NULL && numBrothers((yyvsp[0].no)) == 1){
                                                                                            newBrother((yyvsp[-2].no), (yyvsp[0].no));
                                                                                        } else {
                                                                                            newBrother((yyvsp[-2].no), createNode(NULL,"Block", 0, 0));
                                                                                            (yyvsp[-2].no)->brother->child = (yyvsp[0].no);
                                                                                        }
                                                                                    } else {
                                                                                        struct node * temp = createNode(NULL,"Block", 0, 0);
                                                                                        newBrother((yyvsp[-4].no), temp);
                                                                                        temp->child = (yyvsp[-2].no);
                                                                                        if((yyvsp[0].no) != NULL && numBrothers((yyvsp[0].no)) == 1){
                                                                                            newBrother(temp, (yyvsp[0].no)); 
                                                                                        }
                                                                                        else{
                                                                                            newBrother(temp, createNode(NULL,"Block", 0, 0));
                                                                                            temp->brother->child = (yyvsp[0].no);
                                                                                        }
                                                                                    }
                                                                                if(debug)printf("Statement3\n");}
#line 1685 "y.tab.c"
    break;

  case 32: /* Statement: IF LPAR Expr RPAR Statement  */
#line 225 "jucompiler.y"
                                                                                {(yyval.no) = createNode(NULL,"If", 0, 0); (yyval.no)->child = (yyvsp[-2].no);
                                                                                    if ((yyvsp[0].no)!=NULL && numBrothers((yyvsp[0].no)) == 1) {
                                                                                        newBrother((yyvsp[-2].no), (yyvsp[0].no));
                                                                                        newBrother((yyvsp[0].no), createNode(NULL,"Block", 0, 0));
                                                                                    } else {
                                                                                        struct node * temp = createNode(NULL,"Block", 0, 0);
                                                                                        newBrother((yyvsp[-2].no), temp);
                                                                                        temp->child = (yyvsp[0].no);
                                                                                        newBrother(temp, createNode(NULL,"Block", 0, 0));
                                                                                    }
                                                                                if(debug)printf("Statement4\n");}
#line 1701 "y.tab.c"
    break;

  case 33: /* Statement: WHILE LPAR Expr RPAR Statement  */
#line 236 "jucompiler.y"
                                                                                {(yyval.no) = createNode(NULL,"While", 0, 0); (yyval.no)->child = (yyvsp[-2].no); 
                                                                                    if((yyvsp[0].no) != NULL && numBrothers((yyvsp[0].no)) < 2){
                                                                                        newBrother((yyvsp[-2].no), (yyvsp[0].no));
                                                                                    } else{
                                                                                        newBrother((yyvsp[-2].no), createNode(NULL,"Block", 0, 0));
                                                                                        (yyvsp[-2].no)->brother->child = (yyvsp[0].no);
                                                                                    }
                                                                                if(debug)printf("Statement5\n");}
#line 1714 "y.tab.c"
    break;

  case 34: /* Statement: RETURN Expr SEMICOLON  */
#line 244 "jucompiler.y"
                                                                                {(yyval.no) = createNode(NULL,"Return", (yyvsp[-2].tok).line, (yyvsp[-2].tok).col); (yyval.no)->child = (yyvsp[-1].no);if(debug)printf("Statement6\n");}
#line 1720 "y.tab.c"
    break;

  case 35: /* Statement: RETURN SEMICOLON  */
#line 245 "jucompiler.y"
                                                                                {(yyval.no) = createNode(NULL,"Return", (yyvsp[-1].tok).line, (yyvsp[-1].tok).col);if(debug)printf("Statement7\n");}
#line 1726 "y.tab.c"
    break;

  case 36: /* Statement: MethodInvocation SEMICOLON  */
#line 246 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[-1].no);if(debug)printf("Statement8\n");}
#line 1732 "y.tab.c"
    break;

  case 37: /* Statement: Assignment SEMICOLON  */
#line 247 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[-1].no);if(debug)printf("Statement9\n");}
#line 1738 "y.tab.c"
    break;

  case 38: /* Statement: ParseArgs SEMICOLON  */
#line 248 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[-1].no);if(debug)printf("Statement10\n");}
#line 1744 "y.tab.c"
    break;

  case 39: /* Statement: SEMICOLON  */
#line 249 "jucompiler.y"
                                                                                {(yyval.no) = NULL;if(debug)printf("Statement11\n");}
#line 1750 "y.tab.c"
    break;

  case 40: /* Statement: PRINT LPAR Expr RPAR SEMICOLON  */
#line 250 "jucompiler.y"
                                                                                {(yyval.no) = createNode(NULL,"Print", 0, 0); (yyval.no)->child = (yyvsp[-2].no);if(debug)printf("Statement12\n");}
#line 1756 "y.tab.c"
    break;

  case 41: /* Statement: PRINT LPAR STRLIT RPAR SEMICOLON  */
#line 251 "jucompiler.y"
                                                                                {(yyval.no) = createNode(NULL,"Print", 0, 0); sprintf(aux3, "StrLit(\"%s)", (yyvsp[-2].tok).id); (yyval.no)->child = createNode((yyvsp[-2].tok).id, strdup(aux3), (yyvsp[-2].tok).line, (yyvsp[-2].tok).col);if(debug)printf("Statement13\n");}
#line 1762 "y.tab.c"
    break;

  case 42: /* Statement: error SEMICOLON  */
#line 252 "jucompiler.y"
                                                                                {(yyval.no)=createNode(NULL,NULL, 0, 0);error=true;if(debug)printf("Statement15\n");}
#line 1768 "y.tab.c"
    break;

  case 43: /* recSTAT: Statement recSTAT  */
#line 255 "jucompiler.y"
                                                                                {if((yyval.no)!=NULL){(yyval.no)=(yyvsp[-1].no); newBrother((yyval.no),(yyvsp[0].no));} else{(yyval.no)=(yyvsp[0].no);}}
#line 1774 "y.tab.c"
    break;

  case 44: /* recSTAT: %empty  */
#line 256 "jucompiler.y"
                                                                                {(yyval.no) = NULL;}
#line 1780 "y.tab.c"
    break;

  case 45: /* MethodInvocation: ID LPAR Expr recCOMMAEXP RPAR  */
#line 259 "jucompiler.y"
                                                                                {(yyval.no) = createNode(NULL,"Call", 0, 0); sprintf(aux3, "Id(%s)", (yyvsp[-4].tok).id); (yyval.no)->child = createNode((yyvsp[-4].tok).id, strdup(aux3), (yyvsp[-4].tok).line, (yyvsp[-4].tok).col); newBrother((yyval.no)->child, (yyvsp[-2].no)); newBrother((yyvsp[-2].no), (yyvsp[-1].no));if(debug)printf("MethodInvocation\n");}
#line 1786 "y.tab.c"
    break;

  case 46: /* MethodInvocation: ID LPAR RPAR  */
#line 260 "jucompiler.y"
                                                                                {(yyval.no) = createNode(NULL,"Call", 0, 0); sprintf(aux3, "Id(%s)", (yyvsp[-2].tok).id); (yyval.no)->child = createNode((yyvsp[-2].tok).id, strdup(aux3), (yyvsp[-2].tok).line, (yyvsp[-2].tok).col);if(debug)printf("MethodInvocation3\n");}
#line 1792 "y.tab.c"
    break;

  case 47: /* MethodInvocation: ID LPAR error RPAR  */
#line 261 "jucompiler.y"
                                                                                {(yyval.no)=createNode(NULL, NULL, 0, 0);error=true;if(debug)printf("MethodInvocation4\n");}
#line 1798 "y.tab.c"
    break;

  case 48: /* recCOMMAEXP: COMMA Expr recCOMMAEXP  */
#line 264 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[-1].no); newBrother((yyvsp[-1].no), (yyvsp[0].no));if(debug)printf("recCOMMAEXP\n");}
#line 1804 "y.tab.c"
    break;

  case 49: /* recCOMMAEXP: %empty  */
#line 265 "jucompiler.y"
                                                                                {(yyval.no) = NULL;}
#line 1810 "y.tab.c"
    break;

  case 50: /* Assignment: ID ASSIGN Expr  */
#line 268 "jucompiler.y"
                                                                                {(yyval.no) = createNode(NULL,"Assign", (yyvsp[-1].tok).line, (yyvsp[-1].tok).col); sprintf(aux3, "Id(%s)", (yyvsp[-2].tok).id); (yyval.no)->child = createNode((yyvsp[-2].tok).id, strdup(aux3), (yyvsp[-2].tok).line, (yyvsp[-2].tok).col); newBrother((yyval.no)->child, (yyvsp[0].no));if(debug)printf("Assign\n");}
#line 1816 "y.tab.c"
    break;

  case 51: /* ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR  */
#line 271 "jucompiler.y"
                                                                                {(yyval.no) = createNode(NULL,"ParseArgs", 0, 0); sprintf(aux3, "Id(%s)", (yyvsp[-4].tok).id); (yyval.no)->child = createNode((yyvsp[-4].tok).id, strdup(aux3), (yyvsp[-4].tok).line, (yyvsp[-4].tok).col); newBrother((yyval.no)->child, (yyvsp[-2].no));if(debug)printf("ParseArgs + id(%s)\n",aux3);}
#line 1822 "y.tab.c"
    break;

  case 52: /* ParseArgs: PARSEINT LPAR error RPAR  */
#line 272 "jucompiler.y"
                                                                                {(yyval.no) = NULL;(yyval.no)=createNode(NULL,NULL, 0, 0);error=true;if(debug)printf("ParseArgs2\n");}
#line 1828 "y.tab.c"
    break;

  case 53: /* Expr2: Expr2 PLUS Expr2  */
#line 275 "jucompiler.y"
                                                                                  {(yyval.no) = createNode(NULL,"Add", (yyvsp[-1].tok).line, (yyvsp[-1].tok).col); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("PLUS\n");}
#line 1834 "y.tab.c"
    break;

  case 54: /* Expr2: Expr2 MINUS Expr2  */
#line 276 "jucompiler.y"
                                                                                  {(yyval.no) = createNode(NULL,"Sub", (yyvsp[-1].tok).line, (yyvsp[-1].tok).col); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("MINUS\n");}
#line 1840 "y.tab.c"
    break;

  case 55: /* Expr2: Expr2 STAR Expr2  */
#line 277 "jucompiler.y"
                                                                                  {(yyval.no) = createNode(NULL,"Mul", (yyvsp[-1].tok).line, (yyvsp[-1].tok).col); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("STAR\n");}
#line 1846 "y.tab.c"
    break;

  case 56: /* Expr2: Expr2 DIV Expr2  */
#line 278 "jucompiler.y"
                                                                                  {(yyval.no) = createNode(NULL,"Div", (yyvsp[-1].tok).line, (yyvsp[-1].tok).col); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("DIV\n");}
#line 1852 "y.tab.c"
    break;

  case 57: /* Expr2: Expr2 MOD Expr2  */
#line 279 "jucompiler.y"
                                                                                  {(yyval.no) = createNode(NULL,"Mod", (yyvsp[-1].tok).line, (yyvsp[-1].tok).col); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("MOD\n");}
#line 1858 "y.tab.c"
    break;

  case 58: /* Expr2: Expr2 AND Expr2  */
#line 280 "jucompiler.y"
                                                                                  {(yyval.no) = createNode(NULL,"And", (yyvsp[-1].tok).line, (yyvsp[-1].tok).col); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("AND\n");}
#line 1864 "y.tab.c"
    break;

  case 59: /* Expr2: Expr2 OR Expr2  */
#line 281 "jucompiler.y"
                                                                                  {(yyval.no) = createNode(NULL,"Or", (yyvsp[-1].tok).line, (yyvsp[-1].tok).col); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("OR\n");}
#line 1870 "y.tab.c"
    break;

  case 60: /* Expr2: Expr2 XOR Expr2  */
#line 282 "jucompiler.y"
                                                                                  {(yyval.no) = createNode(NULL,"Xor", (yyvsp[-1].tok).line, (yyvsp[-1].tok).col); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("XOR\n");}
#line 1876 "y.tab.c"
    break;

  case 61: /* Expr2: Expr2 LSHIFT Expr2  */
#line 283 "jucompiler.y"
                                                                                  {(yyval.no) = createNode(NULL,"Lshift", (yyvsp[-1].tok).line, (yyvsp[-1].tok).col); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("LSHIFT\n");}
#line 1882 "y.tab.c"
    break;

  case 62: /* Expr2: Expr2 RSHIFT Expr2  */
#line 284 "jucompiler.y"
                                                                                  {(yyval.no) = createNode(NULL,"Rshift", (yyvsp[-1].tok).line, (yyvsp[-1].tok).col); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("RSHIFT\n");}
#line 1888 "y.tab.c"
    break;

  case 63: /* Expr2: Expr2 EQ Expr2  */
#line 285 "jucompiler.y"
                                                                                  {(yyval.no) = createNode(NULL,"Eq", (yyvsp[-1].tok).line, (yyvsp[-1].tok).col); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("EQ\n");}
#line 1894 "y.tab.c"
    break;

  case 64: /* Expr2: Expr2 GE Expr2  */
#line 286 "jucompiler.y"
                                                                                  {(yyval.no) = createNode(NULL,"Ge", (yyvsp[-1].tok).line, (yyvsp[-1].tok).col); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("GE\n");}
#line 1900 "y.tab.c"
    break;

  case 65: /* Expr2: Expr2 GT Expr2  */
#line 287 "jucompiler.y"
                                                                                  {(yyval.no) = createNode(NULL,"Gt", (yyvsp[-1].tok).line, (yyvsp[-1].tok).col); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("GT\n");}
#line 1906 "y.tab.c"
    break;

  case 66: /* Expr2: Expr2 LE Expr2  */
#line 288 "jucompiler.y"
                                                                                  {(yyval.no) = createNode(NULL,"Le", (yyvsp[-1].tok).line, (yyvsp[-1].tok).col); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("LE\n");}
#line 1912 "y.tab.c"
    break;

  case 67: /* Expr2: Expr2 LT Expr2  */
#line 289 "jucompiler.y"
                                                                                  {(yyval.no) = createNode(NULL,"Lt", (yyvsp[-1].tok).line, (yyvsp[-1].tok).col); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("LT\n");}
#line 1918 "y.tab.c"
    break;

  case 68: /* Expr2: Expr2 NE Expr2  */
#line 290 "jucompiler.y"
                                                                                  {(yyval.no) = createNode(NULL,"Ne", (yyvsp[-1].tok).line, (yyvsp[-1].tok).col); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("NE\n");}
#line 1924 "y.tab.c"
    break;

  case 69: /* Expr2: MINUS Expr2  */
#line 291 "jucompiler.y"
                                                                                 {(yyval.no) = createNode(NULL,"Minus", (yyvsp[-1].tok).line, (yyvsp[-1].tok).col); (yyval.no)->child=(yyvsp[0].no);if(debug)printf("MINUS2\n");}
#line 1930 "y.tab.c"
    break;

  case 70: /* Expr2: PLUS Expr2  */
#line 292 "jucompiler.y"
                                                                                 {(yyval.no) = createNode(NULL,"Plus", (yyvsp[-1].tok).line, (yyvsp[-1].tok).col); (yyval.no)->child=(yyvsp[0].no);if(debug)printf("PLUS2\n");}
#line 1936 "y.tab.c"
    break;

  case 71: /* Expr2: NOT Expr2  */
#line 293 "jucompiler.y"
                                                                                 {(yyval.no) = createNode(NULL,"Not", (yyvsp[-1].tok).line, (yyvsp[-1].tok).col); (yyval.no)->child=(yyvsp[0].no);if(debug)printf("NOT\n");}
#line 1942 "y.tab.c"
    break;

  case 72: /* Expr2: LPAR Expr RPAR  */
#line 294 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[-1].no);if(debug)printf("EXPR\n");}
#line 1948 "y.tab.c"
    break;

  case 73: /* Expr2: MethodInvocation  */
#line 295 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[0].no);if(debug)printf("MI\n");}
#line 1954 "y.tab.c"
    break;

  case 74: /* Expr2: ParseArgs  */
#line 296 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[0].no);if(debug)printf("PA\n");}
#line 1960 "y.tab.c"
    break;

  case 75: /* Expr2: ID  */
#line 297 "jucompiler.y"
                                                                                {sprintf(aux3, "Id(%s)", (yyvsp[0].tok).id); (yyval.no) = createNode((yyvsp[0].tok).id, strdup(aux3), (yyvsp[0].tok).line, (yyvsp[0].tok).col);if(debug)printf("%s_ID111\n", aux3);}
#line 1966 "y.tab.c"
    break;

  case 76: /* Expr2: ID DOTLENGTH  */
#line 298 "jucompiler.y"
                                                                                {(yyval.no) = createNode(NULL, "Length", 0, 0); sprintf(aux3, "Id(%s)", (yyvsp[-1].tok).id); (yyval.no)->child = createNode((yyvsp[-1].tok).id, strdup(aux3), (yyvsp[-1].tok).line, (yyvsp[-1].tok).col);if(debug)printf("DOT\n");}
#line 1972 "y.tab.c"
    break;

  case 77: /* Expr2: INTLIT  */
#line 299 "jucompiler.y"
                                                                                {sprintf(aux3, "DecLit(%s)", (yyvsp[0].tok).id); (yyval.no) = createNode((yyvsp[0].tok).id, strdup(aux3), (yyvsp[0].tok).line, (yyvsp[0].tok).col);if(debug)printf("DEC2\n");}
#line 1978 "y.tab.c"
    break;

  case 78: /* Expr2: REALLIT  */
#line 300 "jucompiler.y"
                                                                                {sprintf(aux3, "RealLit(%s)", (yyvsp[0].tok).id); (yyval.no) = createNode((yyvsp[0].tok).id, strdup(aux3), (yyvsp[0].tok).line, (yyvsp[0].tok).col);if(debug)printf("REAL2\n");}
#line 1984 "y.tab.c"
    break;

  case 79: /* Expr2: BOOLLIT  */
#line 301 "jucompiler.y"
                                                                                {sprintf(aux3, "BoolLit(%s)", (yyvsp[0].tok).id); (yyval.no) = createNode((yyvsp[0].tok).id, strdup(aux3), (yyvsp[0].tok).line, (yyvsp[0].tok).col);if(debug)printf("BOOL2\n");}
#line 1990 "y.tab.c"
    break;

  case 80: /* Expr2: LPAR error RPAR  */
#line 302 "jucompiler.y"
                                                                                {(yyval.no)=createNode(NULL,NULL, 0, 0);error=true;if(debug)printf("666\n");}
#line 1996 "y.tab.c"
    break;

  case 81: /* Expr: Assignment  */
#line 305 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[0].no);}
#line 2002 "y.tab.c"
    break;

  case 82: /* Expr: Expr2  */
#line 306 "jucompiler.y"
                                                                                 {(yyval.no) = (yyvsp[0].no);}
#line 2008 "y.tab.c"
    break;


#line 2012 "y.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 309 "jucompiler.y"
