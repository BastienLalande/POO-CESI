#ifndef CESAR_H
#define CESAR_H

#include "chiffre.h"
#include <string>

class cesar : public chiffre {
    private:
        int key = 3;
        std::string doCesar(std::string _msg);
    public:
        cesar();
        cesar(int _key);
        virtual ~cesar();
        std::string chiffrer(const std::string _msg);
        std::string dechiffrer(const std::string _msg);
        void setKey(int _key);
};

#endif
