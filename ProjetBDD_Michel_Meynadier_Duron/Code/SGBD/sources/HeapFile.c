/*
 * Fichier HeapFile.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/DefStruct.h"
#include "../headers/HeapFile.h"
#include "../headers/PageId.h"

/*
 * Fonction createHeader : Création d'une HeaderPage
 * Param HeapFile : HeapFile
*/
void createHeader(struct HeapFile hf){
	addPage(hf.ptrRelDef->FileId);

}
