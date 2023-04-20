
 /*!
 *  \file td.c
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1
 *  \brief fonctions de cryptage qui serviront aux codes
*/ 

//On inclus le fichier servant à déclarer nos fonctions et utiliser les bibliothèques utiles
#include "td.h"


/*!
 *  \fn void cesar(char* pchar_chaine, int int_decalage)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Mon 12 2022 - 11:15:12
 *  \brief procédure permettant de crypter un message avec la méthode césar
 *  \param pchar_chaine pointeur de chaîne de caractère qui sera la chaîne de caractère à changer
 *  \param int_decalage entier qui représentera la valeur du décalage
*/

void cesar(char* pchar_chaine, int int_decalage){
    //entier qui servira d'itérateur de boucle
    int i;
    for(i=0;i<100;i++){
        //Si un caractère est une lettre de l'alphabet (minuscule ou majuscule)
        if ( ( (pchar_chaine[i]>64) && (pchar_chaine[i]<91) ) || ( (pchar_chaine[i]>96) && (pchar_chaine[i]<123) ) ){
            //Si c'est une des int_decalage dernières lettres de l'alphabet
            if(pchar_chaine[i]>(122-int_decalage) || (pchar_chaine[i]> (90-int_decalage) && pchar_chaine[i]<91 )){
                //On écrit les int_decalage première lettre de l'alphabet
                pchar_chaine[i] = pchar_chaine[i] - (26-int_decalage); 
            }
            else{
                //Sinon on décale l'alphabet de int_decalage
                pchar_chaine[i] = pchar_chaine[i] + int_decalage;
            }
        }
    }
    //On affiche la chaîne changée
    printf("%s\n", pchar_chaine);
}


/*!
 *  \fn void vigenere(char* pchar_chaine, char* pchar_cle)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Thu 15 2022 - 10:33:47
 *  \brief procédure permettant de chiffrer un message par la méthode de vigenere
 *  \param pchar_chaine pointeur de chaine de caractère que l'on voudra chiffrer
 *  \param pchar_cle pointeur de chaîne de caractère qui sera la clé pour chiffrer notre message
*/

void vigenere(char* pchar_chaine, char* pchar_cle){
    //entiers qui serviront d'itérateurs de boucle
    int i;
    int j;
    //entier qui sera le décalage de chaque lettre
    int int_decalage;
    //entier qui représente la taille de la chaîne de caractère à chiffrer
    int int_tailleC;
    //entier qui sera la taille de la chaîne de caractère qui sert de clé
    int int_tailleCle;
    //On attribut la taille de chaque chaîne aux entiers qui correspondent
    int_tailleCle = strlen(pchar_cle);
    int_tailleC = strlen(pchar_chaine);
    //On initialise l'itérateur à 0, il permettra de parcourir la chaîne à chiffrer
    i=0;
    //Tant que l'on ne dépasse pas la taille de notre chaîne de caractère à chiffrer
    while (i<int_tailleC){
        //on initialise l'itérateur à 0, il servira à parcourir notre clé
        j=0;
        //Tant qu'il ne dépasse pas la taille de la clé
        while(j<int_tailleCle){
            //Si le caractère de la chaîne à chiffrer correspond à une lettre (minuscule ou majuscule)
            if (( (pchar_chaine[i]>64) && (pchar_chaine[i]<91) ) || ( (pchar_chaine[i]>96) && (pchar_chaine[i]<123) ) ){
                //On récupère la valeur de décalage donné par notre clé
                int_decalage = pchar_cle[j]-97;
                //Si le caractère est une minuscule (on vérifie qu'une majuscule avec le décalage ne soit pas considérée comme une minuscule)
                if ( ( (pchar_chaine[i]+int_decalage < 123) && pchar_chaine[i]+int_decalage > 96 ) && pchar_chaine[i] > 96){
                    //On applique le décalage
                    pchar_chaine[i]= pchar_chaine[i]+int_decalage;
                }
                //Sinon si c'est une majuscule
                else if (pchar_chaine[i]+int_decalage < 91 && pchar_chaine[i]+int_decalage > 64){
                    //On applique le décalage
                    pchar_chaine[i]= pchar_chaine[i]+int_decalage;
                }
                else{
                    //Si avec le décalage les lettres "sortent" de leur valeur de majuscule ou minuscule alors on recommence l'alphabet 
                    pchar_chaine[i] = pchar_chaine[i]- (26-int_decalage);
                }
                //On incrémente l'itérateur seulement qu'on on parcours la clé et que l'on se sert d'une des lettres de la clé
                j++;
            }
            //On incrément l'itérateur pour se déplacer dans la chaîne à chiffrer
            i++;
        }
    }
    //On affiche la chaîne chiffrée
    printf("%s\n", pchar_chaine);
}

/*!
 *  \fn void scytale(char* pchar_chaine)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Thu 15 2022 - 15:47:11
 *  \brief procédure qui permet de chiffrer un message avec la méthode de scytale
 *  \param pchar_chaine pointeur de chaîne de caractère que l'on va vouloir crypter
*/


void scytale(char* pchar_chaine){
    //entier qui correspondra à la taille de notre chaîne à crypter
    int int_taille;
    //pointeur de tableau de caratère qui servira comme grille pour crypter notre chaîne
    char** ptchar_grille;
    //entier qui sera la taille de chaque côté de la grille
    int int_cote;
    //entier qui serviront d'itérateur de boucle
    int i;
    int j;
    //entier qui servira de variable temporaire pour des calculs
    int int_temp;
    //int_taille prends la valeur de la taille de notre chaine
    int_taille = strlen(pchar_chaine);
    //int_cote prends la valeur de la racine carrée de la taille pour connaitre la taille de la grille
    int_cote = sqrt(int_taille);
    //Si le carré de int_cote est inférieur à la taille de la chaine, c'est qu'elle ne possède pas de carré alors on augmente la taille de la grille de 1
    if (int_cote*int_cote < int_taille){
        int_cote = int_cote+1;
        //On rajoute le nombre d'espace nécessaire à la chaine pour remplire totalement la grille
        for(i=int_taille;i<int_cote*int_cote;i++){
            pchar_chaine[i]=' ';
        }
    }
    //On alloue la mémoire du tableau de tableau
    ptchar_grille = malloc(int_cote*int_cote * sizeof(char));
    for(i=0;i<int_cote;i++){
        //On alloue la mémoire des tableaux contenus dans le premier tableau
        ptchar_grille[i] = malloc(int_cote * sizeof(char));
    }
    //On initialise notre variable temporaire à une valeur neutre
    int_temp = 0;
    //On met les caractères de notre chaine dans la grille
    for(i=0;i<int_cote;i++){
        for(j=0;j<int_cote;j++){
            //Ici le j+int_temp permet de continuer à parcourir notre chaine sans la reprendre depuis le début et d'avoir des caractères en double
            ptchar_grille[i][j] = pchar_chaine[j + int_temp];
            //On affiche la grille
            printf("| %c ", ptchar_grille[i][j]);   
        }
        //La valeur temporaire permet de savoir où l'on s'est arrêter dans la chaine à crypter
        int_temp = int_temp + j;
        printf("|\n");
    }
    //On réattribut la valeur neutre à notre vatiable temporaire
    int_temp = 0;
    //On effectue le cryptage en lisant la grille colonne par colonne
    for(j=0;j<int_cote;j++){
        for(i=0;i<int_cote;i++){
            pchar_chaine[i + int_temp] = ptchar_grille[i][j]; 
        }
        //La variable temporaire permet de savoir la position où l'on se situe dans la chaîne à crypter afin de ne pas réécrire des caractères en double
        int_temp = int_temp + i;
    }
    //on affiche la chaine avec le nombre de caractère que peut contenir la grille pour s'assurer d'afficher tous les caractères
    printf("%.*s\n", int_cote*int_cote, pchar_chaine);
    //On libère la mémoire prise par la grille
    free(ptchar_grille);
}

/*!
 *  \fn void help()
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Fri 16 2022 - 13:30:54
 *  \brief procédure servant à afficher l'aide pour utiliser le programme 
*/

void help(){
    //On affiche l'aide pour utiliser le programme
    printf("Afin de crypter votre message vous disposez de plusieurs méthodes. Voici le guide pour vous aidez à les appliquer : \n\n");
    printf("    --help : vous affiche l'aide pour l'utilisation du programme.\n");
    printf("    -c <nom de la méthode> : écrivez le nom de la méthode que vous souhaitez (cesar, vigenere ou scytale)\n");
    printf("    -d <décalage> : utilisé uniquement pour le code César, indiquez le décalage souhaité (avec un entier compris entre 0 et 25 \n");
    printf("    -k <clé> : écrivez un mot clé permettant de chiffrer votre code, utile uniquement pour le chiffrement de Vigenère\n");
    printf("    -m <message> : message à chiffrer, à utiliser pour tous les codes\n\n");
    printf("Voici un exemple d'utilisation : ./bin/exe -c cesar -d 6 -m 'Bonjour tout le monde!'\n");
    printf("Attention, il faut bien respecter l'ordre dans les arguments : le type de codage, son décalage (si nécessaire en fonction de la méthode) et enfin le message à coder. \n");
}


/*!
 *  \fn void methode(char** pchar_chaine, int int_nbArgument)
 *  \author SERRES Valentin <serresvale@cy-tech.fr>
 *  \version 0.1 Premier jet
 *  \date Fri 16 2022 - 13:34:10
 *  \brief procédure permettant de vérifier si l'utilisateur a mis les bons arguments et si oui exécute les fonctions adéquates à la demande de l'utilisateur
 *  \param pchar_chaine pointeur de pointeur de chaîne servant à utiliser les arguments entrés par l'utilisateur
 *  \param int_nbArgument entier servant à connaitre le nombre d'argument
*/

void methode(char** pchar_chaine, int int_nbArgument){
    //entier qui servira à savoir le décalage voulu par l'utilisateur pour la méthode César
    int int_decalage;
    //Si l'utilisateur veut utiliser la méthode de césar et que le nombre d'argument corresponds
    if ( (strcmp(pchar_chaine[2], "cesar") == 0) && (int_nbArgument == 7) ){
        //On vérifie si le type d'argument est bon aussi
        if( (strcmp(pchar_chaine[3], "-d") == 0)&&(strcmp(pchar_chaine[5], "-m") == 0) ){
            //On récupère la valeur du décalage passée en argument (convertion d'un caractère en entier)
            int_decalage = strtol(pchar_chaine[4],(char**)NULL,10);
            //On effectue le chiffrement du message
            cesar(pchar_chaine[6], int_decalage);
        }else{
            //Si les argument ne sont pas vérifiés on prévient l'utilisateur
            printf("Erreur d'argument. Mauvaise utilisation des Arguments.\n");
        }

    }//Si l'utilisateur veut utiliser la méthode de Vigenère et que le nombre d'argument corresponds
    else if ( (strcmp(pchar_chaine[2], "vigenere") == 0) && (int_nbArgument == 7) ){
        //Si les arguments correspondent à la méthode voulue
        if( (strcmp(pchar_chaine[3], "-k") == 0) && (strcmp(pchar_chaine[5], "-m") == 0)) {
            //On utilise la méthode de Vigenère avec les bons paramètre    
            vigenere(pchar_chaine[6], pchar_chaine[4]);
        }else{
            //Si les argument ne corrspondent pas alors on prévient l'utilisateur
            printf("Erreur d'argument. Mauvaise utilisation des Arguments.\n");
        }
    }
    //Si l'utilisateur veut utiliser la méthode de Scytale et que el nombre d'argument corresponds
    else if ( (strcmp(pchar_chaine[2], "scytale") == 0) && (int_nbArgument == 5) ){
        //Si les arguments correspondent
        if(strcmp(pchar_chaine[3], "-m") == 0){
            //Alors on applique la méthode Scytale
            scytale(pchar_chaine[4]);
        }else{
            //Si les argument ne correspondent pas alors on prévient l'utilisateur
            printf("Erreur d'argument. Mauvaise utilisation des Arguments. \n");
        }
    }else{
        //Si le nombre d'argument de corresponds pas alors on préviens l'utilisateur
        printf("Erreur: trop ou pas assez d'argument\n");
    }
}