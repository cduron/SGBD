/*
 *	GlobalManager.c
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/GlobalManager.h"
#include "../headers/DbDef.h"



struct DbDef dbDef1; /* Declaration de DbDef1 de type DbDef */

void init (){

	dbDef1.compteur_relations = 0;
	struct element liste1={1, NULL, NULL};
	dbDef1.liste_relations = liste1;

	printf("/**** Bienvenue dans l'interface de notre SGBD ******/ \n");
	scanf("%s", &saisie);


	if (&saisie=="exit"){
		printf("/*** Goodbye my lover, Goodbye my friend <3 ****/");
		exit();
	}
	printf("k");

	printf("k");

};

void CreateRelation(char NomRelation, int NombreColonnes, char TypesDesColonnes){
	/* Declaration d'une nouvelle relation de type RelDef */
	struct RelDef RelDef1;
	RelDef1.Schema.nom = NomRelation;
	RelDef1.Schema.nombre_colonnes = NombreColonnes;
	RelDef1.Schema.type_colonnes = TypesDesColonnes;
	RelDef1.FileId = dbDef1.compteur_relations;
	struct tache* ptrRelDef1;
	ptrRelDef1 = &RelDef1 ;
	dbDef1.liste_relations.present = ptrRelDef1;
	dbDef1.compteur_relations ++;
};
