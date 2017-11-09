#ifndef DbDef_H_
#define DbDef_H_
#include "../headers/RelDef.h"



/* Structure DbDef listant les relations existantes dans la DB */
struct DbDef {
	/* "liste" des relations existantes */
	struct RelDef *listeRelations;
	/* nombres de relations */
	int compteurRelations;
};


#endif /* DBDEF_H_ */
