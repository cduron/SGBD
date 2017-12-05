

#ifndef BUFFERMANAGER_H
#define BUFFERMANAGER_H


#include "PageId.h"


/* Structure d'une Frame */
typedef struct frame
{
	/* buffer possédant le contenue d'une page */
	char* buffer;
	/* Id de la page contenue dans la frame */
	PageId page;
	/* flag permettant de voir savoir si elle a été modifié ou non */
	char flag;
	/* compteur d'utilisateur */
	int pin_count;
}frame;

/* Fonction d'initialisation de la structure frame */
void initStruct();
/* Récupère une page pour la mettre dans le buffer pool */
void getPage(PageId pageId);
/* rend une page et spécifie si elle a été modifiée ou non */
void freePage(PageId pageId, char isDirty);

#endif /* BUFFERMANAGER_H */
