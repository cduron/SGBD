#ifndef RECORD_H_
#define RECORD_H_

/* Création de la structure Record */
typedef struct Record {
  char **ptrrecord;
} Record;

void setValues (char *valeurs, int nbcolonnes);


#endif /* RECORD_H_ */
