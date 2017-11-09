/*
 * Création des Structures
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/RelDef.h"
#include "../headers/HeapFile.h"
#include "../headers/PageId.h"

void createHeader(struct HeapFile hf){
	addPage(hf.ptrRelDef->FileId);

}


int main(){
	return 0;
}
