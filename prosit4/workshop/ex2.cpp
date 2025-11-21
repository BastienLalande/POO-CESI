#include <iostream>
#include <string>
using namespace std;

class Instrument {
public:
    virtual void jouer() = 0;
    ~Instrument() = default;
};

class Saxophone : public Instrument {
public:
    void jouer() override {
        cout << "Le saxophone joue le son caracteristique du saxophone." << endl;
    }
};

class Piano : public Instrument {
public:
    void jouer() override {
        cout << "Le piano joue le son caracteristique d'un piano." << endl;
    }
};

int main() {
    string choix;
    cout << "Quel instrument souhaitez-vous jouer (saxophone ou piano) ? ";
    getline(cin, choix);

    Instrument* instrument = nullptr;
    if (choix == "saxophone") {
        instrument = new Saxophone();
    } else if (choix == "piano") {
        instrument = new Piano();
    } else {
        cout << "Instrument inconnu." << endl;
        return -1;
    }

    instrument->jouer();

    return 0;
}
