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
  int FileId;
  int Idx;
} PageId;

/* Fonction qui créé un fichier Data_FileId.rf en vue d’y stocker des records par la suite */
void createFile(int FileId);

/* Fonction qui rajoute une page au fichier spécifié par le champ FileIdx
et qui retourne un PageId correspondant à l’id de la page nouvellement rajoutée */
void addPage(int FileIdx);

/* Fonction permettant de remplir l'argument Buffer avec le contenu de la page identifée par PageId */
void readPage(int PageId, unsigned char *buffer);

/* Fonction permettant l'écriture du contenu de l'argument Buffer dans le fichier dont l'id correspond à l'argument PageId */
void writePage(int PageId, unsigned char *Buffer);

#endif /* RELSCHEMA_H_ */
