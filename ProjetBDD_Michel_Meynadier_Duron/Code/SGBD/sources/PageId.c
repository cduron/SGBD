/*
 * Création des Structures
 */

#include <stdio.h>
#include <stdlib>
#include "/headers/PageId.h"


/*
*  CreateFile			: créé un fichier Data_FileId.rf en vue d’y stocker des records par la suite.
*  param int FileIdx		: identifiant de la page à créer
*   
*/
void CreateFile(int FileId){
	FILE* fh;
	//on passe FileId en chaine de caracteres
	char fileID[100]=(char)FileId;
	char adresse[100]="DB/Data_";
	strcat(adresse, fileID);
	//on créé une chaine de caracteres correspondant à l'adresse du fichier
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
	return(EXIT_SUCCESS);
}

/*
*  AddPage			: rajoute une page au fichier spécifié par le champ FileIdx 
*  param int FileIdx		: identifiant de la page
*   
*/
void AddPage(int FileIdx){
	FILE* fichier;
	char fileID[100]=(char)FileIdx; //on passe FileIdx en chaine de caractere
	char adresse[100]="DB/Data_";
	strcat(adresse, fileID);
	//on créé une chaine de caracteres correspondant à l'adresse du fichier
	strcat(adresse, ".rf");
	fichier = fopen(adresse, "r+b"); //on ouvre le fichier correspondant

    	if (fichier == NULL){
		printf("Impossible d'ouvrir le fichier");
		exit(0);
   	}

    	return (EXIT_SUCCESS);
}

/*
*  ReadPage			: permet de remplir l'argument Buffer avec le contenu d'une page
*  param int PageId		: identifiant de la page
*  param unsigned char *buffer	: un buffer qui contiendra le contenu de la page d'identifiant PageId
*   
*/
void ReadPage(int PageId, unsigned char *buffer){

	//on passe FileId en chaine de charactere
	char fileID[100]=(char)FileIdx;
	char adresse[100]="DB/Data_";
	char adresse2[4]=".rf";

	//On concatene por obtenir le nom & l'adresse du fichier à ouvrir
	strcat(adresse, fileID);
	strcat(adresse, adresse2);

	//Compteur pour le Buffer
	int i;
	//Variable pour stocker le caractere
	int c;

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

	//Sortie
	return (EXIT_SUCCESS);
}

/*
*  WritePage			: permet l'écriture du contenu de l'argument Buffer dans le fichier dont l'id correspond à l'argument PageId 
*  param int PageId		: identifiant de la page
*  param unsigned char *buffer	: un buffer
*   
*/
void WritePage(int PageId, unsigned char *Buffer){
	//on passe FileId en chaine de charactere
	char fileID[100]=(char)FileIdx;
	char adresse[100]="DB/Data_";
	char adresse2[4]=".rf";

	//On concatene por obtenir le nom & l'adresse du fichier à ouvrir
	char ad = strcat(adresse, fileID);
	ad = strcat(ad, adresse2);

	// Ouverture du fichier binaire (b) en mode ajout (a)
	FILE *fic;
	fic = fopen(ad,"ab");

	// Vérification de la bonne ouverture du fichier
	if(fic==NULL){
    		printf("Problème lors de l'ouverture du fichier");
    		exit(0);
  	}

	//Compteur pour parcourir le Buffer
	int i;
	//Variable pour stocker le caractere à écrire dans le fichier
	int c;

	//On parcourt le Buffer, jusqu'à ce qu'on obtienne le caractere de Fin de chaîne
	while (c= (*(Buffer+i)) != '\0') {
		fputc(c,fic);
		i++;
	}

	//Fermeture du fichier
	fclose(fic);

	return(EXIT_SUCCESS);
}
