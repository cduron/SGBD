/*split.c*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//#include "split.h"


int nbLettreAvantSeparateur(char *separateur, char*phrase, int numeroMot){
	int cptlettre = 0;
	while(phrase[cptlettre]!=' '&&'\0'!=phrase[cptlettre]!='\0')
		cptlettre++;
	return cptlettre;
}


/*
* Split 				: permetant de séparer une chaine de caracteres en un tableau de chaines de caracteres.
*  param chaine 		: est la chaine de caractère que l'on veut séparer
*  param separateur		: de séparation de la chaine de caractères
*  return rtnchaine 	: tableau de chaines de chaines de caractères
* 
*
*  var char* token		: permet de récuperer les mots
*  var int ligne		: compteur de ligne
*/

char **split(char *chaine, char* separateur, int nbcolonne){
	int ligne=0, boucle=0;
	char *token;
	/* Alloue le tableau de retour */
	char ** rtnchaine=malloc(sizeof(char*)*(nbcolonne+1));
	if(rtnchaine==NULL)
	{
		printf("Erreur rtnchaine NULL\n");
		free(rtnchaine);
		return NULL;
	
	}
	/*Affecte le premier mot dans token */
	token=strtok(chaine, separateur);
	/*Alloue la taille du mot à la ligne 0 */
	rtnchaine[ligne]=malloc(sizeof(char)*(nbLettreAvantSeparateur(separateur, chaine, ligne)+1));
	/*Stock le mot dans le tableau */
	rtnchaine[ligne]=token;
	ligne++;
	while(token!=NULL){
		/* Alloue la taille du mot à la ligne suivante */
		rtnchaine[ligne]=malloc(sizeof(char)*(nbLettreAvantSeparateur(separateur, chaine, ligne)+1));
		if(rtnchaine[ligne]==NULL){
			printf("Erreur rtnchaine[%d] NULL\n", ligne);
			free(rtnchaine);
			return NULL;
		}
		/*Stock le mot dans token */
		token = strtok(NULL, separateur);
		/*Stock le token au tableau */
		if(token!='\0'){
			printf("%s\n\n", token);
			rtnchaine[ligne]=token;
			ligne++;
		}
	}
	return rtnchaine;
}

/*
* Fonction de test();
*
*/
void testsplit(){
	char chaine[] = "coucou je suis fort";
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