#include <stdio.h>
#include <stdlib.h>
#include "diff.h"
/*
void father_copy(char **tableauFichierOuvert, int nbTarget){
	char extend[2][5];
	int x,j,i=0,length=0,flag=1;
	for(j=0;j<nbTarget;j++){
		length=nombreCharacteChaine(tableauFichierOuvert[j]);
		//while(tableauFichierOuvert[j][length]!='.'){
		x=length;
		flag=1;
		i=0;
		while(flag != 0){
			if(tableauFichierOuvert[j][length]=='.'|| flag == 2){
				flag =2; 
				length++;
				extend[j][i] = tableauFichierOuvert[j][length];
				printf("%c",extend[j][i]);
				i++;
				if(length==x) flag=0;
				
			}else{
				if(length==0) {
					flag=0;
				}
			 	length--;

			}
		}
//
	printf("\n");	
	}
}

char *getExtension(char *target){


	/////////////////////////////////////////
	int i = 0;
	int k = 0 ;
	char extension[10];

	k = nombreCharacteChaine(*target);

	while(k>0 || target[k] == '.'){
		//extension[i]= target[k];
		
		printf("%c",target[i]);
		i++;
		k--;
	}
	return extension;
}
*/


//Fonction qui compte le nombres de charactere dans une chaine on rajoute +1 pour le /0
/*int nombreCharacteChaine(char *maChaine){
	int nb = strlen(maChaine);
	return nb+1;
}*/
int nombreCharacteChaine(char *str) {

    int size = 0;
    while (*str != '\0') 
    {
        str++;
        size++;
    }
    return size;
}

//Fonction qui compte le nombres de lignes d'un fichier
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

//fonction diff
char * diffNormal(FILE * f1, FILE * f2) {
	
	int i=1;int nbligne=0;int cpt_l1=0;int cpt_l2=0;int j=0;int comp=0;int k=0;int dernier_l_trouve=0;int nb_erreur=0;int trouve;
	char chaine;char chaine2;
	int resultat;
	cpt_l1 = nb_lignes(f1);
	cpt_l2 = nb_lignes(f2);
	if(cpt_l1<cpt_l2) comp=cpt_l2;
	else comp = cpt_l1;
	char delate[comp];
	char add[comp];
	char change[comp];
	char *temp[comp][4];
	
	char ligneCourante1[cpt_l1];
	char ligneCourante2[cpt_l2]; 
	int l =0;
    	//on boucle sur tout le fichier 2
	for(i;i<cpt_l2;i++){
       	trouve = 0;
       	ligneCourante2[i] = fgetl(f2,i,MAX_BUFFER); //on obtient la ligne de l'indice I
       	j=dernier_l_trouve+1;
       	while (j<cpt_l1 && trouve==0){
           	ligneCourante1[j] = fgetl(f1,j,MAX_BUFFER); //on obtient la ligne de l'indice J

           	//on compare les deux string, renvoi un entier
          	resultat = strcmp( ligneCourante1[j], ligneCourante2[i]);
           
           	//en fonction du resultat si différent noter les indices dans des tableaus Ajout[] Suppression[]
       		if (resultat != 0){
                              
				// printf ("%s  est donc inferieure a %s\n", s1, s2); // qui est inférieur ?
           	}else if (resultat == 0){
              	if(j != i){
					temp[nb_erreur][0] = 'd'; 
					printf("%c",temp[nb_erreur][0]);
					temp[nb_erreur][1] =dernier_l_trouve;
					printf("%i",temp[nb_erreur][1]);
					temp[nb_erreur][2] = j;
					printf("%i",temp[nb_erreur][2]);
					temp[nb_erreur][3] = i;
					printf("%i",temp[nb_erreur][3]);
					printf("\n");
					dernier_l_trouve = j;
					nb_erreur++;
		      	}
				// printf ("%s est donc égale a %s\n", s1, s2); // c'est egal on met trouve a 1
               	trouve = 1;
			}else{
             	//  printf ("%s est donc supérieure a %s\n", s1, s2); //qui est supérieur ?
            }
           	j++;
       	}
		if(j==cpt_l1 && i!=cpt_l2){
				
			temp[nb_erreur][0] = 'a'; 
			printf("%c",temp[nb_erreur][0]);
			temp[nb_erreur][1] =dernier_l_trouve;
			printf("%i",temp[nb_erreur][1]);
			temp[nb_erreur][2] = 0;
			printf("%i",temp[nb_erreur][2]);
			temp[nb_erreur][3] = i;
			printf("%i",temp[nb_erreur][3]);
			printf("\n");
								
			nb_erreur++;
			dernier_l_trouve--;
		}

   	}
	return temp;
}
