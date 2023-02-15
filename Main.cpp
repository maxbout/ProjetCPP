#include <string>
#include <iostream>
#include <string>
#include "Classes.h"

using namespace std;

int main()
{
    //================================================================
    // === Accueil de l'utilisateur ===
    //================================================================

    // affichage de l'accueil
    cout << "===Bienvenue dans le jeu de combat===" << endl;
    cout << "Vous allez devoir choisir 4 heros pour votre aventure" << endl;
    cout << "Vous allez rencontrer 10 monstres et allez devoir les combatre" << endl;
    cout << "Il y a 3 types de Heros chois au hasard" << endl;
    cout << "Le Chevalier, le Ninja et le Clerc" << endl;
    cout << "Le Clerc a un pouvoir qui lui permet de soigner ses alliés" << endl;
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
        switch (decisionclasse) {                                                   // creation du hero en fonction de la classe choisie au hasard
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


    
    
    

    






    return 0;
}