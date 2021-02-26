#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"




int main(void){
	
	NodeType * L = Create();
	PrintList(L);
	InsertNewLastNode("AAA",L);
	PrintList(L);
	InsertNewLastNode("BBB",L);
	PrintList(L);
	InsertNewLastNode("CCC",L);
	PrintList(L);
	DeleteLastNode(L);
	PrintList(L);
	NodeType * N = ListSearch("BBB", L);
	InsertAfterNode (L, "DDD", N);
	DeleteNode(L,N);
	PrintList(L);
	Delete(L);
	
	
	
}
