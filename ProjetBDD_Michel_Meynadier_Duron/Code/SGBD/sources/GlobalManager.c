/*
 *	GlobalManager.c
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../headers/GlobalManager.h"
#include "../headers/HeapFile.h"
#include "../headers/Record.h"


//Declaration de DbDef1 de type DbDef
struct DbDef dbDef1;

// Declaration de listeHeapFile qui est une liste chainee d'elements de type HeapFile
struct ListeHeapFile *listeHeapFile = NULL;



/**************************************************************************************************/


/* 
 * Fonction createRelation : Creer une relation, c'est a dire une structure de type RelDef
 * param nomRelation : nom de la relation créée
 * param nombreColonnes : nombre de colonnes dans la relation
 * param typesDesColonnes : types des colonnes de la relation
*/
void createRelation(char *nomRelation, int nombreColonnes, char *typesDesColonnes){
	struct RelDef relDef1;
	relDef1.Schema.nom = malloc(sizeof(char)*strlen(nomRelation));
	strcpy(relDef1.Schema.nom, nomRelation);
	relDef1.Schema.nombreColonnes = nombreColonnes;
	strcpy(relDef1.Schema.typeColonnes, typesDesColonnes);
	relDef1.RecordSize = (sizeof(nomRelation)/8+sizeof(nombreColonnes)/8+sizeof(typesDesColonnes)/8);
	relDef1.FileId = dbDef1.compteurRelations;
	dbDef1.listeRelations[dbDef1.compteurRelations] = relDef1;
	dbDef1.compteurRelations ++;
	struct HeapFile hf;
	hf.ptrRelDef = &relDef1;
	ajouterEnFin(listeHeapFile, hf);
	createHeader(hf);
}



/**************************************************************************************************/




/* 
 * Fonction finish : Créer un fichier "Catalog.def" et ecrit le contenu de dbDef1 dans ce fichier
*/


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



/**************************************************************************************************/




/*  
 * Fonction refreshHeapFiles : Pour chaque relation existante dans la BDD creer une structure HeapFile correspondante et l'ajoute a
 * la liste listHeapFile.
 * 
*/


void refreshHeapFiles(){
	for(int i=0; i<dbDef1.compteurRelations; i++){
		struct HeapFile heapFile;
		heapFile.ptrRelDef = malloc(sizeof(dbDef1.listeRelations));
		ajouterEnFin(listeHeapFile, heapFile);
	}
}



/**************************************************************************************************/



/* 
 * Fonction insert :
 *
 *
*/
/*
 * Fonction insert : Ajout d'un record à une relation
 * param nomRelation : La relation à laquelle il faut ajouter le record
 * param listeValeurs : liste des Valeurs à ajouter à la relation
*/

void insert (char * nomRelation, char * listeValeurs){
	struct Record record;
	record.ptrrecord = NULL;
	setValues(listeValeurs, record);
}





/**************************************************************************************************/



/*
 * Foncton init : Initialise le compteur de relations de dbDef1 à 0 puis recupere le contenu du fichier
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




/**************************************************************************************************/
