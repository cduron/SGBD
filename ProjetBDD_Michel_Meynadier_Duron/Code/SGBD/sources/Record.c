#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/Record.h"
#include "../headers/Constante.h"
#include "../headers/split.h"


//Record
struct Record record;

/**
 * Fonction setValues 	: permet de stocker les valeurs entrées en arguments, en tant que valeurs des attributs du Record
 * @param valeurs		: Tableau de char*
*/
void setValues (char *valeurs, int nbcolonne)
{
	record.ptrrecord=split(valeurs, " ", nbcolonne);
}