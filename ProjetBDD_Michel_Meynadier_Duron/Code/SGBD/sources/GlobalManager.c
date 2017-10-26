/*
 *	GlobalManager.c
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/GlobalManager.h"
#include "../headers/DbDef.h"



struct DbDef dbDef1; /* Declaration de DbDef1 de type DbDef */
struct HepaFile *listHeapFile;




void init (){
	dbDef1.compteur_relations = 0;
	FILE* fichier = NULL;
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
	relDef1.FileId = dbDef1.compteur_relations;
	dbDef1.liste_relations[dbDef1.compteur_relations] = relDef1;
	dbDef1.compteur_relations ++;
};

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

int main(){
	init();
	finish();
	return 0;
}

