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
	char *buffer;
	while(buffer==NULL){
		buffer= malloc(sizeof(char)*TAILLE);
		if(buffer==NULL){
			printf("Erreur affectation");
		}
	} 
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
	ListeHeapFile *nouvelHf;
	while(nouvelHf == NULL){
		nouvelHf= malloc(sizeof(*nouvelHf));	
		if(nouvelHf==NULL){
			printf("Erreur affectation");
		}
	}
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

/*
int main(){
	initStruct();
	struct RelSchema k = {"nani", 3, "yamero"};
	struct RelDef a={k, 6, 5, 4};
	struct RelDef *b= malloc(sizeof(*b));
	b = &a;
	struct DbDef def={b, 3};
	struct ListeHeapFile *listeHeapfile = malloc(sizeof(*listeHeapfile));
	struct  HeapFile hf = {b};
	    if (listeHeapfile == NULL)
	    {
	        exit(EXIT_FAILURE);
	    }
	    listeHeapfile->nxt = NULL;
	    listeHeapfile->present = hf;
	printf("compteur de relations: %d\n", def.compteurRelations);
	ajouterEnFin(listeHeapfile, hf);
	printf("-> %d\n", hf.ptrRelDef->FileId );
	ListeHeapFile *actuel = listeHeapfile;
	while (actuel->nxt != NULL)
		{
			printf("-> %d\n", actuel->present.ptrRelDef->FileId);
			actuel = actuel->nxt;

		}
    printf("NULL\n");
	//createHeader(hf);
	

	return 0;
}
*/
