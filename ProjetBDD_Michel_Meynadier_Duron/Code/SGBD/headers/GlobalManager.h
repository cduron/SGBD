#ifndef GLOBALMANAGER_H
#define GLOBALMANAGER_H


/* Structure d'une relation */
struct RelSchema {
	/*Nom de la relation ex: CREATE */
	char *nom;
	/* Nombre maximum d'argument du Schema */
	int nombreColonnes;
	/* Type de colonnes */ 
	char *typeColonnes;
};


/* Structure RelDef contenant les informations associées à une relation */
struct RelDef {
	/* Schéma de la relation */
	struct RelSchema Schema;
	/* Identifiant du fichier */
	int FileId;
	/* Taille d'un record en octets quand on l'écrit sur une page */
	int RecordSize;
	/* Nombre total de cases sur une page */
	int SlotCount;
};

/* Structure DbDef listant les relations existantes dans la DB */
struct DbDef {
	/* "liste" des relations existantes */
	struct RelDef *listeRelations;
	/* nombres de relations */
	int compteurRelations;
};



/* Initialisation de l'application */
void init();

#endif /* GLOBALMANAGER_H */
