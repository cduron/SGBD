/*split.c*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include "../headers/split.h"

/*
* nbLettreAvantSeparateur	: permet de retourner le nombre de caractère d'un mot dans une phrase
*  param char *separateur	: un séparateur de mots
*  param char *phrase		: une chaine de caractère
*  return int cptLettre		: nombre de lettre dans un mot
*   
*/
int nbLettreAvantSeparateur(char *separateur, char*phrase){
	int cptLettre = 0;
	
	while((phrase[cptLettre]!=*separateur)&&(phrase[cptLettre]!='\0'))
		cptLettre++;
	return cptLettre;
}

/*
* nbLettreAvantSeparateur	: permet de retourner le nombre un mot dans une phrase
*  param char *separateur	: un séparateur de mots
*  param char *phrase		: une chaine de caractère
*  return int cptMot		: nombre de mot
*   
*/
int nbMotAvantSeparateur(char *separateur, char*phrase){
	int cptMot = 1, cptLettre=0;
	while(phrase[cptLettre]!='\0'){
		cptLettre++;
		if(phrase[cptLettre]==*separateur){
			cptMot++;
		}
	}			
	return cptMot;
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

char **split(char *chaine, char* separateur){
	int ligne=0;
	char *token;
	int nbColonne = nbMotAvantSeparateur(" ", chaine);
	/* Alloue le tableau de retour */
	char ** rtnchaine;
	while(rtnchaine == NULL){
		rtnchaine=malloc(sizeof(char*)*(nbColonne+1));
		if(rtnchaine==NULL)
		{
			printf("Erreur rtnchaine NULL\n");
			free(rtnchaine);
		}
	}
	/*Affecte le premier mot dans token */
	token=strtok(chaine, separateur);
	/*Alloue la taille du mot à la ligne 0 */
	while(rtnchaine[ligne]==NULL){
		rtnchaine[ligne]=malloc(sizeof(char)*(nbLettreAvantSeparateur(separateur, chaine)+1));
	}
	/*Stock le mot dans le tableau */
	rtnchaine[ligne]=token;
	ligne++;
	while(token!=NULL){
		/* Alloue la taille du mot à la ligne suivante */
		while(rtnchaine[ligne]==NULL){
			rtnchaine[ligne]=malloc(sizeof(char)*(nbLettreAvantSeparateur(separateur, chaine)+1));
			if(rtnchaine[ligne]==NULL){
				printf("Erreur rtnchaine[%d] NULL\n", ligne);
				free(rtnchaine);
			}
		}
		/*Stock le mot dans token */
		token = strtok(NULL, separateur);
		/*Stock le token au tableau */
		if(token!='\0'){
			rtnchaine[ligne]=token;
			ligne++;
		}
	}
	return rtnchaine;
}
