/*
 * Fichier HeapFile.c
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../headers/BufferManager.h"
#include "../headers/HeapFile.h"
#include "../headers/PageId.h"
#include "../headers/GlobalManager.h"
#include "../headers/Constante.h"

frame buffer_pool[F];

// Declaration de listeHeapFile qui est une liste chainee d'elements de type HeapFile
struct ListeHeapFile *listeHeapFile;

/*
 * Fonction createHeader : Création d'une HeaderPage
 * Param HeapFile hf : HeapFile
*/
void createHeader(struct HeapFile hf){
	int idX = addPage(hf.ptrRelDef->FileId);
	PageId pageHeapFile = {hf.ptrRelDef->FileId, idX};
	char *buffer;
	while(buffer==NULL){
		buffer= malloc(sizeof(char)*TAILLE);
		if(buffer==NULL){
			printf("Erreur affectation");
		}
	} 
	buffer="0";
	writePage(pageHeapFile, buffer);
	getPage(pageHeapFile);
	freePage(pageHeapFile, '1');
}

/*
 * Fonction ajouterEnFin : Ajout d'un HeapFile a là fin d'une liste chainee ListeHeapFile
 * Param ListeHeapFile *liste : la liste des HeapFiles
 * Param HeapFile hf : le HeapFile que l'on veut ajouter
 */
void ajouterEnFin(struct ListeHeapFile *liste, struct HeapFile hf){
	ListeHeapFile *nouvelHf;
	while(nouvelHf == NULL){
		nouvelHf= malloc(sizeof(*nouvelHf));	
		if(nouvelHf==NULL){
			printf("Erreur affectation");
		}
	}
	nouvelHf->present = hf;
	nouvelHf->nxt = NULL;
	if(liste == NULL){
		liste = nouvelHf;
	}
	else
	{
		ListeHeapFile* temp=liste;
		while(temp->nxt != NULL)
		{
			temp = temp->nxt;
		}
		temp->nxt = nouvelHf;
	}
}

/*
 * Fonction readHeaderPageInfo : lecture du HeaderPage et affectation des Info dans le HeaderPageInfo
 * Param char *buffer : buffer contenant les information du Header
 * Param HeaderPageInfo hpi : Stockage des information du Header
 */
void readHeaderPageInfo(char *buffer, struct HeaderPageInfo hpi){
	hpi.NbPageDeDonnees = strtol(buffer,NULL,10);
	hpi.tableauCouples.IdxPage = malloc(sizeof(char)*hpi.NbPageDeDonnees);
	for(int i =0, j=0; i<hpi.NbPageDeDonnees || j<hpi.NbPageDeDonnees; i++, j+2){
		hpi.tableauCouples.IdxPage[i]=buffer[j];
		hpi.tableauCouples.NbSlotsRestantDisponible[i]=buffer[j+1];
	}
	free(buffer);
}


/*
 * Fonction writeHeaderPageInfo : Ecriture du HeaderPage
 *
 * Param char * buffer : buffer qui contiendra les informations du Header
 * Param HeaderPageInfo hpi : Information du header
 */
void writeHeaderPageInfo(char *buffer, struct HeaderPageInfo hpi){
	sprintf(buffer, "%d", hpi.NbPageDeDonnees);
	for(int i =0, j=0; i<hpi.NbPageDeDonnees || j<hpi.NbPageDeDonnees; i++,j+2){
		buffer[j]=hpi.tableauCouples.IdxPage[i];
		buffer[j+1]=hpi.tableauCouples.NbSlotsRestantDisponible[i];
	}
}


/*
 * Fonction writeHeaderPageInfo : Permet de récupérer le HeaderPageInfo
 * 
 * Param HeaderPageInfo hpi : Header déjà instancié.
 */
void getHeaderPageInfo(struct HeaderPageInfo hpi){
	PageId idHeader = {0, 0};
	getPage(idHeader);
	readHeaderPageInfo(buffer_pool[0].buffer,hpi);
	freePage(idHeader,'0');
}


/*
 * Fonction updateHeaderNewDataPage : Permet de mettre à jour le HeaderPage, par rapport à une nouvelle page
 * 
 * Param PageId nwpage : Id de la nouvelle page récement créer.
 */

void updateHeaderNewDataPage(PageId nwpage){
	char *buffer = buffer_pool[0].buffer;
	HeaderPageInfo hpi;
	readHeaderPageInfo(buffer, hpi);
	hpi.tableauCouples.IdxPage=nwpage.idX;
	hpi.tableauCouples.NbSlotsRestantDisponible=listeHeapFile->present.ptrRelDef->SlotCount;
	writeHeaderPageInfo(buffer, hpi);
	free(buffer);
}


/*
 * Fonction updateHeaderTakenSlot : Permet de mettre à jour le HeaderPage, par rapport à une nouvelle page
 * 
 * Param PageId nwpage : Id de la nouvelle page récement créée.
 */

void updateHeaderTakenSlot(PageId page){
	HeaderPageInfo hpi;
	char *buffer = buffer_pool[0].buffer;
	readHeaderPageInfo(buffer, hpi);
	hpi.tableauCouples.NbSlotsRestantDisponible--;
}