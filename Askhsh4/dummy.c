#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
#include "functions.h"




NodeType * Create(void){
	NodeType *N;
	N=(NodeType *)malloc(sizeof(NodeType));
	int A = INT_MAX;
	N->item = A ;
	N->Linknext=NULL;
	return N;
}


void Delete(NodeType * L){
	NodeType * N, *temp;
	N=L;
	while(N!=NULL){
		temp=N->Linknext;
		printf("deleting node with item %d \n", N->item );
		free(N);
		N=temp;
	}
}


void InsertNewLastNode(int A, NodeType *L)
{
    NodeType *N, *P;

    N=(NodeType *)malloc(sizeof(NodeType));
    N->item=A;
    N->Linknext=NULL;

    while (L->Linknext != NULL) L=L->Linknext;
    L->Linknext=N;
}




void PrintList(NodeType *L, char *format)
{
      NodeType *N;
      
      N=L->Linknext;
      if (N==NULL)
      	return;
      printf("(");
      while(N != NULL) {
         printf(format , N->item);
         N=N->Linknext;
         if (N!=NULL) printf(",");
      }
      printf(")\n");
}



void DeleteLastNode(NodeType *L)
{
      NodeType *PreviousNode, *CurrentNode;
		
		PreviousNode=L;
     	L=L->Linknext;
     	if (L!=NULL){
	         if (L->Linknext == NULL){
	            PreviousNode->Linknext=NULL;
	            free(L);
	     	}
	        else {
	            PreviousNode=L;
	            CurrentNode=L->Linknext;
	            
	            while (CurrentNode->Linknext != NULL){
	               PreviousNode=CurrentNode;
	               CurrentNode=CurrentNode->Linknext;
	            }
	            PreviousNode->Linknext=NULL;
	            free(CurrentNode);
	        }
	    }
}


void DeleteNode(NodeType *L, NodeType * N)
{
	NodeType *PreviousNode, *CurrentNode;
	if (L->Linknext!=NULL){
		PreviousNode=L;
	    CurrentNode=L->Linknext;
		while (CurrentNode != N && CurrentNode!=NULL){
	    	PreviousNode=CurrentNode;
	        CurrentNode=CurrentNode->Linknext;
	    }
	    if (CurrentNode!=NULL){
	    	PreviousNode->Linknext=CurrentNode->Linknext;
			free(N);
		}
		else printf("Node was not found so could not be deleted\n");
	}
}



void InsertAfterNode (NodeType *L, int A, NodeType *P)
{
	if (P!=NULL){
	    NodeType *N, *temp;
	    N=(NodeType *)malloc(sizeof(NodeType));
	    N->item=A;
	    if (P->Linknext!=NULL){
	    	N->Linknext=P->Linknext;
			P->Linknext=N;
		}else{
		 	free(N);
			InsertNewLastNode(A,L);
		}
 	}
}



NodeType * ListSearch(int A, NodeType *L)
{
      NodeType *N;

      N=L->Linknext;
      while (N != NULL){
        if (N->item==A){
           return N;
        } else {
           N=N->Linknext;
        }
      }
      return N;
}


void Split(NodeType *L, NodeType * A , NodeType * B){
	NodeType * fast, * slow;
	 fast=L;
	 slow=L;
	 while (fast != NULL) 
    { 
    	fast = fast->Linknext; 
    	if (fast != NULL) 
    	{ 
        	slow = slow->Linknext; 
        	fast = fast->Linknext; 
    	} 
    } 
	A->Linknext = L->Linknext;
	B->Linknext = slow->Linknext;
	slow->Linknext = NULL;
}

void MergeSort (NodeType ** L ){
	if ((*L)->Linknext==NULL || (*L)->Linknext->Linknext ==NULL ){
		return;
		
	}
	NodeType * L1 = Create();
	NodeType * L2 = Create();
	Split(*L,L1,L2);
	
	MergeSort (&L1);
	MergeSort (&L2);
	*L=SortedMerge(L1,L2);
}

NodeType * SortedMerge( NodeType * A , NodeType * B){
	NodeType * Ntemp,  *temp  , * N ;  
	NodeType * HEAD;
			if (A->Linknext->item < B->Linknext->item){
				N = A;
				Ntemp=B;
				HEAD = A;
			}else{
				N = B;
				Ntemp=A;
				HEAD= B;
			}
			while (1){
				while(N->Linknext->item <= Ntemp->Linknext->item ){
					N = N->Linknext;
					if (N->Linknext==NULL)
						break;
				}
				if (N->Linknext!=NULL){
					temp=N->Linknext;
					N->Linknext=Ntemp->Linknext;
					Ntemp->Linknext=temp;
				}
				else{
					N->Linknext=Ntemp->Linknext;
					break;
				}
			}
			if (A->Linknext->item < B->Linknext->item){
				free(B);
			}else{
				free(A);
			}
			return  HEAD;
}
