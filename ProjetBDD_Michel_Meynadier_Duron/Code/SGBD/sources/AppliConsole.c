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
	//token prend la valeur du premier mot de la chaîne commande [chaîne de caractère située avant le " "]
	token = strtok(commande,s);

	//Si la commande est un insert
	if(strcmp(token,"insert")==0){
		//Pour faire un insert, il faut le nom de la relation : 2ème élément de la chaîne commande

		token = strtok(NULL,s);
		char * nomRelation = token;

		//Puis la liste des valeurs à insérer, les n valeurs suivantes
		char *listeValeurs = NULL;
		int i=0;
		while( token != NULL ) {
			token = strtok(NULL, s);
			//*(listeValeurs+i)=token;
			i++;
		}
		//insert (nomRelation,listeValeurs);
	}

	else {
		if (strcmp(token,"exit")==0){
		}

	}
}
