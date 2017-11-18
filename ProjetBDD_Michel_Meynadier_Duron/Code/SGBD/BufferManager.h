

#ifndef BUFFERMANAGER_H
#define BUFFERMANAGER_H

#include "PageId.h"
/*
*	Structure d'une frame
*	le buffer permet de stocker une page
*	pageId est l'id de la page ouverte
*	le flag permet de savoir si le fichier a été modifier ou non
*	pinCount permet si une frame est occupée
*/


/* Fonction d'initialisation de la structure frame */
void initStructure();
/* Récupère une page pour la mettre dans le buffer pool */
void getPage(PageId pageId);
/* rend une page et spécifie si elle a été modifiée ou non */
void freePage(PageId pageId, char isDirty);

#endif /* BUFFERMANAGER_H */
