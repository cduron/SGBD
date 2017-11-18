

#ifndef BUFFERMANAGER_H
#define BUFFERMANAGER_H




/* Fonction d'initialisation de la structure frame */
void initStructure();
/* Récupère une page pour la mettre dans le buffer pool */
void getPage(PageId pageId);
/* rend une page et spécifie si elle a été modifiée ou non */
void freePage(PageId pageId, char isDirty);

#endif /* BUFFERMANAGER_H */
