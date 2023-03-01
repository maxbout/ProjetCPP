#include <string>
#include <iostream>
#include <string>
#include "Classes.h"


using namespace std;




// ==============================================================
// methodes appliquées a la classe Monstre
// ==============================================================

// constructeur de la classe Monstre
Monstre::Monstre (int vie, int defense, int degats, string arme, string nom,bool vivant):Personnage(vie, defense, degats, arme, nom, vivant) {
 // constructeur vide car aucune modification de personnage
}