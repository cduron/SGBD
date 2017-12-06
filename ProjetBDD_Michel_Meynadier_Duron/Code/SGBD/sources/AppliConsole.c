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
	char *separateur = " ";
	//Copie de la Chaîne de commande à partir du 2ème mot : soit après l'opérateur (insert,join etc..)
	char *token;
	//token prend la valeur du premier mot de la chaîne commande [Opérateur]
	token = strtok(commande, separateur);
	int taille=strlen(token)+1;
	//Si la commande est un insert
	if(strcmp(token,"insert")==0){
		char *c3;
		c3=malloc(sizeof(char)*strlen(commande));
		token = strtok(NULL, separateur);
		strcpy(c3, (commande+taille+strlen(token)+1));
		char * nomRelation = token;
		printf("%s", token);
		printf("%s", nomRelation);
		printf("C3 : %s\n", c3);
		insert(nomRelation,c3);
		printf("insert réussi");

	}
	//Pour faire un insert, il faut le nom de la relation : 2ème élément de la chaîne commande


	//Puis on fait le insert avec comme liste de Valeurs la suite de la chaîne commande

	else {
		if (strcmp(token,"exit")==0){
		}

	}

}
