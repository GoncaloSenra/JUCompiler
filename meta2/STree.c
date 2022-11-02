
#include "STree.h"


node * createNode(char * var) {
    node * aux = (node *) malloc(sizeof(node));

    aux->var = var;
    aux->brother = NULL;
    aux->child = NULL;

    return aux;

}

void newBrother(node* old, node* newn) {

    node * aux;

    /*
    for (aux = old; aux->brother == NULL; aux = aux->brother){

    }
    */

    while (aux->brother != NULL)
        aux = aux->brother;

    aux->brother = newn;

    return;
}

