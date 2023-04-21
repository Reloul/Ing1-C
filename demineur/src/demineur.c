/*!
 *  \file demineur.c
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief fichier pour les fonctions qui serviront à faire fonctionner notre démineur
*/ 

#include "demineur.h"

/*!
 *  \fn void initialisation(cases** ppcases_grille, int int_taille)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Tue 20 2022 - 15:31:55
 *  \brief procédure permettant d'initialiser ma grille de jeu
 *  \param ppcases_grille pointeur de pointeur de cases qui servira de grille de jeu
 *  \param int_taille entier qui permettra de connaitre la taille de la grille de jeu
*/

void initialisation(cases** ppcases_grille, int int_taille){
    //entiers qui serviront d'itérateurs de boucle 
    int i;
    int j;
    //On initialise les cases de notre grille de jeu
    for(i=0;i<int_taille;i++){
        for(j=0;j<int_taille;j++){
            //Toutes les cases auront un état de 0 -> elles seront cachées
            ppcases_grille[i][j].int_etat = 0;
            //Toutes les cases auront un type de 0 -> ce ne sont que des cases vides
            ppcases_grille[i][j].int_type = 0;
            //Toutes les cases auront un drapeau de 0 -> le joueur n'a pas mis de drapeau sur les cases
            ppcases_grille[i][j].int_drapeau = 0;
            //Le lien entre les cases est définis à 0 -> Le joueur n'a pas commencé à jouer, il n'y a aucun lien entre les cases.
            ppcases_grille[i][j].int_lien = 0;
        }
    }
}

//💣 🏳 ■

/*!
 *  \fn void affichage(cases** ppcases_grille, int int_taille)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Tue 20 2022 - 15:52:02
 *  \brief procédure permettant d'afficher correctement la grille de jeu
 *  \param ppcases_grille pointeur de pointeur de cases qui sert de grille de jeu pour le démineur
 *  \param int_taille entier qui servira à connaître la taille de notre grille de jeu
*/

void affichage(cases** ppcases_grille, int int_taille){
    //Entiers qui serviront d'itérateurs de boucles
    int i;
    int j;
    int k;
    ////On affiche le numéro des colonnes de la grille, si le numéro dépasse 10 on affiche un espace de moins (sinon décalage dans l'affichage des cases)
    printf("     ");
    for(i=1;i<int_taille+1;i++){
        if(i<10){
            printf("%d   ", i);   
        }else{
            printf("%d  ", i);
        }
    }
    printf("\n");
    //Partie pour afficher la première ligne de la grille
    printf("   ┌");
    for(i=0;i<int_taille-1;i++){
        printf("───┬");
    }
    printf("───┐\n");
    //Boucle permettant d'afficher le contenue de notre grille
    for(i=0;i<int_taille;i++){
        //On affiche le numéro des lignes de la grille, si le numéro dépasse 10 on affiche un espace de moins (sinon décalage dans l'affichage des cases)
        if(i+1<10){
            printf("%d  ", i+1);   
        }else{
            printf("%d ", i+1);
        }
        for(j=0;j<int_taille;j++){
            //Si l'état de la case est de 0 alors elle reste cachée
            if(ppcases_grille[i][j].int_etat == 0){
                //Mais si le joueur y a mis un drapeau alors la case reste cachée mais avec un drapeau
                if(ppcases_grille[i][j].int_drapeau == 1){
                    printf("│ 🏳 ");
                }else{
                    //Sinon elle apparait cachée
                    printf("│ ■ ");
                }
            }
            //Si l'état de la case vaut 1 alors elle ne doit pas être cachée
            else{
                //Si son type vaut 1 alors c'est une case vide sans bombe à côté
                if(ppcases_grille[i][j].int_type == 0){
                    printf("│   ");
                }
                //Sinon si son type vaut 10 alors c'est une bombe
                else if (ppcases_grille[i][j].int_type == 10){
                    printf("│💣 ");
                }
                //sinon c'est une case à côté d'une bombe et on affiche son type qui correspondra au nombre de bombe
                else{
                    printf("│ %d ", ppcases_grille[i][j].int_type);
                }        
            }
        }
        printf("│\n");
        //On affiche ce qui sépare les lignes jusqu'à int_taille-1 pour éviter d'en avoir 1 en trop
        if(i<int_taille-1){
            printf("   ├");
            for(k=0;k<int_taille-1;k++){
                printf("───┼");
            }
            printf("───┤\n");
        }
    }
    //On affiche la dernière ligne
    printf("   └");
    for(i=0;i<int_taille-1;i++){
        printf("───┴");
    }
    printf("───┘\n");
}


/*!
 *  \fn int verifBombe(cases** ppcases_grille, int int_x, int int_y)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Wed 21 2022 - 10:37:49
 *  \brief fonction permettant de vérifier si la case choisie est une bombe ou non
 *  \param ppcases_grille pointeur de pointeur de cases, nous sert de grille de jeu
 *  \param int_x entier qui permettra de savoir quelle ligne l'utilisateur a choisi
 *  \param int_y entier qui permettra de savoir quelle colonne l'utilisateur a chois
 *  \return int_verif, un entier qui prendra comme valeur 0 si la case n'est pas une bombe sinon il prendra 1
*/

int verifBombe(cases** ppcases_grille, int int_x, int int_y){
    //entier permettant de vérifier si une case est une bombe
    int int_verif;
    //On l'initialise à 0 : la case n'est pas une bombe
    int_verif = 0;
    //Si la case est une bombe
    if(ppcases_grille[int_x][int_y].int_type == 10 ){
        //Alors int_verif vaudra 1
        int_verif = 1;
    }
    //On retourne int_verif
    return(int_verif);
}


/*!
 *  \fn int nbBombe(cases** ppcases_grille, int int_x, int int_y, int int_taille)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Wed 21 2022 - 11:10:54
 *  \brief fonction permettant de compter le nombre de bombe dans les cases voisines d'une case donnée
 *  \param ppcases_grille pointeur de pointeur de cases qui sert de grille de jeu
 *  \param int_x entier qui sera le numéro de la ligne souhaitée
 *  \param int_y entier qui sera le numéro de la colonne souaitée
 *  \param int_taille entier qui représente la taille de la grille de jeu
 *  \return le nombre de bombe qui entoure une case donnée
*/

int nbBombe(cases** ppcases_grille, int int_x, int int_y, int int_taille){
    //entier qui permettra de compter le nombre de bombe qui entoure une case
    int int_compte;
    //On initialise le nombre de bombe à 0
    int_compte = 0;
    //Si la case en haut à gauche est une bombe et si la case existe on compte une bombe
    if((int_x>0) && (int_y>0) && (ppcases_grille[int_x-1][int_y-1].int_type == 10) ){
        int_compte = int_compte + 1;
    }
    //Si la case en haut est une bombe et si la case existe on compte une bombe
    if((int_x>0) && (ppcases_grille[int_x-1][int_y].int_type == 10)){
        int_compte = int_compte + 1;
    }
    //Si la case en haut à droite est une bombe et si la case existe on compte une bombe
    if((int_x>0) && (int_y<int_taille-1) && (ppcases_grille[int_x-1][int_y+1].int_type == 10)){
        int_compte = int_compte + 1;
    }
    //Si la case à gauche est une bombe et si la case existe on compte une bombe
    if((int_y>0) && (ppcases_grille[int_x][int_y-1].int_type == 10)){
        int_compte = int_compte + 1;
    }
    //Si la case en bas à gauche est une bombe et si la case existe on compte une bombe
    if((int_y>0) && (int_x<int_taille-1) && (ppcases_grille[int_x+1][int_y-1].int_type == 10)){
        int_compte = int_compte + 1;
    }
    //Si la case en bas est une bombe et si la case existe on compte une bombe
    if((int_x<int_taille-1) && (ppcases_grille[int_x+1][int_y].int_type == 10) ){
        int_compte = int_compte + 1;
    }
    //Si la case en bas à droite est une bombe et si la case existe on compte une bombe
    if((int_x<int_taille-1) && (int_y<int_taille-1) && (ppcases_grille[int_x+1][int_y+1].int_type == 10)){
        int_compte = int_compte + 1;
    }
    //Si la case à droite est une bombe et si la case existe on compte une bombe
    if((int_y<int_taille-1) && (ppcases_grille[int_x][int_y+1].int_type == 10)){
        int_compte = int_compte + 1;
    }
    //On retourne le nombre de bombe
    return(int_compte);
}


/*!
 *  \fn void attributionType(cases** ppcases_grille, int int_taille, int int_x, int int_y, int* pint_compteBombe)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Wed 21 2022 - 11:37:21
 *  \brief procédure permetttant d'attribuer un type (case avec 0 bombe, 1 bombe etc...) aux cases de notre grille
 *  \param ppcases_grille pointeur de pointeur de cases permettant de représenter notre grille de jeu
 *  \param int_taille entier qui représente la taille de notre grille
 *  \param int_x entier qui représente le numéro de la ligne où le joueur joue pour la première fois
 *  \param int_y entier qui représente le numéro de la colonne où le joueur joue pour la première fois
 *  \param int_compteBombe entier qui servira à compter le nombre de bombe
*/

void attributionType(cases** ppcases_grille, int int_taille, int int_x, int int_y, int int_compteBombe){
    //entiers qui serviront d'itérateurs de boucle
    int i;
    int j;
    //entier qui sera une variable temporaire qui servira à prendre la valeur du rand()
    int int_temp;
    //On paramètre srand pour pouvoir utiliser rand()
    srand(time(NULL));
    //Boucle se répétant tant que nous n'avons pas mis le nombre de bombe voulue par l'utilisateur
    while(int_compteBombe > 0){
        //Boucle permettant d'initialiser les cases qui seront des bombes
        for(i=0;i<int_taille;i++){
            for(j=0;j<int_taille;j++){
                //On les attributs de façon aléatoire proportionnellement à la taille de notre grille de jeu
                int_temp=rand()*int_taille+1;
                //On veut éviter que la première case où l'on joue soit une bombe
                if(((i != int_x) && (j != int_y))){
                    //Et l'on évite que les cases autour de notre première case ne soit des bombes aussi
                    if(((i != int_x+1) || (j != int_y+1)) && ((i != int_x-1) || (j != int_y-1)) && ((i!=int_x-1) || (j!=int_y)) && ((i!=int_x-1) || (j!=int_y+1)) && ((i!=int_x) || (j!=int_y-1)) && ((i!=int_x+1) || (j!=int_y+1))){
                        //On choisit les cases avec les bombes de façon aléatoire, on évite de poser des bombes si nous avons déjà posé toutes les bombes ou que la case choisie est déjà une bombe
                        if((int_temp%int_taille == 1) && (int_compteBombe>0) && (ppcases_grille[i][j].int_type!=10)){
                            //On définit la case choisie comme étant une bombe
                            ppcases_grille[i][j].int_type = 10;
                            //Si on pose une bombe alors il nous reste int_compteBombe-1 à poser
                            int_compteBombe--;
                        }
                    }
                }
            }
        }
    }
    //Boucle permettant d'attribuer aux cases "classiques" le nombre de bombes qu'elles ont à côté d'elles
    for(i=0;i<int_taille;i++){
        for(j=0;j<int_taille;j++){
            //On vérifie que la case n'est pas une bombe
            if(ppcases_grille[i][j].int_type != 10){
                //Et leur attribut le nombre de bombes comme type
                ppcases_grille[i][j].int_type = nbBombe(ppcases_grille, i, j, int_taille);
            }
        }
    }
}

/*!
 *  \fn void premierCoup(cases** ppcases_grille, int int_taille, int* pint_compteBombe)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Wed 21 2022 - 20:39:36
 *  \brief procédure permettant au joueur de réaliser le premier coup
 *  \param ppcases_grille pointeur de pointeur de cases qui représente la grille de jeu
 *  \param int_taille entier qui sert à connaître la taille de notre grille de jeu
 *  \param int_compteBombe entier représentant le nombre de bombe sur notre grille de jeu
*/

void premierCoup(cases** ppcases_grille, int int_taille, int int_compteBombe){
    //entier qui représentera la ligne de la première case où l'utilisateur voudra jouer
    int int_ligne;
    //entier qui représentera la colonne de la première case où l'utilisateur voudra jouer
    int int_colonne;
    //On initialise notre grille de jeu
    initialisation(ppcases_grille, int_taille);
    //On affiche notre grille de jeu
    affichage(ppcases_grille, int_taille);
    //On demande à l'utilisateur la case où il veut jouer (en choisissant la ligne et la colonne correspondante)
    printf("Choisissez la ligne où vous voulez commencer : \n");
    int_ligne = saisieEntier(int_taille-1);
    printf("Choisissez la colonne où vous voulez commencer : \n");
    int_colonne = saisieEntier(int_taille-1);
    //On change l'état de la case où l'utilisateur souhaites jouer (son état passe de cacher : 0 à découvert : 1)
    ppcases_grille[int_ligne][int_colonne].int_etat = 1;
    //On créer un lien sur la première case qui permettra de faire un lien avec toutes les autres cases "vides"
    ppcases_grille[int_ligne][int_colonne].int_lien = 1;
    //On attribut les valeurs à toutes les cases, on le fait après le premier coup afin d'éviter que le joueur tombe sur une bombe dès le premier coup
    attributionType(ppcases_grille, int_taille, int_ligne, int_colonne, int_compteBombe);
    //On fait le lien entre toutes les cases "vides" afin d'afficher toutes les cases vides qui sont côte à côte
    lien(ppcases_grille, int_taille);
    //procédure permettant de révèler les cases à côté des cases vides => ce ne seront donc pas des bombes
    reveleLien(ppcases_grille, int_taille);
    //On affiche la grille de jeu après avoir effectué le premier coup
    affichage(ppcases_grille, int_taille);
}

/*!
 *  \fn void lien(cases** ppcases_grille, int int_taille)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Wed 21 2022 - 16:10:38
 *  \brief procédure permettant de faire le lien entre les cases "vides" et de les faire apparaître
 *  \param ppcases_grille pointeur de pointeur qui permet de représenter notre grille de jeu
 *  \param int_taille entier qui représente la taille de notre grille de jeu
*/

void lien(cases** ppcases_grille, int int_taille){
    //entiers qui serviront d'itérateurs de boucle
    int i;
    int j;
    //entier qui servira à compter
    int int_compte;
    //On l'initialise à 0
    int_compte=0;
    //Tant que notre compteur ne dépasse pas 10, boucle permettant de s'assurer que l'on vérifie assez de fois les cases vides de notre grille
    while (int_compte < int_taille){
        //Boucle pour parcourir notre grille
        for(i=0;i<int_taille;i++){
            for(j=0;j<int_taille;j++){
                //Si la case au dessus de la où se situe a un lien (donc elle est "vide") et que notre case est vide alors on créer un lien et on la dévoile
                if((i>0 ) && (ppcases_grille[i-1][j].int_lien==1) && (ppcases_grille[i][j].int_type==0)){
                    ppcases_grille[i][j].int_lien=1;
                    ppcases_grille[i][j].int_etat=1;
                }
                //Si la case à gauche de la où se situe a un lien (donc elle est "vide") et que notre case est vide alors on créer un lien et on la dévoile
                if((j>0 ) && (ppcases_grille[i][j-1].int_lien==1) && (ppcases_grille[i][j].int_type==0)){
                    ppcases_grille[i][j].int_lien=1;
                    ppcases_grille[i][j].int_etat=1;
                }
                //Si la case en dessous de la où se situe a un lien (donc elle est "vide") et que notre case est vide alors on créer un lien et on la dévoile
                if((i<int_taille-1 ) && (ppcases_grille[i+1][j].int_lien==1) && (ppcases_grille[i][j].int_type==0)){
                    ppcases_grille[i][j].int_lien=1;
                    ppcases_grille[i][j].int_etat=1;
                }
                //Si la case à droite de la où se situe a un lien (donc elle est "vide") et que notre case est vide alors on créer un lien et on la dévoile
                if((j<int_taille-1 ) && (ppcases_grille[i][j+1].int_lien==1) && (ppcases_grille[i][j].int_type==0)){
                    ppcases_grille[i][j].int_lien=1;
                    ppcases_grille[i][j].int_etat=1;
                }
            }
        }
        //On incrémente la variable compte pour ne pas tomber dans une boucle infinie
        int_compte++;
    }
}


/*!
 *  \fn int saisieEntier(int int_taille)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Thu 01 2022 - 14:14:18
 *  \brief fonction qui permet de savoir si l'utilisateur rentre bien un entier
 *  \param int_taille entier qui sera la taille maximale de l'entier voulu
 *  \return l'entier choisis par l'utilisateur
*/

int saisieEntier(int int_taille){
    //entier qui servira à vérifier si l'utilisateur rentre un entier
    int int_verif;
    //entier qui correspondra à la colonne où le joueur souhaite jouer
    int int_valeur;
    //on lis la valeur
    int_verif=scanf("%d", &int_valeur);
    //Tant que ce n'est pas un entier et que ça ne correpond pas à nos conditions on fait la boucle
    while ((int_verif == 0) || ((int_valeur<0) && (int_valeur>int_taille)) ){
        //On informe l'utilisateur qu'il s'est trompé
        printf("Erreur de saisie veuillez recommencer \n");
        //On vide le buffer pour réutiliser le scanf
        while (getchar() != '\n'){};
        //On re demande l'entier
        int_verif=scanf("%d",&int_valeur);
    }
    //On envoie le numéro de la colonne correspondant à celle du tableau
    return(int_valeur-1);
}

/*!
 *  \fn void tourJeu(cases** ppcases_grille, int int_taille, int* pint_compteBombe)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Thu 22 2022 - 10:13:29
 *  \brief procédure permettant de jouerau démineur
 *  \param ppcases_grille pointeur de pointeur de cases permettant de représenter la frille de jeu
 *  \param int_taille entier permettant de connaître la taille de notre grille
 *  \param int_compteBombe entier permettant de connaître le nombre de bombe
*/


void tourJeu(cases** ppcases_grille, int int_taille, int int_compteBombe){
    //entier qui permettra de connaître le choix de l'utilisateur
    int int_choix;
    //entier qui représentera la ligne où l'utilisateur veut jouer
    int int_ligne;
    //entier qui représenteta la colonne où l'utilisateur ceut jouer
    int int_colonne;
    //entier qui permettra de savoir si le joueur a touché une bombe
    int int_bombe;
    //entier qui permettra de savoir si le jouer a gagné ( a trouvé toutes les bombes)
    int int_gagne;
    //entier permettant de compter le nombre de drapeau posé par le jouer
    int int_compteDrapeau;
    //On initialise les variables à 0
    int_compteDrapeau = 0; //Le joueur n'a pas encore posé de drapeau
    int_gagne = 0; //Le joueur n'a pas gagné
    int_bombe = 0; //Le joueur n'a pas touché de bombe
    //Boucle permettant de jouer tant que le joueur n'a pas gagné ou perdu
    while (int_bombe==0 && int_gagne == 0)
    {
        //On initialise int_choix à -1 -> choix pas possible pour l'utilisateur
        int_choix = -1;
        //On demande ce que l'utilisateur veut faire
        printf("Que voulez-vous faire: dévoiler une case(1), Poser un Drapeau(2) ou Enlever un Drapeau(3)?\n");
        int_choix=saisieEntier(3);
        //Si l'utilisateur choisit de poser un drapeau
        if(int_choix == 1){
            //On appelle la procédure permettant de poser un drapeau
            drapeau(ppcases_grille, int_taille);
            //On compte le nombre de drapeau posé
            int_compteDrapeau++;
            //On affiche la grille de jeu après le coup de l'utilisateur
            affichage(ppcases_grille, int_taille);
        }
        //Si l'utilisateur veut dévoiler une case
        else if(int_choix == 0){
            //On demande la case sur laquelle il veut jouer (on demande la ligne puis la colonne)
            printf("Choisissez la ligne où vous voulez jouer : \n");
            int_ligne = saisieEntier(int_taille-1);
            printf("Choisissez la colonne où vous voulez jouer : \n");
            int_colonne = saisieEntier(int_taille-1);
            //Tant que l'utilisateur essaye de dévoiler une case déjà dévoiler
            while (ppcases_grille[int_ligne][int_colonne].int_etat == 1)
            {
                //On lui signal que ce n'est pas possible
                printf("La case est déjà dévoilée. Recommencez. \n");
                //Et on lui redemandela cas où il veut jouer
                printf("Choisissez la ligne où vous voulez commencer : \n");
                int_ligne = saisieEntier(int_taille-1);
                printf("Choisissez la colonne où vous voulez commencer : \n");
                int_colonne = saisieEntier(int_taille-1);
            }
            //On révèle la case où l'utilisateur veut jouer
            ppcases_grille[int_ligne][int_colonne].int_etat = 1;
            //Si la case est "vide"
            if(ppcases_grille[int_ligne][int_colonne].int_type == 0){
                //On créer un lien
                ppcases_grille[int_ligne][int_colonne].int_lien = 1;
                //On fait un lien avec les cases vides voisinnes
                lien(ppcases_grille, int_taille);
                //On révèle les cases à côté des cases vides
                reveleLien(ppcases_grille, int_taille);
            }
            //On affiche la grille de jeu après le coup de l'utilisateur
            affichage(ppcases_grille, int_taille);
            //On vérifie si il a touché une bombe
            int_bombe = verifBombe(ppcases_grille, int_ligne, int_colonne);
        }
        //Si l'utilisateur décide de supprimer un drapeau
        else{
            //On vérifie qu'il y ait au moins 1 drapeau
            if(int_compteDrapeau > 0){
                //Si oui alors on décide de supprimer un drapeau
                supprDrapeau(ppcases_grille, int_taille);
                //Eto n diminue le nombre de drapeau
                int_compteDrapeau--;
                //On affiche la grille de jeu après le coup de l'utilisateur
                affichage(ppcases_grille, int_taille);
            //Si il n'y a pas de drapeau
            }else{
                //Alors on informe l'utilisateur qu'il ne peut pas enlever de drapeau
                printf("Vous n'avez pas mis de Drapeau\n");
            }
        }
        //On informe l'utilisateru du nombre de bombe qu'il doit trouver
        printf("Vous avez trouvé : %d bombes sur %d bombes \n", int_compteDrapeau, int_compteBombe);
        //On vérifie si il a gagné
        int_gagne = verifGagne(ppcases_grille, int_taille, int_compteBombe, int_compteDrapeau);   
    }
    //On appel la procédure pour informer l'utilisateur si il a gagné ou perdu
    gainPerte(ppcases_grille, int_taille, int_gagne, int_bombe);
}

/*!
 *  \fn void drapeau(cases** ppcases_grille, int int_taille)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Wed 21 2022 - 14:19:48
 *  \brief procédure permettant de demander là où l'on veut mettre un drapeau
 *  \param ppcases_grille pointeur de pointeur de case représentant notre grille de jeu
 *  \param int_taille entier représentant la taille de notre grille de jeu
*/

void drapeau(cases** ppcases_grille, int int_taille){
    //entier qui sera la ligne sur laquelle l'utilisateur voudra jouer
    int int_ligne;
    //entier qui sera la colonne sur laquelle l'utilisateur voudra jouer
    int int_colonne;
    //On demande la ligne sur laquelle l'utilisateur veut jouer
    printf("Sur quelle ligne souhaitez-vous mettre votre drapeau?\n");
    int_ligne = saisieEntier(int_taille-1);
    //On demande la colonne sur laquelle l'utilisateur veut jouer
    printf("Sur quelle colonne souhaitez-vous mettre votre drapeau?\n");
    int_colonne = saisieEntier(int_taille-1);
    //Tant que l'on veut jouer sur case déjà découverte ou où il y a déjà un drapeau on demande la ligne et la colonne
    while(ppcases_grille[int_ligne][int_colonne].int_etat == 1 || ppcases_grille[int_ligne][int_colonne].int_drapeau == 1 ){
        //Si la case a déjà été découverte alors on le signale à l'utilisateur
        if(ppcases_grille[int_ligne][int_colonne].int_etat == 1){
            printf("Cette case n'est plus cachée, vous ne pouvez par mettre de drapeau\n");
        }
        //Si la case a déjà un drapeau alors on le signale à l'utilisateur
        else if (ppcases_grille[int_ligne][int_colonne].int_drapeau == 1)
        {
            printf("Vous avez déjà mis un drapeau sur cette case\n");
        }
        //Et on redemande la ligne et la colonne
        printf("Sur quelle ligne souhaitez-vous mettre votre drapeau?\n");
        int_ligne = saisieEntier(int_taille-1);
        printf("Sur quelle colonne souhaitez-vous mettre votre drapeau? \n");
        int_colonne = saisieEntier(int_taille-1);
    }
    //On place le drapeau sur la case souhaitée par l'utilisateur
    ppcases_grille[int_ligne][int_colonne].int_drapeau=1;
}

/*!
 *  \fn void supprDrapeau(cases** ppcases_grille, int int_taille)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Wed 21 2022 - 21:19:31
 *  \brief procédure permettant de supprimer un drapeau
 *  \param ppcases_grille pointeur de pointeur de cases représentant notre grille de jeu
 *  \param int_taille entier permettant de connaître la taille de notre grille
*/

void supprDrapeau(cases** ppcases_grille, int int_taille){
    //entier qui sera la ligne sur laquelle l'utilisateur voudra jouer
    int int_ligne;
    //entier qui sera la colonne sur laquelle l'utilisateur voudra jouer
    int int_colonne;
    //On demande la ligne sur laquelle l'utilisateur veut jouer
    printf("Sur quelle ligne souhaitez-vous supprimer votre drapeau?\n");
    int_ligne = saisieEntier(int_taille-1);
    //On demande la colonne sur laquelle l'utilisateur veut jouer
    printf("Sur quelle colonne souhaitez-vous supprimer votre drapeau?\n");
    int_colonne = saisieEntier(int_taille-1);
    //Tant que l'on veut jouer sur case déjà découverte ou où il y a déjà un drapeau on demande la ligne et la colonne
    while(ppcases_grille[int_ligne][int_colonne].int_etat == 1 || ppcases_grille[int_ligne][int_colonne].int_drapeau == 0 ){
        //Si la case a déjà été découverte alors on le signale à l'utilisateur
        if(ppcases_grille[int_ligne][int_colonne].int_etat == 1){
            printf("Cette case n'est plus cachée, vous ne pouvez par enlever de drapeau\n");
        }
        //Si la case a déjà un drapeau alors on le signale à l'utilisateur
        else if (ppcases_grille[int_ligne][int_colonne].int_drapeau == 0)
        {
            printf("Vous n'avez pas mis de drapeau sur cette case\n");
        }
        //Et on redemande la ligne et la colonne
        printf("Sur quelle ligne souhaitez-vous supprimer votre drapeau?\n");
        int_ligne = saisieEntier(int_taille-1);
        printf("Sur quelle colonne souhaitez-vous supprimer votre drapeau? \n");
        int_colonne = saisieEntier(int_taille-1);
    }
    //On supprime le drapeau sur la case souhaitée par l'utilisateur
    ppcases_grille[int_ligne][int_colonne].int_drapeau=0;
}


/*!
 *  \fn int verifGagne(cases** ppcases_grille, int int_taille, int* pint_compteBombe, int int_compteDrapeau)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Wed 21 2022 - 21:30:10
 *  \brief fonction permettant de vérifier que toutes les bombes ont bien un drapeau
 *  \param ppcases_grille pointeur de pointeur de cases représentant la grille de jeu
 *  \param int_taille entier qui sert à connaître la taille de notre grille
 *  \param int_compteBombe entier qui permet de connaître le nombre de Bombe sur notre grille
 *  \param int_compteDrapeau entier permettant de connaître le nombre de drapeau posé par l'utilisateur
 *  \return 1 si toutes les bombes ont été trouvées sinon on retourne 0
*/

int verifGagne(cases** ppcases_grille, int int_taille, int int_compteBombe, int int_compteDrapeau){
    //Entiers qui serviront d'itérateur de boucle
    int i;
    int j;
    //Entier que l'on retournera qui permettra de savoir si l'on a gagné ou non
    int int_verif;
    //Entier qui permettra de compter le nombre de bombe ayant un drapeau
    int int_compte;
    //On initialise le compte à 0
    int_compte = 0;
    //On choisit que nous n'avons pas gagné de base
    int_verif=0;
    //Boucle pour parcourir la grille de jeu
    for(i=0;i<int_taille;i++){
        for(j=0;j<int_taille;j++){
            //Une case est une bombe et a un drapeau alors on le compte
            if((ppcases_grille[i][j].int_type == 10) && (ppcases_grille[i][j].int_drapeau == 1)){
                int_compte++;
            }
        }
    }
    //Si le compte de bombe ayant un drapeau est égal au nombre de bombe alors nous avons gagné
    if((int_compte == int_compteBombe) && (int_compteDrapeau == int_compteBombe)){
        int_verif = 1;
    }
    //On retourne int_verif
    return(int_verif);
}

/*!
 *  \fn void gainPerte(cases** ppcases_grille, int int_taille, int int_gagne, int int_perd)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Thu 22 2022 - 10:09:25
 *  \brief procédure permettant de dire si le joueur a perdu ou gagné
 *  \param ppcases_grille pointeur de pointeur de cases servant à représenter notre grille de jeu
 *  \param int_taille entier permettant de connaître la taille de notre grilles
 *  \param int_gagne entier permettant de savoir si le joueur a gagné
 *  \param int_perd entier permettant de savoir si le joueur a perdu
*/


void gainPerte(cases** ppcases_grille, int int_taille, int int_gagne, int int_perd){
    //Entiers servant d'itérateurs de boucle
    int i;    
    int j;
    //Boucle pour révèler toutes les cases
    for(i=0;i<int_taille;i++){
        for(j=0;j<int_taille;j++){
            ppcases_grille[i][j].int_etat = 1;
        }
    }
    //Si int_gagne est égale à 1 alors le joueur a gagné
    if(int_gagne == 1){
        printf("Vous avez trouvez toutes les bombes. Bien Joué!\n");
        affichage(ppcases_grille, int_taille);
    }
    //Sinon si int_perd est égale à 1 alors le joueur a perdu
    else if(int_perd == 1){
        printf("Vous avez fait exploser une bombe! \n");
        affichage(ppcases_grille, int_taille);
    //Sinon il y a une erreur
    }else{
        printf("Erreur\n");
    }
}

/*!
 *  \fn void reveleLien(cases** ppcases_grille, int int_taille)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Thu 22 2022 - 10:32:53
 *  \brief procédure permettant de révèler les cases voisinnes des cases possédant un lien
 *  \param ppcases_grille pointeur de pointeur permettant de représenter notre grille de jeu
 *  \param int_taille entier permettant de connaître la taille de notre grille
*/

void reveleLien(cases** ppcases_grille, int int_taille){
    //Entiers servant d'itérateurs de boucles
    int i;
    int j;
    //Boucle pour parcourir toute notre grille
    for(i=0;i<int_taille;i++){
        for(j=0;j<int_taille;j++){
            //On affiche la case au dessus de la case vide si la case existe
            if((i>0 ) && (ppcases_grille[i-1][j].int_lien==1)){
                ppcases_grille[i][j].int_etat=1;
            }
            ////On affiche la case à gauche de la case vide si la case existe
            if((j>0 ) && (ppcases_grille[i][j-1].int_lien==1)){
                ppcases_grille[i][j].int_etat=1;
            }
            ////On affiche la case en dessous de la case vide si la case existe
            if((i<int_taille-1 ) && (ppcases_grille[i+1][j].int_lien==1)){
                ppcases_grille[i][j].int_etat=1;
            }
            ////On affiche la case à droite de la case vide si la case existe
            if((j<int_taille-1 ) && (ppcases_grille[i][j+1].int_lien==1)){
                ppcases_grille[i][j].int_etat=1;
            }
        }
    }
}