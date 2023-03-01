#include <string>
#include <iostream>
#include <string>
#include "Classes.h"
#include <cstdlib>
#include <random>

using namespace std;

// ==============================================================
// definitions des differentes fonctions utiles
// ==============================================================

// fonction de verification de la partie

int verifpartie(Hero* listehero[],Monstre* listemonstre[]){
    
    // verification des heros

    if (listehero[0]->estvivant()==false & listehero[1]->estvivant()==false & listehero[2]->estvivant()==false & listehero[3]->estvivant()==false){ // si les 4 heros sont tous mort
        return 1;
    }
    // verification des monstres

    if(listemonstre[0]->estvivant()==false & listemonstre[1]->estvivant()==false & listemonstre[2]->estvivant()==false & listemonstre[3]->estvivant()==false &
     listemonstre[4]->estvivant()==false & listemonstre[5]->estvivant()==false & listemonstre[6]->estvivant()==false & listemonstre[7]->estvivant()==false &
      listemonstre[8]->estvivant()==false & listemonstre[9]->estvivant()==false){               // si les 10 monstres sont tous morts
        return 2;                                                                                                                           
    }

    return 0;                                                                                   // si la partie continue
}




int main()
{
    //================================================================
    // === Accueil de l'utilisateur ===
    //================================================================

    // affichage de l'accueil
    cout << "===Bienvenue dans le jeu de combat===" << endl;
    cout << "Vous allez devoir choisir 4 heros pour votre aventure" << endl;
    cout << "Vous allez rencontrer 10 monstres et allez devoir les combattre" << endl;
    cout << "Il y a 3 types de Heros choisis au hasard" << endl;
    cout << "Le Chevalier, le Ninja et le Clerc" << endl;
    cout << "Le Clerc a un pouvoir qui lui permet de se soigner" << endl;
    cout << "Le Ninja a un pouvoir qui lui permet d'attaquer deux fois'" << endl;
    cout << "Le Chevalier a un pouvoir qui lui permet d'augmenter son attaque'" << endl;
    cout << "==Bonne chance et bon jeu==" << endl;
    cout << endl;
    cout << endl;


    cout << "Appuyez sur entree pour continuer" << endl;
    cin.ignore();                                                            // attend entrée




    // demande du nom des 4 heros
    cout << "Dans un royaume lointain, il y a longtemps...." << endl;
    cout << "Autour d'une forteresse en etoile, 4 heros se sont reunis pour partir a l'aventure" << endl;
    cout << "Leur but: sauver les bars lillois de la destruction !!" << endl;
    cout << "Mais pour cela, ils vont devoir affronter les 10 monstres de la mairie..." << endl;
    cout <<"Leur aventure commence maintenant !";
    cout << "..." << endl;
    cout << endl;

    cout << "Appuyez sur entrer pour continuer" << endl;
    cin.ignore();                                                                   // attend entrée de l'utilisateur
    
    string listenom [4];                                                            // creation d'un tableau de 4 noms

    cout << "===== Entrez le nom du premier heros de votre aventure====" << endl;    // demande du nom du premier hero
    string nom1;                                                                    // creation d'une variable nom1
    cin >> nom1;                                                                    // stockage du nom1
    listenom[0] = nom1;                                                             // stockage du nom1 dans le tableau listenom
    cin.ignore();                                                                   // vide le buffer de cin

    cout << "===== Entrez le nom du deuxieme heros de votre aventure====" << endl;   // demande du nom du deuxieme hero
    string nom2;                                                                    // creation d'une variable nom2
    cin >> nom2;                                                                    // stockage du nom2
    listenom[1] = nom2;                                                             // stockage du nom2 dans le tableau listenom
    cin.ignore();                                                                   // vide le buffer de cin

    cout << "===== Entrez le nom du troisieme heros de votre aventure====" << endl;  // demande du nom du troisieme hero
    string nom3;                                                                    // creation d'une variable nom3
    cin >> nom3;                                                                    // stockage du nom3
    listenom[2] = nom3;                                                             // stockage du nom3 dans le tableau listenom
    cin.ignore();                                                                   // vide le buffer de cin

    cout << "===== Entrez le nom du quatrieme heros de votre aventure====" << endl;  // demande du nom du quatrieme hero
    string nom4;                                                                    // creation d'une variable nom4
    cin >> nom4;                                                                    // stockage du nom4
    listenom[3] = nom4;                                                             // stockage du nom4 dans le tableau listenom
    cout << endl;                                                                   // saut de ligne
    cin.ignore();                                                                   // vide le buffer de cin

    // === creation des 4 heros ===
    Hero* listehero [4];                                                            // creation d'un tableau de 4 heros
    int decisionclasse = 0;                                                         // variable pour le choix de la classe du hero
    int decisionarme = 0;                                                          // variable pour le choix de l'arme du hero
    default_random_engine generator;
    uniform_int_distribution<int> distribution3(0,2);                        // creation d'un generateur de nombre aleatoire pour la classe du hero
    uniform_int_distribution<int> distribution2(0,1);                         // creation d'un generateur de nombre aleatoire pour l'arme du hero
    string nomarme = "";                                                        // variable pour le nom de l'arme du hero

        
    for (int i = 0; i < 4; i++) {                                                   // boucle pour creer les 4 heros
        
        decisionclasse = distribution3(generator);                              // choix aleatoire de la classe du hero
        decisionarme = distribution2(generator);                              // choix aleatoire de l'arme du hero

        
        switch (decisionclasse) {                                                   // creation du hero en fonction de la classe choisie avec switch
        case 0:
            if (decisionarme == 0) {nomarme = "epee";}                                                                          //if du choix de l'are du heros random
            else {nomarme = "hallebarde";}
            listehero[i] = new Chevalier((rand() %20 +50), rand() %2+4, 8, nomarme, listenom[i], true, "attaque puissante");    // creation du hero type chevalier avec les parametres aleatoires
            cout << endl <<"Le chevalier " << listenom[i] << " a rejoint l'aventure !" << endl << endl;                         // affichage du type du hero
            listehero[i]->afficherstats();                                                                                      // affichage des stats du hero
            break;
        case 1:
            listehero[i] = new Ninja((rand() %10 +30), rand() %3+1, 5, "Saï",listenom[i] , true, "double attaque");             // creation du hero type ninja avec les parametres aleatoires
            cout << endl <<"Le Ninja " << listenom[i] << " a rejoint l'aventure !" << endl << endl;                             // affichage du type du hero
            listehero[i]->afficherstats();                                                                                      // affichage des stats du hero
            break;
        case 2:
            if (decisionarme == 0) {nomarme = "hache";}                                                                     //choix au hasard de l'arme du clerc
            else {nomarme = "masse";}
            listehero[i] = new Clerc((rand() %20 +40), rand() %5+5, 8, nomarme, listenom[i], true, "soin");                 // creation du hero type Clerc avec les parametres aleatoires
            cout << endl <<"Le Clerc " << listenom[i] << " a rejoint l'aventure !" << endl << endl;                         // affichage du type du hero
            listehero[i]->afficherstats();                                                                                  // affichage des stats du hero
            break;
        }
        cout << "appuyez sur entrée pour continuer" << endl;                                 // affichage pour continuer
        cin.ignore();                                                                           // attente de l'appui sur entrée

    }

    cout << endl;
    cout << "Appuyez sur entrer pour continuer" << endl;            // attend que l'utilisateur appuie sur entrer
    cin.ignore();                                                   // attend entrée de l'utilisateur
    



    // === creation des 10 monstres ===
    Monstre* listemonstre [10];                                                                                     // creation d'un tableau de 10 monstres
    int decisionmonstre = 0;                                                                                        // variable pour le choix du type de monstre

    for (int i = 0; i < 10; i++) {                                                                                  // boucle pour creer les 10 monstres
        
        decisionmonstre = distribution2(generator);                                                                                // choix aleatoire du type de monstre
        decisionarme = distribution2(generator);                                                                                  // choix aleatoire de l'arme du monstre
        int degats = 0;                                                                                             // variable pour les degats de l'arme du monstre

        if (decisionarme == 0) {nomarme = "hache";degats=8;}                                                        // choix de l'arme du monstre
        else {nomarme = "gourdin";degats=5;}

        if (decisionmonstre == 0) {
            listemonstre[i] = new Monstre((rand() %10 +10), rand() %2+4, degats, nomarme,"Monstre n:" + to_string(i+1) + " ORC" , true);             // creation du monstre type monstre avec les parametres aleatoires
        }
        else {
            listemonstre[i] = new Monstre((rand() %10 +10), rand() %3+2, degats, nomarme, "Monstre n:" + to_string(i+1) + " Gobelin", true);         // creation du monstre type boss avec les parametres aleatoires
        }
    }


    // === debut combat ===
    cout << endl << "===== Debut du combat =====" << endl << endl;                          // affichage du debut du combat
    cout << "Une orde de 10 monstre s'approche, attention !" << endl << endl;               // affichage debut
    int nbtour=1;                                                                           // variable pour le nombre de tour
    int a=0;                                                                                // variable pour le choix du monstre a attaquer

    cout << endl;
    cout << "Appuyez sur entrer pour continuer" << endl;                                    // attend que l'utilisateur appuie sur entrer
    cin.ignore();                                                                           // attend entrée de l'utilisateur
    
    uniform_int_distribution<int> distribution10(0,9);                                              // creation d'un generateur de nombre aleatoire pour le choix de monstre
    bool stop=0;                                                                            // variable pour arreter la boucle
    int ptpouvoir=3;                                                                           // variable pour le nombre de point de pouvoir pour l'equipe


    while (verifpartie(listehero,listemonstre)==0 && stop==0){                              // boucle pour faire les tours de combat


        cout << endl << "===== Debut du tour n "<< nbtour << "=====" << endl << endl;               // affichage du debut du tour
        cout << "Les heros attaquent !" << endl;                                                    // affichage debut du tour
        cout << "======================" << endl << endl;                                           // affichage debut du tour
        bool truc=true;                                                                            // variable pour arreter la boucle

        

        int boucle=0;                                                                           // variable pour arreter la boucle
        while(boucle<4 && stop==0){                                                               // boucle pour faire attaquer les 4 heros
            if (listehero[boucle]->estvivant()==true){                                                   // si le hero est vivant
                listehero[boucle]->afficherstats();                                                      // affichage des stats du hero

                bool verif=0;                                                                       // variable pour verifier si le monstre est vivant
                int a = 0;                                              // choix aleatoire du monstre a attaquer

                while (verif==0){
                    if (listemonstre[a]->estvivant()==true){                                        // si le monstre est vivant
                        verif=1;                                                                    // verif passe a 1
                    }
                    else {a++;}                                          // sinon on en choisit un autre

                    if (a>10){                                                                     // si tous les monstres sont morts
                        cout << endl << "Les monstres sont tous morts, les heros ont gagnes !" << endl; // affichage fin du combat
                        verif=1;                                                                    // verif passe a 1
                        a=0;                                                                        // a passe a 0 
                        stop=1;                                                                     // stop passe a 1                                                                
                    }

                }

                bool verifinput=0;
                int choix = 0;

                // check des pb d'input user
                while (verifinput==0 && stop==0){
                    cout << endl << endl;                                                                // saut de ligne
                    cout << "=================================================================" << endl; // saut de ligne
                    cout << "Que voulez vous faire avec "<< listehero[boucle]->getnom() <<" ?" << endl;  // affichage debut du tour
                    cout << "1 - Attaquer" << endl;                                                     // affichage debut du tour
                    cout << "2 - Defendre" << endl;                                                     // affichage debut du tour
                    cout << "3 - Pouvoir (-3pts)" << endl << endl;                                      // affichage debut du tour
                    ptpouvoir++;                                                                        // augmentation du nombre de pouvoir
                    cout << "Points de pouvoir : " << ptpouvoir << endl << endl;                        // affichage du nombre de pts pouvoir

                    cin >> choix;                                                                       // choix du hero
                    cin.clear();                                                                        // vide le buffer de cin
                    cin.ignore();
                    cout << endl;                                                                       // saut de ligne

                    
                    switch (choix) {                                                                    // choix du hero avec switch
                        case 1:
                            listehero[boucle]->attaquer(listemonstre[a]);                               // attaque du hero
                            verifinput=1;                                                               // verifinput passe a 1
                        break;

                        case 2:
                            listehero[boucle]->defendre();                                               // deffense du hero
                            verifinput=1;                                                                // verifinput passe a 1
                        break;

                        case 3:
                            if(ptpouvoir<3){cout << "Vous n'avez plus de points de pouvoir !" << endl;}           // si l'equipe n'a plus de pouvoir
                            else {listehero[boucle]->usepouvoir();ptpouvoir=ptpouvoir-3; cout << "paiement de 3 points pouvoir" << endl ; }           // pouvoir du hero
                            verifinput=1;                                                               // verifinput passe a 1
                        break;

                        default:
                            cout << "Erreur : choix non valide" << endl;                                // affichage erreur
                            verifinput=0;                                                               // verifinput passe a 0
                        break;
                        }
                    
                }
            }

            else {                                                                                  // si le hero est mort
                cout << endl << listehero[boucle]->getnom() << " est mort !" << endl;               // affichage du hero mort
                if(boucle==3){stop=1;}                                                              // si le hero est le dernier de la liste, boucle passe a 4
            }

            boucle++;                                                                               // boucle passe a 1
        }

        while (stop==0 && truc==true ){                                                             // boucle pour annoncer le debut du tour monstre mais pas quand la partie est finie
        cout << endl << "Les monstres attaquent !" << endl;                                         // affichage debut du tour monstre
        cout << "==========================" << endl;                                               // affichage debut du tour monstre
        truc = false;
        }

        int bouclemonstre=0;                                                                        // variable pour arreter la boucle
        while (bouclemonstre<10 && stop==0){                                                        // boucle pour faire attaquer les 10 monstres
                if (listemonstre[bouclemonstre]->estvivant()==true){                                // si le monstre est vivant
                listemonstre[bouclemonstre]->afficherstats();                                       // affichage des stats du monstre

                bool verif=0;                                                                       // variable pour verifier si le hero est vivant
                while (verif==0){
                    int a = distribution3(generator);                                               // choix aleatoire du hero a attaquer
                    if (listehero[a]->estvivant()==true){                                           // si le hero est vivant
                        verif=1;                                                                    // verif passe a 1
                    }
                }

                listemonstre[bouclemonstre]->attaquer(listehero[a]);                                // attaque du monstre
            }
            else {                                                                                  // si le monstre est mort
                cout << endl << listemonstre[bouclemonstre]->getnom() << " est mort !" << endl;     // affichage du monstre mort
            }
            bouclemonstre++;                                                                        // boucle incrementee

            cout << "appuyez sur entrée pour continuer" << endl;                                 // affichage pour continuer
            cin.ignore();                                                                           // attente de l'appui sur entrée


        }
        


        nbtour++;                                                                                   // incrementation du nombre de tour
        cout << endl << "===== Fin du tour =====" << endl << endl;                                  // affichage fin du tour

        





    }


    // fin de la partie et vainqueurs

    if (verifpartie(listehero,listemonstre)==1){ // si les 4 heros sont tous mort
        cout << endl << "===== Fin de la partie =====" << endl << endl; // affichage fin de la partie
        cout << "Les monstres ont gagne, les heros sont morts !" << endl << endl; // affichage des vainqueurs
    }
    else if (verifpartie(listehero,listemonstre)==2){ // si les 10 monstres sont tous mort
        cout << endl << "===== Fin de la partie =====" << endl << endl; // affichage fin de la partie
        cout << "Les heros ont gagne, les monstres sont morts !" << endl << endl; // affichage des vainqueurs
    }
    
    cout << endl << "===== Fin du programme =====" << endl << endl; // affichage fin du programme
    cout << "Merci d'avoir joué" << endl << endl; // affichage fin du programme

    






    return 0;
}




