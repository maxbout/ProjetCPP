#include <string>
#include <iostream>
#include <string>
#include "Classes.h"


using namespace std;

// ==============================================================
// methodes appliquées a la classe Personnage
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



// ==============================================================
// methodes appliquées a la classe Monstre
// ==============================================================

// constructeur de la classe Monstre
Monstre::Monstre (int vie, int defense, int degats, string arme, string nom,bool vivant):Personnage(vie, defense, degats, arme, nom, vivant) {
 // constructeur vide car aucune modification de personnage
}


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





