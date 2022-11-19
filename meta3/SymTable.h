


typedef struct sym{
    char * name;
    char * type;
    char * param;
    struct sym * prev;
    struct sym * next;
    struct sym * child;
    int placed;
    //int line;
    //int col;
}Sym;