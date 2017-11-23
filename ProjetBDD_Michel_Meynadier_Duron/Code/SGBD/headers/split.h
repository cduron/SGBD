/*split.h */ 


#ifndef SPLIT_H
#define SPLIT_H

/* Fonction permettant de séparer une chaine de caractères en un tableau de chaînes */

char ** split (char *chaine, char* separateur);

/* Fonction permettant de calculer le nombre de lettre Avant le separateur */

int nbLettreAvantSeparateur(char *separateur, char*phrase);

/* Fonction permettant de calculer le separateur en fonction du nombre de lettre */

int nbMotAvantSeparateur(char *separateur, char*phrase);

#endif

