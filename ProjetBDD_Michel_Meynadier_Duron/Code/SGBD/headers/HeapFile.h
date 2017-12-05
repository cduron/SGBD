#ifndef HeapFile_H_
#define Heapfile_H_

#include "PageId.h"

/* Structure Heapfile listant les relations existantes dans la DB */
typedef struct HeapFile {
	/* pointeur vers une structure de type RelDef */
	struct RelDef *ptrRelDef;
}
HeapFile;

typedef struct ListeHeapFile ListeHeapFile;
struct ListeHeapFile{
	struct HeapFile present;
    ListeHeapFile *nxt;
};


typedef struct TabCouples TabCouples;
struct TabCouples{
	int  IdxPage;
	int NbSlotsRestantDisponible;
    struct TabCouples *nxt;
};

/* Création de la structure HeaderPageInfo */
typedef struct HeaderPageInfo {
  int NbPageDeDonnees;
  struct TabCouples tableauCouples;
}HeaderPageInfo;



/* Permet d'ajouter en fin de liste de HeapFile un HeapFile */
void ajouterEnFin(ListeHeapFile *liste, HeapFile hf);

/* Permet la creation du Header */
void createHeader();

/* Lecture du contenu du Directory dans un buffer */
void readHeaderPageInfo(char *buffer, struct HeaderPageInfo hpi);

/* */
void writeHeaderPageInfo(char *buffer, struct HeaderPageInfo hpi);

/* */
void getHeaderPageInfo(struct HeaderPageInfo hpi);


/* */
void updateHeaderNewDataPage(PageId nwpage);


#endif /* HeapFile_H_ */
