 /*!
 *  \file Tri.c
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief fichiers des différentes fonctions de tri
*/ 

//on inclut le fichier Tri.h pour utiliser les fonctions
#include "Tri.h"

/*!
 *  \fn int* copierSousTableau(int* ptint_source, int int_taille)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Mon 05 2022 - 14:29:10
 *  \brief fonction permettant de copier les valeurs du tableau source dnas le tableau dest allant de la case debut à fin
 *  \param ptint_source tableau dynamique de pointeur d'entier
 *  \param int_debut entier correspondant à l'indice de début du tableau source
 *  \param int_fin entier qui correspond à l'indice de fin du tableau
 *  \return ptint_dest un tableau de pointeur d'entier contenant les valeurs du tableau source
*/

int* copierSousTableau(int* ptint_source, int int_debut, int int_fin){
    //entier qui servira d'itérateurs 
    int i;
    //tableau dynamique de pointeur d'entier
    int* ptint_dest;
    //allocation de l'espace mémoire
    ptint_dest = malloc((int_fin-int_debut) * sizeof(int));
    //on fait une boucle pour copier les valeurs du tableau source dans le tableau dest
    for(i=int_debut;i<int_fin;i++){
        ptint_dest[i-int_debut] = ptint_source[i];
    }
    //retourne le tableau créé
    return(ptint_dest);
}


/*!
 *  \fn void fusion(int* ptint_tab1, int int_taille1, int* ptint_tab2, int int_taille2, int* ptint_tabRes)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Mon 05 2022 - 17:54:25
 *  \brief procédure qui permet de fusionner 2 tableaux triés dans un autre de façon trié
 *  \param ptint_tab1 tableau d'ynamique d'entier 
 *  \param int_taille1 taille du premeir tableau dynamique
 *  \param ptint_tab2 taleau dynaique d'entier
 *  \param int_taille2 taille du deuxième tableau dynamique
 *  \param ptint_tabRes tableau dynamique qui permettra de fusionner les 2 premiers tableaux
*/

void fusion(int* ptint_tab1, int int_taille1, int* ptint_tab2, int int_taille2, int* ptint_tabRes){
    //entier qui servira d'itérateur et de compte pour parcourir le tableau 1
    int int_compteDroite;
    //entier qui servira d'itérateur et de compte pour parcourir le tableau 2
    int int_compteGauche;
    //entier qui servira d'itérateur afin d'affecter les valeurs au tableau Res
    int int_compte;
    //On initialise tous les itérateurs à 0 (valeurs de base des tableaux)
    int_compteDroite = 0;
    int_compteGauche = 0;
    int_compte= 0;
    //Tant qu'un des 2 itérateurs ne dépasse pas la taille d'un des 2 tableaux :
    while ( (int_compteGauche < int_taille1) && (int_compteDroite < int_taille2))
    {
        //Si la case du tab1 est plus petite que la case du tab2
        if( ptint_tab1[int_compteGauche] <= ptint_tab2[int_compteDroite]){
            //Alors le tabRes prend la valeur de la case de tab1
            ptint_tabRes[int_compte] = ptint_tab1[int_compteGauche];
            //On augmente l'itérateur du tab1
            int_compteGauche++;
            int_compte++;
        }else{
            //Le tabRes prend la valeur de la case de tab
            ptint_tabRes[int_compte] = ptint_tab2[int_compteDroite];
            //On augmente l'itérateur du tab2
            int_compteDroite++;
            int_compte++;
        }

    }
    //On affecte les valeurs restantes de tab1 dans tabRes
    while (int_compteGauche < int_taille1){
        ptint_tabRes[int_compte] = ptint_tab1[int_compteGauche];
        int_compteGauche++;
        int_compte++;
    }
    //On affecte les valeurs restantes de tab2 dans tabRes
    while (int_compteDroite < int_taille2){
        ptint_tabRes[int_compte] = ptint_tab2[int_compteDroite];
        int_compteDroite++;
        int_compte++;
    }  
}




/*!
 *  \fn void triFusion(int* tintp_tableau, int int_taille)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Fri 02 2022 - 20:54:50
 *  \brief procédure qui permet de trier un tableau de façon croissante
 *  \param tintp_tableau tableau dynamique d'entier 
 *  \param int_taille taille du tableau
 *  \return 
*/

void triFusion(int *ptint_tableau, int int_taille){
    //entier qui correspondra au milieu de mon tableau
    int int_milieu; 
    //tableau dynamique qui sera mon tableau de droite
    int* ptint_tabDroite;
    //tableau dynamique qui sera mon tableau de gauche
    int* ptint_tabGauche;
    //entier qui correcpondra à la taille de mon tableau de gauche
    int int_taille2;
    //Si le tableau est plu grand que 1
    if ( int_taille > 1) {
        //Le milieu du tableau est la taille divisée par 2
        int_milieu = (int_taille)/2;
        //Si le tableau de base est paire alors la taille du tableau de droite sera aussi grand que celui de gauche
        if((int_taille)%2 == 0){
            int_taille2 = int_milieu;
        }else{
            //Si il et impaire alors la taille du tableau de droite aura 1 case de plus que celui de gauche
            int_taille2 = int_milieu +1;
        }
        //Le tableau de gauche prends les valeurs de la partie gauche de mon tableau source
        ptint_tabGauche = copierSousTableau(ptint_tableau, 0, int_milieu);
        //Le tableau droite prends les valeurs de la partie droite de mon tableau source
        ptint_tabDroite = copierSousTableau(ptint_tableau, int_milieu, int_taille);
        //On exécute la fonction triFusion de façon récursive en s'occupant de la partie gauche
        triFusion(ptint_tabGauche, int_milieu);
        //Puis de la partie droite
        triFusion(ptint_tabDroite, int_taille2);
        //Et on fusionne les tableaux pour former notre tableau source trié 
        fusion(ptint_tabGauche, int_milieu, ptint_tabDroite, int_taille2, ptint_tableau);
    
        //On libère la mémoire prise par nos tableaux
        free(ptint_tabDroite);
        free(ptint_tabGauche);   
    }
}
 
/*!
 *  \fn void affichage(int *ptint_tab, int int_taille)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Tue 06 2022 - 14:48:04
 *  \brief procédure qui permet d'afficher nos tableaux
 *  \param ptint_tab tableau dynamique d'entier que l'on affichera
 *  \param int_taille entier qui correspond à la taille du tableau
*/

void affichage(int *ptint_tab, int int_taille){
    //entier qui servira d'itérateur
    int i;
    //Boucle pour afficher le tableau
    printf("|");
    for(i=0; i<int_taille; i++){
        printf(" %d |", ptint_tab[i]);
    }
    printf("\n");
}


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
    int int_entier;
    //on lis la valeur
    int_verif=scanf("%d", &int_entier);
    //Tant que ce n'est pas un entier on fait la boucle
    while (int_verif == 0){
        //On informe l'utilisateur qu'il s'est trompé
        printf("Erreur de Saisie veuillez recommencer \n");
        //On vide le buffer pour réutiliser le scanf
        while (getchar() != '\n'){};
        //On re demande l'entier
        int_verif=scanf("%d",&int_entier);
    }
    //On envoie le numéro de la colonne correspondant à celle du tableau
    return(int_entier);
}