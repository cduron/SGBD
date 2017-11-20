/*
 * Création des Structures
 */

#include "../headers/RelSchema.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int testRelSchema(){

	struct RelSchema relschema1={.nom="Bob", .nombre_colonnes=4, .type_colonnes="peremptoire"};
	printf("nombre de colonnes: %d", relschema1.nombre_colonnes);
    return 0;

}
