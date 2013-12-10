//test lio
#include <stdio.h>
#include <stdlib.h>
#include "diff.h"

int main ( int argc, char** argv ) {
	int i;
	int j;
    	int nbOption_basique = 0;
 	int nbOption_complexe =0;
	int cpt=1; 
	int nbOption=0;	
    	int nbTarget = 0;
    	int opti = 0;
    	int targ = 0;
	int parametre;
	int k;   
    
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
                	nbOption += (nombreCharacteChaine(argv[j]));
                }else{
                	//il s'agit d'un argument normal
                	nbOption ++;
                }
            }else{
                nbTarget ++;
            }
        }
}
	nbOption+=3; // car -a retourne un caractere et non deux
	printf("nbOption:%i\n ",nbOption); // affichage pour tester
        // si j'ai bien 1 option et deux adresses minimum c'est bon
     //   if(nbOption > 0 && nbTarget == 2) {
            
            char *target[nbTarget];
            char *optionComplex[nbOption];
            char option_basiq[nbOption];
            FILE *fichier[nbTarget];
            int optiCompl=0;
	    opti =0 ;
	    
            //j'isole les adresses dans un tableau et les option dans un autre
            for(j = 1; j < argc; j++) {
	        //opti =0;
                if(argv[j][0] == '-') {
                    if(argv[j][1] == '-'){
                    	//on recupere l'argument a therme on fera appel au fichier je pense
                    	//on fait sauter les deux --
                    	//option[opti] = argv[j][2];
                    	//opti ++;

                   	optionComplex[optiCompl] = &argv[j];
                    	optiCompl ++;


                    }else if(nombreCharacteChaine(argv[j]) > 2){
                    	//on a plus d'un parametre
                    	//le - est enlevé par k=1 et non 0
                    	for(k=1;k<=nombreCharacteChaine(argv[j]);k++){
                    		option_basiq[opti] = argv[j][k];
                    		opti ++;
                    	}
                    }else{
                    	//parametre normal
                    	// on enleve le -
                    	option_basiq[opti] = argv[j][1];
                    	opti ++;	
                    }
                    
                    
                }else{
                    target[targ] = argv[j];
                    targ ++;
                }
            }
	//j=0;
	//while(optionComplex[j]!='\0')
        printf("option %s\n",*optionComplex);         
	//father_copy(target,nbTarget);
//}
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

          diffNormal(fichier[0], fichier[1]);



	 for(i=0; i<=nbTarget;i++) {
               if (fichier[i] != NULL) {
                   fclose(fichier[i]);
               }
           
    
        	else{
           	 printf("Parametres incorrect\n");
            	return 1;
        	}
    	}

	
	return 0;
}
