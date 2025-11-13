#ifndef MIXT_H
#define MIXT_H

#include "XOR.h"
#include "cesar.h"
#include "chiffre.h"
#include <string>

class Mixt : public chiffre {
    private:
        cesar cesarCypher;
        XOR xorCypher;
    public:
        Mixt();
        Mixt(int _keyCesar, std::string _keyXor);
        virtual ~Mixt();
        std::string chiffrer(const std::string _msg);
        std::string dechiffrer(const std::string _msg);
        void setKey(int _keyCesar, std::string _keyXor);
};

#endif
