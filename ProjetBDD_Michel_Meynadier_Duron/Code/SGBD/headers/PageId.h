/*
 * PageId.h
 *
 *  Created on: 21 sept. 2017
 *      Author: ii05586
 */

#ifndef PAGEID_H_
#define PAGEID_H_

/* Structure d'une Page */
typedef struct PageId {
  int fileId;
  int idX;
} PageId;

/* Fonction qui créé un fichier Data_FileId.rf en vue d’y stocker des records par la suite */
void createFile(int fileId);

/* Fonction qui rajoute une page au fichier spécifié par le champ FileIdx
et qui retourne un PageId correspondant à l’id de la page nouvellement rajoutée */
int addPage(int fileIdx);

/* Fonction permettant de remplir l'argument Buffer avec le contenu de la page identifée par PageId */
void readPage(PageId page, unsigned char *buffer);

/* Fonction permettant l'écriture du contenu de l'argument Buffer dans le fichier dont l'id correspond à l'argument PageId */
void writePage(PageId page, unsigned char *Buffer);

/*Fonction qui passe FileIdx en chaine de caracteres et crée une chaine de caracteres correspondant à l'adresse du fichier */
void nameFile(int fileIdx, char * adresse);

#endif /* RELSCHEMA_H_ */
