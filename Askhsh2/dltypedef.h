#include <stdio.h>





typedef char AirportCode[4] ;
typedef AirportCode ItemType;
typedef int (*CompareType)(ItemType a, ItemType b);
typedef struct NodeTag {
                        ItemType Airport;
                        struct NodeTag *Linknext;
                        struct NodeTag *Linkbefore;
                } NodeType;
typedef NodeType *NodePointer;
