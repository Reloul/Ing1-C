/*!
 *  \mainpage Programme pour jouer au démineur
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \section INFO
 *     Voici le code fais par Valentin Serres qui permet de jouer au démineur en choisissant la taille de sa grille de jeu
*/


 /*!
 *  \file main.c
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief progamme principal pour faire tourner notre démineur
*/ 

/*Inclusion du fichier où l'on déclare nos fonctions pour faire fonctionner notre démineur*/
#include "demineur.h"


/*!
 *  \fn int main ()
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Thu 22 2022 - 11:44:02
 *  \brief programme principal pour faire tourner notre démineur
 *  \return 0 si tout se passe bien
*/


int main(){
    //entier qui sera la taille de notre grille de jeu
    int int_taille;
    //pointeur de pointeur de cases qui représentera notre grille de jeu
    cases** ppcases_grille;
    //entier qui servira d'itérateur de boucle
    int i;
    //Entier qui prendra la valeur du nombre de bombe présente sur notre grille de jeu
    int int_compteBombe;
    //On demande la taille de notre grille de jeu
    printf("Choisissez la taille de votre plateau de jeu de taille minimum 4 (conseil : 50 max pour l'affichage): \n");
    int_taille=saisieEntier(80)+1;
    //On vérifie qu'elle n'est pas trop petite
    while(int_taille < 4){
        printf("La taille de la grille est trop petite. Recommencez.\n");
        int_taille=saisieEntier(80)+1;
    }
    //On demande le nombre de bombe voulue par l'utilisateur
    printf("Combien de Bombes voulez-vous placer?(ce nombre doit être inférieur à la taille de la grille)\n");
    //On vérifie qu'i ls'agit bien d'un entier
    int_compteBombe = saisieEntier(int_taille*int_taille)+1;
    //Et tant que le nombre bombe est supérieur au nombre de case + 1 ne notre grille de jeu on recommence
    while(int_compteBombe > (int_taille*int_taille-1)){
        //On informe l'utilisateur de son erreur
        printf("Le nombre de bombes est trop élevé! Recommencez.\n");
        //On redemande le nombre de bombe
        int_compteBombe=saisieEntier(int_taille*int_taille)+1;
    }
    //On alloue le premier tableau de notre grille
    ppcases_grille = malloc(int_taille* sizeof(cases*));
    //boucle pour allouez la taille nécessaire à notre grille
    for(i=0; i<int_taille; i++){
        ppcases_grille[i]=malloc(int_taille * sizeof(cases));
    }
    //On appelle la procédure pour effectuer le premier coup
    premierCoup(ppcases_grille, int_taille, int_compteBombe);
    //Appel de la procédure pour jouer les autres tour
    tourJeu(ppcases_grille, int_taille, int_compteBombe);
    //Quand on a fini on libère la mémoire prise par les pointeurs
    for(i=0;i<int_taille;i++){
        free(ppcases_grille[i]);
    }
    free(ppcases_grille);
    //On retourne 0 si tout se passe bien
    return(0);
}
