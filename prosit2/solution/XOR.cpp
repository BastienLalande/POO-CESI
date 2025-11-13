#include "XOR.h"
#include <string>

std::string XOR::doXOR(std::string msg){
    std::string resultat;
    int len_msg = msg.length();
    int key_len = this->key.length();
    for (int i = 0; i < len_msg; ++i) {
        resultat += msg[i] ^ this->key[i % key_len];
    }
    return resultat;
}

XOR::XOR(std::string _key){
    this->key=_key;
}

XOR::XOR(){
    this->key = "cle de base !";
}

XOR::~XOR(){

}

std::string XOR::chiffrer(const std::string msg){
    return doXOR(msg);
}

std::string XOR::dechiffrer(const std::string msg){
    return doXOR(msg);
}

void XOR::setKey(std::string key) {
    this->key = key;
}
