
#include "STree.h"


struct node * createNode(char * value, char * var) {
    node * aux2 = (node *) malloc(sizeof(node));

    aux2->var = var;
    aux2->value = value;
    aux2->brother = NULL;
    aux2->child = NULL;

    return aux2;

}

void newBrother(struct node* old, struct node* newn) {

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

int numBrothers(struct node * no) {
		int count = 0;
		struct node * aux;
		aux = no;
		while (aux != NULL) {
			aux = aux->brother;
			count++;
		}
		return count;
}


