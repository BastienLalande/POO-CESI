#ifndef CHIFFRE_H
#define CHIFFRE_H

#include <string>

class chiffre {
    public:
        chiffre(){}
        virtual ~chiffre(){}
        std::string chiffrer(const std::string _msg);
        std::string dechiffrer(const std::string _msg);
};

#endif
