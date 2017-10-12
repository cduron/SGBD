/*
 *	GlobalManager.c
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/GlobalManager.h"
#include "../headers/DbDef.h"



struct DbDef dbDef1; /* Declaration de DbDef1 de type DbDef */

int main(){
	return 0;
}


void init (){

	dbDef1.compteur_relations = 0;

};

void CreateRelation(char NomRelation, int NombreColonnes, char TypesDesColonnes){
	/* Declaration d'une nouvelle relation de type RelDef */
	struct RelDef RelDef1;
	RelDef1.Schema.nom = NomRelation;
	RelDef1.Schema.nombre_colonnes = NombreColonnes;
	RelDef1.Schema.type_colonnes = TypesDesColonnes;
	RelDef1.FileId = dbDef1.compteur_relations;
	dbDef1.liste_relations[dbDef1.compteur_relations] = RelDef1;
	dbDef1.compteur_relations ++;
};
