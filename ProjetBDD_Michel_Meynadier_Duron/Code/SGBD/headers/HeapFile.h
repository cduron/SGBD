#ifndef HeapFile_H_
#define Heapfile_H_


/* Structure Heapfile listant les relations existantes dans la DB */
struct HeapFile {
	/* pointeur vers une structure de type RelDef */
	struct RelDef *ptrRelDef;
};

struct ListeHeapFile {
	struct HeapFile present;
	struct HeapFile *nxt;
};

void createHeader();

#endif /* HeapFile_H_ */
