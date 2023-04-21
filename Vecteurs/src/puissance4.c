
 /*!
 *  \file puissance4.c
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief fichier pour faire les fonctions du puissance 4
*/ 

#include "puissance4.h"

/*!
 *  \fn int saisieEntier()
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Thu 01 2022 - 14:14:18
 *  \brief fonction qui permet de savoir si l'utilisateur rentre bien un entier
 *  \return l'entier choisis par l'utilisateur
*/

int saisieEntier(){
    //entier qui servira à vérifier si l'utilisateur rentre un entier
    int int_verif;
    //entier qui correspondra à la colonne où le joueur souhaite jouer
    int int_colonne;
    //on lis la valeur
    int_verif=scanf("%d", &int_colonne);
    //Tant que ce n'est pas un entier on fait la boucle
    while (int_verif == 0){
        //On informe l'utilisateur qu'il s'est trompé
        printf("Erreur de Saisie veuillez recommencer \n");
        //On vide le buffer pour réutiliser le scanf
        while (getchar() != '\n'){};
        //On re demande l'entier
        int_verif=scanf("%d",&int_colonne);
    }
    //On envoie le numéro de la colonne correspondant à celle du tableau
    return(int_colonne-1);
}

/*!
 *  \fn void initialisation(int ttint_plateau[LARGEUR][LONGUEUR])
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Wed 30 2022 - 19:50:58
 *  \brief procédure qui permet d'initialiser un tableau 2D d'entier
 *  \param ttint_plateau[LARGEUR][LONGUEUR] tableau 2D d'neiter
*/

void initialisation(int ttint_plateau[LARGEUR][LONGUEUR]){
    //2 entiers qui serviront d'itérateurs
    int i;
    int j;
    //Les bouclent qui permettent d'initialiser les tableaux
    for(i=0;i<LARGEUR;i++){
        for(j=0;j<LONGUEUR;j++){
            //On initialise toutes les case à -1
            ttint_plateau[i][j] = -1;
        }
    }
}
// │ ┌ ┐ └ ┘ ─ ├ ┤ ┬ ┴ ┼

/*!
 *  \fn void affichage(int ttint_plateau[LARGEUR][LONGUEUR])
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Wed 30 2022 - 19:53:56
 *  \brief procédure qui permet d'afficher un tableau d'entier 2D
 *  \param ttint_plateau[LARGEUR][LONGUEUR] un tableau 2D d'entier
*/

void affichage(int ttint_plateau[LARGEUR][LONGUEUR]){
    //2 entiers qui serviront d'itérateurs
    int i;
    int j;
    //Affichage "propre" du plateau de jeu
    printf("  1   2   3   4   5   6   7 \n");
    printf("┌───┬───┬───┬───┬───┬───┬───┐\n");
    for(i=0;i<LARGEUR;i++){
        for(j=0;j<LONGUEUR;j++){
            //On vérifie dans quel cas on se situe
            switch (ttint_plateau[i][j])
            {
            //Si la case vaut -1 alors on affiche " "
            case -1 :
                printf("│   ");
                break;
            //Si la case vaut 1 alors on affiche X
            case 1 :
                printf("│ X ");
                break;
            //Si la case vaut 2 alors on affiche O
            case 2 :
                printf("│ O ");
                break;
            default:
            //Si on arrive ici c'est qu'il y a un soucis de valeur dans une case
                printf("Erreur\n");
                exit(ERREUR_CASE);
                break;
            }
        }
        printf("│\n");
        //Condition pour éviter que cette barre s'affiche en bas du plateau de jeu
        if (i < LARGEUR-1){
            printf("├───┼───┼───┼───┼───┼───┼───┤\n");
        }
    }
    printf("└───┴───┴───┴───┴───┴───┴───┘\n");
}


/*!
 *  \fn int jouer (int ttint_plateau[LARGEUR][LONGUEUR], int int_joueur, int int_x)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Wed 30 2022 - 20:10:01
 *  \brief fonction permettant de vérifier si un joueur peut jouer dans une colonne ou non, si oui on plasse son pion dans la colonne
 *  \param ttint_plateau[LARGEUR][LONGUEUR] tableau 2D d'entier qui représente le plateau de jeu
 *  \param int_joueur entier qui représente le joueur qui joue
 *  \param int_x entier qui représente le numéro de la colonne
 *  \return int_verif qui voudra 0 ou 1
*/

int jouer (int ttint_plateau[LARGEUR][LONGUEUR], int int_x){
    //entier qui servira d'itérateur
    int i;
    //entier qui servira a vérifier si le joueur a pu jouer ou non
    int int_verif;
    //On l'initialise à 0 => faux
    int_verif = 0;
    //Boucle qui permet de vérifier 1 colonne
    for(i=LARGEUR-1; i>=0; i--){
        //si une des case est vide alors on plasse le pion
        if(ttint_plateau[i][int_x] == -1){
            int_verif = 1;
        }
    }
    //retourne 0 ou 1
    return (int_verif);
}

/*!
 *  \fn int verifLigne(int ttint_plateau[LARGEUR][LONGUEUR])
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Wed 30 2022 - 21:03:01
 *  \brief fonction qui permet de vérifier si l'on a gagné sur une colonne
 *  \param ttint_plateau[LARGEUR][LONGUEUR] tableau 2D d'entier qui représentel plateau de jeu
 *  \return -1 si personne n'a validé de ligne, 1 si le joueur 1 à gagné ou 2 si le joueur 2 a gagné
*/


int verifColonne(int ttint_plateau[LARGEUR][LONGUEUR]){
    //entier qui servent d'itérateurs
    int i;
    int j;
    //entier qui servira à compter le nb de pion bon de chaque joueur
    int int_verif;
    //entier qui permettra de connaitre l'état de la partie
    int int_joueur;
    //On initialise le nombre de pion bon à 1
    int_verif = 1;
    //boucle pour vérifier 1 ligne 
    for(j=0;j<LONGUEUR;j++){
        for(i=0;i<LARGEUR;i++){
            //On vérifie si la case n'est pas vide et que les pions côte à côte sont identiques
            if( (ttint_plateau[i][j] == ttint_plateau[i+1][j]) && ((ttint_plateau[i][j] == 1) || (ttint_plateau[i][j] == 2)  )){
                //Dans ce cas on compte le nombre de pion bon
                int_verif = int_verif + 1;
                //On vérifie de quel joueur il s'agit
                int_joueur=ttint_plateau[i][j];
            }else{
                //Si les pions ne sont pas identiques on vérifie que personne n'est gagné
                if(int_verif < 4){
                    //Dans ce cas on réinitialise les valeurs
                    int_verif = 1;
                    int_joueur=-1;
                }
            }
        }
    }
    //On retourne l'état de la partie (gagnée ou non)
    return (int_joueur);

}

/*!
 *  \fn int verifLigne(int ttint_plateau[LARGEUR][LONGUEUR])
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Thu 01 2022 - 08:15:24
 *  \brief fonction qui vérifie si un joueur a gagné dans une ligne
 *  \param ttint_plateau[LARGEUR][LONGUEUR] tableau 2D d'entier qui représente le plateau de jeu
 *  \return la personne qui a gagné (1 ou 2) ou indique que la partie continue (-1)
*/


int verifLigne(int ttint_plateau[LARGEUR][LONGUEUR]){
    //entier qui servent d'itérateurs
    int i;
    int j;
    //entier qui servira à compter le nb de pion bon de chaque joueur
    int int_verif;
    //entier qui permettra de connaitre l'état de la partie
    int int_joueur;
    //On initialise le nombre de pion bon à 1
    int_verif = 1;
    //boucle pour vérifier 1 ligne 
    for(i=0;i<LARGEUR;i++){
        for(j=0;j<LONGUEUR;j++){
            //On vérifie si la case n'est pas vide et que les pions côte à côte sont identiques
            if( (ttint_plateau[i][j] == ttint_plateau[i][j+1]) && ((ttint_plateau[i][j] == 1) || (ttint_plateau[i][j] == 2)  )){
                //Dans ce cas on compte le nombre de pion bon
                int_verif = int_verif + 1;
                //On vérifie de quel joueur il s'agit
                int_joueur=ttint_plateau[i][j];
            }else{
                //Si les pions ne sont pas identiques on vérifie que personne n'est gagné
                if(int_verif < 4){
                    //Dans ce cas on réinitialise les valeurs
                    int_verif = 1;
                    int_joueur=-1;
                }
            }
        }
    }
    //On retourne l'état de la partie (gagnée ou non)
    return (int_joueur);
}


/*!
 *  \fn int ttint_plateau[LARGEUR][LONGUEUR])
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Thu 01 2022 - 08:45:16
 *  \brief fonction qui permet de vérifier si quelqu'un a gagné en diagonale
 *  \param ttint_plateau[LARGEUR][LONGUEUR] tableau 2D d'entier qui sert de plateau de jeu
 *  \return le joueur qui a gagné ou -1 si le jeu continue
*/

int verifDiag(int ttint_plateau[LARGEUR][LONGUEUR]){
    //entier qui serviront d'itérateurs
    int i;
    int j;
    int k;
    int l;
    //entier qui servira à compter le nb de pion bon de chaque joueur
    int int_verif;
    //entier qui permettra de connaitre l'état de la partie
    int int_joueur;
    //On initialise le nombre de pion bon à 1
    int_verif = 1;
    //boucle pour vérifier 1 ligne 
    for(i=0;i<LARGEUR;i++){
        for(j=0;j<LONGUEUR;j++){
            //On vérifie si la case n'est pas vide et que les pions côte à côte sont identiques
            if( (ttint_plateau[i][j] == ttint_plateau[i+1][j+1]) && ((ttint_plateau[i][j] == 1) || (ttint_plateau[i][j] == 2)  )){
                //k prend la valeur de i pour ne pas modifier la boucle for
                k=i;
                //l prend la valeur de j pour ne pas modifier la boucle for
                l=j;
                //Tant que la case en diagonale est égale à notre case actuelle alors on boucle
                while(ttint_plateau[k][l] == ttint_plateau[k+1][l+1]){
                    //Dans ce cas on compte le nombre de pion bon
                    int_verif = int_verif + 1;
                    //on augmente la valeur de k et de l pour changer de case
                    k++;
                    l++;
                }
                //On vérifie de quel joueur il s'agit
                int_joueur=ttint_plateau[i][j];
            }else{
                //Si les pions ne sont pas identiques on vérifie que personne n'est gagné
                if(int_verif < 4){
                    //Dans ce cas on réinitialise les valeurs
                    int_verif = 1;
                    int_joueur=-1;
                }
            }
        }
    }
    //On retourne l'état de la partie (gagnée ou non)
    return (int_joueur);
}   

/*!
 *  \fn int verifDiagInv(int ttint_plateau[LARGEUR][LONGUEUR])
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Thu 01 2022 - 08:56:33
 *  \brief finction qui permet de vérifier si un joueur a gagné sur une diagonale "Inverse"
 *  \param ttint_plateau[LARGEUR][LONGUEUR] tableau 2D d'entier qui représente le plateau de jeu
 *  \return le joueur qui a gagné (1 ou 2) ou si la partie est toujours en cours (-1)
*/

int verifDiagInv(int ttint_plateau[LARGEUR][LONGUEUR]){
    //entier qui serviront d'itérateurs
    int i;
    int j;
    int k;
    int l;
    //entier qui servira à compter le nb de pion bon de chaque joueur
    int int_verif;
    //entier qui permettra de connaitre l'état de la partie
    int int_joueur;
    //On initialise le nombre de pion bon à 1
    int_verif = 1;
    //boucle pour vérifier 1 ligne 
    for(i=0;i<LARGEUR;i++){
        for(j=LONGUEUR;j>2;j--){
            //On vérifie si la case n'est pas vide et que les pions côte à côte sont identiques
            if( (ttint_plateau[i][j] == ttint_plateau[i+1][j-1]) && ((ttint_plateau[i][j] == 1) || (ttint_plateau[i][j] == 2)  )){
                //k prend la valeur de i pour ne pas modifier la boucle for
                k=i;
                //l prend la valeur de j pour ne pas modifier la boucle for
                l=j;
                //Tant que la case en diagonale est égale à notre case actuelle alors on boucle
                while(ttint_plateau[k][l] == ttint_plateau[k+1][l-1]){
                    //Dans ce cas on compte le nombre de pion bon
                    int_verif = int_verif + 1;
                    //on augmente la valeur de k et de l pour changer de case
                    k++;
                    l--;
                }
                //On vérifie de quel joueur il s'agit
                int_joueur=ttint_plateau[i][j];
            }else{
                //Si les pions ne sont pas identiques on vérifie que personne n'est gagné
                if(int_verif < 4){
                    //Dans ce cas on réinitialise les valeurs
                    int_verif = 1;
                    int_joueur=-1;
                }
            }
        }
    }
    //On retourne l'état de la partie (gagnée ou non)
    return (int_joueur);
}

/*!
 *  \fn int aGagne(int ttint_plateau[LARGEUR][LONGUEUR])
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Thu 01 2022 - 09:25:49
 *  \brief fonction qui permet de vérifier si un joueur a gagné, si la partie est finie ou si il y a match nul
 *  \param ttint_plateau[LARGEUR][LONGUEUR] tableau 2D d'entier qui représente le plateau de jeu
 *  \return le numéro du joueur qui a gagné (1 ou 2) ou -1 si la partie n'est pas finie ou 0 en cas d'égalité
*/

int aGagne(int ttint_plateau[LARGEUR][LONGUEUR]){
    //entier qui permettra de connaître l'état de la partie
    int int_verifFinie;
    //entier qui serviront d'itérateur
    int i;
    int j;
    //On l'initialise à match nul
    int_verifFinie = 0;
    //Boucle pour parcours le plateau
    for (i=0;i<LARGEUR; i++)
    {
        for(j=0;j<LONGUEUR;j++){
            //Si il reste une case vide alors la partie n'est pas finie
            if(ttint_plateau[i][j] == -1 ){
                int_verifFinie = -1;
            }
        }
    }
    //Si une ligne a un joueur gagnant alors on récupère le numéro du joueur
    if (verifLigne(ttint_plateau) != -1){
        int_verifFinie = verifLigne(ttint_plateau);
    }
    //Si une colonne a un joueur gagnant alors on récupère le numéro du joueur
    if (verifColonne(ttint_plateau) != -1)
    {
        int_verifFinie = verifColonne(ttint_plateau);
    }
    //Si une diagonale a un joueur gagnant alors on récupère le numéro du joueur
    if (verifDiag(ttint_plateau) != -1)
    {
        int_verifFinie = verifDiag(ttint_plateau);
    }
    //Si une diagonale inversée a un joueur gagnant alors on récupère le numéro du joueur
    if (verifDiagInv(ttint_plateau) != -1)
    {
        int_verifFinie = verifDiagInv(ttint_plateau);
    }
    //On retourne l'état de la partie
    return(int_verifFinie);
}

/*!
 *  \fn void tourDeJeu(int ttint_plateau[LARGEUR][LONGUEUR])
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Thu 01 2022 - 14:36:07
 *  \brief fonction qui permet de jouer au puissance 4 à tour de rôle
 *  \param ttint_plateau[LARGEUR][LONGUEUR]
*/

void tourDeJeu(int ttint_plateau[LARGEUR][LONGUEUR]){
    //entier qui correspond au numéro du joueur
    int int_joueur;
    //entier qui correspond au numéro de la colonne où l'on joue
    int int_colonne;
    //entier qui servira d'itérateur
    int i;
    //entier qui permet de ne pas poser plusieurs pions en 1 coups
    int int_compte;
    //initialisation valeur neutre
    int_compte = 0;
    //initialisation premier joueur
    int_joueur = 0;
    //On affichel e plateau vide
    affichage(ttint_plateau);
    //Tant qu'une case est vide on joue
    while (aGagne(ttint_plateau) == -1 )
    {
        //On demande à l'utilisateur de jouer
        printf("c'est au joueur %d de jouer\n Choisissez une colonne : \n", int_joueur+1);
        //On vérifie que int_colonne est bien un entier
        int_colonne = saisieEntier();
        //Tant qu'on que la colonne est plein on demande à l'utilisateur de changer de colonne
        while (jouer(ttint_plateau, int_colonne) != 1 ){
            //On informe que la colonne est pleine et on demande de recommencer
            printf("La colonne est pleine. Veuillez recommencez. \n");
            //on vérifie que int_colonne est bien un entier
            int_colonne = saisieEntier();
        }
        //boucle pour mettre le pion le plus bas possible
        for(i=LARGEUR-1;i> -1;i--){
            //si la case la plus basse est vide alors on y met le pion du joueur
            if( (ttint_plateau[i][int_colonne] == -1) && (int_compte != 1)){
                //On met le pion
                ttint_plateau[i][int_colonne] = int_joueur+1;
                //compte afin de dire que l'on a bien posé le pion
                int_compte = 1;
            }
        }
        //On réinitialise à une valeur neutre
        int_compte = 0;
        //Après chaque coup on affiche le plateau
        affichage(ttint_plateau);
        //On change de joueur
        int_joueur++;
        int_joueur = int_joueur%2;
    }
    //Si le joueur 1  a gagné on le dis
    if(aGagne(ttint_plateau) == 1){
        printf("Le joueur 1  a gagné \n");
    }
    //sinon si le joueur 2 a gagné on le dis
    else if (aGagne(ttint_plateau) == 2) {
        printf("Le joueur 2 a gagné\n");
    }
    //sinon il y a égalité
    else{
        printf("égalité! \n");
    }
    
}