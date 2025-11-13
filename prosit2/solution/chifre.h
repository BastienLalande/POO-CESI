#ifndef CHIFFRE_H
#define CHIFFRE_H

#include <string>

class chiffre {
    public:
        chiffre();
        virtual ~chiffre();
        chiffre(std::string key);
        chiffre(int key);
        std::string chiffrer(const std::string &msg);
        std::string dechiffrer(const std::string &msg);
};

#endif
