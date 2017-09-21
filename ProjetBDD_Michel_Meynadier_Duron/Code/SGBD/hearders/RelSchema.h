/*
 * Struct.h
 *
 *  Created on: 14 sept. 2017
 *      Author: ii05586
 */

#ifndef RELSCHEMA_H_
#define RELSCHEMA_H_

/* Structure d'une relation */
typedef struct RelSchema {
	/*Nom de la relation ex: CREATE */
	char *nom;
	/* Nombre maximum d'argument du Schema */
	int nombre_colonnes;
	/* Type de colonnes */ 
	char *type_colonnes;
};


#endif /* RELSCHEMA_H_ */
