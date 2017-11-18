/*
 *	BufferManager.c
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../headers/BufferManager.h"
#include "../headers/Constante.h"
#include "../headers/PageId.h"

struct frame buffer_pool[F];

/**
* Initialisation des frames
*
*
*/ 
void initStruct(){
	for(int i = 0;i<F;i++){
		buffer_pool[i].buffer=NULL;
		buffer_pool[i].page.fileId=0;
		buffer_pool[i].page.idX=0;
		buffer_pool[i].flag='0';
		buffer_pool[i].pin_count=0;
	}
}

/**
*	La fonction getPage permet de retourner une page (buffer),
*	elle incrémente aussi le pin_count et s'occupe du remplacement d'une frame
*	
*	@param	int pageId, id de la page retourner.
*
*/

void getPage(PageId page){
	for(int i = 0;i<F;i++){
		if (buffer_pool[i].pin_count==0||buffer_pool[i].buffer==NULL)
		{
			readPage(page, buffer_pool[i].buffer);
			buffer_pool[i].pin_count++;
			buffer_pool[i].page=page;
		}
	}

}

/**
*	La fonction freePage rend une page et spécifie si elle a été modifié ou non
*
*
*
*/

void freePage(PageId page, char isDirty){
	for (int i = 0; i < F; ++i)
	{
		if(buffer_pool[i].page.fileId == page.fileId && buffer_pool[i].page.idX == page.idX){
			buffer_pool[i].pin_count--;
			buffer_pool[i].flag=isDirty;
		}
	}
}



int main(){
	initStruct();
	int fileId = 1;
	unsigned char * buffer = malloc(sizeof(char)*TAILLE);
	struct PageId page = {1, 0};
	
	createFile(fileId);
	addPage(fileId);
	for(int i = 0 ; i<5; i++){
		buffer[i]='C';
	}

	writePage(page, buffer);
	unsigned char * buffer2 = malloc(sizeof(char)*TAILLE);
	readPage(page, buffer2);
	printf("%s",buffer2);
	free(buffer);
	return 0;
}
