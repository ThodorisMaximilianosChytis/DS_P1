#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"




NodePointer Create(void){
	NodeType *N;
	N=(NodeType *)malloc(sizeof(NodeType));
	char *A= "!!!";
	strcpy(N->Airport, A);
	NodeType *P;
	P=(NodeType *)malloc(sizeof(NodeType));
	A= "!!!";
	strcpy(P->Airport, A);
	N->Linknext=P;
	N->Linkbefore=NULL;
	P->Linknext=NULL;
	P->Linkbefore=N;
	return N;
}

void Delete(NodeType * L){
	NodeType * N, *temp;
	N=L;
	while(N!=NULL){
		temp=N->Linknext;
		printf("deleting node with item %s \n", N->Airport );
		free(N);
		N=temp;
	}
}

NodeType * GetLast(NodeType * LB){
	while (LB->Linknext != NULL) LB=LB->Linknext;
	return LB; 		// return LE
}

void InsertNewLastNode(char *A, NodeType *LE)
{
    NodeType *N, *P;

    N=(NodeType *)malloc(sizeof(NodeType));
    strcpy(N->Airport, A);
	LE->Linkbefore->Linknext=N;
	N->Linknext=LE;
	N->Linkbefore=LE->Linkbefore;
	LE->Linkbefore=N;
}



void PrintList(NodeType *L, char *format)
{
      NodeType *N;
      N=L->Linknext;
      if (N==NULL)
      	return;
      printf("(");
      while(N->Linknext != NULL) {
         printf(format , N->Airport);
         N=N->Linknext;
         if (N->Linknext!=NULL) printf(",");
      }
      printf(")\n");
}


void DeleteLastNode(NodeType *LE)
{
      NodeType *temp;
		
		if ((LE->Linkbefore)->Linkbefore==NULL){
			printf("only dummy nodes in  this list \n");
		}else{
			LE->Linkbefore->Linkbefore->Linknext=LE;
			temp=LE->Linkbefore;
			LE->Linkbefore=LE->Linkbefore->Linkbefore;
			free(temp);
		}
}


void DeleteNode(NodeType *L, NodeType * N)
{
	if (N!=NULL){
		if (L->Linknext!=NULL){
			N->Linkbefore->Linknext=N->Linknext;
			N->Linknext->Linkbefore=N->Linkbefore;
			free(N);
		}
	}else printf("Node was not found so could not be deleted\n");
		
}



void InsertAfterNode (NodeType *L, char * A, NodeType *P)
{
	if (P!=NULL){
	    NodeType *N;
	    N=(NodeType *)malloc(sizeof(NodeType));
	    strcpy(N->Airport,A);
	    if (P->Linknext!=NULL){
	    	N->Linknext=P->Linknext;
	    	N->Linkbefore=P;
	    	P->Linknext->Linkbefore=N;
			P->Linknext=N;
		}else{
		 	free(N);
			InsertNewLastNode(A,GetLast(L));
		}
	}
}

void InsertBeforeNode (NodeType *L, char * A, NodeType *P)
{
	if (P!=NULL){
	    NodeType *N, *temp;
	    N=(NodeType *)malloc(sizeof(NodeType));
	    strcpy(N->Airport,A);
	    if (P->Linknext!=NULL){
	    	N->Linknext=P;
			N->Linkbefore = P->Linkbefore;
			P->Linkbefore->Linknext=N;
			P->Linkbefore=N;	
		}else{
		 	free(N);
			InsertNewLastNode(A,GetLast(L));
		}
	}
}

NodeType * ListSearch( NodeType *L, ItemType item, CompareType compare)
{
      NodeType *N;

      N=L->Linknext;
      
      while (N != NULL){
        if (compare(item, N->Airport)==0){
           return N;
        } else {
           N=N->Linknext;
        }
      }
      return N;
}
int Compare(ItemType a, ItemType b){
	if (strcmp(a,b)==0)
		return 0;
	else 
		return 1;	
}

