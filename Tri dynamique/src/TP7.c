/*!
 *  \mainpage Programme pour effectuer un tri
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \section INFO
 *     Voici le code fais par Valentin Serres qui permet d'effectuer un tri d'un tableau dynamique
*/


 /*!
 *  \file TP7.c
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief programme principal
*/ 

//On inclut le Tri.h pour avoir accès à nos fonctions
#include "Tri.h"

/*!
 *  \fn int main ()
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Tue 06 2022 - 14:57:39
 *  \brief fonction main pour effectuer le tri fusion d'un tableau dynamique d'entier
 *  \return 0 si tout se passe bien
*/

int main(){
    //entier qui correspondra à la taille de notre tableau
    int int_taille;
    //déclaration de notre tableau dynamique
    int* ptint_tab;
    //entier qui servira d'itérateur
    int i;
    //On demande à l'utilisateur la taille du tableau qu'il souhaite
    printf("Choisissez la taille du tableau à trier : \n");
    //On vérifie qu'il s'agit bel et bien d'un entier
    int_taille = saisieEntier();
    //On alloue la mémoire nécessaire du tableau correspondant à la taille choisie
    ptint_tab = malloc(int_taille * sizeof(int));
    //on demande à l'utilisateur de rentrer des entiers
    printf("Choisissez les valeurs de votre tableaux : \n");
    for(i=0; i<int_taille; i++){
        //On vérifie qu'il s'agit bien d'entier et le tableau prend les bonnes valeurs
        ptint_tab[i] = saisieEntier();
    }
    //On montre le tableau que l'on a
    printf("Le Tri Fusion de votre tableau : \n");
    affichage(ptint_tab, int_taille);
    //On le trie
    triFusion(ptint_tab, int_taille);
    printf("Donne : \n");
    //On affiche le tableau trié
    affichage(ptint_tab, int_taille);
    printf("\n");
    //On libère la mémoire prise par le tableau
    free(ptint_tab);
    return(0);
}
