#ifndef FILE_H
#define FILE_H

#include <string>

class file {
    private:
        std::string name;
    public:
        file(std::string _filename);
        ~file();
        bool saveFile(std::string _msg);
        std::string readFile();
};

#endif
