/*
 *	GlobalManager.c
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/GlobalManager.h"
#include "../headers/DbDef.h"
#include "../headers/RelDef.h"
#include "../headers/HeapFile.h"


struct DbDef dbDef1; /* Declaration de DbDef1 de type DbDef */
struct HeapFile *listHeapFile; /* Declaration de listHeapFile qui est une liste chainee d'elements de type HeapFile */

/* Creer une relation, c'est a dire une structure de tpe RelDef */
void createRelation(char nomRelation, int nombreColonnes, char typesDesColonnes){
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

/* Pour chaque relartion existante dans la BDD creer une structure HeapFile correspondante et l'ajoute a
 * la liste listHeapFile.
 * ATTENTION! ERREUR DE SEGMENTATION!
 */
void refreshHeapFiles(){
	for(int i=0; i<dbDef1.compteurRelations; i++){
		struct HeapFile heapFile;
		heapFile.ptrRelDef = malloc(sizeof(dbDef1.listeRelations[i]));
	    heapFile.ptrRelDef[i] = (dbDef1.listeRelations[i]);
		listHeapFile[i] = heapFile;
	}
}

/* Initialise le compteur de relations de dbDef1 à 0 puis recupere le contenu du fichier
 * "Catalog.def" dans dbDef1 si le fichier existe.
 * Puis listHeapFile est mise à jour.
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
	refreshHeapFiles();
};

int main(){
	init();
	finish();
	return 0;
}

