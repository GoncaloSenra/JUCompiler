
#include "STree.h"

typedef struct sym{
    char * name;
    char * type;
    char * param;
    struct sym * prev;
    struct sym * next;
    struct sym * in;
    int variable;
    int line;
    int col;
}Sym;


Sym * createSym(char * name, char * type, char * param, int line, int col, int variable);
Sym * CheckIfAlreadyDefined(Sym * simTab, char * name, int aux);
void printTable(Sym * elem);
void MethodDecl(Sym * last, Sym * first, struct node * root);
void Header(struct node * root, Sym * first);
char* myStrCat(char* s1, char* s2/*, bool free1, bool free2*/);
void Vardecl (struct node * root, Sym * func);
void FieldDecl (struct node * root, Sym * last, Sym * first, int aux);
Sym * insertSym(Sym * last, Sym * new);
void createTable (Sym * last, struct node * root);
char * tolower_word(char * param);


void checkTypes(struct node * root, Sym * first, char * name);

void checkOneMemberOperationNL(struct node * root, Sym * first, char * name);

char * searchType(struct node * root, Sym * first, char * name, char * type);