
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

void printASTree(struct node *node, int depth){
    char dots[depth*2];
    for (int i = 0; i<depth*2; i++){
        dots[i]='.';
    }
    dots[2*depth]='\0';

    printf("%s%s\n",dots,node->var);
    if (node->child)    printASTree(node->child, depth+1);
    if (node->brother)  printASTree(node->brother, depth);

    //if printTree and hasError==False limpa a memória depois de printar!!
    free(node);
}


void freeASTree(struct node *node){
    if (node->child)    freeASTree(node->child);
    if (node->brother)  freeASTree(node->brother);

    //if printTree and hasError==False limpa a memória depois de printar!!
    free(node);
}