/*
 *	GlobalManager.c
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/GlobalManager.h"
#include "../headers/DbDef.h"



struct DbDef DbDef1; /* Declaration de DbDef1 de type DbDef */

void init (){

	DbDef1.compteurRelations = 0;
	struct DbDef1.list = NULL;

	printf("/**** Bienvenue dans l'interface de notre SGBD ******/ \n");
	scanf("%s", &saisie);


	if (&saisie=="exit"){
		printf("/*** Goodbye my lover, Goodbye my friend <3 ****/");
		exit();
	}
	printf("k");

	printf("k");

}

void CreateRelation(char NomRelation, int NombreColonnes, char TypesDesColonnes){
	/* Declaration d'une nouvelle relation de type RelDef */
	struct RelDef RelDef1;
	RelDef1.RelSchema.nom = NomRelation;
	RelDef1.RelSchema.nombres_colonnes = NombreColonnes;
	RelDef1.RelSchema.tye_colonnes = TypesDesColonnes;
	RelDef1.FileId = DbDef1.compteurRelations;
	DbDef1.listRel[DbDef1.compteurRelations]= RelDef1;
	DbDef1.compteurRelations ++;


}
