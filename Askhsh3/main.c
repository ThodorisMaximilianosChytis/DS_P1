#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"




int main(void){
	
	NodeType * L1 = Create();
	NodeType * L2 = Create();
	InsertNewLastNode(1,L1);
	InsertNewLastNode(3,L1);
	InsertNewLastNode(9,L1);
	PrintList(L1,"%d");
	
	
	
	
	InsertNewLastNode(2,L2);
	InsertNewLastNode(4,L2);
	InsertNewLastNode(5,L2);
	PrintList(L2,"%d");
	
	L1 = Merge (L1, L2);
	PrintList(L1,"%d");
	
	Delete(L1);
	

	
	
	
}
