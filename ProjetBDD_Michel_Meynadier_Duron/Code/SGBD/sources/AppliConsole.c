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
void traitementConsole(char commande[]){

	const char s[1] = " ";
	char *token;
	token = strtok(commande,s);
	printf("Commande : %s\n",token);
	if(strcmp(token,"insert")==0){
		char * nomRelation;
		nomRelation = strtok(NULL,commande);
		printf("nomRel : %s\n",nomRelation);
		char *listeValeurs;
		int i=0;
		while( token != NULL ) {
			printf("Liste des valeurs : %s   ",token);
			//*(listeValeurs+i)= strtok(NULL, commande);
			token = strtok(NULL, s);
		}
		/*printf("%s",listeValeurs);
		insert (nomRelation,listeValeurs);*/
	}

	else {
		if (strcmp(token,"exit")==0){
		}

	}
}
