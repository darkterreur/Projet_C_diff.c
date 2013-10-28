Usage: diff [OPTION]... FICHIERS
Comparer les fichiers ligne par ligne.


Les paramètres requis pour les options longues sont également requis pour les options courtes.

		--normal                  Produire un « diff » en format normal (par défaut)

	-q, --brief                   Indiquer seulement si les fichiers diffèrent

	-s, --report-identical-files  Indiquer si les deux fichiers sont identiques

	-c, -C N, --context[=N]              Afficher N (3 par défaut) lignes du contexte copié

	-u, -U N, --unified[=N]              Afficher N (3 par défaut) lignes dans le context unifié

	-e, --ed                      Générer un script pour « ed »

	-n, --rcs                     Générer un fichier « diff » au format RCS

	-y, --side-by-side            Affichage sur deux colonnes

	-w, --width=N                Limiter la sortie à au plus N colonnes imprimées (130 par défaut)
		--left-column            Afficher les lignes identiques uniquement dans la colonne de gauche
		--suppress-common-lines   Ne pas afficher les lignes identiques


	-p, --show-c-function         Afficher dans quelle fonction C le changement se trouve

	-F, --show-function-line=RE   Montrer la ligne la plus récente correspondant à RE
		--label ÉTIQUETTE        Utiliser ÉTIQUETTE au lieu du nom de fichier
								(peut être répété)


	-t, --expand-tabs             Étaler les tabulateurs en espaces dans la sortie

	-T, --initial-tab            Aligner les tabulateurs en préfixant un tabulateur
		--tabsize=N              Les balises de tabulation sont à chaque N (8 par défaut) colonnes
		--suppress-blank-empty   Supprimer les espaces et les tabulations avant les lignes vides

	-l, --paginate                Relayer la sortie à « pr » afin de la paginer


	-r, --recursive               Comparer récursivement les sous-répertoires trouvés

	-N, --new-file                Traiter les fichiers absents comme des fichiers vides
		--unidirectional-new-file Traiter les premiers fichiers absents comme vides
		--ignore-file-name-case   Ignorer la casse lors de la comparaison des noms de fichiers
		--no-ignore-file-name-case Tenir compte de la casse lors de la comparaison des noms de fichiers

	-x, --exclude=PAT            Exclure les fichiers dont les noms concordent avec le PATron

	-X, --exclude-from=FICHIER   Exclure les fichiers dont les noms	concordent avec ceux contenus dans le FICHIER

	-S, --starting-file=FICHIER  Débuter la comparaison des répertoires par le FICHIER
		--from-file=FICHIER1     Comparer le FICHIER1 à toutes les opérandes. FICHIER1 peut être un répertoire
		--to-file=FICHIER2       Comparer toutes les opérandes à FICHIER2. FICHIER2 peut être un répertoire


	-i, --ignore-case            Ignorer les différences de casses dans le contenu des fichiers

	-E, --ignore-tab-expansion   Ignorer les changements liés à l'expansion des tabulations

	-Z, --ignore-trailing-space ignore les espaces à la fin d'une ligne

	-b, --ignore-space-change     Ignorer les changements dans le nombre d'espaces

	-w, --ignore-all-space        Ignorer tout blanc d'espacement

	-B, --ignore-blank-lines     Ignorer les changements dont toutes les lignes sont blanches

	-I, --ignore-matching-lines=RE Ignorer les différences dont toutes les lignes concordent avec l'expression régulière RE


	-a, --text                    Traiter tous les fichiers comme des textes
		--strip-trailing-cr       Éliminer les retours de chariot de l'entrée


	-D, --ifdef=NOM              Afficher les fichiers fusionnés en marquant les différences par des « #ifdef NOM »
		--GTYPE-group-format=GFMT Formater les groupes d'entrée GTYPE avec GFMT
		--line-format=LFMT       Formater toutes les lignes d'entrée avec LFMT
		--LTYPE-line-format=LFMT Formater les lignes d'entrée LTYPE avec LFMT

	Ces options de formatage fournissent un contrôle fin sur la sortie de diff et généralise -D/--ifdef.
	LTYPE peut être soit « old », « new », ou « unchanged ».  GTYPE prend une des valeurs de LTYPE ou « changed ».
	GFMT (uniquement) peut contenir :
		%<  pour marquer les lignes du FICHIER1
		%>  pour marquer les lignes du FICHIER2
		%=  pour marquer les lignes identiques entre FICHIER1 et FICHIER2
		%[-][LARGEUR][.[PREC]]{doxX}LETTRE  la spécification de LETTRE est identique à la notation de printf()
      dont les codes possibles de LETTRE sont
      en majuscule pour le nouveau groupe, 
      en minuscules pour l'ancien groupe:
          F  numéro de la première ligne
          L  numéro de la dernière ligne
          N  nombre de lignes = L-F+1
          E  F-1
          M  L+1    %(A=B?T:E)  si A égal B alors T sinon E
    LFMT (uniquement) peut contenir :
        %L   pour le contenu de la ligne
        %l   pour le contenu de la ligne sans fin de ligne
        %[-][LARGEUR][.[PREC]]{doxX}n  la spécification du numéro de ligne
                              d'entrée selon le format de printf
    GFMT et LFMT peuvent contenir :
      %%  %
      %c«C»     le caractère «C» lui-même
      %c'\OOO» le caractère dont le code octal est OOO    C         le caractère C (les autres caractères se représentent eux-mêmes)


  -d, --minimal                Rechercher assidûment le plus petit ensemble de différences
      --horizon-lines=N        Retenir N lignes ayant des préfixes et suffixes identiques
      --speed-large-files      Suppose de grands fichiers et de nombreux petits changements éparpillés


      --help                    Afficher cette aide et terminer
  -v, --version                 Afficher le nom et la version du logiciel et terminer


FICHIERS sont « FICHIER1 FICHIER2 » ou « RÉP1 RÉP2 » ou « RÉP FICHIER... » ou « FICHIER... RÉP ».
Si --from-file ou --to-file sont fournis, il n'y a pas de restriction sur les FICHIERS.
Si le FICHIER spécifié est « - » alors lire depuis l'entrée standard.
Le statut de fin d'exécution est 0 si les entrées sont les mêmes, 1 si différentes et 2 si problématiques.
