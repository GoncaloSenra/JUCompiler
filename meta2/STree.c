
#include "STree.h"


node * createNode(char * var) {
    node * aux2 = (node *) malloc(sizeof(node));

    aux2->var = var;
    aux2->brother = NULL;
    aux2->child = NULL;

    return aux2;

}

void newBrother(node* old, node* newn) {

    while (old->brother != NULL)
        old = old->brother;

    old->brother = newn;

    return;
}

void printSTree(struct node *node, int prof){
    char pontos [prof * 2];

    for (int i = 0; i < prof * 2; i++){
        pontos[i]='.';
    }
    pontos [2 * prof] = '\0';

    printf("%s%s\n", pontos, node->var);
    if (node->child)    printSTree(node->child, prof + 1);
    if (node->brother)  printSTree(node->brother, prof);

    free(node);
}


void freeSTree(struct node *node){
    if (node->child)    freeSTree(node->child);
    if (node->brother)  freeSTree(node->brother);

    free(node);
}