/*
 * Fichier PageId.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/PageId.h"
#include "../headers/Constante.h"


/*
*  createFile		: créé un fichier Data_FileId.rf en vue d’y stocker des records par la suite.
*  param int fileId	: identifiant de la page à créer
*
*/
void createFile(int fileId){
	FILE* fh;
	//on passe FileId en chaine de caracteres eton créé une chaine de caracteres correspondant à l'adresse du fichier

	char * adresse = malloc(sizeof(char)*100);
	nameFile(fileId, adresse);
	//on créé et on ouvre le fichier binaire d'adresse Data_FileId.rf dans le répertoire DB
	// Si le fichier n'existe pas, en mode (w) le fichier est créé, si il existe il est écrasé
	fh = fopen(adresse, "wb");

	// Vérification de la bonne ouverture du fichier
  	if(fh==NULL){
    		printf("Error access createFile");
    		exit(0);
  	}
	// Fermeture du fichier
	fclose(fh);
	free(adresse);
}

/*
*  addPage		: rajoute une page au fichier spécifié par le champ FileIdx
*  param int fileIdx	: identifiant de la page
*
*/

int addPage(int fileIdx){
	//on ouvre le fichier correspondant
	FILE* fichier;
	char * adresse = malloc(sizeof(char)*100);
	nameFile(fileIdx, adresse);
	fichier = fopen(adresse, "a+b"); 

	//Vérification de l'ouverture du fichier
  	if (fichier == NULL){
		printf("Error Access addPage");
		exit(0);
 	}

	//On se positionne à la fin du fichier
	fseek(fichier, 0, SEEK_END);
	long int tailleFichier = ftell(fichier);

	//Création d'un tableau contenant les (4096-1) bytes (un char = un byte) à ajouter à la fin du fichier pour créer le bloc de 4Ko
	char * ptab;
	ptab = calloc(TAILLE, sizeof(char));

	//Ecriture dans le fichier binaire	
	fwrite( ptab , sizeof(char) , TAILLE , fichier);

	PageId page;
	page.fileId = fileIdx;
	page.idX =  tailleFichier/TAILLE;

	FILE* stockID;
	stockID = fopen("../DB/Data_0.rf", "a+b");
	fprintf(stockID,"%d%d", page.fileId, page.idX);

	free(adresse);
	return page.idX;

}
/*
*  readPage 			: permet de remplir l'argument Buffer avec le contenu d'une page
*  param PageId page		: Page à parcourir -> Identifiant du fichier & de la page 
*  param unsigned char *buffer	: un buffer qui contiendra le contenu de la page d'identifiant FileId
*
*/

void readPage(PageId page, unsigned char *buffer){
	//on passe FileId en chaine de charactere
	char * adresse = malloc(sizeof(char)*100);
	nameFile(page.fileId, adresse);
	//Compteur pour le Buffer
	int i=0;
	//Variable pour stocker le caractere
	int c;

	FILE *fic;

	// Ouverture du fichier d'identifiant PageId
	// Droit en Lecture seulement (r) Fichier binaire (b)
	fic = fopen(adresse,"r+b");
	
	// Vérification de la bonne ouverture du fichier

	if(fic==NULL){
		printf("Error access readPage");
		exit(0);
	}

	fseek(fic,TAILLE*page.idX,SEEK_SET);

	for (int i = 0; i< TAILLE; i++){
		*(buffer+i)=fgetc(fic);
	}
	// Fermeture du fichier
	fclose(fic);

	free(adresse);
}


/*
* nameFile 		: la fonction qui permet de récupérer le chemin du fichier
* param int fileIdx 	: l'iD du fichier
* return adresse 	: l'adresse du fichier 
*/

void nameFile(int fileIdx, char *adresse){
	//on passe FileIdx en chaine de caracteres eton créé une chaine de caracteres correspondant à l'adresse du fichier
        adresse[0]=0;
	strcat(adresse, "../DB/Data_");
	char FileIdChar[12];
    	sprintf(FileIdChar, "%d", fileIdx);
	strcat(adresse,FileIdChar);
	strcat(adresse, ".rf");
}


/*
*  writePage			: permet l'écriture du contenu de l'argument Buffer dans le fichier dont l'id correspond à l'argument FileId
*  param int FileIdeId		: identifiant de la page
*  param unsigned char *buffer	: un buffer
*
*/

void writePage(PageId page, unsigned char *buffer){
	//on passe FileId en chaine de charactere et on concatene
	char * adresse = malloc(sizeof(char)*100);
	nameFile(page.fileId, adresse);
	// OufileIdxverture du fichier binaire (b) en mode ajout (a)
	FILE *fic;
	fic = fopen(adresse,"a+b");
	
	// Vérification de la bonne ouverture du fichier
	if(fic==NULL){
  		printf("Error access writePage");
  		exit(0);
	}
	
	//Aller à la page page.Idx du fichier
	fseek(fic,TAILLE*page.idX,SEEK_SET);

	// Parcourir les n bytes de la page et y copier les données du buffer
	fwrite(buffer, sizeof(char), TAILLE, fic);

	//Fermeture du fichier
	fclose(fic);
	free(adresse);

}
