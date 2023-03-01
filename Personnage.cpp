#include <string>
#include <iostream>
#include <string>
#include "Classes.h"


using namespace std;


// ==============================================================
//methodes appliquées a la classe Personnage
// ==============================================================

// constructeur de la classe Personnage
Personnage::Personnage (int vie, int defense, int degats, string arme, string nom,bool vivant){
    this->vie=vie;                   // initialisation de la vie
    this->defense=defense;           // initialisation de la defense
    this->degats=degats;             // initialisation des degats
    this->arme=arme;                 // initialisation de l'arme
    this->nom=nom;                   // initialisation du nom
    this->vivant=vivant;             // initialisation de l'etat de vie
};

// methode attaquer
void Personnage::attaquer(Personnage* cible){
    cout << "Le personnage " << this->nom << " attaque "<< cible->nom <<" avec son arme:  " << this->arme << endl;   // affichage de l'attaque
    cible->prenddegats(this->degats);                                                                             // appel de la methode degats de la cible

};

// methode degats
void Personnage::prenddegats(int ptdegat){      
    // etape 1: calcul des degats subis
    int perdu=ptdegat-this->defense;                                                                     // calcul
    if (perdu<0){                                                                                       // si les degats sont inferieurs a la defense
        perdu=0;                                                                                        // les degats sont nuls
    };
    // etape 2: soustraction des degats subis a la vie
    this->vie=this->vie-(perdu);                                                                          // soustraction des degats subis a la vie
    cout << "Le personnage " << this->nom << " a subit " << perdu << " points de degats" << endl;        // affichage des degats subis
    // etape 3: verification si le personnage est vivant
    if (this->vie<0){                                                                                    // si la vie est inferieur a 0
        this->vivant=false;                                                                              // le personnage est mort
        cout << "Le personnage " << this->nom << " est mort" << endl;                                    // affichage de la mort du personnage
    };
};
// methode afficherstats
void Personnage::afficherstats(){

    cout << endl <<"======== STATS DU PERSONNAGE: "<<this->nom << " ========" << endl;                             // affichage du titre "STATS DU PERSONNAGE
    cout << "points de vie: " << this->vie << endl;                                                         // affichage de la vie
    cout << "points de defense: " << this->defense << endl;                                                 // affichage de la defense
    cout << "points de degats: " << this->degats << endl;                                                   // affichage des degats
    cout << "arme: " << this->arme << endl;                                                                 // affichage de l'arme
    
    if (this->vivant==true){                                                                                // si le personnage est vivant
        cout << "Le personnage " << this->nom << " est vivant" << endl;                                     // affichage de l'etat de vie
    }
    else{                                                                                                   // si le personnage est mort
        cout << "Le personnage " << this->nom << " est mort" << endl;                                       // affichage de l'etat de vie
    }
};

// methode est vivant
bool Personnage::estvivant(){
    return this->vivant;                                                                                    // retourne l'etat de vie
};

// methode defendre
void Personnage::defendre(){
    cout << "Le personnage " << this->nom << " se defend" << endl;                                          // affichage de la defense
    this->defense=(this->defense*1.75);                                                                     // augmentation de la defense de 75 %
};

// methode getnom
string Personnage::getnom(){
    return this->nom;                                                                                       // retourne le nom du personnage
};
