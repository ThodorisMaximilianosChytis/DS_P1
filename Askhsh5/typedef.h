#include <stdio.h>




typedef char item[18];
typedef item ItemType;
typedef struct NodeTag {
                        ItemType item;
                        struct NodeTag *Linknext;
                } NodeType;
