
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <locale.h>

#define true 1
#define false 0


typedef struct node{
    char * var;
    char * value;
    char * anotation;
    struct node * brother;
    struct node * child;
    int line;
    int col;

    int valid;
}node;

struct node * createNode(char * value, char * var, int line, int col);

void newBrother(struct node * old, struct node * newn);

void printSTree(struct node * node, int prof);

void freeSTree(struct node * node);

int numBrothers(struct node * no);
