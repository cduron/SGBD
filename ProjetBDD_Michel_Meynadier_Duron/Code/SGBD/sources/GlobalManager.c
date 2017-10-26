/*
 *	GlobalManager.c
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/GlobalManager.h"
#include "../headers/DbDef.h"



struct DbDef dbDef1; /* Declaration de DbDef1 de type DbDef */
struct HeapFile *listHeapFile;



/* Initialise le compteur de relations de dbDef1 à 0 puis recupere le contenu du fichier
 * "Catalog.def" dans dbDef1 si le fichier existe.
 */
void init (){
	dbDef1.compteurRelations = 0;
	FILE* fichier;
	fichier = fopen("../DB/Catalog.def", "r+");
	if (fichier != NULL){
		fread(&dbDef1, sizeof(dbDef1), 1, fichier);
		fclose(fichier);
	}
	else {
		printf("Impossible d'ouvrir le fichier Catalog.def");
	}
};

void CreateRelation(char nomRelation, int nombreColonnes, char typesDesColonnes){
	/* Declaration d'une nouvelle relation de type RelDef */
	struct RelDef relDef1;
	relDef1.Schema.nom = nomRelation;
	relDef1.Schema.nombre_colonnes = nombreColonnes;
	relDef1.Schema.type_colonnes = typesDesColonnes;
	relDef1.FileId = dbDef1.compteurRelations;
	dbDef1.listeRelations[dbDef1.compteurRelations] = relDef1;
	dbDef1.compteurRelations ++;
};


/* Créer un fichier "Catalog.def" et ecrit le contenu de dbDef1 dans ce fichier. */
int finish(){
	    FILE* fichier = NULL;
	    fichier = fopen("../DB/Catalog.def", "r+");
	    if (fichier != NULL){
	    	fwrite(&dbDef1, sizeof(dbDef1), 1, fichier);
	    	fclose(fichier);
	    }
	    else {
	        printf("Impossible d'ouvrir le fichier Catalog.def");
	    }
	    return 0;
}


void refreshHeapFiles(){
	for(int i=0; i<dbDef1.compteurRelations; i++){
		struct HeapFile heapFileTest;
		heapFileTest.ptrRefDel[i] = &(dbDef1.listeRelations[i]);
		listHeapFile[i] = heapFileTest;
	}
}

int main(){
	init();
	finish();
	return 0;
}

