#ifndef HeapFile_H_
#define Heapfile_H_

#include "PageId.h"
#include "Record.h"

/* Structure Heapfile listant les relations existantes dans la DB */
typedef struct HeapFile {
	/* pointeur vers une structure de type RelDef */
	struct RelDef *ptrRelDef;
}
HeapFile;

/* Liste chaîné d'HeapFile */
typedef struct ListeHeapFile{
	/* Un HeapFile */
	struct HeapFile present;
    /* Accès au HeapFile suivant */
    struct ListeHeapFile *nxt;
}ListeHeapFile;

/* Liste chaîné des références des pages et du nombre de slots disponibles */
typedef struct TabCouples TabCouples;
struct TabCouples{
	int  *IdxPage;
	int *NbSlotsRestantDisponible;
};

/* Création de la structure HeaderPageInfo */
typedef struct HeaderPageInfo {
	int NbPageDeDonnees;
  	struct TabCouples tableauCouples;
}HeaderPageInfo;


/* Création de la structure PageBitmapInfo */
typedef struct PageBitmapInfo {
	char *SlotStatus;
}PageBitmapInfo;

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

/* Remplit la liste dans la PageBitmapInfo avec les informations dans la bitmap du buffer */
void readPageBitmapInfo(char *buffer, struct PageBitmapInfo pbi);

/* Ecrit  au début du buffer la bitmap donnée par la liste d’octets de la PageBitmapInfo */
void writePageBitmapInfo(char *buffer, struct PageBitmapInfo pbi);

/* Ecrit les champs du record à l’offset indiqué par l’argument */
void writeRecordInBuffer(struct Record rec, char *buffer, int offset);

/* Ajoute une page de données */
PageId addDataPage();

#endif /* HeapFile_H_ */
