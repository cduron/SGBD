/*
 * Création des Structures
 */

#include <stdio.h>
#include "/headers/PageId.h"

int CreateFile(int FileId){
	char fileID[100]=(char)FileId; //on passe FileId en chaine de charactere
	char adresse[100]="DB/Data_";
	char adresse2[4]=".rf";
	strcat(adresse, fileID);
	strcat(adresse, adresse2); //on creer une chaine de caracteres correspondant à l'adresse du fichier
	FILE* fh = fopen(adresse, "wb"); //on créer le fichier binaire d'adresse Data_FileId.rf dans le répertoire DB
	return 0;
}

int AddPage(int FileIdx){
	FILE* fichier = NULL;
	char fileID[100]=(char)FileIdx; //on passe FileIdx en chaine de charactere
	char adresse[100]="DB/Data_";
	char adresse2[4]=".rf";
	fichier = fopen(adresse, "rbw"); //on ouvre le fichier correspondant

    if (fichier != NULL){

    }

    else {
      printf("Impossible d'ouvrir le fichier");
    } //si l'adresse ne correspond a rien on envoie un message d'erreur
    return 0;

}
/*
 * Fonction permettant de remplir l'argument Buffer avec le contenu
 * de la page identifée par PageId
*/
void ReadPage(int PageId, unsigned char *buffer){
  FILE *fic;
  // Ouverture du fichier d'identifiant PageId
  // Droit en Lecture seulement (r) Fichier binaire (b)
  fic = fopen(PageId.dat,"rb");
  // Vérification de la bonne ouverture du fichier
  if(fic==NULL){
    printf("Problème lors de l'ouverture du fichier");
    exit(0);
  }

  // Fermeture du fichier
  fclose(fic);
}
