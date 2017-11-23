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
#include "../headers/HeaderPageInfo.h"



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
 * Fonction ajouterEnFin : Ajout d'un HeapFile a là fin d'une liste chainee ListeHeapFile
 * Param ListeHeapFile
 * Param  HeapFile
 */
void ajouterEnFin(struct ListeHeapFile *liste, struct HeapFile hf){
	ListeHeapFile *nouvelHf = malloc(sizeof(*nouvelHf));
	nouvelHf->present = hf;
	nouvelHf->nxt = NULL;
	if(liste == NULL){
		liste = nouvelHf;
	}
	else
	{
		ListeHeapFile* temp=liste;
		while(temp->nxt != NULL)
		{
			temp = temp->nxt;
		}
		temp->nxt = nouvelHf;
	}
}

/*
void readHeaderPageInfo(char *buffer ,HeaderPageInfo Hpi){
readpage()
}
*/


int main(){
	initStruct();
	struct ListeHeapFile *listeHeapFile = NULL;
	struct RelSchema k = {"nani", 3, "yamero"};
	struct RelDef a={k, 6};
	struct RelDef *b= &a;
	struct DbDef def={b, 3};
	printf("compteur de relations: %d\n", def.compteurRelations);
	struct HeapFile hf = {b};
	ajouterEnFin(listeHeapFile, hf);
    ListeHeapFile *actuel = listeHeapFile;
    while (actuel->nxt != NULL)
    {
        printf("%d -> ", actuel->present->ptrRelDef->FileId);
    }
    printf("NULL\n");
	//createHeader(hf);
	

	return 0;
}

