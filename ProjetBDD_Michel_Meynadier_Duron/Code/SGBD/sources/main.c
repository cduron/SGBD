/*
 *	main.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/GlobalManager.h"
#include "../headers/AppliConsole.h"

int main(){
	/*initStruct();
	struct RelSchema k = {"nani", 3, "yamero"};
	struct RelDef a={k, 6, 5, 4};
	struct RelDef *b= malloc(sizeof(*b));
	b = &a;
	struct DbDef def={b, 3};
	struct ListeHeapFile *listeHeapfile = malloc(sizeof(*listeHeapfile));
	struct  HeapFile hf = {b};
	    if (listeHeapfile == NULL)
	    {
	        exit(EXIT_FAILURE);
	    }
	    listeHeapfile->nxt = NULL;
	    listeHeapfile->present = hf;
	printf("compteur de relations: %d\n", def.compteurRelations);
	ajouterEnFin(listeHeapfile, hf);
	printf("-> %d\n", hf.ptrRelDef->FileId );
	ListeHeapFile *actuel = listeHeapfile;
	while (actuel->nxt != NULL)
		{
			printf("-> %d\n", actuel->present.ptrRelDef->FileId);
			actuel = actuel->nxt;

		}
    printf("NULL\n");
	//createHeader(hf);*/
	printf("Bienvenue dans notre superbe BDD.\nSaisissez votre requête!\n");
	fflush(stdout);
	char *commande;
	while(commande==NULL){
		commande=malloc(sizeof(char)*500);
		if(commande==NULL)
			printf("Erreur affectation");
	}
	gets(commande);
	traitementConsole(commande);
	return(0);

}
