/*split.c*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NBMOT 15

//#include "split.h"

/*
* Split 				: permetant de séparer une chaine de caracteres en un tableau de chaines de caracteres.
*  param chaine 		: est la chaine de caractère que l'on veut séparer
*  param separateur		: de séparation de la chaine de caractères
*  return rtnchaine 	: tableau de chaines de chaines de caractères
* 
*
*  var int cptchar		: compte le nombre de caractère
*  var int ligne		: compteur de ligne
*  var int cptfirst 	: coordonné du de la première lettre d'un mot
*/
char ** split (char *chaine, char separateur, int nbMot){
	int cptchar=0, ligne=0, cptfirst=0;
	char *rtnchaine[nbMot+1];
	while(chaine[cptchar]=='\0'){
		printf("1");
		if(chaine[cptchar]==separateur){
			/* alloue dynamiquement à la taille exact du mot*/
			rtnchaine[ligne]=malloc(sizeof(char)*(cptchar+2-cptfirst));
			/* copie le mot trouver dans rtnchaine en prenant le */
			strncpy(rtnchaine[ligne], chaine+cptfirst, cptchar-1);
			if(rtnchaine[ligne]==NULL){
				printf("Erreur fatal, case %d vide", ligne);
				return NULL;
			}else
			printf("%s\n", rtnchaine[ligne]);

			ligne++;
			/* cptfirst devient la position de la première lettre du prochain mot */

			cptfirst=1+cptchar;
			printf("%d\n", cptfirst);
		}	
		/* passage au caractère d'après s'il est différent du séparateur */ 
		cptchar++;
	}

	return rtnchaine;
}

int main(){
	char *chaine = {
		"coucou je suis fort"
	};
	printf("%s\n", split(chaine, ' ', 4));
	return 0;
}