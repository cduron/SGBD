/*
 *	GlobalManager.c
 */
#include <stdio.h>
#include <string.h>
#include "/headers/GlobalManager.h"

void init (){
	printf("/**** Bienvenue dans l'interface de notre SGBD ******/ \n");
	scanf("%s", &saisie);


	if (&saisie=="exit"){
		printf("/*** Goodbye my lover, Goodbye my friend <3 ****/");
		exit();
	}
	printf("");

	printf("");
  
}
