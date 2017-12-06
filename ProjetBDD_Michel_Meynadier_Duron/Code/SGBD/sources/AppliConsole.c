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
	
	//Si l'opérateur est un fill : permet d'insérer le contenu situé dans un ficher dans un record de la relation nommée en 2ème argument
	else if (strcmp(token,"fill")==0){
		char * c2;
		c2=malloc(sizeof(char)*strlen(commande));
		token = strtok(NULL,separateurEspace);
		strcpy(c2, (commande+taille+strlen(token)+1));
		//On extrait le nom de la relation
		char * nomRelation = token;
		FILE* fichier = NULL;
		char * chaineFichier;
		// On extrait le nom du fichier
		chaineFichier = malloc(sizeof(char)*40);
		char adresse [15]= "../DB/";
		strcat(adresse, c2);
		fichier = fopen(adresse, "r");
	  	char chaine[100000] = "";
		//On lit les lignes du fichier
		if (fichier != NULL){
			while (fgets(chaine, 100000, fichier) != NULL)
			{
				printf("%s", chaineFichier);
				strcat(chaineFichier,chaine);
			}
		}else
			printf("Fichier non ouvert");
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
		}
		insert (nomRelation, chaineFichierFinal);	//on créer le record avec cette chaine
		free(c2);
		free(chaineFichierFinal);
		free(chaineFichier);
        fclose(fichier);

	}
	//Si l'utilisateur fait un exit
	else if (strcmp(token,"exit")==0){
		finish();
	}
}
