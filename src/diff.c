#include <stdio.h>
#include <stdlib.h>
#include "diff.h"



void diff(char * parametre) {
	printf("Salut %s\n", parametre);
	
}
/**
	--normal                  Produire un « diff » en format normal (par défaut)
*/
void normal(FILE * f1, FILE * f2) {
	int car2fich1;
	int car2fich2;
	int ligne=0;
	// Boucle de parcour des fichiers
	do {
		car2fich1 = fgetc(f1);
		car2fich2 = fgetc(f2);
		// Si les deux caractere sont diferrent
		if (car2fich1 != car2fich2) {
			//flag=0;
		}
		printf("c1=%i \t c1=%i \t c2=%i \t c2=%c\n", car2fich1, car2fich1, car2fich2, car2fich2);
		
	} while (car2fich1 != EOF || car2fich2 != EOF);
}



/**
	-q, --brief
		Indiquer seulement si les fichiers diffèrent
		return 0 s'ils sont different et 1 s'ils sont égaux
*/
int brief(FILE * f1, FILE * f2) {
	int car2fich1;
	int car2fich2;
	int flag=1;
	int ligne=0;
	// Boucle de comparaison
	do {
		car2fich1 = fgetc(f1);
		car2fich2 = fgetc(f2);
		// Si les deux caractere sont diferrent
		if (car2fich1 != car2fich2) {
			flag=0;
		}
		printf("car2fich1=%i \t\t car2fich1=%i\n", car2fich1, car2fich2);
		
	} while (car2fich1 != EOF || car2fich2 != EOF);
	
	return flag;
}
/**
	Fonction qui compte la taille du fichier
*/
int taille_fichier(FILE * f) {
	int car;
	int i=0;
	do {
		car = fgetc(f);
		i++;
	} while (car != EOF);
	
	return i;
}


/**
	Fonction qui compte le nombres de lignes d'un fichier
*/
int nb_lignes(FILE * f) {
	int car;
	int i=1;
	do {
		car = fgetc(f);
		if (car == LF) {
			i++;
		}
	} while (car != EOF);
	
	return i;
}


/**
	Lit le fichier ligne par ligne
	int index - lit la ligne indiquée
*/
char * fgetl(FILE * f, int index, int taille_max) {
	int car;
	int i=0;
	char * ligne = malloc(sizeof(char) * taille_max);
	int nb_lignes = 1;
	// Boucle de parcour du fichier
	do {

		car = fgetc(f);

		// Si la ligne actuel est egale a la ligne indiquer
		if (nb_lignes == index) {
			// on lit la ligne et si on passe a la ligne on arrete
			if (  (car != LF)  &&  (i<(taille_max-1))  ) {
				ligne[i] = car;
				i++;
			} else {
				break;
			}
		}

		if (car == LF) {
			nb_lignes++;
		}


	} while (car != EOF);
	ligne[i] = '\0';
	return ligne;
}






