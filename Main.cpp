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

    string listenom [4]; // creation d'un tableau de 4 noms

    cin.ignore();
    cout << "===== Entrez le nom du premier hero de votre aventure====" << endl;
    string nom1;
    cin >> nom1;
    listenom[0] = nom1;
    cin.ignore();

    cout << "===== Entrez le nom du deuxieme hero de votre aventure====" << endl;
    string nom2;
    cin >> nom2;
    listenom[1] = nom2;
    cin.ignore();

    cout << "===== Entrez le nom du troisieme hero de votre aventure====" << endl;
    string nom3;
    cin >> nom3;
    listenom[2] = nom3;
    cin.ignore();

    cout << "===== Entrez le nom du quatrieme hero de votre aventure====" << endl;
    string nom4;
    cin >> nom4;
    listenom[3] = nom4;
    cout << endl;
    cin.ignore();

    // === creation des 4 heros ===
    Hero listehero [4]; // creation d'un tableau de 4 heros
    int decisionclasse = 0; // variable pour le choix de la classe du hero

    for (int i = 0; i < 4; i++) {
        int decisionclasse = rand() % 3; // choix aleatoire de la classe du hero
        switch (decisionclasse) {
        case 0:
            listehero[i] = Chevalier((rand() %20 +50), rand() %2+4, 8, "epee", listenom[i], true, "attaque puissante");
            break;
        case 1:
            listehero[i] = Ninja((rand() %10 +30), rand() %3+1, 5, "Saï",listenom[i] , true, "double attaque");
            break;
        case 2:
            listehero[i] = Clerc((rand() %20 +40), rand() %5+5, 8, "baton",listenom[i], true, "soin");
            break;
    }
    }
    
    

    






    return 0;
}