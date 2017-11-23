#ifndef RECORD_H_
#define RECORD_H_

/* Création de la structure Record */
typedef struct Record {
  char **ptrrecord;
} Record;

//Fonction permettant de stocker les valeurs entrées en arguments, en tant que valeurs des attributs du Record
void setValues (char *valeurs, int nbcolonnes, Record record);


#endif /* RECORD_H_ */
