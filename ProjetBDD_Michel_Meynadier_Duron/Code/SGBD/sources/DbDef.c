/*
 * Création des Structures
 */

#include "../headers/RelSchema.h"
#include "../headers/RelDef.h"
#include "../headers/DbDef.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int testDbDef(){

	struct RelSchema k = {"Roger", 3, "Santa"};
	struct RelDef a={k, 6};
	struct RelDef* b = a;
	struct DbDef def={b, 3};
	printf("compteur de relations: %d\n", def.compteur_relations);

    return 0;
}

int main(){
	return 0;
}
