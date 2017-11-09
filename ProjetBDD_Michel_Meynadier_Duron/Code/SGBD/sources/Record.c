#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/Record.h"
#include "../headers/Constante.h"


//Record
struct Record *record;

/**
 * Fonction setValues 	: permet de stocker les valeurs entrées en arguments, en tant que valeurs des attributs du Record
 * @param valeurs		: Tableau de char*
*/
void setValues (char **valeurs){
	for (int i=0; i<strlen(valeurs);i++){
		memcpy(record->ptrrecord[i], valeurs[i], sizeof(record->ptrrecord[i]));
	}
}

int main(){
	char *valeurs[3]= {
			"test",
			"testt",
			"testt"
	};
	printf("%s",valeurs[0]);
	printf("%s",record->ptrrecord[0]);
	setValues(valeurs);


	return 0;
}
