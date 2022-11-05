
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct node{
    char * var;
    struct node * brother;
    struct node * child;
}node;

node * createNode(char * var);

void newBrother(node* old, node* newn);

void printSTree(struct node *node, int prof);

void freeSTree(struct node *node);