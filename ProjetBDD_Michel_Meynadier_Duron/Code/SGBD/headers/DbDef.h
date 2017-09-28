#ifndef DbDef_H_
#define DbDef_H_

/* Structure DbDef listant les relations existantes dans la DB */
struct DbDef {
	/* Array des relations existantes */
//	struct list liste_relations;
	/* nombres de relations */
	int compteurRelations;
};

struct list
    {
        struct  RelDef ;
        struct list *next;
    };

#endif /* DBDEF_H_ */
