#ifdef DEFSTRUCT_H
#define DEFSTRUCT_H

#include "PageId.h"
/* Structure RelDef contenant les informations associées à une relation */
struct RelDef {
	/* Schéma de la relation */
	struct RelSchema Schema;
	/* Identifiant du fichier */
	int FileId;
};


/* Structure d'une relation */
struct RelSchema {
	/*Nom de la relation ex: CREATE */
	char nom;
	/* Nombre maximum d'argument du Schema */
	int nombre_colonnes;
	/* Type de colonnes */ 
	char type_colonnes;
};

/* Structure DbDef listant les relations existantes dans la DB */
struct DbDef {
	/* "liste" des relations existantes */
	struct RelDef *listeRelations;
	/* nombres de relations */
	int compteurRelations;
};

/*
*	Structure d'une frame
*	le buffer permet de stocker une page
*	pageId est l'id de la page ouverte
*	le flag permet de savoir si le fichier a été modifier ou non
*	pinCount permet si une frame est occupée
*/

typedef struct frame
{
	unsigned char* buffer;
	PageId page;
	char flag;
	int pin_count;
}frame;


#endif