/*
 * Création des Structures
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../headers/PageId.h"


/*
*  createFile		: créé un fichier Data_FileId.rf en vue d’y stocker des records par la suite.
*  param int FileIdx	: identifiant de la page à créer
*
*/
void createFile(int FileId){
	FILE* fh;
	//on passe FileId en chaine de caracteres eton créé une chaine de caracteres correspondant à l'adresse du fichier
	char adresse[100]= "../DB/Data_";
	char FileIdChar[12];
    	sprintf(FileIdChar, "%d", FileId);
	strcat(adresse,FileIdChar);
	strcat(adresse, ".rf");

	//on créé et on ouvre le fichier binaire d'adresse Data_FileId.rf dans le répertoire DB
	// Si le fichier n'existe pas, en mode (w) le fichier est créé
	fh = fopen(adresse, "wb");

	// Vérification de la bonne ouverture du fichier
  	if(fh==NULL){
    		printf("Problème lors de l'ouverture du fichier");
    		exit(0);
  	}
	// Fermeture du fichier
	fclose(fh);
}

/*
*  addPage		: rajoute une page au fichier spécifié par le champ FileIdx
*  param int FileIdx	: identifiant de la page
*
*/

int addPage(int FileIdx){
	//on passe FileId en chaine de caracteres eton créé une chaine de caracteres correspondant à l'adresse du fichier
	char adresse[100]= "../DB/Data_";
	char FileIdChar[12];
    	sprintf(FileIdChar, "%d", FileIdx);
	strcat(adresse,FileIdChar);
	strcat(adresse, ".rf");

	FILE* fichier;
	fichier = fopen(adresse, "r+b"); //on ouvre le fichier correspondant
		

	//Vérification de l'ouverture du fichier
  	if (fichier == NULL){
		printf("Impossible d'ouvrir le fichier");
		exit(0);
 	}

	//Ajout d'un bloc de n bytes à la fin du fichier d'identifiant FileIdx
	

	//Création de ce bloc 
	PageId page;
	page.FileIdx = FileIdx;
	page.Idx = 0;
	return Page.Idx;
}

/*
*  readPage			            : permet de remplir l'argument Buffer avec le contenu d'une page
*  param PageId page		        : Page à parcourir -> Identifiant du fichier & de la page 
*  param unsigned char *buffer	: un buffer qui contiendra le contenu de la page d'identifiant FileId
*
*/

void readPage(PageId page, unsigned char *buffer){

	//on passe FileId en chaine de charactere
	char adresse[]= "DB/Data_";
	strcat(adresse,(char)page.FileId);
	strcat(adresse, ".rf");

	//Compteur pour le Buffer
	int i;
	//Variable pour stocker le caractere
	int c;
	
	// Trouver le début de la page PageId
	// Parcourir la page d'identifiant PageId
	// Remplir le buffer
	

	FILE *fic;
	// Ouverture du fichier d'identifiant PageId
	// Droit en Lecture seulement (r) Fichier binaire (b)
	fic = fopen(adresse,"rb");

	// Vérification de la bonne ouverture du fichier
	if(fic==NULL){
		printf("Problème lors de l'ouverture du fichier");
		exit(0);
	}

	// On lit le contenu du fichier jusqu'au caractere final : EOF
	while (c=fgetc(fic)!=EOF) {
		// On affecte cette valeur au Buffer
		buffer[i]=c;
		i++;
	}

	// Fermeture du fichier
	fclose(fic);
}

/*
*  writePage			: permet l'écriture du contenu de l'argument Buffer dans le fichier dont l'id correspond à l'argument FileId
*  param int FileIdeId		: identifiant de la page
*  param unsigned char *buffer	: un buffer
*
*/
void writePage(PageId page, unsigned char *Buffer){
	//on passe FileId en chaine de charactere et on concatene
	char adresse[]= "DB/Data_";
	strcat(adresse,(char)page.FileId);
	strcat(adresse, ".rf");
	// Ouverture du fichier binaire (b) en mode ajout (a)
	FILE *fic;
	fic = fopen(adresse,"ab");

	// Vérification de la bonne ouverture du fichier
	if(fic==NULL){
  		printf("Problème lors de l'ouverture du fichier");
  		exit(0);
	}
	
	//Aller à la page page.Idx du fichier 
	// Parcourir les n bytes de la page et y copier les données du buffer

	//Fermeture du fichier
	fclose(fic);

}
*/

void main(){
	int FileId = 1;
	unsigned char * Buffer = NULL;
	printf("test");
	createFile(FileId);
	//addPage(FileId);
	//readPage(FileId, Buffer);
	//writePage(Buffer, FileId);
}
