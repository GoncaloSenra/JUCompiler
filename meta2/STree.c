
#include "STree.h"


node * createNode(char * var) {
    node * aux = (node *) malloc(sizeof(node));

    aux->var = var;
    aux->brother = NULL;
    aux->child = NULL;

    return aux;

}

void newBrother(node* old, node* newn) {

    while (old->brother != NULL)
        old = old->brother;

    old->brother = newn;

    return;
}

