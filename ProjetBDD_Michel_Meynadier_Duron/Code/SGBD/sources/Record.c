#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/Record.h"
#include "../headers/Constante.h"
#include "../headers/split.h"

/**
 * Fonction setValues 	: Permet de stocker les valeurs entrées en arguments, en tant que valeurs des attributs du Record
 * param valeurs		: Tableau de char*
 * param nbColonnes 	: Nombre de colonnes dans valeurs
 * param record			: Fichier Record dans lequel le tableau de Valeurs sera sauvegardé
*/
void setValues (char *valeurs, int nbcolonne, Record record)
{
	record.ptrrecord=split(valeurs, " ", nbcolonne);
}
