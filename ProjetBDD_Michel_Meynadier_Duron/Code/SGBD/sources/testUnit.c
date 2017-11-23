/*
  Fichier de tests
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "testUnit.h"

/*

/*
 * Fonction testPageId : Fonction de test de toutes les fonctions du fichier PageId.c
 * CreateFile(), writePage(), readPage(), addPage()
 * Retour attendu :
 *   -Création d'un fichier Data_1.rf (createFile())
 *   -Ajout d'une page vide dans ce fichier (addPage())
 *   -Remplissage de ce fichier ((writePage())
 *   -Vérification de l'écriture dans le fichier (readPage())
 *
int testPageId(){
	int fileId = 1;
	unsigned char * buffer = malloc(sizeof(char)*TAILLE);
	struct PageId page = {1, 0};
	
	createFile(fileId);
	addPage(fileId);
	for(int i = 0 ; i<5; i++){
		buffer[i]='C';
	}

	writePage(page, buffer);
	unsigned char * buffer2 = malloc(sizeof(char)*TAILLE);
	readPage(page, buffer2);
	printf("%s",buffer2);
	free(buffer);

	return 1;
}

/*
 * Fonction testSetValues : Test de la fonction setValues du fichier Record.c
 * Retour attendu : Première valeur de ptrrecord correspondant à la première valeur du tableau valeurs
 *
void testSetValues(){
	char *valeurs[3]= {
			"test",
			"testt",
			"testt"
	};
	setValues(valeurs, 3);
	printf("%s",valeurs[0]);
	printf("%s",record.ptrrecord[0]);
}

/*
 * Fonction testsplit : Test de la fonction Split
 * Retour attendu : tous les mots de la chaîne de caractère séparés par un retour à la ligne
 *
void testsplit(){	
	char chaine[] = "test test test test test";
	printf("%s\n\n", chaine);
	printf("Alloue\n\n");
	char **souschaine = split(chaine, " ", 4);
	if(souschaine==NULL)
		printf("ERREUR D'AFFECTATION\n");
	if(souschaine==NULL){
		printf("Erreur NULL\n");	
		free(souschaine);
	}
	for (int i = 0; i < 4; ++i)
	{
		printf("%s\n", souschaine[i]);
	}
	free(souschaine);
}

/*
 * Fonction testDbDef : Test de la création de la Structure DbDef
 * Retour attendu : Affichage du nombre de relations crées
 *
void testDbDef(){
	struct RelSchema k = {"insert", 3, "table1"};
	struct RelDef a={k, 6};
	struct RelDef* b = a;
	struct DbDef def={b, 3};
	printf("compteur de relations: %d\n", def.compteur_relations);
}

/*
 * Fonction testRelDef : Test de la création d'une structure RelDef
 * Retour attendu : Affichage de l'Id de la structure crée
 *
void testRelDef(){	struct RelSchema a = {"Bob", 4, "Nani"};
	struct RelDef reldef1={a, 3};
	printf("OMEWA MOU SHINJIIR\n");
	printf("type de l'ID: %d", reldef1.FileId);
}

/*
 * Fonction testRelSchema : Test de la création de la structure RelSchema
 * Retour attendu : Affichage du nombre de colonnes dans le Schema crée
 *
void testRelSchema(){
	struct RelSchema relschema1={.nom="Bob", .nombre_colonnes=4, .type_colonnes="peremptoire"};
	printf("nombre de colonnes: %d", relschema1.nombre_colonnes);
}
*/
