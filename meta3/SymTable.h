
#include "STree.h"

typedef struct sym{
    char * name;
    char * type;
    char * param;
    struct sym * next;
    struct sym * in;
    int variable;
    int auxparam;
    int line;
    int col;
}Sym;


Sym * createSym(char * name, char * type, char * param, int line, int col, int variable);
Sym * CheckIfAlreadyDefined(Sym * simTab, char * name, int aux, int flag);
void printTable(Sym * elem);
int MethodDecl(Sym * last, Sym * first, struct node * root);
void Header(struct node * root, Sym * first);
char* StringCat(char* s1, char* s2);
void Vardecl (struct node * root, Sym * func);
void FieldDecl (struct node * root, Sym * last, Sym * first, int aux);
void createTable (Sym * last, struct node * root);
char * tolower_word(char * param);

void Calls(struct node * root, Sym * first, char * name);


void checkTypes(struct node * root, Sym * first, char * name);

void OneMemberNL(struct node * root, Sym * first, char * name, int flag);

char * searchType(struct node * root, Sym * first, char * name, char * id, int line, int val);

int isVAR(struct node * root);

void TwoMember(struct node * root, Sym * first, char * name, int flag);

int checkParameters(char * param, char * auxparam);

char * Operadores(char* string);