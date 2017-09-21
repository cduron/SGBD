/*
 *	main.c
 */
#include <stdio.h>
#include <string.h>
#include "menu.h"
#include "RelSchema.h"


int main (){
	RelSchema relation1;
	char requete[100];
	char *recup = malloc(sizeof(recup)*strlen(requete));
	char *p = requete;
	printf("Saisir votre requete");
	scanf("%s", requete);
	int j= 0;

	for(int i = 0 ;i<strlen(requete);i++){

		if(requete[i]==' '){
			recup=str_sub(requete, j, i-1);
			j=i+1;
		}
		p++;
	}


}

/*
 * Function Split, to substring of only one word
 */
char *str_sub (char str[], )
{
  char * pch;
  printf ("Splitting string \"%s\" into tokens:\n",str);
  pch = strtok (str," ");
  return pch;
}
