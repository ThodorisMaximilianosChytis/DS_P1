#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"




NodePointer Create(void){
	NodeType *N;
	N=(NodeType *)malloc(sizeof(NodeType));
	char *A= "!!!";
	strcpy(N->Airport, A);
	N->Link=NULL;
}

void Delete(NodeType * L){
	NodeType * N, *temp;
	N=L;
	while(N!=NULL){
		temp=N->Link;
		printf("deleting node with item %s \n", N->Airport );
		free(N);
		N=temp;
	}
}

void InsertNewLastNode(char *A, NodeType *L)
{
    NodeType *N, *P;

    N=(NodeType *)malloc(sizeof(NodeType));
    strcpy(N->Airport, A);
    N->Link=NULL;

    while (L->Link != NULL) L=L->Link;
    L->Link=N;
}



void PrintList(NodeType *L)
{
      NodeType *N;
      N=L->Link;
      if (N==NULL)
      	return;
      printf("(");
      while(N != NULL) {
         printf("%s", N->Airport);
         N=N->Link;
         if (N!=NULL) printf(",");
      }
      printf(")\n");
}


void DeleteLastNode(NodeType *L)
{
      NodeType *PreviousNode, *CurrentNode;
		
		PreviousNode=L;
     	L=L->Link;
     	if (L!=NULL){
	         if (L->Link == NULL){
	            PreviousNode->Link=NULL;
	            free(L);
	     	}
	        else {
	            PreviousNode=L;
	            CurrentNode=L->Link;
	            
	            while (CurrentNode->Link != NULL){
	               PreviousNode=CurrentNode;
	               CurrentNode=CurrentNode->Link;
	            }
	            PreviousNode->Link=NULL;
	            free(CurrentNode);
	        }
	    }
}


void DeleteNode(NodeType *L, NodeType * N)
{
	NodeType *PreviousNode, *CurrentNode;
	if (L->Link!=NULL){
		PreviousNode=L;
	    CurrentNode=L->Link;
		while (CurrentNode != N && CurrentNode!=NULL){
	    	PreviousNode=CurrentNode;
	        CurrentNode=CurrentNode->Link;
	    }
	    if (CurrentNode!=NULL){
	    	PreviousNode->Link=CurrentNode->Link;
			free(N);
		}
		else printf("Node was not found so could not be deleted\n");
	}
}



void InsertAfterNode (NodeType *L, char * A, NodeType *P)
{
	if (P!=NULL){
	    NodeType *N, *temp;
	    N=(NodeType *)malloc(sizeof(NodeType));
	    strcpy(N->Airport,A);
	    if (P->Link!=NULL){
	    	N->Link=P->Link;
			P->Link=N;
		}else{
		 	free(N);
			InsertNewLastNode(A,L);
		}
 	}
}



NodeType * ListSearch(char *A, NodeType *L)
{
      NodeType *N;

      N=L->Link;
      while (N != NULL){
        if (strcmp(N->Airport,A)==0){
           return N;
        } else {
           N=N->Link;
        }
      }
      return N;
}
