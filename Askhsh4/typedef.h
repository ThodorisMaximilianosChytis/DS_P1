#include <stdio.h>




typedef int ItemType;
typedef struct NodeTag {
                        ItemType item;
                        struct NodeTag *Linknext;
                } NodeType;
