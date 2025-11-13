#include "mixt.h"
#include "XOR.h"
#include "cesar.h"
#include <string>

// Constructeur par défaut
Mixt::Mixt() {
    this->cesarCypher = cesar(3);
    this->xorCypher = XOR("cle de base !");
}

// Constructeur avec paramètre
Mixt::Mixt(int _keyCesar, std::string _keyXor) {
    this->cesarCypher.setKey(_keyCesar);
    this->xorCypher.setKey(_keyXor);
}

// Destructeur
Mixt::~Mixt() {
    // Rien à libérer pour cette classe
}

// Méthode pour chiffrer un message
std::string Mixt::chiffrer(const std::string _msg) {
    std::string r;
    r = this->cesarCypher.chiffrer(_msg);
    r = this->xorCypher.chiffrer(r);
    return r;
}

// Méthode pour déchiffrer un message
std::string Mixt::dechiffrer(const std::string _msg) {
    std::string r;
    r = this->xorCypher.dechiffrer(_msg);
    r= this->cesarCypher.dechiffrer(r);
    return r;
}

// Setter pour modifier la clé
void Mixt::setKey(int _keyCesar, std::string _keyXor) {
    this->cesarCypher.setKey(_keyCesar);
    this->xorCypher.setKey(_keyXor);
}
