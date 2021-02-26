#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"




int main(void){
	NodeType * L = Create();
	InsertNewLastNode(3 ,L);
	InsertNewLastNode(11,L);
	InsertNewLastNode(9,L);
	InsertNewLastNode(7,L);
	InsertNewLastNode(34,L);
	InsertNewLastNode(666,L);
	InsertNewLastNode(23,L);
	InsertNewLastNode(70,L);
	InsertNewLastNode(8,L);
	InsertNewLastNode(56,L);
	InsertNewLastNode(4,L);
	PrintList(L,"%d");
	MergeSort(&L);
	PrintList(L,"%d");
	Delete(L);

	
}
