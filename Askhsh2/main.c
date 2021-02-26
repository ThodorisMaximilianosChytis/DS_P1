#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"




int main(void){
	CompareType compare;
	compare = Compare;
	NodeType * L = Create();
	NodeType * LE = GetLast(L);
	InsertNewLastNode("AAA",LE);
	PrintList(L,"%s");
	DeleteLastNode(LE);
	PrintList(L,"%s");
	InsertNewLastNode("BBB",LE);
	InsertNewLastNode("CCC",LE);
	InsertNewLastNode("DDD",LE);
	PrintList(L,"%s");
	NodeType * N = ListSearch(L, "BBB" , compare);
	InsertAfterNode (L, "III", N);
	N = ListSearch(L, "DDD" , compare);
	InsertBeforeNode (L, "III", N);
	PrintList(L,"%s");
	Delete(L);
	
	
}
