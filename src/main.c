//test lio
#include <stdio.h>
#include <stdlib.h>
#include "diff.h"

int main ( int argc, char** argv ) {
	int i;
    int j;
    int k;
    int nbOption = 0;
    int nbTarget = 0;
    int opti = 0;
    int targ = 0;
    
	int parametre;

//J'aime les naine avec plein de poils    
    
	if (2 > argc) {
        printf("Nombre de parametres insuffisants\n");
        return 1;
    }else{
        //je boucle pour compter le nombre d'élément de chaque
        for(j = 1; j < argc; j++) {
            if(argv[j][0] == '-') {
                if(argv[j][1] == '-'){
                	//il s'agit d'un grand argument
                	nbOption ++;
                }else if(nombreCharacteChaine(argv[j]) > 2){
                	//il nous faut eclater le nombre
                	nbOption += (nombreCharacteChaine(argv[j])-1);
                }else{
                	//il s'agit d'un argument normal
                	nbOption ++;
                }
            }else{
                nbTarget ++;
            }
        }
        // si j'ai bien 1 option et deux adresses minimum c'est bon
        if(nbOption > 0 && nbTarget == 2) 
        {
            char* target[nbTarget];
            char* option[nbOption];
            FILE *fichier[nbTarget];
            


            //j'isole les adresses dans un tableau et les option dans un autre
            for(j = 1; j <= argc; j++) {
                if(argv[j][0] == '-') {
                    if(argv[j][1] == '-'){
                    	//on recupere l'argument a therme on fera appel au fichier je pense
                    	//on fait sauter les deux --
                    	//option[opti] = argv[j][2];
                    	//opti ++;

                    	optionComplex[optiCompl] = &argv[j][2];
                    	optiCompl ++;


                    }else if(nombreCharacteChaine(argv[j]) > 2){
                    	//on a plus d'un parametre
                    	//le - est enlevé par k=1 et non 0
                    	for(k=1;k<=nombreCharacteChaine(argv[j]);k++){
                    		option[opti] = argv[j][k];
                    		opti ++;
                    	}
                    }else{
                    	//parametre normal
                    	// on enleve le -
                    	option[opti] = argv[j][1];
                    	opti ++;	
                    }
                    
                    
                }else{
                    target[targ] = argv[j];
                    targ ++;
                }
            }

            
            //j'ouvre une bonne fois pour toutes les deux fichier en cas d'erreur c'est qu'il n'existent pas
            for(i=0; i<=nbTarget;i++) {
            	if(fopen(target[i], "r+") != NULL) {
            		fichier[i] = fopen(target[i], "r+");
            	}else{
					printf("Impossible d'ouvrir le fichier %s\n", argv[1] );
                	return 1;
            	}
            }
            //si on arrive ici c'est que tout est bon on peut commencer le switch case.
            //on enverra juste le pointeur des fichier ouvert plus besoin de les ouvrire ou de faire des test
            //on attend la retour de lionel sur ce qui est attendu quand on rentre plusieur option


            

            for(i=0; i<=nbTarget;i++) {
               if (fichier[i] != NULL) {
                   fclose(fichier[i]);
               }
           }
    
        }
        else{
            printf("Parametres incorrect\n");
            return 1;
        }
    }
	
    
    
//------------------------------------séparation code egor -----------------------------------------
    
    
    
    
    
    
    
    
    
    /*
    
    
	
	// Parcours des paramètres
	for (i=1; i<argc; i++) {
		// Si la première lettre d'un paramètre est égale à un tiret
		if ( argv[1][0] == TIRET ) {
			parametre = argv[1][1];
		} else {
			// Sinon on est en fonctionnement en mode normal
			parametre = 0;
		}
	}
	
	
	
	switch(parametre) {
		case q :
			// Ouverture du fichier numero 1
			fichier1 = fopen(argv[2], "r+");
			if (fichier1==NULL) { printf("Impossible d'ouvrir le fichier %s\n", argv[1] ); 
								 return 1; }
					
			// Ouverture du fichier numero 2
			fichier2 = fopen(argv[3], "r+");
			if (fichier2==NULL) { printf("Impossible d'ouvrir le fichier %s\n", argv[2] );
								 return 1; }
								 
			
			if (brief(fichier1, fichier2) == 0) {
				printf("Les fichiers %s et %s sont différents", argv[2], argv[3]);
			} else {
				printf("les fichiers sont egaux");
			}
			break;
		case 0 : // --normal	Fonctionnement en mode normal
			// Ouverture du fichier numero 1
			fichier1 = fopen(argv[1], "r+");
			if (fichier1==NULL) { printf("Impossible d'ouvrir le fichier %s\n", argv[1] ); 
								 return 1; }
					
			// Ouverture du fichier numero 2
			fichier2 = fopen(argv[2], "r+");
			if (fichier2==NULL) { printf("Impossible d'ouvrir le fichier %s\n", argv[2] );
								 return 1; }
			
			break;
		case 108 : // l
			// Ouverture du fichier numero 1
			fichier1 = fopen(argv[2], "r+");
			if (fichier1==NULL) { printf("Impossible d'ouvrir le fichier %s\n", argv[1] ); 
								 return 1; }
			char * ligne = malloc(sizeof(char) * MAX_BUFFER);
			ligne = fgetl(fichier1, 2, MAX_BUFFER);
			printf("%s", ligne);
			break;
	}
	
	
	
	fclose(fichier1);
	fclose(fichier2);
	
	*/
	
	return 0;
}
