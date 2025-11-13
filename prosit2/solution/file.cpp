#include "file.h"
#include <fstream>

using namespace std;

file::~file(){}

bool file::saveFile(string _msg){
    ofstream outfile(this->name, ios::trunc);
    if (!outfile.is_open()) {
        return false;
    }
    outfile << _msg;
    outfile.close();
    return true;
}

file::file(string _filename){
    this->name=_filename;
    // Test if the file exists by trying to open it for reading
    ifstream infile(_filename);
    if (!infile.is_open()) {
        // File does not exist, so create it using saveFile (save empty content)
        this->saveFile("");
    } else {
        infile.close();
    }
}

string file::readFile(){
    ifstream infile(this->name);
    if (!infile.is_open()) {
        return "";
    }
    string content((istreambuf_iterator<char>(infile)), istreambuf_iterator<char>());
    infile.close();
    return content;
}
