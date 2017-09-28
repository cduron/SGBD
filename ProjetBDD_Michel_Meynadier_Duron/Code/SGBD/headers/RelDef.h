#ifndef RELDEF_H_
#define RELDEF_H_

/* Structure RelDef contenant les informations associées à une relation */
typedef struct RelDef {
	/* Schéma de la relation */
	struct RelSchema;
	/* Identifiant du fichier */
	int FileId;
};

#endif /* RELDEF_H_ */
