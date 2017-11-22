#ifdef DEFSTRUCT_H
#define DEFSTRUCT_H

#include "PageId.h"





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