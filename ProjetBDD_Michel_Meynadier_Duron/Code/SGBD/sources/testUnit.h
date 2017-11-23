#ifdef TESTUNIT_H
#define TESTUNIT_H

#include "BufferManager.h"
#include "Constante.h"
#include "DefStruct.h"
#include "GlobalManager.h"
#include "HeapFile.h"
#include "Record.h"
#include "split.h"
#include "PageId.h"

//Test de toutes les fonctions du fichier PageId.c
void testPageId();

//Test de la fonction setValues du fichier Record.c
void testSetValues();

//Test de la fonction Split
void testsplit();

//Test de la création de la Structure DbDef
void testDbDef();

//Test de la création d'une structure RelDef
void testRelDef();

//Test de la création de la structure RelSchema
void testRelSchema();

#endif
