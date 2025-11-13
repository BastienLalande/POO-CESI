#include "Cesar.h"
#include <string>

// Constructeur par défaut
cesar::cesar() {
    this->key = 3;
}

// Constructeur avec paramètre
cesar::cesar(int _key) {
    this->key = _key;
}

// Destructeur
cesar::~cesar() {
    // Rien à libérer pour cette classe
}

// Méthode privée qui effectue l'opération XOR
std::string cesar::doCesar(std::string _msg) {
    std::string resultat;
    for (size_t i = 0; i < _msg.length(); ++i) {
        char c = _msg[i];
        if (c >= 'a' && c <= 'z') {
            c = ((c - 'a' + key) % 26) + 'a';
        } else if (c >= 'A' && c <= 'Z') {
            c = ((c - 'A' + key) % 26) + 'A';
        }
        resultat += c;
    }
    return resultat;
}

// Méthode pour chiffrer un message
std::string cesar::chiffrer(const std::string _msg) {
    return doCesar(_msg);
}

// Méthode pour déchiffrer un message
std::string cesar::dechiffrer(const std::string _msg) {
    this->key = -this->key;
    std::string resultat = doCesar(_msg);
    this->key = -this->key;
    return resultat;
}

// Setter pour modifier la clé
void cesar::setKey(int _key) {
    this->key = _key;
}
