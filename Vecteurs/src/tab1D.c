 /*!
 *  \file tab1D.c
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief fichier qui sert à définir les différentes fonctions pour les tableaux 1 dimension
*/ 

/*Inclusion de la librairie stdio.h qui permet à l'utilisateur de faire un printf*/
#include <stdio.h>
/*Inclusion de la librairie stdlib.h qui permet à l'utilisateur de gérer la mémoire de façon dynamique ou encore de pouvoir intéragir avec le système d'exploitation*/
#include <stdlib.h>
#include <time.h>
#include "tab1D.h"



/*!
 *  \fn void initInvers ()
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Wed 30 2022 - 12:33:11
 *  \brief procédure qui permet d'initialiser les variables pour la procédure d'inversion 
*/

void initInvers(){
    //entier qui servira d'itérateur
    int i;
    //tableau d'entier de taille DIMENSION
    int tint_tab[DIMENSION];
    //Initialisation pour la fonction rand
    srand(time(NULL));
    //Bouce pour initialiser le tableau d'entier
    for(i=0;i<DIMENSION;i++){
        //Les valeurs seront comprises entre 0 et 9
        tint_tab[i] = rand()%10;
        //On affiche le tableau avant inversion
        printf("| %d ", tint_tab[i]);
    }
    printf("|\n");
    //On effectue l'inversion
    inversion(tint_tab,DIMENSION-1);
    //On affiche le tableau après inversion
    for(i=0;i<DIMENSION;i++){
        printf("| %d ", tint_tab[i]);
    }
    printf("|\n");
}   


/*!
 *  \fn void inversion (int tint_tab[], int int_taille)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Wed 30 2022 - 10:28:07
 *  \brief procédure qui permet d'inverser un tableau
 *  \param tin_tab[] un tableau d'entier de taille int_taille
 *  \param int_taille entier qui représente la taille du tableau
*/

void inversion(int tint_tab[], int int_taille){
    //entier qui servira d'itérateur
    int i;
    //entier qui servira de variable temporaire
    int int_temp;
    //Boucle qui permettra d'aller de la case 0 jusqu'a int_taille pour parcourir tout le tableau
    for(i=0; i<int_taille; i++){
        //affectation qui permettront d'inverser les cases du tableaux opposées
        int_temp = tint_tab[i];
        tint_tab[i] = tint_tab[int_taille];
        tint_tab[int_taille]= int_temp;
        //On diminue la taille car nous déjà échangé la case la plus lointaine
        int_taille--; 
    }
}

/*!
 *  \fn void initSomme()
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Wed 30 2022 - 12:42:53
 *  \brief procédure permettant d'initialiser les variables pour la procédure somme
*/

void initSomme(){
    //entier qui servira d'itérateur
    int i;
    //tableau d'entier de taille DIMENSION
    int tint_tabP[DIMENSION];
    int tint_tabD[DIMENSION];
    int tint_tabT[DIMENSION];
    //Initialisation pour la fonction rand
    srand(time(NULL));
    //Bouce pour initialiser le tableau d'entier
    for(i=0;i<DIMENSION;i++){
        //Les valeurs seront comprises entre 0 et 9
        tint_tabP[i] = rand()%10;
        //On affiche le tableau avant inversion
        printf("| %d ", tint_tabP[i]);
    }
    printf("|\n");
    //Bouce pour initialiser le tableau d'entier
    for(i=0;i<DIMENSION;i++){
        //Les valeurs seront comprises entre 0 et 9
        tint_tabD[i] = rand()%10;
        //On affiche le tableau avant inversion
        printf("| %d ", tint_tabD[i]);
    }
    printf("|\n");
    //On effectue l'inversion
    somme(tint_tabP, tint_tabD, DIMENSION, tint_tabT);
    //On affiche le tableau après inversion
    for(i=0;i<DIMENSION;i++){
        printf("| %d ", tint_tabT[i]);
    }
    printf("|\n");
}
/*!
 *  \fn void somme (int tint_tabP[], int tint_tabD[], int int_taille, int tint_tabT[])
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Wed 30 2022 - 10:30:28
 *  \brief procédure qui calcule la somme de tableaux et la met dans un troisième
 *  \param tint_tabP[] premier tableau d'entier
 *  \param tint_tabD[] deuxième tableau d'entier
 *  \param int_taille taille de tous les tabelaux
 *  \param tint_tabT[] troisième tableau d'entier
*/

void somme(int tint_tabP[], int tint_tabD[], int int_taille, int tint_tabT[]){
    //entier qui servira d'itérateur
    int i;
    //Boucle permettant de parcourir les tableaux
    for(i=0;i<int_taille;i++){
        //La case i du tableau 3 prend la somme des cases i des 2 autres tableaux
        tint_tabT[i]=tint_tabP[i]+tint_tabD[i];
    }
}


/*!
 *  \fn void initTraver() ()
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Wed 30 2022 - 16:39:08
 *  \brief prcédure qui permet d'initialiser les variables pour la procédure traversale
*/

void initTraver(){
    //Entier qui servira d'itérateur
    int i;
    //Un tableau d'entier de taille 6
    int tint_tab[6];
    //Entier qui sera les valeurs choisies par l'utilisateur
    int int_valeur;
    //Entier qui servira a vérifier si un tableau est traversale ou non
    int int_verif;
    //Boucle pour récupèrer les valeurs choisies par l'utilisateur
    for (i=0; i<6; i++)
    {
        //On demande les valeurs à l'utilisateur et on les lis 
        printf("Vous allez remplir un tableau de taille 6. Choisissez ses valeurs: \n");
        int_verif=scanf("%d", &int_valeur);
        //On vérifie s'il rentre bien un entier
        while (int_verif == 0){
            //On informe l'utilisateur qu'il s'est trompé
            printf("Erreur de Saisie veuillez recommencer \n");
            //On vide le buffer pour réutiliser le scanf
            while (getchar() != '\n'){};
            //On re demande l'entier
            int_verif=scanf("%d",&int_valeur);
        }
        //On ajoute la valeur à la case correspondante au tableau
        tint_tab[i]=int_valeur;
    }
    //Si i lest traversale alors on le dit
    if(traversable(tint_tab, 5)==1){
        printf("Le tableau est traversable  \n");
    }
    else{
        //sino on prévient qu'il n'est pas traversal
        printf("Le tableau n'est pas traversable \n");
    }
}

/*!
 *  \fn int traversable(int tint_tab[], int int_taille)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Wed 30 2022 - 10:51:40
 *  \brief Vérifie si un tableau est traversable
 *  \param tint_tab[] tableau d'entier
 *  \param int_taille entier qui représente la taille de tint_tab
 *  \return 1 ou 0 en fonction de si le tabelau est traversable ou non
*/

int traversable(int tint_tab[], int int_taille){
    //Variable qui servira à vérifier si le tableau est traversable ou non
    int int_verif;
    //Entier qui servira à ne pas boucler à l'infini
    int int_compte;
    //entier qui servira de variable temporaire
    int int_temp;
    //On les initialise tous à une valeur neutre
    int_temp = 0 ;
    int_verif = 0;
    int_compte = 0;
    //Tant que ce n'est pas un tableau traversable ou que l'on dépasse pas 50 boucle on recompense
    while ( (int_verif != 1) && ( int_temp< int_taille ))
    {
        //On effectue le calcul pour choisir la case du tableau
        int_temp = int_temp + tint_tab[int_temp];
        //Si le cacul correspond à la dernière case du tableau
        if (int_temp == int_taille){
            //la verfication prends la valeur 1
            int_verif = 1;
        }
        //On augmente la valeur du compte
        int_compte++;
    }
    //On retourne la valeur de verif (0 ou 1)
    return(int_verif);
}

/*!
 *  \fn void initPalindrome()
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Wed 30 2022 - 17:05:58
 *  \brief procédure pour initialiser les variables et tester la procédure palindrome
*/

/*void initPalindrome(){
    //Initialisation de 2 tableaux de caractères
    char tchar_tab[30];
    int i;
    printf("choisissez un mot ou une phrase (moins de 30 caractères) : \n");
    scanf("%s", tchar_tab);
    
    if (palindrome(tchar_tab, 4) == 1){
        printf("Ce mot est un palindrome\n");
    }else{
        printf("Ce n'est pas un palindrome\n");
    }

}*/
/*!
 *  \fn int palindrome(char tchar_tab[], int int_taille)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Wed 30 2022 - 11:43:20
 *  \brief fonction qui permet de vérifier si un mot est un palindrome ou non
 *  \param tchar_tab[] tableau de caractère
 *  \param int_taille taille du tabelau de caractère
 *  \return 0 ou 1 on fonction de si le mot est un palindrome ou non
*/

/*int palindrome(char tchar_tab[], int int_taille){
    //entier qui servira d'itérateur
    int i;
    //entier qui permettra de vérifier si le mot est un palindrome ou non
    int int_verif;
    //On l'initialise à 1 (=> vrai)
    int_verif = 1;
    //Boucle qui permettra d'aller de la case 0 jusqu'a int_taille pour parcourir tout le tableau
    for(i=0; i<int_taille; i++){
        //tant qu'on a des espaces on continue l'itération sans comparer
        while (tchar_tab[i]==' ')
        {
            i++;
        }
        //Tant qu'on a des espaces on réduit la taille sans comparer
        while (tchar_tab[int_taille]==' ')
        {
            int_taille--;
        }
        //Si les caratères opposés sont différents alors int_verif prends la valeur 0
        if ( tchar_tab[i] != tchar_tab[int_taille]){
                int_verif = 0;
        }
        //On diminue la taille car nous déjà échangé la case la plus lointaine
        int_taille--; 
    }
    //On retourne 0 ou 1
    return(int_verif);
}*/