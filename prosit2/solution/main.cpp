#include "XOR.h"
#include "cesar.cpp"
#include "XOR.cpp"
#include "Cesar.h"
#include "mixt.cpp"
#include "file.cpp"
#include <iostream>
#include <string>
#include "file.h"
#include "mixt.h"

using namespace std;

int main() {
    string sourceFilename;
    cout << "entrez le fichier source :";
    cin >> sourceFilename;

    file fsource(sourceFilename);

    int mode_secu;
    cout << "entrez le mode de securite (1, 2 ou 3) :";
    cin >> mode_secu;

    string destFilename;
    cout << "entrez le fichier de destination :";
    cin >> destFilename;

    file fdest(destFilename);

    if (mode_secu == 1) {
        cesar cypher;
        if (sourceFilename.size() >= 6 && sourceFilename.substr(sourceFilename.size() - 6) == ".crypt") {
            fdest.saveFile(cypher.dechiffrer(fsource.readFile()));
        } else if (sourceFilename.size() >= 6 && sourceFilename.substr(sourceFilename.size() - 6) == ".clair") {
            fdest.saveFile(cypher.chiffrer(fsource.readFile()));
        }
    } else if (mode_secu == 2) {
        XOR cypher;
        if (sourceFilename.size() >= 6 && sourceFilename.substr(sourceFilename.size() - 6) == ".crypt") {
            fdest.saveFile(cypher.dechiffrer(fsource.readFile()));
        } else if (sourceFilename.size() >= 6 && sourceFilename.substr(sourceFilename.size() - 6) == ".clair") {
            fdest.saveFile(cypher.chiffrer(fsource.readFile()));
        }
    } else if (mode_secu == 3) {
        Mixt cypher;
        if (sourceFilename.size() >= 6 && sourceFilename.substr(sourceFilename.size() - 6) == ".crypt") {
            fdest.saveFile(cypher.dechiffrer(fsource.readFile()));
        } else if (sourceFilename.size() >= 6 && sourceFilename.substr(sourceFilename.size() - 6) == ".clair") {
            fdest.saveFile(cypher.chiffrer(fsource.readFile()));
        }
    } else {
        cerr << "Mode de securite invalide." << endl;
    }

    return 0;
}
