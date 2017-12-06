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
<<<<<<< HEAD
	char *separateurEspace = " ";
	//Copie de la Chaîne de commande à partir du 2ème mot : soit après l'opérateur (insert,join etc..)
	char *token;
	//token prend la valeur du premier mot de la chaîne commande [Opérateur]
	token = strtok(commande, separateurEspace);
	int taille=strlen(token)+1;
	//Si la commande est un insert
	if(strcmp(token,"insert")==0){
		char *c2;
		c2=malloc(sizeof(char)*strlen(commande));
		token = strtok(NULL, separateurEspace);
		strcpy(c2, (commande+taille+strlen(token)+1));
		char * nomRelation = token;
		printf("%s", token);
		printf("%s", nomRelation);
		printf("C3 : %s\n", c2);
		insert(nomRelation,c2);
		printf("insert réussi");

	}

	else if (strcmp(token,"fill")==0){
		char * c2;
		c2=malloc(sizeof(char)*strlen(commande));
		token = strtok(NULL,separateurEspace);
		strcpy(c2, (commande+taille+strlen(token)+1));
		char * nomRelation = token;
		FILE* fichier = NULL;
		char * chaineFichier;
		chaineFichier = malloc(sizeof(char)*40);
		char adresse [15]= "../DB/";
		strcat(adresse, c2);
		printf("%s\n", adresse);
		fichier = fopen("../DB/R1.csv", "r");
	    char chaine[1000] = "";
		printf("prout\n");
		if (fichier != NULL){
			while (fgets(chaine, 1000, fichier) != NULL)
			{
				printf("%s", chaineFichier);
				strcat(chaineFichier,chaine);
			}
		}else
			printf("Fichier non ouvert");
		printf("HOLLA AMIGO !");
		char* chaineFichierFinal;
		int mst = strlen(chaineFichier)+1;
		printf("%d", mst);
		chaineFichierFinal=malloc(sizeof(char)*strlen(chaineFichier+1));

		char *separateurPointVirgule = ",";
		fflush(stdout);

		char *token2 = strtok(chaineFichierFinal, separateurPointVirgule);

		strcpy(chaineFichierFinal, token2);
		printf("%d", (int)strlen(chaineFichier));
		for (int i=1; i<strlen(chaineFichier); i++){
			token2 = strtok(NULL, separateurPointVirgule);
			strcat(chaineFichierFinal, token2);
=======
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
>>>>>>> b53867ba47a10e7a5dd503024e5095482ae128e1

		}
		insert (nomRelation, chaineFichierFinal);	//on créer le record avec cette chaine
		free(c2);
		free(chaineFichierFinal);
		free(chaineFichier);
        fclose(fichier);

	}
<<<<<<< HEAD

	else if (strcmp(token,"exit")==0){
		finish();
	}
=======
>>>>>>> b53867ba47a10e7a5dd503024e5095482ae128e1

}
