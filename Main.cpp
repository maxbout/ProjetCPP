#include <string>
#include <iostream>
#include <string>
#include "Classes.h"

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
    cout << "Vous allez rencontrer 10 monstres et allez devoir les combatre" << endl;
    cout << "Il y a 3 types de Heros choisis au hasard" << endl;
    cout << "Le Chevalier, le Ninja et le Clerc" << endl;
    cout << "Le Clerc a un pouvoir qui lui permet de se soigner" << endl;
    cout << "Le Ninja a un pouvoir qui lui permet d'attaquer deux fois'" << endl;
    cout << "Le Chevalier a un pouvoir qui lui permet d'augmenter son attaque'" << endl;
    cout << "==Bonne chance et bon jeu==" << endl;
    cout << endl;
    cout << endl;
    cout << "Appuyez sur une touche pour continuer" << endl;
    std::getchar();



    // demande du nom des 4 heros
    cout << "Dans un royame lointain, il y a longtemps...." << endl;
    cout << "Autour d'une forteresse en etoile, 4 heros se sont reunis pour partir a l'aventure" << endl;
    cout << "Leur but: sauver les bars lillois de la destruction !!" << endl;
    cout << "Mais pour cela, ils vont devoir affronter les 10 monstres de la mairie..." << endl;
    cout <<"Leur aventure commence maintenant !";
    cout << "..." << endl;
    cout << endl;
    cout << "Appuyez sur une touche pour continuer" << endl;
    std::getchar();                                                                 // attend que l'utilisateur appuie sur une touche

    string listenom [4];                                                            // creation d'un tableau de 4 noms

    cin.ignore();                                                                   // vide le buffer
    cout << "===== Entrez le nom du premier hero de votre aventure====" << endl;    // demande du nom du premier hero
    string nom1;                                                                    // creation d'une variable nom1
    cin >> nom1;                                                                    // stockage du nom1
    listenom[0] = nom1;                                                             // stockage du nom1 dans le tableau listenom
    cin.ignore();                                                                   // vide le buffer de cin

    cout << "===== Entrez le nom du deuxieme hero de votre aventure====" << endl;   // demande du nom du deuxieme hero
    string nom2;                                                                    // creation d'une variable nom2
    cin >> nom2;                                                                    // stockage du nom2
    listenom[1] = nom2;                                                             // stockage du nom2 dans le tableau listenom
    cin.ignore();                                                                   // vide le buffer de cin

    cout << "===== Entrez le nom du troisieme hero de votre aventure====" << endl;  // demande du nom du troisieme hero
    string nom3;                                                                    // creation d'une variable nom3
    cin >> nom3;                                                                    // stockage du nom3
    listenom[2] = nom3;                                                             // stockage du nom3 dans le tableau listenom
    cin.ignore();                                                                   // vide le buffer de cin

    cout << "===== Entrez le nom du quatrieme hero de votre aventure====" << endl;  // demande du nom du quatrieme hero
    string nom4;                                                                    // creation d'une variable nom4
    cin >> nom4;                                                                    // stockage du nom4
    listenom[3] = nom4;                                                             // stockage du nom4 dans le tableau listenom
    cout << endl;                                                                   // saut de ligne
    cin.ignore();                                                                   // vide le buffer de cin

    // === creation des 4 heros ===
    Hero* listehero [4];                                                            // creation d'un tableau de 4 heros
    int decisionclasse = 0;                                                         // variable pour le choix de la classe du hero

    for (int i = 0; i < 4; i++) {                                                   // boucle pour creer les 4 heros
        
        int decisionclasse = rand() % 3;                                            // choix aleatoire de la classe du hero
        int decisionarme = rand() % 2;                                              // choix aleatoire de l'arme du hero
        string nomarme = "";                                                        // variable pour le nom de l'arme du hero
        
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
    }

    // === creation des 10 monstres ===
    Monstre* listemonstre [10];                                                                                     // creation d'un tableau de 10 monstres
    int decisionmonstre = 0;                                                                                        // variable pour le choix du type de monstre
    int decisionarme = 0;                                                                                           // variable pour le choix de l'arme du monstre
    string nomarme = "";                                                                                            // variable pour le nom de l'arme du monstre

    for (int i = 0; i < 10; i++) {                                                                                  // boucle pour creer les 10 monstres
        
        decisionmonstre = rand() %2;                                                                                // choix aleatoire du type de monstre
        decisionarme = rand() % 2;                                                                                  // choix aleatoire de l'arme du monstre
        string nomarme = "";                                                                                        // variable pour le nom de l'arme du monstre
        int degats = 0;                                                                                             // variable pour les degats de l'arme du monstre

        if (decisionarme == 0) {nomarme = "hache";degats=8;}                                                        // choix de l'arme du monstre
        else {nomarme = "gourdin";degats=5;}

        if (decisionmonstre == 0) {
            listemonstre[i] = new Monstre((rand() %10 +10), rand() %2+4, degats, nomarme,"Monstre n:" + to_string(i) + " ORC" , true);             // creation du monstre type monstre avec les parametres aleatoires
        }
        else {
            listemonstre[i] = new Monstre((rand() %10 +10), rand() %3+2, degats, nomarme, "Monstre n:" + to_string(i) + " Gobelin", true);         // creation du monstre type boss avec les parametres aleatoires
        }
    }


    // === debut combat ===
    cout << endl << "===== Debut du combat =====" << endl << endl;                          // affichage du debut du combat
    cout << "Une orde de 10 monstre s'approche, attention !" << endl << endl;               // affichage debut
    int nbtour=1;                                                                           // variable pour le nombre de tour
    int a=0;                                                                                // variable pour le choix du monstre a attaquer
    
    while (verifpartie(listehero,listemonstre)==0){
        cout << endl << "===== Debut du tour n "<< nbtour << "=====" << endl << endl;               // affichage du debut du tour
        cout << "Les heros attaquent !" << endl;                                                    // affichage debut du tour
        cout << "======================" << endl;                                                   // affichage debut du tour

        for (int i = 0; i < 4; i++) {                                                               // boucle pour faire attaquer les 4 heros
            if (listehero[i]->estvivant()==true){                                                   // si le hero est vivant
                listehero[i]->afficherstats();                                                      // affichage des stats du hero

                bool verif=0;                                                                       // variable pour verifier si le monstre est vivant
                while (verif==0){
                    int a = rand() % 10;                                                            // choix aleatoire du monstre a attaquer
                    if (listemonstre[a]->estvivant()==true){                                        // si le monstre est vivant
                        verif=1;                                                                    // verif passe a 1
                    }
                }

                // check des pb d'input user



                cout << endl;                                                                       // saut de ligne
                cout << "Que voulez vous faire avec"<< listehero[i]->getnom() <<" ?" << endl;       // affichage debut du tour
                cout << "1 - Attaquer" << endl;                                                     // affichage debut du tour
                cout << "2 - Defendre" << endl;                                                     // affichage debut du tour
                cout << "3 - Pouvoir" << endl;                                                      // affichage debut du tour
                int choix = 0;                                                                      // variable pour le choix du hero
                cin >> choix;                                                                       // choix du hero
                cout << endl;                                                                       // saut de ligne
                switch (choix) {                                                                    // choix du hero avec switch
                case 1:
                    listehero[i]->attaquer(listemonstre[a]);                                        // attaque du hero
                    break;
                case 2:
                    listehero[i]->defendre();                                                       // deffense du hero
                    break;
                case 3:
                    listehero[i]->usepouvoir();                                                     // pouvoir du hero
                    break;
                }
            }
        }
        




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




