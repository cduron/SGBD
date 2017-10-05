#ifndef DbDef_H_
#define DbDef_H_
#include "../headers/RelDef.h"


/* structure element qui simule une liste de structures de type DbDef */
struct element {
	/* numero de l'element de la "liste" */
    int val;
    /* objet DbDef a cette instance de la "liste" */
    struct Dbdef *present;
    /* prochain objet de la "liste" */
    struct element *nxt;
};




/* Structure DbDef listant les relations existantes dans la DB */
struct DbDef {
	/* "liste" des relations existantes */
	struct element liste_relations;
	/* nombres de relations */
	int compteur_relations;
};


#endif /* DBDEF_H_ */
