#ifndef RELDEF_H_
#define RELDEF_H_
#include <stdio.h>
#include "../headers/RelSchema.h"

/* Structure RelDef contenant les informations associées à une relation */
struct RelDef {
	/* Schéma de la relation */
	struct RelSchema Schema;
	/* Identifiant du fichier */
	int FileId;
};


#endif /* RELDEF_H_ */

