#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"




NodeType * Create(void){
	NodeType *N;
	N=(NodeType *)malloc(sizeof(NodeType));
	char *A= "!!!";
	strcpy(N->item, A);
	N->Linknext=NULL;
}

void Delete(NodeType * L){
	NodeType * N, *temp;
	N=L;
	while(N!=NULL){
		temp=N->Linknext;
		printf("deleting node with item %s \n", N->item);
		free(N);
		N=temp;
	}
}

void InsertNewLastNode(char *A, NodeType *L)
{
    NodeType *N, *P;

    N=(NodeType *)malloc(sizeof(NodeType));
    strcpy(N->item, A);
    N->Linknext=NULL;

    while (L->Linknext != NULL) L=L->Linknext;
    L->Linknext=N;
}



void PrintList(NodeType *L, char *format)
{
      NodeType *N;
      N=L->Linknext;
      if (N==NULL) return;
      printf("(");
      while(N->Linknext != NULL) {
         printf(format , N->item);
         N=N->Linknext;
         if (N->Linknext!=NULL) printf(",");
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



void InsertAfterNode (NodeType *L, char * A, NodeType *P)
{
	if (P!=NULL){
	    NodeType *N, *temp;
	    N=(NodeType *)malloc(sizeof(NodeType));
	    strcpy(N->item,A);
	    if (P->Linknext!=NULL){
	    	N->Linknext=P->Linknext;
			P->Linknext=N;
		}else{
		 	free(N);
			InsertNewLastNode(A,L);
		}
 	}
}



NodeType * ListSearch(char *A, NodeType *L)
{
      NodeType *N;

      N=L->Linknext;
      while (N != NULL){
        if (strcmp(N->item,A)==0){
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

NodeType * Similar(char * word ){
	FILE *pfile=fopen("words.txt","r");
	int count=0;
	char str[18];
	NodeType * L = Create();
	if (pfile==NULL){
		printf("Error opening file\n");
		return L;
	}
	while (fgets(str,18,pfile)!=NULL){
		count++;
	}
	printf("words has %d words \n", count);
	rewind(pfile);
	char ** dictionary;
	dictionary = (char **)malloc(count * sizeof(char *));
	int i=0;
	while (fgets(str,18,pfile)!=NULL){
		dictionary[i] = strdup(str); 
		i++;
	}
	sort(dictionary,count);
	int j;
	char  k;
	j=0 ;
	int found , l=strlen(word)+2;
	strcpy(str,word);
	while (j<strlen(word)){
		str[l-2]='\n';
		str[l-1]='\0';
		for (k = 'a' ; k <= 'z' ; k++){
			str[j]=k;
				if  ((found=binsearch(str,count,dictionary))!=0){
					strcpy(str,word);
					str[l-2]='\n';
					str[l-1]='\0';
					if (strcmp(str,dictionary[found])!=0){
						InsertNewLastNode(dictionary[found],L);
					}
				}
		}
		j++;
		strcpy(str,word);
		}
	for (i=0; i<count ; i++)
		free (dictionary[i]);
	free(dictionary);
	return L;
}


int myCompare( const void* a,  const void* b) 
{ 
  
    return strcmp(*(const char**)a, *(const char**)b); 
} 

void sort(char* arr[], int n) 
{ 
    qsort(arr, n, sizeof( char*), myCompare); 
} 


int binsearch(char *w, int n, char **x){
	int cond, low, high, mid;
	low = 0; 
	high = n-1; 
	while (low <= high) { 
		mid = (low+high)/2; 
		if ((cond = strcmp(w, x[mid])) < 0) 
			high = mid-1; 
		else if (cond > 0)
			low = mid+1; 
		else {
			return mid;
		}
	} 
	return 0; 
	
}


