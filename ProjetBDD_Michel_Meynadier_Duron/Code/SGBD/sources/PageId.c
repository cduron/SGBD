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
	// Si le fichier n'existe pas, en mode (a+) le fichier est créé
	fh = fopen(adresse, "a+b");

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

int addPage(int fileIdx){
	//on ouvre le fichier correspondant
	FILE* fichier;
	char * adresse = nameFile(fileIdx);
	fichier = fopen(adresse, "a+b"); 
		

	//Vérification de l'ouverture du fichier
  	if (fichier == NULL){
		printf("Impossible d'ouvrir le fichier");
		exit(0);
 	}

	//On se positionne à la fin du fichier
	fseek(fichier, 0, SEEK_END);

	// Création d'un tableau contenant les (4096-1) bytes (un char = un byte) à ajouter à la fin du fichier pour créer le bloc de 4Ko
	char * ptab;
	ptab = malloc(4095 * sizeof(char));

	//Ecriture dans le fichier binaire	
	fwrite( ptab , sizeof(char) , 4095 , fichier);

	//Ajout du séparateur '$' à la fin de la page
	char separateur = '$';
	fwrite( &separateur , sizeof(char) , 1 , fichier);
 
	PageId page;
	page.FileId = fileIdx;
	page.Idx =  ;
	
	FILE* stockID;
	createFile(0);
	stockID = fopen("../DB/Data_0.rf", "a+b");
	fprintf(stockID,"%d %d", page.
	return page.Idx;
}

/*
*  readPage 			: permet de remplir l'argument Buffer avec le contenu d'une page
*  param PageId page		: Page à parcourir -> Identifiant du fichier & de la page 
*  param unsigned char *buffer	: un buffer qui contiendra le contenu de la page d'identifiant FileId
*
*/

void readPage(PageId page, unsigned char *buffer){

	//on passe FileId en chaine de charactere
	char adresse[]= "DB/Data_";
	strcat(adresse,(char)page.FileId);
	strcat(adresse, ".rf");

	//Compteur pour le Buffer
	int i=0;
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

	fseek(fic,4096*page.idX,0,SEEK_SET);

	// On lit le contenu du fichier jusqu'au caractere final : EOF
	while (c=fgetc(fic)!='$') {
		// On affecte cette valeur au Buffer
		buffer[i]=c;
		i++;
	}

	// Fermeture du fichier
	fclose(fic);
}


/*
* nameFile 		: la fonction qui permet de récupérer le chemin du fichier
* param int fileIdx 	: l'iD du fichier
* return adresse 	: l'adresse du fichier 
*/

char * nameFile(int fileIdx){
	//on passe FileIdx en chaine de caracteres eton créé une chaine de caracteres correspondant à l'adresse du fichier
	char adresse[100]= "../DB/Data_";
	char FileIdChar[12];
    	sprintf(FileIdChar, "%d", fileIdx);
	strcat(adresse,FileIdChar);
	strcat(adresse, ".rf");
	return adresse;
}


/*
*  writePage			: permet l'écriture du contenu de l'argument Buffer dans le fichier dont l'id correspond à l'argument FileId
*  param int FileIdeId		: identifiant de la page
*  param unsigned char *buffer	: un buffer
*
*/
/*
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

/*
*
*
*
*/

int cptSeparatorFile(int fileIdx, char separator){
	int c, cpt = 0;	
	char * name = nameFile(fileIdx);
	FILE* fichier = fopen(name,"r+b");
	if(fichier==NULL){
		printf("Error FILE not exist");
		return;
	}
	while (c=fgetc(fic)!=EOF) {
		if(c==separator)	
			cpt++;
	}
	return cpt;		
}
/*
void main(){
	int FileId = 1;
	unsigned char * Buffer = NULL;
	printf("test");
	//createFile(FileId);
	//addPage(FileId);
	//readPage(FileId, Buffer);
	//writePage(Buffer, FileId);
}*/

int main(){
	return 0;	
}
