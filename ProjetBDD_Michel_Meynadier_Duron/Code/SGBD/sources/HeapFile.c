/*
 * Fichier HeapFile.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/BufferManager.h"
#include "../headers/HeapFile.h"
#include "../headers/PageId.h"
#include "../headers/GlobalManager.h"
#include "../headers/Constante.h"




/*
 * Fonction createHeader : Création d'une HeaderPage
 * Param HeapFile : HeapFile
*/
void createHeader(struct HeapFile hf){
	int idX = addPage(hf.ptrRelDef->FileId);
	PageId pageHeapFile = {hf.ptrRelDef->FileId, idX};
	char *buffer = malloc(sizeof(char)*TAILLE);
	buffer="0";
	writePage(pageHeapFile, buffer);
	getPage(pageHeapFile);
	freePage(pageHeapFile, '1');
}

/*
int main(){

	initStruct();
	struct RelSchema k = {"insert", 3, "table1"};
	struct RelDef a={k, 6};
	struct RelDef *b= &a;
	struct DbDef def={b, 3};
	printf("compteur de relations: %d\n", def.compteurRelations);
	struct HeapFile hf = {b};
	createHeader(hf);
	

	return 0;
}
*/