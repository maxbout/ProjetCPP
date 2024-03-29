#ifndef CLASSES_H
#define CLASSES_H

#include <iostream>
#include <string>

// ==============================================================
// creationde la classe principale
// ==============================================================

// creation de la classe personnage avec comme attribits vie defense degat et nom
class Personnage {
    public:
        Personnage(int vie, int defense, int degats,std::string arme, std::string nom,bool vivant);        // constructeur de la classe Personnage
        void attaquer(Personnage* cible);                                           // methode attaquer
        void prenddegats(int ptdegat);                                                   // methode degats
        bool estvivant();                                                               // methode estvivant
        virtual void afficherstats();                                                       // methode afficherstats
        void defendre();                                                                // methode defendre
        std::string getnom();                                                                // methode getnom
    protected:    
        int vie;                                                                    // attributs de la classe Personnage mis en protected
        int defense;
        int degats;
        std::string arme;
        std::string nom;
        bool vivant;
};

//==============================================================
// heritage de personnage
//==============================================================

// creation de la classe Monstre qui herite de la classe Personnage
class Monstre : public Personnage {
    public:
        Monstre(int vie, int defense, int degats, std::string arme,std::string nom, bool vivant); // constructeur de la classe Monstre
};

// creation de la classe hero qui herite de la classe Personnage
class Hero : public Personnage {
    public:
        Hero ();                                                                    // constructeur de la classe Hero
        Hero(int vie, int defense, int degats,std::string arme, std::string nom, bool vivant, std::string pouvoir);     // constructeur de la classe Hero
        void afficherstats();                                                               // methode afficherstats
        virtual void usepouvoir(Personnage* cible);                                                                  // methode pouvoir
    protected:
        std::string pouvoir;                                                                // attribut pouvoir mis en protected
    };

// ==============================================================
// heritage de hero
// ==============================================================

// creation de la classe Chevalier qui herite de la classe hero
class Chevalier : public Hero {
    public:
        Chevalier(int vie, int defense, int degats,std::string arme, std::string nom, bool vivant, std::string pouvoir);    // constructeur de la classe Chevalier
        virtual void usepouvoir(Personnage* cible);                                                                         // methode pouvoir appliquée au Chevalier
        
};

//creation de la classe Ninja qui herite de la classe hero
class Ninja : public Hero {
    public:
        Ninja(int vie, int defense, int degats,std::string arme, std::string nom, bool vivant, std::string pouvoir);    // constructeur de la classe Ninja
        virtual void usepouvoir(Personnage* cible);                                                                    // methode pouvoir appliquée au Ninja
};

// creation de la classe Clerc qui herite de la classe hero
class Clerc : public Hero {
    public:
        Clerc(int vie, int defense, int degats,std::string arme, std::string nom, bool vivant, std::string pouvoir);    // constructeur de la classe Clerc
        virtual void usepouvoir(Personnage* cible);                                                                   // methode pouvoir appliquée au Clerc
};


#endif