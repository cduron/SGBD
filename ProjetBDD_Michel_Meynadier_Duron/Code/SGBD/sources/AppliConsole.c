/*
 *	AppliConsole.c
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../headers/split.h"
#include "../headers/AppliConsole.h"
#include "../headers/GlobalManager.h"

/*
 * fonction traitementConsole : permet de lire les commandes entrées par l'utilisateur et d'appeler les fonctions
 * correspondantes
 * param commande : commande en console de l'utilisateur
 */
void traitementConsole(char *commande){
	char s[1] = " ";

	//Copie de la Chaîne de commande à partir du 2ème mot : soit après l'opérateur (insert,join etc..)
	char * c2 ;
	while(c2==NULL){
		c2=malloc(sizeof(char)*strlen(commande));
		if(c2==NULL){
			printf("Erreur d'affectation");
		}
	}
	strcpy(c2,commande+(nbLettreAvantSeparateur(s,commande)));


	char *token;
	//token prend la valeur du premier mot de la chaîne commande [Opérateur]
	token = strtok(commande,s);

	//Si la commande est un insert
	if(strcmp(token,"insert")==0){
		char * c3;
		while(c3==NULL){
			c3=malloc(sizeof(char)*strlen(c2));
			if(c2==NULL){
				printf("Erreur d'affectation");
			}
		}

		//Pour faire un insert, il faut le nom de la relation : 2ème élément de la chaîne commande
		token = strtok(NULL,s);
		char * nomRelation = token;

		//Puis on fait le insert avec comme liste de Valeurs la suite de la chaîne commande
		strcpy(c3,c2+strlen(token)+1);
		insert(nomRelation,c3);

		free(c3);
	}

	else {
		if (strcmp(token,"exit")==0){
		}

	}
	free(c2);

}
