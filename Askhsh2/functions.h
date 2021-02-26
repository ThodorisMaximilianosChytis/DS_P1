#include <stdio.h>
#include "dltypedef.h"




void InsertBeforeNode(NodeType *, char * , NodeType *);
void InsertNewLastNode(char *, NodeType *);
void DeleteLastNode(NodeType *);
void PrintList(NodeType *, char *);
NodePointer Create(void);
void DeleteNode(NodeType *, NodeType* );
void InsertAfterNode (NodeType *, char * , NodeType *);
NodeType * ListSearch(NodeType * , ItemType , CompareType);
int Compare(ItemType, ItemType);
void Delete(NodeType *);
NodeType * GetLast(NodeType *);
