
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define true 1
#define false 0

typedef struct node{
    char * var;
    char * value;
    struct node * brother;
    struct node * child;
}node;

struct node * createNode(char * value, char * var);

void newBrother(struct node * old, struct node * newn);

void printSTree(struct node * node, int prof);

void freeSTree(struct node * node);

int numBrothers(struct node * no);
