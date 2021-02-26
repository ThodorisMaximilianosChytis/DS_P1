#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "functions.h"




int main(void){
	NodeType * L; 
	L=Similar("art");
	PrintList(L,"%s");
	Delete(L);

	
}
