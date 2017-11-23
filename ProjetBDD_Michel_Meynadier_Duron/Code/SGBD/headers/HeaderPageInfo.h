#ifndef HEADERPAGEINFO_H_
#define HEADERPAGEINFO_H_



/*Creéation d'une liste chainee de couples d'entiers */
typedef struct TabCouples TabCouples;
struct TabCouples{
	int  IdxPage;
	int NbSlotsRestantDisponible;
    TabCouples *nxt;
};

/* Création de la structure HeaderPageInfo */
typedef struct HeaderPageInfo {
  int NbPageDeDonnees;
  struct TabCouples tableauCouples;
}
HeaderPAgeInfo;

#endif /* HEADERPAGEINFO_H_ */
