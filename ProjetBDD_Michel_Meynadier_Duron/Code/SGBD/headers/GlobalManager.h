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

/* Creer une relation, c'est a dire une structure de type RelDef */
void createRelation(char *nomRelation, int nombreColonnes, char *typesDesColonnes);

/* Créer un fichier "Catalog.def" et ecrit le contenu de dbDef1 dans ce fichier */
int finish();

/* Pour chaque relation existante dans la BDD creer une structure HeapFile correspondante et l'ajoute a
 * la liste listHeapFile.*/
void refreshHeapFiles();

/* Fonction insert */
void insert (char * nomRelation, char * listeValeurs);

/* Initialisation de l'application */
void init();

#endif /* GLOBALMANAGER_H */
