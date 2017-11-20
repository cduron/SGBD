/*
 * Création des Structures
 */

#include "../headers/RelDef.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int testRelDef(){
	struct RelSchema a = {"Bob", 4, "Nani"};
	struct RelDef reldef1={a, 3};
	printf("OMEWA MOU SHINJIIR\n");
	printf("type de l'ID: %d", reldef1.FileId);
	return 0;
}
