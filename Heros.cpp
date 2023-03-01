#include <string>
#include <iostream>
#include <string>
#include "Classes.h"


using namespace std;



// ==============================================================
// constructeur de la classe Hero
// ==============================================================

Hero::Hero(int vie, int defense, int degats, string arme, string nom,bool vivant, string pouvoir):Personnage(vie, defense, degats, arme, nom, vivant) {
    // constructeur presque vide car aucune modification de personnage, on ajoute seulement le pouvoir differenten fonction de la fille
    this->pouvoir=pouvoir;           // initialisation du pouvoir
}

// ==============================================================
// methodes pouvoir appliquées au descendants de la classe hero
// ==============================================================

// methode afficherstats appliquée à hero
void Hero::afficherstats(){
    Personnage::afficherstats();    // appel de la methode afficherstats de la classe mere
    cout << "pouvoir: " << this->pouvoir << endl;    // affichage du pouvoir
};

void Hero::usepouvoir(){};


//========Construteurs des classes filles de Hero================

// constructeur de la classe Chevalier
Chevalier::Chevalier(int vie, int defense, int degats, string arme, string nom,bool vivant, string pouvoir):Hero(vie, defense, degats, arme, nom, vivant,pouvoir){
    //on ne modifie pas la classe hero seulement les methodes
}

//constructeur de la classe Ninja
Ninja::Ninja(int vie, int defense, int degats, string arme, string nom,bool vivant, string pouvoir):Hero(vie, defense, degats, arme, nom, vivant,pouvoir){
    //on ne modifie pas la classe hero seulement les methodes
}

// constructeur de la classe Clerc
Clerc::Clerc(int vie, int defense, int degats, string arme, string nom,bool vivant, string pouvoir):Hero(vie, defense, degats, arme, nom, vivant,pouvoir){
    //on ne modifie pas la classe hero seulement les methodes
}

//======== methodes pouvoir des classes filles de Hero================

// pouvoir du chevalier +5 degats
void Chevalier::usepouvoir(){
    cout << "Le chevalier " << this->nom << " utilise son pouvoir" << endl;      // affichage de l'utilisation du pouvoir
    cout << "il devient plus fort de 5 pts de degats" << endl;                  // affichage de l'effet du pouvoir
    this->degats=this->degats+5;                                                  // ajout des degats
}

// pouvoir du ninja attaque deux fois
void Ninja::usepouvoir(){
    cout << "Le Ninja " << this->nom << " utilise son pouvoir" << endl;          // affichage de l'utilisation du pouvoir
    cout << "il attaque deux fois" << endl;                                     // affichage de l'effet du pouvoir
    this->degats=this->degats*2;                                                  // multiplication des degats par 2
}

// pouvoir du Clerc  se soigne de 5 pts
void Clerc::usepouvoir(){
    cout << "Le Clerc " << this->nom << " utilise son pouvoir" << endl;          // affichage de l'utilisation du pouvoir
    cout << "il se soigne de 5 pts" << endl;                                    // affichage de l'effet du pouvoir
    this->vie=this->vie+5;                                                        // ajout des degats
}





