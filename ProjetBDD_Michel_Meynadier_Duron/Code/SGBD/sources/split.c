/*split.c*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "../headers/split.h"

/*
* nbLettreAvantSeparateur	: permet de retourner le nombre de caractère d'un mot dans une phrase
*  param char *separateur	: un séparateur de mots
*  param char *phrase		: une chaine de caractère
*  param int numeroMot 		: place du mot
*  return int cptlettre		: nombre de lettre dans un mot
*   
*/
int nbLettreAvantSeparateur(char *separateur, char*phrase, int numeroMot){
	int cptlettre = 0;
	while((phrase[cptlettre]!=' ')&&(phrase[cptlettre]!='\0'))
		cptlettre++;
	return cptlettre;
}


/*
* Split 					: permetant de séparer une chaine de caracteres en un tableau de chaines de caracteres.
*  param char *chaine 		: est la chaine de caractère que l'on veut séparer
*  param char *separateur 	: chaine de caractères de séparation de la chaine de caractères
*  return rtnchaine 		: tableau de chaines de chaines de caractères
* 
*
*  var char* token			: permet de récuperer les mots
*  var int ligne			: compteur de ligne
*/

char **split(char *chaine, char* separateur, int nbcolonne){
	int ligne=0;
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