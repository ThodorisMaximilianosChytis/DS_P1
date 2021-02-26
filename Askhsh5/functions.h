#include <stdio.h>
#include "typedef.h"




void InsertNewLastNode(char *, NodeType *);
void DeleteLastNode(NodeType *);
NodeType *ListSearch(char * , NodeType *);
void PrintList(NodeType *, char *);
NodeType * Create(void);
void DeleteNode(NodeType *, NodeType* );
void InsertAfterNode (NodeType *, char * , NodeType *);
NodeType * SortedMerge( NodeType * , NodeType *);
void Delete(NodeType *);
void MergeSort(NodeType ** );
static int myCompare(const void* , const void* );
void sort( char** , int) ;
int binsearch(char *, int , char **);
NodeType * Similar(char *);


