#ifndef DIFF_C
#define DIFF_C


// ASCII
#define TIRET 45
#define q 113
#define s 115
// Retour a la ligne sous linux
#define LF 10
// Retour a la ligne sous Windows s'est CR et LF
#define CR 13

// Taille maximal du buffer
#define MAX_BUFFER 1000

//const char *tempFichier0 = "./temporaire/temp_0";
//const char (*tempFichier1)[20] = './temporaire/temp_1';
//#define (*tempFichier1)  './temporaire/temp_1'
//tempFichier1 =malloc( sizeof(char)*(20 );




void diff(char * parametre);
void father_copy(char **tableauFichierOuvert, int nbTarget);
char *getExtension(char *target);
int copier_fichier(char const * const source, char const * const destination);
int nombreCharacteChaine(char *maChaine);
void diff(char * parametre);
char * diffNormal(FILE * f1, FILE * f2);

/**
	-q, --brief
		Indiquer seulement si les fichiers diffèrent
		return 0 s'ils sont different et 1 s'ils sont égaux
*/
int brief(FILE * f1, FILE * f2);

/**
	--normal                  Produire un « diff » en format normal (par défaut)
*/
void normal(FILE * f1, FILE * f2);

/**
	Fonction qui compte la taille du fichier
*/
int taille_fichier(FILE * f);

/**
	Fonction qui compte le nombres de lignes d'un fichier
*/
int nb_lignes(FILE * f);

/**
	Lit le fichier ligne par ligne

	int index - lit la ligne indiquée
				0 si on veux lire tous les lignes
*/
char *fgetl(FILE *f, int index, int taille_max);


#endif
