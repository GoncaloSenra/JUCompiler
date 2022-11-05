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
#line 2 "jucompiler.y"


    //Gonçalo Senra   2020213750
    //Henrique Costa  2020214120
    
    #include <stdio.h>
    #include "STree.h"
    int yylex(void);
    #define true 1
    #define false 0

    char aux3[1024]; 
    char aux4[1024]; 
    struct node * prog;
    int hasError;
    int printTree= true;
    int debug = true;

    void yyerror (const char *s);

#line 92 "y.tab.c"

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
    RESERVED = 305,                /* RESERVED  */
    MUL = 306,                     /* MUL  */
    LOWER = 307,                   /* LOWER  */
    HIGHER = 308                   /* HIGHER  */
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
#define MUL 306
#define LOWER 307
#define HIGHER 308

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "jucompiler.y"

    char* id;
    int intlit;
    float reallit;
    struct node * no;

#line 258 "y.tab.c"

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
  YYSYMBOL_MUL = 51,                       /* MUL  */
  YYSYMBOL_LOWER = 52,                     /* LOWER  */
  YYSYMBOL_HIGHER = 53,                    /* HIGHER  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_Program = 55,                   /* Program  */
  YYSYMBOL_recPR = 56,                     /* recPR  */
  YYSYMBOL_MethodDecl = 57,                /* MethodDecl  */
  YYSYMBOL_FieldDecl = 58,                 /* FieldDecl  */
  YYSYMBOL_recCOMMAID = 59,                /* recCOMMAID  */
  YYSYMBOL_Type = 60,                      /* Type  */
  YYSYMBOL_MethodHeader = 61,              /* MethodHeader  */
  YYSYMBOL_FormalParams = 62,              /* FormalParams  */
  YYSYMBOL_recFP = 63,                     /* recFP  */
  YYSYMBOL_MethodBody = 64,                /* MethodBody  */
  YYSYMBOL_recMD = 65,                     /* recMD  */
  YYSYMBOL_VarDecl = 66,                   /* VarDecl  */
  YYSYMBOL_recVAR = 67,                    /* recVAR  */
  YYSYMBOL_Statement = 68,                 /* Statement  */
  YYSYMBOL_recSTAT = 69,                   /* recSTAT  */
  YYSYMBOL_MethodInvocation = 70,          /* MethodInvocation  */
  YYSYMBOL_recCOMMAEXP = 71,               /* recCOMMAEXP  */
  YYSYMBOL_Assignment = 72,                /* Assignment  */
  YYSYMBOL_ParseArgs = 73,                 /* ParseArgs  */
  YYSYMBOL_Expr = 74                       /* Expr  */
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
#define YYLAST   665

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  91
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  185

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   308


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
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   121,   121,   122,   125,   126,   127,   128,   129,   130,
     133,   136,   146,   147,   150,   151,   154,   155,   156,   159,
     160,   161,   162,   165,   170,   173,   174,   177,   178,   181,
     182,   183,   184,   187,   197,   200,   201,   204,   205,   206,
     207,   208,   209,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   221,   222,   224,   225,   226,   227,   230,   231,
     234,   237,   238,   241,   242,   243,   244,   245,   246,   247,
     248,   249,   250,   251,   252,   253,   254,   255,   256,   257,
     258,   259,   260,   261,   262,   263,   264,   265,   266,   267,
     268,   269
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
  "STRING", "VOID", "WHILE", "RESERVED", "MUL", "LOWER", "HIGHER",
  "$accept", "Program", "recPR", "MethodDecl", "FieldDecl", "recCOMMAID",
  "Type", "MethodHeader", "FormalParams", "recFP", "MethodBody", "recMD",
  "VarDecl", "recVAR", "Statement", "recSTAT", "MethodInvocation",
  "recCOMMAEXP", "Assignment", "ParseArgs", "Expr", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-36)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-31)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -26,    35,    43,    28,   -36,    24,    17,   -36,    39,     6,
      38,    60,    70,   -36,   -36,   108,   -36,   -36,   -36,   -36,
     -36,   -36,    81,    99,    92,    85,    16,    15,   -36,    54,
     107,   147,   -36,    86,    94,    -4,   194,   -36,   -36,   112,
     114,   116,   294,   122,   123,   117,    32,   177,   118,   120,
     121,   -36,   128,   149,   126,   160,   -36,   148,   -36,   -36,
     323,   252,   -36,   -36,   222,   323,   285,    90,    -1,   -36,
     -36,   -36,   278,   323,   323,   323,   -36,   -36,   -36,   -36,
     369,   323,    19,   -36,   -36,   -36,   -36,   -36,   -36,   150,
     166,   -36,   -36,   -36,   531,   153,   -36,   342,   -36,   -36,
     396,   156,   157,   423,   158,   170,   -36,   162,   450,   -36,
     -36,   -36,   323,   323,   323,   323,   323,   323,   323,   323,
     323,   323,   323,   323,   323,   -36,   323,   323,   323,   477,
     189,   -36,   168,   193,    87,   -36,   -36,   323,   -36,     4,
      93,   169,   -36,   171,   -36,   323,   -36,   -36,   583,   -36,
      53,   632,   313,   313,   313,   313,    66,    53,   632,   558,
      66,   -36,   -36,   608,    93,   191,   -36,   -36,   197,   531,
     323,   -36,   164,   -36,   -36,   504,   -36,   -36,   166,   531,
      93,   178,   -36,   -36,   -36
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     1,     0,     0,     3,     0,     0,
       0,     0,     0,    13,     9,     0,     2,     7,     8,    16,
      18,    17,     0,     0,     0,     0,     0,     0,    10,     0,
       0,     0,    12,     0,     0,     0,     0,    28,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    22,     0,     0,     0,    14,    20,     0,    11,    51,
       0,     0,    38,    52,     0,     0,     0,     0,    86,    88,
      89,    90,     0,     0,     0,     0,    43,    83,    84,    85,
       0,     0,     0,    27,    32,    31,    44,    45,    46,     0,
      26,    21,    15,    19,    60,     0,    56,     0,    37,    53,
       0,     0,     0,     0,     0,     0,    87,     0,     0,    79,
      81,    80,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    42,     0,     0,     0,     0,
       0,    34,     0,     0,     0,    23,    57,     0,    55,     0,
       0,     0,    50,     0,    62,     0,    91,    82,    68,    65,
      66,    73,    74,    75,    76,    77,    64,    67,    78,    69,
      63,    71,    72,    70,     0,    35,    33,    24,     0,    59,
       0,    54,    40,    49,    48,     0,    41,    36,    26,    58,
       0,     0,    25,    39,    61
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -36,   -36,    -5,   -36,   -36,   154,    -3,   -36,   174,    30,
     -36,    33,   -36,    48,   -35,   -36,   -27,   -36,   -25,   -23,
      46
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     2,    10,    11,    12,    33,    44,    24,    54,   135,
      28,    45,    46,   132,    47,    64,    77,   139,    78,    79,
      80
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    63,    49,    14,    50,    60,    17,    18,    60,    48,
       1,    49,    23,    50,    61,   170,    34,    61,    35,    48,
      48,    49,    49,    50,    50,     6,    53,    30,    53,    99,
     130,    36,   171,    34,    31,    35,   106,    48,     3,    49,
       6,    50,    37,     4,     5,    38,    32,    13,    36,   131,
      19,     7,    15,    20,     8,    39,    21,    40,    41,   -30,
      42,     6,    38,   113,    43,    16,    -6,    19,     9,     8,
      20,     6,    39,    21,    40,    41,   113,    42,   114,    84,
      85,    43,    51,     9,    25,   126,   127,    -4,   121,    19,
       8,   104,    20,   105,    34,    21,    35,    -5,   126,   127,
       8,    52,    26,    29,     9,   172,    94,    97,    27,    36,
      55,   100,   103,    48,     9,    49,    58,    50,   108,   109,
     110,   111,    19,    38,    59,    20,    82,   129,    21,   176,
      65,   168,    66,    39,    67,    40,    41,    48,    42,    49,
      81,    50,    43,    19,    83,   183,    20,    89,    86,    21,
      87,    88,    90,    48,    91,    49,    22,    50,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,   158,   159,
     160,    30,   161,   162,   163,    56,    93,   134,    34,   133,
      35,   136,    19,   169,   141,    20,   144,   142,    21,   145,
     146,   175,   165,    36,    52,    34,   167,    35,   166,   173,
     178,   174,   130,   180,   -29,    57,   184,    38,   182,    92,
      36,     0,    19,   177,     0,    20,   179,    39,    21,    40,
      41,    62,    42,    34,    38,    35,    43,     0,     0,     0,
       0,     0,     0,     0,    39,     0,    40,    41,    36,    42,
       0,     0,     0,    43,     0,     0,     0,     0,     0,    98,
       0,     0,    38,    95,     0,    68,    69,     0,    70,    71,
       0,     0,    39,     0,    40,    41,     0,    42,     0,     0,
      72,    43,     0,    73,     0,     0,    74,     0,    75,   107,
      96,    68,    69,     0,    70,    71,     0,     0,    68,    69,
     101,    70,    71,     0,     0,    41,    72,    68,    69,    73,
      70,    71,    74,    72,    75,     0,    73,     0,     0,    74,
       0,    75,    72,   102,     0,    73,     0,     0,    74,     0,
      75,    41,     0,   113,    76,   114,    68,    69,    41,    70,
      71,     0,     0,     0,   120,   121,     0,    41,     0,   124,
       0,    72,     0,     0,    73,   126,   127,    74,     0,    75,
     112,     0,   113,   137,   114,   115,   116,   117,     0,   118,
       0,     0,   119,   120,   121,   122,    41,   123,   124,     0,
     138,     0,     0,     0,   126,   127,   128,   112,     0,   113,
       0,   114,   115,   116,   117,     0,   118,     0,     0,   119,
     120,   121,   122,     0,   123,   124,     0,     0,     0,   125,
       0,   126,   127,   128,   112,     0,   113,     0,   114,   115,
     116,   117,     0,   118,     0,     0,   119,   120,   121,   122,
       0,   123,   124,     0,   140,     0,     0,     0,   126,   127,
     128,   112,     0,   113,     0,   114,   115,   116,   117,     0,
     118,     0,     0,   119,   120,   121,   122,     0,   123,   124,
       0,   143,     0,     0,     0,   126,   127,   128,   112,     0,
     113,     0,   114,   115,   116,   117,     0,   118,     0,     0,
     119,   120,   121,   122,     0,   123,   124,     0,   147,     0,
       0,     0,   126,   127,   128,   112,     0,   113,     0,   114,
     115,   116,   117,     0,   118,     0,     0,   119,   120,   121,
     122,     0,   123,   124,     0,   164,     0,     0,     0,   126,
     127,   128,   112,     0,   113,     0,   114,   115,   116,   117,
       0,   118,     0,     0,   119,   120,   121,   122,     0,   123,
     124,     0,     0,   181,     0,     0,   126,   127,   128,   112,
       0,   113,     0,   114,   115,   116,   117,     0,   118,     0,
       0,   119,   120,   121,   122,     0,   123,   124,     0,     0,
       0,     0,     0,   126,   127,   128,   112,     0,   113,     0,
     114,   115,   116,   117,     0,   118,     0,     0,   119,   120,
     121,   122,     0,     0,   124,     0,     0,     0,     0,     0,
     126,   127,   128,   113,     0,   114,   115,   116,   117,     0,
     118,     0,     0,   119,   120,   121,   122,     0,     0,   124,
       0,     0,     0,     0,     0,   126,   127,   128,   113,     0,
     114,   115,   116,   117,     0,   118,     0,     0,   119,   120,
     121,   122,     0,     0,   124,     0,     0,     0,     0,     0,
     126,   127,   113,     0,   114,     0,   116,   117,     0,   118,
       0,     0,   119,   120,   121,     0,     0,     0,   124,     0,
       0,     0,     0,     0,   126,   127
};

static const yytype_int16 yycheck[] =
{
      27,    36,    27,     8,    27,     9,    11,    12,     9,    36,
      36,    36,    15,    36,    18,    11,     1,    18,     3,    46,
      47,    46,    47,    46,    47,     1,    29,    11,    31,    64,
      11,    16,    28,     1,    18,     3,    37,    64,     3,    64,
       1,    64,    27,     0,    16,    30,    30,    30,    16,    30,
      35,    27,    46,    38,    30,    40,    41,    42,    43,    27,
      45,     1,    30,    10,    49,    27,    27,    35,    44,    30,
      38,     1,    40,    41,    42,    43,    10,    45,    12,    46,
      47,    49,    28,    44,     3,    32,    33,    27,    22,    35,
      30,     1,    38,     3,     1,    41,     3,    27,    32,    33,
      30,    47,     3,    18,    44,   140,    60,    61,    16,    16,
       3,    65,    66,   140,    44,   140,    30,   140,    72,    73,
      74,    75,    35,    30,    30,    38,     3,    81,    41,   164,
      18,   134,    18,    40,    18,    42,    43,   164,    45,   164,
      18,   164,    49,    35,    27,   180,    38,    19,    30,    41,
      30,    30,     3,   180,    28,   180,    48,   180,   112,   113,
     114,   115,   116,   117,   118,   119,   120,   121,   122,   123,
     124,    11,   126,   127,   128,    28,    28,    11,     1,    29,
       3,    28,    35,   137,    28,    38,    28,    30,    41,    19,
      28,   145,     3,    16,    47,     1,     3,     3,    30,    30,
       3,    30,    11,    39,    27,    31,    28,    30,   178,    55,
      16,    -1,    35,   165,    -1,    38,   170,    40,    41,    42,
      43,    27,    45,     1,    30,     3,    49,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    40,    -1,    42,    43,    16,    45,
      -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,    -1,    27,
      -1,    -1,    30,     1,    -1,     3,     4,    -1,     6,     7,
      -1,    -1,    40,    -1,    42,    43,    -1,    45,    -1,    -1,
      18,    49,    -1,    21,    -1,    -1,    24,    -1,    26,     1,
      28,     3,     4,    -1,     6,     7,    -1,    -1,     3,     4,
       5,     6,     7,    -1,    -1,    43,    18,     3,     4,    21,
       6,     7,    24,    18,    26,    -1,    21,    -1,    -1,    24,
      -1,    26,    18,    28,    -1,    21,    -1,    -1,    24,    -1,
      26,    43,    -1,    10,    30,    12,     3,     4,    43,     6,
       7,    -1,    -1,    -1,    21,    22,    -1,    43,    -1,    26,
      -1,    18,    -1,    -1,    21,    32,    33,    24,    -1,    26,
       8,    -1,    10,    11,    12,    13,    14,    15,    -1,    17,
      -1,    -1,    20,    21,    22,    23,    43,    25,    26,    -1,
      28,    -1,    -1,    -1,    32,    33,    34,     8,    -1,    10,
      -1,    12,    13,    14,    15,    -1,    17,    -1,    -1,    20,
      21,    22,    23,    -1,    25,    26,    -1,    -1,    -1,    30,
      -1,    32,    33,    34,     8,    -1,    10,    -1,    12,    13,
      14,    15,    -1,    17,    -1,    -1,    20,    21,    22,    23,
      -1,    25,    26,    -1,    28,    -1,    -1,    -1,    32,    33,
      34,     8,    -1,    10,    -1,    12,    13,    14,    15,    -1,
      17,    -1,    -1,    20,    21,    22,    23,    -1,    25,    26,
      -1,    28,    -1,    -1,    -1,    32,    33,    34,     8,    -1,
      10,    -1,    12,    13,    14,    15,    -1,    17,    -1,    -1,
      20,    21,    22,    23,    -1,    25,    26,    -1,    28,    -1,
      -1,    -1,    32,    33,    34,     8,    -1,    10,    -1,    12,
      13,    14,    15,    -1,    17,    -1,    -1,    20,    21,    22,
      23,    -1,    25,    26,    -1,    28,    -1,    -1,    -1,    32,
      33,    34,     8,    -1,    10,    -1,    12,    13,    14,    15,
      -1,    17,    -1,    -1,    20,    21,    22,    23,    -1,    25,
      26,    -1,    -1,    29,    -1,    -1,    32,    33,    34,     8,
      -1,    10,    -1,    12,    13,    14,    15,    -1,    17,    -1,
      -1,    20,    21,    22,    23,    -1,    25,    26,    -1,    -1,
      -1,    -1,    -1,    32,    33,    34,     8,    -1,    10,    -1,
      12,    13,    14,    15,    -1,    17,    -1,    -1,    20,    21,
      22,    23,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      32,    33,    34,    10,    -1,    12,    13,    14,    15,    -1,
      17,    -1,    -1,    20,    21,    22,    23,    -1,    -1,    26,
      -1,    -1,    -1,    -1,    -1,    32,    33,    34,    10,    -1,
      12,    13,    14,    15,    -1,    17,    -1,    -1,    20,    21,
      22,    23,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      32,    33,    10,    -1,    12,    -1,    14,    15,    -1,    17,
      -1,    -1,    20,    21,    22,    -1,    -1,    -1,    26,    -1,
      -1,    -1,    -1,    -1,    32,    33
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,    55,     3,     0,    16,     1,    27,    30,    44,
      56,    57,    58,    30,    56,    46,    27,    56,    56,    35,
      38,    41,    48,    60,    61,     3,     3,    16,    64,    18,
      11,    18,    30,    59,     1,     3,    16,    27,    30,    40,
      42,    43,    45,    49,    60,    65,    66,    68,    70,    72,
      73,    28,    47,    60,    62,     3,    28,    62,    30,    30,
       9,    18,    27,    68,    69,    18,    18,    18,     3,     4,
       6,     7,    18,    21,    24,    26,    30,    70,    72,    73,
      74,    18,     3,    27,    65,    65,    30,    30,    30,    19,
       3,    28,    59,    28,    74,     1,    28,    74,    27,    68,
      74,     5,    28,    74,     1,     3,    37,     1,    74,    74,
      74,    74,     8,    10,    12,    13,    14,    15,    17,    20,
      21,    22,    23,    25,    26,    30,    32,    33,    34,    74,
      11,    30,    67,    29,    11,    63,    28,    11,    28,    71,
      28,    28,    30,    28,    28,    19,    28,    28,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    28,     3,    30,     3,    60,    74,
      11,    28,    68,    30,    30,    74,    68,    67,     3,    74,
      39,    29,    63,    68,    28
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    55,    56,    56,    56,    56,    56,    56,
      57,    58,    58,    58,    59,    59,    60,    60,    60,    61,
      61,    61,    61,    62,    62,    63,    63,    64,    64,    65,
      65,    65,    65,    66,    66,    67,    67,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    69,    69,    70,    70,    70,    70,    71,    71,
      72,    73,    73,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74,    74,    74,    74,    74,    74,    74,    74,    74,
      74,    74
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     5,     4,     1,     1,     1,     2,     2,     2,
       4,     6,     5,     2,     2,     3,     1,     1,     1,     5,
       4,     5,     4,     3,     4,     4,     0,     3,     2,     1,
       1,     2,     2,     4,     3,     2,     3,     3,     2,     7,
       5,     5,     3,     2,     2,     2,     2,     1,     5,     5,
       4,     2,     1,     2,     5,     4,     3,     4,     3,     2,
       3,     7,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       2,     2,     3,     1,     1,     1,     1,     2,     1,     1,
       1,     3
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
#line 121 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Program"); sprintf(aux3, "Id(%s)", (yyvsp[-3].id)); (yyval.no)->child = createNode(strdup(aux3)); newBrother((yyval.no)->child, (yyvsp[-1].no)); if (printTree==true && hasError==false){printASTree((yyval.no),0);} else{freeASTree((yyval.no));}  if(debug)printf("Program\n");}
#line 1528 "y.tab.c"
    break;

  case 3: /* Program: CLASS ID LBRACE RBRACE  */
#line 122 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Program"); sprintf(aux3, "Id(%s)", (yyvsp[-2].id)); (yyval.no)->child = createNode(strdup(aux3));if(debug)printf("Program2\n");}
#line 1534 "y.tab.c"
    break;

  case 4: /* recPR: MethodDecl  */
#line 125 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[0].no);if(debug)printf("recPR\n");}
#line 1540 "y.tab.c"
    break;

  case 5: /* recPR: FieldDecl  */
#line 126 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[0].no);if(debug)printf("recPR2\n");}
#line 1546 "y.tab.c"
    break;

  case 6: /* recPR: SEMICOLON  */
#line 127 "jucompiler.y"
                                                                                {;if(debug)printf("recPR3\n");}
#line 1552 "y.tab.c"
    break;

  case 7: /* recPR: MethodDecl recPR  */
#line 128 "jucompiler.y"
                                                                               {(yyval.no) = (yyvsp[-1].no); newBrother((yyval.no), (yyvsp[0].no));if(debug)printf("recPR4\n");}
#line 1558 "y.tab.c"
    break;

  case 8: /* recPR: FieldDecl recPR  */
#line 129 "jucompiler.y"
                                                                               {(yyval.no) = (yyvsp[-1].no); newBrother((yyval.no), (yyvsp[0].no));if(debug)printf("recPR5\n");}
#line 1564 "y.tab.c"
    break;

  case 9: /* recPR: SEMICOLON recPR  */
#line 130 "jucompiler.y"
                                                                               {(yyval.no) = (yyvsp[0].no);if(debug)printf("recPR6\n");}
#line 1570 "y.tab.c"
    break;

  case 10: /* MethodDecl: PUBLIC STATIC MethodHeader MethodBody  */
#line 133 "jucompiler.y"
                                                                                {(yyval.no) = createNode("MethodDecl"); (yyval.no)->child = (yyvsp[-1].no); newBrother((yyvsp[-1].no), (yyvsp[0].no));if(debug)printf("MethodDecl\n");}
#line 1576 "y.tab.c"
    break;

  case 11: /* FieldDecl: PUBLIC STATIC Type ID recCOMMAID SEMICOLON  */
#line 136 "jucompiler.y"
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
#line 1591 "y.tab.c"
    break;

  case 12: /* FieldDecl: PUBLIC STATIC Type ID SEMICOLON  */
#line 146 "jucompiler.y"
                                                                                {(yyval.no) = createNode("FieldDecl"); (yyval.no)->child = (yyvsp[-2].no); sprintf(aux3, "Id(%s)", (yyvsp[-1].id)); newBrother((yyvsp[-2].no), createNode(strdup(aux3)));if(debug)printf("FieldDecl2\n");}
#line 1597 "y.tab.c"
    break;

  case 13: /* FieldDecl: error SEMICOLON  */
#line 147 "jucompiler.y"
                                                                                {hasError=true;if(debug)printf("FieldDecl3\n");}
#line 1603 "y.tab.c"
    break;

  case 14: /* recCOMMAID: COMMA ID  */
#line 150 "jucompiler.y"
                                                                                {(yyval.no) = createNode("FieldDecl"); sprintf(aux3, "Id(%s)", (yyvsp[0].id)); (yyval.no)->child = createNode(strdup(aux3));if(debug)printf("recCommaId(%s)\n", aux3);}
#line 1609 "y.tab.c"
    break;

  case 15: /* recCOMMAID: COMMA ID recCOMMAID  */
#line 151 "jucompiler.y"
                                                                                {(yyval.no) = createNode("FieldDecl"); sprintf(aux3, "Id(%s)", (yyvsp[-1].id)); (yyval.no)->child = createNode(strdup(aux3)); newBrother((yyval.no), (yyvsp[0].no));if(debug)printf("recCommaId2(%s)\n", aux3);}
#line 1615 "y.tab.c"
    break;

  case 16: /* Type: BOOL  */
#line 154 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Bool");if(debug)printf("Bool\n");}
#line 1621 "y.tab.c"
    break;

  case 17: /* Type: INT  */
#line 155 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Int");if(debug)printf("Int\n");}
#line 1627 "y.tab.c"
    break;

  case 18: /* Type: DOUBLE  */
#line 156 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Double");if(debug)printf("Double\n");}
#line 1633 "y.tab.c"
    break;

  case 19: /* MethodHeader: Type ID LPAR FormalParams RPAR  */
#line 159 "jucompiler.y"
                                                                                {(yyval.no) = createNode("MethodHeader"); (yyval.no)->child = (yyvsp[-4].no); sprintf(aux3, "Id(%s)", (yyvsp[-3].id)); newBrother((yyvsp[-4].no), createNode(strdup(aux3))); newBrother((yyvsp[-4].no), (yyvsp[-1].no));if(debug)printf("MethodHeader\n");}
#line 1639 "y.tab.c"
    break;

  case 20: /* MethodHeader: Type ID LPAR RPAR  */
#line 160 "jucompiler.y"
                                                                                {(yyval.no) = createNode("MethodHeader"); (yyval.no)->child = (yyvsp[-3].no); sprintf(aux3, "Id(%s)", (yyvsp[-2].id)); newBrother((yyvsp[-3].no), createNode(strdup(aux3))); newBrother((yyvsp[-3].no), createNode("MethodParams"));if(debug)printf("MethodHeader2\n");}
#line 1645 "y.tab.c"
    break;

  case 21: /* MethodHeader: VOID ID LPAR FormalParams RPAR  */
#line 161 "jucompiler.y"
                                                                                {(yyval.no) = createNode("MethodHeader"); (yyval.no)->child = createNode("Void"); sprintf(aux3, "Id(%s)", (yyvsp[-3].id)); newBrother((yyval.no)->child, createNode(strdup(aux3))); newBrother((yyval.no)->child, (yyvsp[-1].no));if(debug)printf("MethodHeader3\n");}
#line 1651 "y.tab.c"
    break;

  case 22: /* MethodHeader: VOID ID LPAR RPAR  */
#line 162 "jucompiler.y"
                                                                                {(yyval.no) = createNode("MethodHeader");(yyval.no)->child = createNode("Void"); sprintf(aux3, "Id(%s)", (yyvsp[-2].id)); newBrother((yyval.no)->child, createNode(strdup(aux3)));newBrother((yyval.no)->child,createNode("MethodParams"));if(debug)printf("MethodHeader4\n");}
#line 1657 "y.tab.c"
    break;

  case 23: /* FormalParams: Type ID recFP  */
#line 165 "jucompiler.y"
                                                                                {(yyval.no) = createNode("MethodParams"); (yyval.no)->child = createNode("ParamDecl"); (yyval.no)->child->child = (yyvsp[-2].no); sprintf(aux3, "Id(%s)", (yyvsp[-1].id)); newBrother((yyvsp[-2].no), createNode(strdup(aux3))); newBrother((yyval.no), (yyvsp[0].no));

                                                                                    if(debug)printf("FormalParams\n");
                                                                                }
#line 1666 "y.tab.c"
    break;

  case 24: /* FormalParams: STRING LSQ RSQ ID  */
#line 170 "jucompiler.y"
                                                                                {(yyval.no) = createNode("MethodParams"); (yyval.no)->child = createNode("ParamDecl"); (yyval.no)->child->child = createNode("StringArray"); sprintf(aux3, "Id(%s)", (yyvsp[0].id)); newBrother((yyval.no)->child->child, createNode(strdup(aux3)));if(debug)printf("FormalParams3\n");}
#line 1672 "y.tab.c"
    break;

  case 25: /* recFP: COMMA Type ID recFP  */
#line 173 "jucompiler.y"
                                                                                {(yyval.no) = createNode("ParamDecl"); newBrother((yyval.no), (yyvsp[0].no)); (yyval.no)->child = (yyvsp[-2].no); sprintf(aux3, "Id(%s)", (yyvsp[-1].id)); newBrother((yyvsp[-2].no), createNode(strdup(aux3)));if(debug)printf("recFP2\n");}
#line 1678 "y.tab.c"
    break;

  case 26: /* recFP: %empty  */
#line 174 "jucompiler.y"
                                                                                {(yyval.no) = NULL;}
#line 1684 "y.tab.c"
    break;

  case 27: /* MethodBody: LBRACE recMD RBRACE  */
#line 177 "jucompiler.y"
                                                                                {(yyval.no) = createNode("MethodBody"); (yyval.no)->child = (yyvsp[-1].no);if(debug)printf("MethodBody\n");}
#line 1690 "y.tab.c"
    break;

  case 28: /* MethodBody: LBRACE RBRACE  */
#line 178 "jucompiler.y"
                                                                                {(yyval.no) = createNode("MethodBody");if(debug)printf("MethodBody2\n");}
#line 1696 "y.tab.c"
    break;

  case 29: /* recMD: Statement  */
#line 181 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[0].no);if(debug)printf("recMD\n");}
#line 1702 "y.tab.c"
    break;

  case 30: /* recMD: VarDecl  */
#line 182 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[0].no);if(debug)printf("recMD2\n");}
#line 1708 "y.tab.c"
    break;

  case 31: /* recMD: Statement recMD  */
#line 183 "jucompiler.y"
                                                                                {if((yyvsp[-1].no)) {(yyval.no) = (yyvsp[-1].no); newBrother((yyval.no), (yyvsp[0].no));}else{(yyval.no)=(yyvsp[0].no);}if(debug)printf("recMD3\n");}
#line 1714 "y.tab.c"
    break;

  case 32: /* recMD: VarDecl recMD  */
#line 184 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[-1].no); newBrother((yyval.no), (yyvsp[0].no));if(debug)printf("recMD4\n");}
#line 1720 "y.tab.c"
    break;

  case 33: /* VarDecl: Type ID recVAR SEMICOLON  */
#line 187 "jucompiler.y"
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
#line 1735 "y.tab.c"
    break;

  case 34: /* VarDecl: Type ID SEMICOLON  */
#line 197 "jucompiler.y"
                                                                                {(yyval.no) = createNode("VarDecl"); (yyval.no)->child = (yyvsp[-2].no); sprintf(aux3, "Id(%s)", (yyvsp[-1].id)); newBrother((yyvsp[-2].no), createNode(strdup(aux3)));if(debug)printf("VarDecl2\n");}
#line 1741 "y.tab.c"
    break;

  case 35: /* recVAR: COMMA ID  */
#line 200 "jucompiler.y"
                                                                                {(yyval.no) = createNode("VarDecl"); sprintf(aux3, "Id(%s)", (yyvsp[0].id)); (yyval.no)->child = createNode(strdup(aux3));if(debug)printf("recVAR\n");}
#line 1747 "y.tab.c"
    break;

  case 36: /* recVAR: COMMA ID recVAR  */
#line 201 "jucompiler.y"
                                                                                {(yyval.no) = createNode("VarDecl"); newBrother((yyval.no), (yyvsp[0].no)); sprintf(aux3, "Id(%s)", (yyvsp[-1].id)); (yyval.no)->child = createNode(strdup(aux3));if(debug)printf("recVAR2\n");}
#line 1753 "y.tab.c"
    break;

  case 37: /* Statement: LBRACE recSTAT RBRACE  */
#line 204 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[-1].no);if(debug)printf("Statement\n");}
#line 1759 "y.tab.c"
    break;

  case 38: /* Statement: LBRACE RBRACE  */
#line 205 "jucompiler.y"
                                                                                {;if(debug)printf("Statement2\n");}
#line 1765 "y.tab.c"
    break;

  case 39: /* Statement: IF LPAR Expr RPAR Statement ELSE Statement  */
#line 206 "jucompiler.y"
                                                                                {(yyval.no) = createNode("If"); (yyval.no)->child = (yyvsp[-4].no); newBrother((yyvsp[-4].no), (yyvsp[-2].no)); newBrother((yyvsp[-2].no), createNode("Block")); newBrother((yyvsp[-2].no), (yyvsp[0].no));if(debug)printf("Statement3\n");}
#line 1771 "y.tab.c"
    break;

  case 40: /* Statement: IF LPAR Expr RPAR Statement  */
#line 207 "jucompiler.y"
                                                                                {(yyval.no) = createNode("If"); (yyval.no)->child = (yyvsp[-2].no); newBrother((yyvsp[-2].no), (yyvsp[0].no)); newBrother((yyvsp[0].no), createNode("Block"));if(debug)printf("Statement4\n");}
#line 1777 "y.tab.c"
    break;

  case 41: /* Statement: WHILE LPAR Expr RPAR Statement  */
#line 208 "jucompiler.y"
                                                                                {(yyval.no) = createNode("While"); (yyval.no)->child = (yyvsp[-2].no); newBrother((yyvsp[-2].no), (yyvsp[0].no));if(debug)printf("Statement5\n");}
#line 1783 "y.tab.c"
    break;

  case 42: /* Statement: RETURN Expr SEMICOLON  */
#line 209 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Return"); (yyval.no)->child = (yyvsp[-1].no);if(debug)printf("Statement6\n");}
#line 1789 "y.tab.c"
    break;

  case 43: /* Statement: RETURN SEMICOLON  */
#line 210 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Return");if(debug)printf("Statement7\n");}
#line 1795 "y.tab.c"
    break;

  case 44: /* Statement: MethodInvocation SEMICOLON  */
#line 211 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[-1].no);if(debug)printf("Statement8\n");}
#line 1801 "y.tab.c"
    break;

  case 45: /* Statement: Assignment SEMICOLON  */
#line 212 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[-1].no);if(debug)printf("Statement9\n");}
#line 1807 "y.tab.c"
    break;

  case 46: /* Statement: ParseArgs SEMICOLON  */
#line 213 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[-1].no);if(debug)printf("Statement10\n");}
#line 1813 "y.tab.c"
    break;

  case 47: /* Statement: SEMICOLON  */
#line 214 "jucompiler.y"
                                                                                {;if(debug)printf("Statement11\n");}
#line 1819 "y.tab.c"
    break;

  case 48: /* Statement: PRINT LPAR Expr RPAR SEMICOLON  */
#line 215 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Print"); (yyval.no)->child = (yyvsp[-2].no);if(debug)printf("Statement12\n");}
#line 1825 "y.tab.c"
    break;

  case 49: /* Statement: PRINT LPAR STRLIT RPAR SEMICOLON  */
#line 216 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Print"); sprintf(aux3, "StrLit(\"%s\")", (yyvsp[-2].id)); (yyval.no)->child = createNode(strdup(aux3));if(debug)printf("Statement13\n");}
#line 1831 "y.tab.c"
    break;

  case 50: /* Statement: PRINT LPAR RPAR SEMICOLON  */
#line 217 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Print");if(debug)printf("Statement14\n");}
#line 1837 "y.tab.c"
    break;

  case 51: /* Statement: error SEMICOLON  */
#line 218 "jucompiler.y"
                                                                                {hasError=true;if(debug)printf("Statement15\n");}
#line 1843 "y.tab.c"
    break;

  case 52: /* recSTAT: Statement  */
#line 221 "jucompiler.y"
                                                                                {(yyval.no)=(yyvsp[0].no);}
#line 1849 "y.tab.c"
    break;

  case 53: /* recSTAT: recSTAT Statement  */
#line 222 "jucompiler.y"
                                                                                {if((yyvsp[-1].no)!=NULL){(yyval.no)=(yyvsp[-1].no); newBrother((yyvsp[-1].no),(yyvsp[0].no));} else{(yyval.no)=(yyvsp[0].no);}}
#line 1855 "y.tab.c"
    break;

  case 54: /* MethodInvocation: ID LPAR Expr recCOMMAEXP RPAR  */
#line 224 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Call"); sprintf(aux3, "Id(%s)", (yyvsp[-4].id)); (yyval.no)->child = createNode(strdup(aux3)); newBrother((yyval.no)->child, (yyvsp[-2].no)); newBrother((yyvsp[-2].no), (yyvsp[-1].no));if(debug)printf("MethodInvocation\n");}
#line 1861 "y.tab.c"
    break;

  case 55: /* MethodInvocation: ID LPAR Expr RPAR  */
#line 225 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Call"); sprintf(aux3, "Id(%s)", (yyvsp[-3].id)); (yyval.no)->child = createNode(strdup(aux3)); newBrother((yyval.no)->child, (yyvsp[-1].no));if(debug)printf("MethodInvocation2\n");}
#line 1867 "y.tab.c"
    break;

  case 56: /* MethodInvocation: ID LPAR RPAR  */
#line 226 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Call"); sprintf(aux3, "Id(%s)", (yyvsp[-2].id)); (yyval.no)->child = createNode(strdup(aux3));if(debug)printf("MethodInvocation3\n");}
#line 1873 "y.tab.c"
    break;

  case 57: /* MethodInvocation: ID LPAR error RPAR  */
#line 227 "jucompiler.y"
                                                                                {hasError=true;if(debug)printf("MethodInvocation4\n");}
#line 1879 "y.tab.c"
    break;

  case 58: /* recCOMMAEXP: recCOMMAEXP COMMA Expr  */
#line 230 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[-2].no); newBrother((yyvsp[-2].no), (yyvsp[0].no));if(debug)printf("recCOMMAEXP\n");}
#line 1885 "y.tab.c"
    break;

  case 59: /* recCOMMAEXP: COMMA Expr  */
#line 231 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[0].no);if(debug)printf("recCOMMAEXP2\n");}
#line 1891 "y.tab.c"
    break;

  case 60: /* Assignment: ID ASSIGN Expr  */
#line 234 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Assign"); sprintf(aux3, "Id(%s)", (yyvsp[-2].id)); (yyval.no)->child = createNode(strdup(aux3)); newBrother((yyval.no)->child, (yyvsp[0].no));if(debug)printf("Assign\n");}
#line 1897 "y.tab.c"
    break;

  case 61: /* ParseArgs: PARSEINT LPAR ID LSQ Expr RSQ RPAR  */
#line 237 "jucompiler.y"
                                                                                {(yyval.no) = createNode("ParseArgs"); sprintf(aux3, "Id(%s)", (yyvsp[-4].id)); (yyval.no)->child = createNode(strdup(aux3)); newBrother((yyval.no)->child, (yyvsp[-2].no));if(debug)printf("ParseArgs + id(%s)\n",aux3);}
#line 1903 "y.tab.c"
    break;

  case 62: /* ParseArgs: PARSEINT LPAR error RPAR  */
#line 238 "jucompiler.y"
                                                                                {(yyval.no) = NULL;hasError=true;if(debug)printf("ParseArgs2\n");}
#line 1909 "y.tab.c"
    break;

  case 63: /* Expr: Expr PLUS Expr  */
#line 241 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Add"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("PLUS\n");}
#line 1915 "y.tab.c"
    break;

  case 64: /* Expr: Expr MINUS Expr  */
#line 242 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Sub"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("MINUS\n");}
#line 1921 "y.tab.c"
    break;

  case 65: /* Expr: Expr STAR Expr  */
#line 243 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Mul"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("STAR\n");}
#line 1927 "y.tab.c"
    break;

  case 66: /* Expr: Expr DIV Expr  */
#line 244 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Div"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("DIV\n");}
#line 1933 "y.tab.c"
    break;

  case 67: /* Expr: Expr MOD Expr  */
#line 245 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Mod"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("MOD\n");}
#line 1939 "y.tab.c"
    break;

  case 68: /* Expr: Expr AND Expr  */
#line 246 "jucompiler.y"
                                                                                {(yyval.no) = createNode("And"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("AND\n");}
#line 1945 "y.tab.c"
    break;

  case 69: /* Expr: Expr OR Expr  */
#line 247 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Or"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("OR\n");}
#line 1951 "y.tab.c"
    break;

  case 70: /* Expr: Expr XOR Expr  */
#line 248 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Xor"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("XOR\n");}
#line 1957 "y.tab.c"
    break;

  case 71: /* Expr: Expr LSHIFT Expr  */
#line 249 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Lshift"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("LSHIFT\n");}
#line 1963 "y.tab.c"
    break;

  case 72: /* Expr: Expr RSHIFT Expr  */
#line 250 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Rshift"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("RSHIFT\n");}
#line 1969 "y.tab.c"
    break;

  case 73: /* Expr: Expr EQ Expr  */
#line 251 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Eq"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("EQ\n");}
#line 1975 "y.tab.c"
    break;

  case 74: /* Expr: Expr GE Expr  */
#line 252 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Ge"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("GE\n");}
#line 1981 "y.tab.c"
    break;

  case 75: /* Expr: Expr GT Expr  */
#line 253 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Gt"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("GT\n");}
#line 1987 "y.tab.c"
    break;

  case 76: /* Expr: Expr LE Expr  */
#line 254 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Le"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("LE\n");}
#line 1993 "y.tab.c"
    break;

  case 77: /* Expr: Expr LT Expr  */
#line 255 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Lt"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("LT\n");}
#line 1999 "y.tab.c"
    break;

  case 78: /* Expr: Expr NE Expr  */
#line 256 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Ne"); (yyval.no)->child=(yyvsp[-2].no); newBrother((yyvsp[-2].no),(yyvsp[0].no));if(debug)printf("NE\n");}
#line 2005 "y.tab.c"
    break;

  case 79: /* Expr: MINUS Expr  */
#line 257 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Minus"); (yyval.no)->child=(yyvsp[0].no);if(debug)printf("MINUS2\n");}
#line 2011 "y.tab.c"
    break;

  case 80: /* Expr: PLUS Expr  */
#line 258 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Plus"); (yyval.no)->child=(yyvsp[0].no);if(debug)printf("PLUS2\n");}
#line 2017 "y.tab.c"
    break;

  case 81: /* Expr: NOT Expr  */
#line 259 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Not"); (yyval.no)->child=(yyvsp[0].no);if(debug)printf("NOT\n");}
#line 2023 "y.tab.c"
    break;

  case 82: /* Expr: LPAR Expr RPAR  */
#line 260 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[-1].no);if(debug)printf("EXPR\n");}
#line 2029 "y.tab.c"
    break;

  case 83: /* Expr: MethodInvocation  */
#line 261 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[0].no);if(debug)printf("MI\n");}
#line 2035 "y.tab.c"
    break;

  case 84: /* Expr: Assignment  */
#line 262 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[0].no);if(debug)printf("ASS\n");}
#line 2041 "y.tab.c"
    break;

  case 85: /* Expr: ParseArgs  */
#line 263 "jucompiler.y"
                                                                                {(yyval.no) = (yyvsp[0].no);if(debug)printf("PA\n");}
#line 2047 "y.tab.c"
    break;

  case 86: /* Expr: ID  */
#line 264 "jucompiler.y"
                                                                                {sprintf(aux3, "Id(%s)", (yyvsp[0].id)); (yyval.no) = createNode(strdup(aux3));if(debug)printf("%s_ID111\n", aux3);}
#line 2053 "y.tab.c"
    break;

  case 87: /* Expr: ID DOTLENGTH  */
#line 265 "jucompiler.y"
                                                                                {(yyval.no) = createNode("Length"); sprintf(aux3, "Id(%s)", (yyvsp[-1].id)); (yyval.no)->child = createNode(strdup(aux3));if(debug)printf("DOT\n");}
#line 2059 "y.tab.c"
    break;

  case 88: /* Expr: INTLIT  */
#line 266 "jucompiler.y"
                                                                                {sprintf(aux3, "DecLit(%s)", (yyvsp[0].id)); (yyval.no) = createNode(strdup(aux3));if(debug)printf("DEC2\n");}
#line 2065 "y.tab.c"
    break;

  case 89: /* Expr: REALLIT  */
#line 267 "jucompiler.y"
                                                                                {sprintf(aux3, "RealLit(%s)", (yyvsp[0].id)); (yyval.no) = createNode(strdup(aux3));if(debug)printf("REAL2\n");}
#line 2071 "y.tab.c"
    break;

  case 90: /* Expr: BOOLLIT  */
#line 268 "jucompiler.y"
                                                                                {sprintf(aux3, "BoolLit(%s)", (yyvsp[0].id)); (yyval.no) = createNode(strdup(aux3));if(debug)printf("BOOL2\n");}
#line 2077 "y.tab.c"
    break;

  case 91: /* Expr: LPAR error RPAR  */
#line 269 "jucompiler.y"
                                                                                {hasError=true;if(debug)printf("666\n");}
#line 2083 "y.tab.c"
    break;


#line 2087 "y.tab.c"

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

#line 273 "jucompiler.y"



