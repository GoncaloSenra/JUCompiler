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
    #include "STree.h"
    int yylex(void);
    

    char aux3[1024]; 
    char aux4[1024]; 

    int error;
    struct node * prog;
    int debug = false;

    void yyerror (const char *s);

#line 91 "y.tab.c"

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
#line 22 "jucompiler.y"

    char* id;
    struct node * no;

#line 249 "y.tab.c"

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
  YYSYMBOL_recSEMICOLON = 66,              /* recSEMICOLON  */
  YYSYMBOL_recSTAT = 67,                   /* recSTAT  */
  YYSYMBOL_MethodInvocation = 68,          /* MethodInvocation  */
  YYSYMBOL_recCOMMAEXP = 69,               /* recCOMMAEXP  */
  YYSYMBOL_Assignment = 70,                /* Assignment  */
  YYSYMBOL_ParseArgs = 71,                 /* ParseArgs  */
  YYSYMBOL_Expr = 72,                      /* Expr  */
  YYSYMBOL_Expr2 = 73                      /* Expr2  */
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
#define YYLAST   412

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  51
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  23
/* YYNRULES -- Number of rules.  */
#define YYNRULES  84
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

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
       0,   120,   120,   123,   124,   125,   126,   129,   132,   142,
     145,   146,   149,   150,   151,   154,   155,   156,   157,   160,
     165,   168,   169,   172,   175,   176,   177,   180,   192,   193,
     196,   197,   219,   230,   238,   239,   240,   241,   242,   243,
     244,   245,   248,   249,   250,   253,   254,   257,   258,   259,
     262,   263,   266,   269,   270,   273,   274,   277,   278,   279,
     280,   281,   282,   283,   284,   285,   286,   287,   288,   289,
     290,   291,   292,   293,   294,   295,   296,   297,   298,   299,
     300,   301,   302,   303,   304
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
  "Statement", "recSEMICOLON", "recSTAT", "MethodInvocation",
  "recCOMMAEXP", "Assignment", "ParseArgs", "Expr", "Expr2", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-58)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-47)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -25,     0,     6,    10,   -58,    42,     1,    42,   -16,    14,
      42,    42,   -58,   -58,   186,   -58,   -58,   -58,   -58,   -58,
     -58,    45,    47,    54,    62,    33,    89,   -58,    59,    80,
     142,    58,    61,    28,   139,   -58,    77,    94,    99,   237,
     102,    95,    96,    89,    89,    91,   -58,   -58,   -58,   -58,
     103,   125,   108,   128,   -58,   115,   -58,   -58,   244,   202,
     139,   117,   244,   211,    44,    -2,   -58,   -58,   -58,    75,
     253,   253,   253,   -58,   -58,   -58,   -58,   116,   278,   244,
     134,   -58,   -58,   -58,   -58,   118,   138,   -58,   -58,   -58,
     -58,   126,   -58,   146,   -58,   -58,   131,   132,   135,   133,
     136,   149,   -58,   144,   147,   -13,   -58,   -58,   -58,   -58,
     253,   253,   253,   253,   253,   253,   253,   253,   253,   253,
     253,   253,   253,   253,   253,   253,   148,   175,   156,   184,
      36,   -58,   -58,   244,   162,   155,   161,   -58,   163,   -58,
     244,   -58,   -58,   330,   -58,   -58,   379,   141,   141,   141,
     141,    30,   -58,   379,   305,    30,    63,    63,   355,   155,
     134,   -58,   -58,   189,   146,   -58,   157,   -58,   -58,   165,
     -58,   -58,   138,   -58,   155,   171,   -58,   -58,   -58
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     0,     0,     0,
       0,     0,     9,     5,     0,     2,     3,     4,    12,    14,
      13,     0,     0,     0,     0,    11,     0,     7,     0,     0,
       0,     0,     0,     0,     0,    37,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    44,    43,    42,    18,
       0,     0,     0,    11,    16,     0,     8,    41,     0,     0,
       0,     0,     0,     0,     0,    79,    81,    82,    83,     0,
       0,     0,     0,    35,    77,    55,    78,     0,    56,     0,
      29,    23,    25,    24,    36,     0,    22,    17,    10,    15,
      52,     0,    48,    51,    45,    30,     0,     0,     0,     0,
       0,     0,    80,     0,     0,    79,    73,    75,    74,    34,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,    49,     0,     0,     0,     0,    40,     0,    54,
       0,    84,    76,    62,    59,    60,    67,    68,    69,    70,
      71,    58,    61,    72,    63,    57,    65,    66,    64,     0,
      29,    27,    20,     0,    51,    47,    32,    39,    38,     0,
      33,    28,    22,    50,     0,     0,    21,    31,    53
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -58,   -58,    97,   -58,   -58,   154,    -5,   -58,   172,    29,
     -58,    71,   -58,    50,   -33,   -58,   151,   -26,    48,   -24,
     -22,   -30,   -57
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,     9,    10,    11,    31,    41,    23,    52,   131,
      27,    42,    43,   128,    44,    45,    61,    74,   134,    75,
      76,    77,    78
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      46,    60,    47,     3,    48,    59,     4,    58,    46,    22,
      47,     1,    48,   106,   107,   108,    59,    46,    46,    47,
      47,    48,    48,    51,   102,    51,     5,    60,    90,    93,
      14,    12,    96,    99,    46,   102,    47,    58,    48,   104,
     111,    15,   112,     6,    29,   100,    59,   101,    24,   126,
      25,    30,   119,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,    -6,
      26,    18,     7,   111,    19,   112,   103,    20,    65,    66,
      28,    67,    68,    53,   118,   119,     8,    49,    56,   122,
      32,    57,    33,    69,    18,    62,    70,    19,    80,    71,
      20,    72,   166,   164,    13,    34,    50,    16,    17,    46,
     169,    47,    63,    48,    82,    83,   -26,    64,    38,    35,
      79,    84,    85,    81,    18,   163,   170,    19,    86,    36,
      20,    37,    38,    46,    39,    47,    87,    48,    40,    29,
      32,   177,    33,    89,    95,   127,   109,   129,    46,   130,
      47,   111,    48,   112,   132,    34,    32,   133,    33,   135,
     136,   138,   118,   119,   139,   137,   -46,   122,   140,    35,
      54,    34,   141,   123,   124,   142,   159,    18,   160,    36,
      19,    37,    38,    20,    39,    35,   161,   162,    40,    50,
     165,   167,   172,   168,   175,    36,   174,    37,    38,   178,
      39,   176,    55,    91,    40,    65,    66,    88,    67,    68,
     171,    94,   173,     0,    65,    66,    97,    67,    68,     0,
      69,    18,     0,    70,    19,     0,    71,    20,    72,    69,
      92,     0,    70,     0,    21,    71,     0,    72,     0,    98,
      65,    66,     0,    67,    68,    38,     0,    65,    66,     0,
      67,    68,     0,     0,    38,    69,   105,    66,    70,    67,
      68,    71,    69,    72,     0,    70,     0,    73,    71,     0,
      72,    69,     0,     0,    70,     0,     0,    71,     0,    72,
      38,     0,     0,     0,     0,     0,   110,    38,   111,     0,
     112,   113,   114,   115,     0,   116,    38,     0,   117,   118,
     119,   120,     0,   121,   122,     0,     0,     0,     0,     0,
     123,   124,   125,   110,     0,   111,     0,   112,   113,   114,
     115,     0,   116,     0,     0,   117,   118,   119,   120,     0,
       0,   122,     0,     0,     0,     0,     0,   123,   124,   125,
     111,     0,   112,   113,   114,   115,     0,   116,     0,     0,
     117,   118,   119,   120,     0,     0,   122,     0,     0,     0,
       0,     0,   123,   124,   125,   111,     0,   112,   113,   114,
     115,     0,   116,     0,     0,   117,   118,   119,   120,     0,
       0,   122,     0,     0,     0,     0,     0,   123,   124,   111,
       0,   112,     0,   114,   115,     0,   116,     0,     0,   117,
     118,   119,     0,     0,     0,   122,     0,     0,     0,     0,
       0,   123,   124
};

static const yytype_int16 yycheck[] =
{
      26,    34,    26,     3,    26,    18,     0,     9,    34,    14,
      34,    36,    34,    70,    71,    72,    18,    43,    44,    43,
      44,    43,    44,    28,    37,    30,    16,    60,    58,    59,
      46,    30,    62,    63,    60,    37,    60,     9,    60,    69,
      10,    27,    12,     1,    11,     1,    18,     3,     3,    79,
       3,    18,    22,   110,   111,   112,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,    27,
      16,    35,    30,    10,    38,    12,     1,    41,     3,     4,
      18,     6,     7,     3,    21,    22,    44,    28,    30,    26,
       1,    30,     3,    18,    35,    18,    21,    38,     3,    24,
      41,    26,   135,   133,     7,    16,    47,    10,    11,   135,
     140,   135,    18,   135,    43,    44,    27,    18,    43,    30,
      18,    30,    19,    27,    35,   130,   159,    38,     3,    40,
      41,    42,    43,   159,    45,   159,    28,   159,    49,    11,
       1,   174,     3,    28,    27,    11,    30,    29,   174,    11,
     174,    10,   174,    12,    28,    16,     1,    11,     3,    28,
      28,    28,    21,    22,    28,    30,    27,    26,    19,    30,
      28,    16,    28,    32,    33,    28,    28,    35,     3,    40,
      38,    42,    43,    41,    45,    30,    30,     3,    49,    47,
      28,    30,     3,    30,    29,    40,    39,    42,    43,    28,
      45,   172,    30,     1,    49,     3,     4,    53,     6,     7,
     160,    60,   164,    -1,     3,     4,     5,     6,     7,    -1,
      18,    35,    -1,    21,    38,    -1,    24,    41,    26,    18,
      28,    -1,    21,    -1,    48,    24,    -1,    26,    -1,    28,
       3,     4,    -1,     6,     7,    43,    -1,     3,     4,    -1,
       6,     7,    -1,    -1,    43,    18,     3,     4,    21,     6,
       7,    24,    18,    26,    -1,    21,    -1,    30,    24,    -1,
      26,    18,    -1,    -1,    21,    -1,    -1,    24,    -1,    26,
      43,    -1,    -1,    -1,    -1,    -1,     8,    43,    10,    -1,
      12,    13,    14,    15,    -1,    17,    43,    -1,    20,    21,
      22,    23,    -1,    25,    26,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,     8,    -1,    10,    -1,    12,    13,    14,
      15,    -1,    17,    -1,    -1,    20,    21,    22,    23,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    32,    33,    34,
      10,    -1,    12,    13,    14,    15,    -1,    17,    -1,    -1,
      20,    21,    22,    23,    -1,    -1,    26,    -1,    -1,    -1,
      -1,    -1,    32,    33,    34,    10,    -1,    12,    13,    14,
      15,    -1,    17,    -1,    -1,    20,    21,    22,    23,    -1,
      -1,    26,    -1,    -1,    -1,    -1,    -1,    32,    33,    10,
      -1,    12,    -1,    14,    15,    -1,    17,    -1,    -1,    20,
      21,    22,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,
      -1,    32,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,    52,     3,     0,    16,     1,    30,    44,    53,
      54,    55,    30,    53,    46,    27,    53,    53,    35,    38,
      41,    48,    57,    58,     3,     3,    16,    61,    18,    11,
      18,    56,     1,     3,    16,    30,    40,    42,    43,    45,
      49,    57,    62,    63,    65,    66,    68,    70,    71,    28,
      47,    57,    59,     3,    28,    59,    30,    30,     9,    18,
      65,    67,    18,    18,    18,     3,     4,     6,     7,    18,
      21,    24,    26,    30,    68,    70,    71,    72,    73,    18,
       3,    27,    62,    62,    30,    19,     3,    28,    56,    28,
      72,     1,    28,    72,    67,    27,    72,     5,    28,    72,
       1,     3,    37,     1,    72,     3,    73,    73,    73,    30,
       8,    10,    12,    13,    14,    15,    17,    20,    21,    22,
      23,    25,    26,    32,    33,    34,    72,    11,    64,    29,
      11,    60,    28,    11,    69,    28,    28,    30,    28,    28,
      19,    28,    28,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    28,
       3,    30,     3,    57,    72,    28,    65,    30,    30,    72,
      65,    64,     3,    69,    39,    29,    60,    65,    28
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    51,    52,    53,    53,    53,    53,    54,    55,    55,
      56,    56,    57,    57,    57,    58,    58,    58,    58,    59,
      59,    60,    60,    61,    62,    62,    62,    63,    64,    64,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    66,    66,    66,    67,    67,    68,    68,    68,
      69,    69,    70,    71,    71,    72,    72,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    73,    73,    73
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     2,     2,     2,     0,     4,     6,     2,
       3,     0,     1,     1,     1,     5,     4,     5,     4,     3,
       4,     4,     0,     3,     2,     2,     0,     4,     3,     0,
       3,     7,     5,     5,     3,     2,     2,     1,     5,     5,
       4,     2,     1,     1,     1,     2,     0,     5,     3,     4,
       3,     0,     3,     7,     4,     1,     1,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     2,     2,     2,     3,     1,     1,     1,
       2,     1,     1,     1,     3
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
#line 120 "jucompiler.y"
                                                                                {(yyval.no) = prog = createNode("Program"); sprintf(aux3, "Id(%s)", (yyvsp[-3].id)); (yyval.no)->child = createNode(strdup(aux3)); newBrother((yyval.no)->child, (yyvsp[-1].no)); if(debug)printf("Program\n");}
#line 1462 "y.tab.c"
    break;

  case 3: /* recPR: MethodDecl recPR  */
#line 123 "jucompiler.y"
                                                                               {(yyval.no) = (yyvsp[-1].no); newBrother((yyval.no), (yyvsp[0].no));if(debug)printf("recPR4\n");}
#line 1468 "y.tab.c"
    break;

  case 4: /* recPR: FieldDecl recPR  */
#line 124 "jucompiler.y"
                                                                               {(yyval.no) = (yyvsp[-1].no); newBrother((yyval.no), (yyvsp[0].no));if(debug)printf("recPR5\n");}
#line 1474 "y.tab.c"
    break;

  case 5: /* recPR: SEMICOLON recPR  */
#line 125 "jucompiler.y"
                                                                               {(yyval.no) = (yyvsp[0].no);if(debug)printf("recPR6\n");}
#line 1480 "y.tab.c"
    break;

  case 6: /* recPR: %empty  */
#line 126 "jucompiler.y"
                                                                               {(yyval.no) = NULL;}
#line 1486 "y.tab.c"
    break;

  case 7: /* MethodDecl: PUBLIC STATIC MethodHeader MethodBody  */
#line 129 "jucompiler.y"
                                                                                {(yyval.no) = createNode("MethodDecl"); (yyval.no)->child = (yyvsp[-1].no); newBrother((yyvsp[-1].no), (yyvsp[0].no));if(debug)printf("MethodDecl\n");}
#line 1492 "y.tab.c"
    break;

  case 8: /* FieldDecl: PUBLIC STATIC Type ID recCOMMAID SEMICOLON  */
#line 132 "jucompiler.y"
                                                                                {(yyval.no) = createNode("FieldDecl"); (yyval.no)->child = (yyvsp[-3].no); sprintf(aux3, "Id(%s)", (yyvsp[-2].id)); newBrother((yyvsp[-3].no), createNode(strdup(aux3))); newBrother((yyval.no), (yyvsp[-1].no));
                                                                                    struct node * auxnode = (yyvsp[-1].no), * auxnode2;
                                                                                    while(auxnode != NULL){
                                                                                        auxnode2 = auxnode->child;
                                                                                        auxnode->child = createNode((yyvsp[-3].no)->var);
                                                                                        auxnode->child->brother = auxnode2;
                                                                                        auxnode = auxnode->brother;
                                                                                    }
                                                                                    if(debug)printf("FieldDecl\n");
                                                                                }
#line 1507 "y.tab.c"
    break;

  case 9: /* FieldDecl: error SEMICOLON  */
#line 142 "jucompiler.y"
                                                                                {(yyval.no)=createNode(NULL);error=true;if(debug)printf("FieldDecl3\n");}
#line 1513 "y.tab.c"
    break;

  case 10: /* recCOMMAID: COMMA ID recCOMMAID  */
#line 145 "jucompiler.y"
                                                                                {(yyval.no) = createNode("FieldDecl"); sprintf(aux3, "Id(%s)", (yyvsp[-1].id)); (yyval.no)->child = createNode(strdup(aux3)); newBrother((yyval.no), (yyvsp[0].no));if(debug)printf("recCommaId2(%s)\n", aux3);}
#line 1519 "y.tab.c"
    break;

  case 11: /* recCOMMAID: %empty  */
#line 146 "jucompiler.y"
                                                                                {(yyval.no) = NULL;}
#line 1525 "y.tab.c"
    break;

  case 12: /* Type: BOOL  */
#line 149 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Bool");if(debug)printf("Bool\n");}
#line 1531 "y.tab.c"
    break;

  case 13: /* Type: INT  */
#line 150 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Int");if(debug)printf("Int\n");}
#line 1537 "y.tab.c"
    break;

  case 14: /* Type: DOUBLE  */
#line 151 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Double");if(debug)printf("Double\n");}
#line 1543 "y.tab.c"
    break;

  case 15: /* MethodHeader: Type ID LPAR FormalParams RPAR  */
#line 154 "jucompiler.y"
                                                                                {(yyval.no) = createNode("MethodHeader"); (yyval.no)->child = (yyvsp[-4].no); sprintf(aux3, "Id(%s)", (yyvsp[-3].id)); newBrother((yyvsp[-4].no), createNode(strdup(aux3))); newBrother((yyvsp[-4].no), (yyvsp[-1].no));if(debug)printf("MethodHeader\n");}
#line 1549 "y.tab.c"
    break;

  case 16: /* MethodHeader: Type ID LPAR RPAR  */
#line 155 "jucompiler.y"
                                                                                {(yyval.no) = createNode("MethodHeader"); (yyval.no)->child = (yyvsp[-3].no); sprintf(aux3, "Id(%s)", (yyvsp[-2].id)); newBrother((yyvsp[-3].no), createNode(strdup(aux3))); newBrother((yyvsp[-3].no), createNode("MethodParams"));if(debug)printf("MethodHeader2\n");}
#line 1555 "y.tab.c"
    break;

  case 17: /* MethodHeader: VOID ID LPAR FormalParams RPAR  */
#line 156 "jucompiler.y"
                                                                                {(yyval.no) = createNode("MethodHeader"); (yyval.no)->child = createNode("Void"); sprintf(aux3, "Id(%s)", (yyvsp[-3].id)); newBrother((yyval.no)->child, createNode(strdup(aux3))); newBrother((yyval.no)->child, (yyvsp[-1].no));if(debug)printf("MethodHeader3\n");}
#line 1561 "y.tab.c"
    break;

  case 18: /* MethodHeader: VOID ID LPAR RPAR  */
#line 157 "jucompiler.y"
                                                                                {(yyval.no) = createNode("MethodHeader");(yyval.no)->child = createNode("Void"); sprintf(aux3, "Id(%s)", (yyvsp[-2].id)); newBrother((yyval.no)->child, createNode(strdup(aux3)));newBrother((yyval.no)->child,createNode("MethodParams"));if(debug)printf("MethodHeader4\n");}
#line 1567 "y.tab.c"
    break;

  case 19: /* FormalParams: Type ID recFP  */
#line 160 "jucompiler.y"
                                                                                {(yyval.no) = createNode("MethodParams"); (yyval.no)->child = createNode("ParamDecl"); (yyval.no)->child->child = (yyvsp[-2].no); sprintf(aux3, "Id(%s)", (yyvsp[-1].id)); newBrother((yyvsp[-2].no), createNode(strdup(aux3))); newBrother((yyval.no)->child, (yyvsp[0].no));

                                                                                    if(debug)printf("FormalParams\n");
                                                                                }
#line 1576 "y.tab.c"
    break;

  case 20: /* FormalParams: STRING LSQ RSQ ID  */
#line 165 "jucompiler.y"
                                                                                {(yyval.no) = createNode("MethodParams"); (yyval.no)->child = createNode("ParamDecl"); (yyval.no)->child->child = createNode("StringArray"); sprintf(aux3, "Id(%s)", (yyvsp[0].id)); newBrother((yyval.no)->child->child, createNode(strdup(aux3)));if(debug)printf("FormalParams3\n");}
#line 1582 "y.tab.c"
    break;

  case 21: /* recFP: COMMA Type ID recFP  */
#line 168 "jucompiler.y"
                                                                                {(yyval.no) = createNode("ParamDecl"); newBrother((yyval.no), (yyvsp[0].no)); (yyval.no)->child = (yyvsp[-2].no); sprintf(aux3, "Id(%s)", (yyvsp[-1].id)); newBrother((yyvsp[-2].no), createNode(strdup(aux3)));if(debug)printf("recFP\n");}
#line 1588 "y.tab.c"
    break;

  case 22: /* recFP: %empty  */
#line 169 "jucompiler.y"
                                                                                {(yyval.no) = NULL;if(debug)printf("recFP2\n");}
#line 1594 "y.tab.c"
    break;

  case 23: /* MethodBody: LBRACE recMD RBRACE  */
#line 172 "jucompiler.y"
                                                                                {(yyval.no) = createNode("MethodBody"); (yyval.no)->child = (yyvsp[-1].no);if(debug)printf("MethodBody\n");}
#line 1600 "y.tab.c"
    break;

  case 24: /* recMD: Statement recMD  */
#line 175 "jucompiler.y"
                                                                                {if((yyvsp[-1].no)) {(yyval.no) = (yyvsp[-1].no); newBrother((yyval.no), (yyvsp[0].no));}else{(yyval.no)=(yyvsp[0].no);}if(debug)printf("recMD3\n");}
#line 1606 "y.tab.c"
    break;

  case 25: /* recMD: VarDecl recMD  */
#line 176 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[-1].no); newBrother((yyval.no), (yyvsp[0].no));if(debug)printf("recMD4\n");}
#line 1612 "y.tab.c"
    break;

  case 26: /* recMD: %empty  */
#line 177 "jucompiler.y"
                                                                                {(yyval.no) = NULL;}
#line 1618 "y.tab.c"
    break;

  case 27: /* VarDecl: Type ID recVAR SEMICOLON  */
#line 180 "jucompiler.y"
                                                                                {(yyval.no) = createNode("VarDecl"); (yyval.no)->child = (yyvsp[-3].no); sprintf(aux3, "Id(%s)", (yyvsp[-2].id)); newBrother((yyval.no)->child, createNode(strdup(aux3))); newBrother((yyval.no), (yyvsp[-1].no));
                                                                                    struct node * auxnode = (yyvsp[-1].no), * auxnode2;
                                                                                    while(auxnode != NULL){
                                                                                        auxnode2 = auxnode->child;
                                                                                        auxnode->child = createNode((yyvsp[-3].no)->var);
                                                                                        auxnode->child->brother = auxnode2;
                                                                                        auxnode = auxnode->brother;
                                                                                    }
                                                                                    if(debug)printf("VarDecl\n");
                                                                                }
#line 1633 "y.tab.c"
    break;

  case 28: /* recVAR: COMMA ID recVAR  */
#line 192 "jucompiler.y"
                                                                                {(yyval.no) = createNode("VarDecl"); newBrother((yyval.no), (yyvsp[0].no)); sprintf(aux3, "Id(%s)", (yyvsp[-1].id)); (yyval.no)->child = createNode(strdup(aux3));if(debug)printf("recVAR2\n");}
#line 1639 "y.tab.c"
    break;

  case 29: /* recVAR: %empty  */
#line 193 "jucompiler.y"
                                                                                {(yyval.no) = NULL;}
#line 1645 "y.tab.c"
    break;

  case 30: /* Statement: LBRACE recSTAT RBRACE  */
#line 196 "jucompiler.y"
                                                                                {if ((yyvsp[-1].no)!=NULL){if ((yyvsp[-1].no)->brother != NULL){(yyval.no) = createNode("Block"); (yyval.no)->child = (yyvsp[-1].no);} else {(yyval.no) = (yyvsp[-1].no);}} else {(yyval.no) = (yyvsp[-1].no);}; if(debug)printf("Statement\n");}
#line 1651 "y.tab.c"
    break;

  case 31: /* Statement: IF LPAR Expr RPAR Statement ELSE Statement  */
#line 197 "jucompiler.y"
                                                                                {(yyval.no) = createNode("If"); (yyval.no)->child = (yyvsp[-4].no);
                                                                                    if ((yyvsp[-2].no) != NULL && numBrothers((yyvsp[-2].no)) == 1) {
                                                                                        newBrother((yyvsp[-4].no), (yyvsp[-2].no));
                                                                                        if ((yyvsp[0].no) != NULL && numBrothers((yyvsp[0].no)) == 1){
                                                                                            newBrother((yyvsp[-2].no), (yyvsp[0].no));
                                                                                        } else {
                                                                                            newBrother((yyvsp[-2].no), createNode("Block"));
                                                                                            (yyvsp[-2].no)->brother->child = (yyvsp[0].no);
                                                                                        }
                                                                                    } else {
                                                                                        struct node * temp = createNode("Block");
                                                                                        newBrother((yyvsp[-4].no), temp);
                                                                                        temp->child = (yyvsp[-2].no);
                                                                                        if((yyvsp[0].no) != NULL && numBrothers((yyvsp[0].no)) == 1){
                                                                                            newBrother(temp, (yyvsp[0].no)); 
                                                                                        }
                                                                                        else{
                                                                                            newBrother(temp, createNode("Block"));
                                                                                            temp->brother->child = (yyvsp[0].no);
                                                                                        }
                                                                                    }
                                                                                if(debug)printf("Statement3\n");}
#line 1678 "y.tab.c"
    break;

  case 32: /* Statement: IF LPAR Expr RPAR Statement  */
#line 219 "jucompiler.y"
                                                                                {(yyval.no) = createNode("If"); (yyval.no)->child = (yyvsp[-2].no);
                                                                                    if ((yyvsp[0].no)!=NULL && numBrothers((yyvsp[0].no)) == 1) {
                                                                                        newBrother((yyvsp[-2].no), (yyvsp[0].no));
                                                                                        newBrother((yyvsp[0].no), createNode("Block"));
                                                                                    } else {
                                                                                        struct node * temp = createNode("Block");
                                                                                        newBrother((yyvsp[-2].no), temp);
                                                                                        temp->child = (yyvsp[0].no);
                                                                                        newBrother(temp, createNode("Block"));
                                                                                    }
                                                                                if(debug)printf("Statement4\n");}
#line 1694 "y.tab.c"
    break;

  case 33: /* Statement: WHILE LPAR Expr RPAR Statement  */
#line 230 "jucompiler.y"
                                                                                {(yyval.no) = createNode("While"); (yyval.no)->child = (yyvsp[-2].no); 
                                                                                    if((yyvsp[0].no) != NULL && numBrothers((yyvsp[0].no)) < 2){
                                                                                        newBrother((yyvsp[-2].no), (yyvsp[0].no));
                                                                                    } else{
                                                                                        newBrother((yyvsp[-2].no), createNode("Block"));
                                                                                        (yyvsp[-2].no)->brother->child = (yyvsp[0].no);
                                                                                    }
                                                                                if(debug)printf("Statement5\n");}
#line 1707 "y.tab.c"
    break;

  case 34: /* Statement: RETURN Expr SEMICOLON  */
#line 238 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Return"); (yyval.no)->child = (yyvsp[-1].no);if(debug)printf("Statement6\n");}
#line 1713 "y.tab.c"
    break;

  case 35: /* Statement: RETURN SEMICOLON  */
#line 239 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Return");if(debug)printf("Statement7\n");}
#line 1719 "y.tab.c"
    break;

  case 36: /* Statement: recSEMICOLON SEMICOLON  */
#line 240 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[-1].no);if(debug)printf("StatementRecSEMICOLON\n"); }
#line 1725 "y.tab.c"
    break;

  case 37: /* Statement: SEMICOLON  */
#line 241 "jucompiler.y"
                                                                                {(yyval.no) = NULL;if(debug)printf("Statement11\n");}
#line 1731 "y.tab.c"
    break;

  case 38: /* Statement: PRINT LPAR Expr RPAR SEMICOLON  */
#line 242 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Print"); (yyval.no)->child = (yyvsp[-2].no);if(debug)printf("Statement12\n");}
#line 1737 "y.tab.c"
    break;

  case 39: /* Statement: PRINT LPAR STRLIT RPAR SEMICOLON  */
#line 243 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Print"); sprintf(aux3, "StrLit(\"%s)", (yyvsp[-2].id)); (yyval.no)->child = createNode(strdup(aux3));if(debug)printf("Statement13\n");}
#line 1743 "y.tab.c"
    break;

  case 40: /* Statement: PRINT LPAR RPAR SEMICOLON  */
#line 244 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Print");if(debug)printf("Statement14\n");}
#line 1749 "y.tab.c"
    break;

  case 41: /* Statement: error SEMICOLON  */
#line 245 "jucompiler.y"
                                                                                {(yyval.no)=createNode(NULL);error=true;if(debug)printf("Statement15\n");}
#line 1755 "y.tab.c"
    break;

  case 42: /* recSEMICOLON: ParseArgs  */
#line 248 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[0].no);if(debug)printf("Statement8\n");}
#line 1761 "y.tab.c"
    break;

  case 43: /* recSEMICOLON: Assignment  */
#line 249 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[0].no);if(debug)printf("Statement9\n");}
#line 1767 "y.tab.c"
    break;

  case 44: /* recSEMICOLON: MethodInvocation  */
#line 250 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[0].no);if(debug)printf("Statement10\n");}
#line 1773 "y.tab.c"
    break;

  case 45: /* recSTAT: Statement recSTAT  */
#line 253 "jucompiler.y"
                                                                                {if((yyval.no)!=NULL){(yyval.no)=(yyvsp[-1].no); newBrother((yyval.no),(yyvsp[0].no));} else{(yyval.no)=(yyvsp[0].no);}}
#line 1779 "y.tab.c"
    break;

  case 46: /* recSTAT: %empty  */
#line 254 "jucompiler.y"
                                                                                {(yyval.no) = NULL;}
#line 1785 "y.tab.c"
    break;

  case 47: /* MethodInvocation: ID LPAR Expr recCOMMAEXP RPAR  */
#line 257 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Call"); sprintf(aux3, "Id(%s)", (yyvsp[-4].id)); (yyval.no)->child = createNode(strdup(aux3)); newBrother((yyval.no)->child, (yyvsp[-2].no)); newBrother((yyvsp[-2].no), (yyvsp[-1].no));if(debug)printf("MethodInvocation\n");}
#line 1791 "y.tab.c"
    break;

  case 48: /* MethodInvocation: ID LPAR RPAR  */
#line 258 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Call"); sprintf(aux3, "Id(%s)", (yyvsp[-2].id)); (yyval.no)->child = createNode(strdup(aux3));if(debug)printf("MethodInvocation3\n");}
#line 1797 "y.tab.c"
    break;

  case 49: /* MethodInvocation: ID LPAR error RPAR  */
#line 259 "jucompiler.y"
                                                                                {(yyval.no)=createNode(NULL);error=true;if(debug)printf("MethodInvocation4\n");}
#line 1803 "y.tab.c"
    break;

  case 50: /* recCOMMAEXP: COMMA Expr recCOMMAEXP  */
#line 262 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[-1].no); newBrother((yyvsp[-1].no), (yyvsp[0].no));if(debug)printf("recCOMMAEXP\n");}
#line 1809 "y.tab.c"
    break;

  case 51: /* recCOMMAEXP: %empty  */
#line 263 "jucompiler.y"
                                                                                {(yyval.no) = NULL;}
#line 1815 "y.tab.c"
    break;

  case 52: /* Assignment: ID ASSIGN Expr  */
#line 266 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Assign"); sprintf(aux3, "Id(%s)", (yyvsp[-2].id)); (yyval.no)->child = createNode(strdup(aux3)); newBrother((yyval.no)->child, (yyvsp[0].no));if(debug)printf("Assign\n");}
#line 1821 "y.tab.c"
    break;

  case 53: /* ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR  */
#line 269 "jucompiler.y"
                                                                                {(yyval.no) = createNode("ParseArgs"); sprintf(aux3, "Id(%s)", (yyvsp[-4].id)); (yyval.no)->child = createNode(strdup(aux3)); newBrother((yyval.no)->child, (yyvsp[-2].no));if(debug)printf("ParseArgs + id(%s)\n",aux3);}
#line 1827 "y.tab.c"
    break;

  case 54: /* ParseArgs: PARSEINT LPAR error RPAR  */
#line 270 "jucompiler.y"
                                                                                {(yyval.no) = NULL;(yyval.no)=createNode(NULL);error=true;if(debug)printf("ParseArgs2\n");}
#line 1833 "y.tab.c"
    break;

  case 55: /* Expr: Assignment  */
#line 273 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[0].no);}
#line 1839 "y.tab.c"
    break;

  case 56: /* Expr: Expr2  */
#line 274 "jucompiler.y"
                                                                                 {(yyval.no) = (yyvsp[0].no);}
#line 1845 "y.tab.c"
    break;

  case 57: /* Expr2: Expr2 PLUS Expr2  */
#line 277 "jucompiler.y"
                                                                                  {(yyval.no) = createNode("Add"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("PLUS\n");}
#line 1851 "y.tab.c"
    break;

  case 58: /* Expr2: Expr2 MINUS Expr2  */
#line 278 "jucompiler.y"
                                                                                  {(yyval.no) = createNode("Sub"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("MINUS\n");}
#line 1857 "y.tab.c"
    break;

  case 59: /* Expr2: Expr2 STAR Expr2  */
#line 279 "jucompiler.y"
                                                                                  {(yyval.no) = createNode("Mul"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("STAR\n");}
#line 1863 "y.tab.c"
    break;

  case 60: /* Expr2: Expr2 DIV Expr2  */
#line 280 "jucompiler.y"
                                                                                  {(yyval.no) = createNode("Div"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("DIV\n");}
#line 1869 "y.tab.c"
    break;

  case 61: /* Expr2: Expr2 MOD Expr2  */
#line 281 "jucompiler.y"
                                                                                  {(yyval.no) = createNode("Mod"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("MOD\n");}
#line 1875 "y.tab.c"
    break;

  case 62: /* Expr2: Expr2 AND Expr2  */
#line 282 "jucompiler.y"
                                                                                  {(yyval.no) = createNode("And"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("AND\n");}
#line 1881 "y.tab.c"
    break;

  case 63: /* Expr2: Expr2 OR Expr2  */
#line 283 "jucompiler.y"
                                                                                  {(yyval.no) = createNode("Or"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("OR\n");}
#line 1887 "y.tab.c"
    break;

  case 64: /* Expr2: Expr2 XOR Expr2  */
#line 284 "jucompiler.y"
                                                                                  {(yyval.no) = createNode("Xor"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("XOR\n");}
#line 1893 "y.tab.c"
    break;

  case 65: /* Expr2: Expr2 LSHIFT Expr2  */
#line 285 "jucompiler.y"
                                                                                  {(yyval.no) = createNode("Lshift"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("LSHIFT\n");}
#line 1899 "y.tab.c"
    break;

  case 66: /* Expr2: Expr2 RSHIFT Expr2  */
#line 286 "jucompiler.y"
                                                                                  {(yyval.no) = createNode("Rshift"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("RSHIFT\n");}
#line 1905 "y.tab.c"
    break;

  case 67: /* Expr2: Expr2 EQ Expr2  */
#line 287 "jucompiler.y"
                                                                                  {(yyval.no) = createNode("Eq"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("EQ\n");}
#line 1911 "y.tab.c"
    break;

  case 68: /* Expr2: Expr2 GE Expr2  */
#line 288 "jucompiler.y"
                                                                                  {(yyval.no) = createNode("Ge"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("GE\n");}
#line 1917 "y.tab.c"
    break;

  case 69: /* Expr2: Expr2 GT Expr2  */
#line 289 "jucompiler.y"
                                                                                  {(yyval.no) = createNode("Gt"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("GT\n");}
#line 1923 "y.tab.c"
    break;

  case 70: /* Expr2: Expr2 LE Expr2  */
#line 290 "jucompiler.y"
                                                                                  {(yyval.no) = createNode("Le"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("LE\n");}
#line 1929 "y.tab.c"
    break;

  case 71: /* Expr2: Expr2 LT Expr2  */
#line 291 "jucompiler.y"
                                                                                  {(yyval.no) = createNode("Lt"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("LT\n");}
#line 1935 "y.tab.c"
    break;

  case 72: /* Expr2: Expr2 NE Expr2  */
#line 292 "jucompiler.y"
                                                                                  {(yyval.no) = createNode("Ne"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("NE\n");}
#line 1941 "y.tab.c"
    break;

  case 73: /* Expr2: MINUS Expr2  */
#line 293 "jucompiler.y"
                                                                                 {(yyval.no) = createNode("Minus"); (yyval.no)->child=(yyvsp[0].no);if(debug)printf("MINUS2\n");}
#line 1947 "y.tab.c"
    break;

  case 74: /* Expr2: PLUS Expr2  */
#line 294 "jucompiler.y"
                                                                                 {(yyval.no) = createNode("Plus"); (yyval.no)->child=(yyvsp[0].no);if(debug)printf("PLUS2\n");}
#line 1953 "y.tab.c"
    break;

  case 75: /* Expr2: NOT Expr2  */
#line 295 "jucompiler.y"
                                                                                 {(yyval.no) = createNode("Not"); (yyval.no)->child=(yyvsp[0].no);if(debug)printf("NOT\n");}
#line 1959 "y.tab.c"
    break;

  case 76: /* Expr2: LPAR Expr RPAR  */
#line 296 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[-1].no);if(debug)printf("EXPR\n");}
#line 1965 "y.tab.c"
    break;

  case 77: /* Expr2: MethodInvocation  */
#line 297 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[0].no);if(debug)printf("MI\n");}
#line 1971 "y.tab.c"
    break;

  case 78: /* Expr2: ParseArgs  */
#line 298 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[0].no);if(debug)printf("PA\n");}
#line 1977 "y.tab.c"
    break;

  case 79: /* Expr2: ID  */
#line 299 "jucompiler.y"
                                                                                {sprintf(aux3, "Id(%s)", (yyvsp[0].id)); (yyval.no) = createNode(strdup(aux3));if(debug)printf("%s_ID111\n", aux3);}
#line 1983 "y.tab.c"
    break;

  case 80: /* Expr2: ID DOTLENGTH  */
#line 300 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Length"); sprintf(aux3, "Id(%s)", (yyvsp[-1].id)); (yyval.no)->child = createNode(strdup(aux3));if(debug)printf("DOT\n");}
#line 1989 "y.tab.c"
    break;

  case 81: /* Expr2: INTLIT  */
#line 301 "jucompiler.y"
                                                                                {sprintf(aux3, "DecLit(%s)", (yyvsp[0].id)); (yyval.no) = createNode(strdup(aux3));if(debug)printf("DEC2\n");}
#line 1995 "y.tab.c"
    break;

  case 82: /* Expr2: REALLIT  */
#line 302 "jucompiler.y"
                                                                                {sprintf(aux3, "RealLit(%s)", (yyvsp[0].id)); (yyval.no) = createNode(strdup(aux3));if(debug)printf("REAL2\n");}
#line 2001 "y.tab.c"
    break;

  case 83: /* Expr2: BOOLLIT  */
#line 303 "jucompiler.y"
                                                                                {sprintf(aux3, "BoolLit(%s)", (yyvsp[0].id)); (yyval.no) = createNode(strdup(aux3));if(debug)printf("BOOL2\n");}
#line 2007 "y.tab.c"
    break;

  case 84: /* Expr2: LPAR error RPAR  */
#line 304 "jucompiler.y"
                                                                                {(yyval.no)=createNode(NULL);error=true;if(debug)printf("666\n");}
#line 2013 "y.tab.c"
    break;


#line 2017 "y.tab.c"

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

#line 307 "jucompiler.y"
