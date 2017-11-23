#ifndef HeapFile_H_
#define Heapfile_H_


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

void ajouterEnFin(ListeHeapFile *liste, HeapFile hf);
void createHeader();

#endif /* HeapFile_H_ */
