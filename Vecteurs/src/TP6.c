/*!
 *  \mainpage Programme pour effectuer plusieurs actions avec des tableaux 1D
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \section INFO
 *     Voici le code fais par Valentin Serres qui permet d'effectuer une inversion de tableau, faire la somme de 2 tableaux, verifier qu'un tableau est traversable, jouer au puissance 4
*/

 /*!
 *  \file TP6.c
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief Programme principal
*/ 

//Inclusion de nos fichiers .h pour utiliser nos fonctions
#include "tab1D.h"
#include "puissance4.h"

#define ERREUR_SAISIE -1
/*!
 *  \fn int main ()
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Tue 06 2022 - 15:09:44
 *  \brief fonction main qui permet d'afficher un menu pour utiliser les différents fonctions de nos tableaux
 *  \return 0 si tout se passe bien
*/


int main(){
    //entier qui correspondra au choix de l'utilisateur
    int int_choix;
    //définition de notre plateau de jeu pour le puissance 4
    int ttint_plateau[LARGEUR][LONGUEUR];
    //On affiche le menu des approximations
    printf("    ╔══════════════════════════════╗\n");
    printf("    ║                              ║\n");
    printf("    ║    Choisissez un programme   ║\n");
    printf("    ║                              ║\n");
    printf("    ║    1 • Inversion d'un        ║\n");
    printf("    ║           tableau            ║\n");
    printf("    ║                              ║\n");
    printf("    ║    2 •  Somme de 2           ║\n");
    printf("    ║          tableaux            ║\n");
    printf("    ║                              ║\n");
    printf("    ║    3 • Tableau traversable   ║\n");
    printf("    ║                              ║\n");
    printf("    ║    4 • Puissance 4           ║\n");
    printf("    ║                              ║\n");
    printf("    ╚══════════════════════════════╝\n");
    //On lit la valeur du choix
    scanf("%d", &int_choix);

    switch (int_choix)
    {
    case 1:
        //Si l'utilisateur choisis le 1 alors il choisit d'inverser le tableau
        initInvers();
        break;
    case 2:
        //Si l'utilisateur choisis le 2 alors il choisit de sommer 2 tableaux
        initSomme();
        break;
    case 3:
        //Si l'utilisateur choisis le 3 alors il choisit de vérifier si un tableau est traversable
        initTraver();
        break;
    case 4:
        //Si l'utilisateur choisis le 4 alors il choisit de jouer au puissance 4
        initialisation(ttint_plateau);

        tourDeJeu(ttint_plateau);
        break;
    default:
        //Si l'utilisateur se trompe sur le menu alors on lui signal et on arrête le programme
        printf("Erreur de Saisie. Relancez le programme. \n");
        exit(ERREUR_SAISIE);
        break;
    }

    return(0);
}
