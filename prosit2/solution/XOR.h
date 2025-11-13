#ifndef XOR_H
#define XOR_H

#include "chiffre.h"
#include <string>

class XOR : public chiffre {
    private:
        std::string key;
        std::string doXOR(std::string _msg);
    public:
        XOR();
        XOR(std::string _key);
        virtual ~XOR();
        std::string chiffrer(const std::string _msg);
        std::string dechiffrer(const std::string _msg);
        void setKey(std::string _key);
};

#endif
