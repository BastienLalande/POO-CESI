#include <iostream>
#include <list>
using namespace std;

class Vehicule {
public:
    virtual void lavage() = 0;
    virtual ~Vehicule() = default;
};

class CLvoiture : public Vehicule {
public:
    void lavage() override {
        cout << "Voiture lavee" << endl;
    }
};

class Moto : public Vehicule {
public:
    void lavage() override {
        cout << "Moto lavee" << endl;
    }
};

class StationLavage {
    list<Vehicule*> parc;
public:
    void ajouterVehicule(Vehicule* v) {
        parc.push_back(v);
    }

    void clearParc() {
        parc.clear();
    }

    void lavageTous() {
        for (Vehicule* v : parc) {
            v->lavage();
        }
    }
};

int main() {
    StationLavage station;
    Vehicule* v1 = new CLvoiture();
    Vehicule* v2 = new CLvoiture();
    Vehicule* m1 = new Moto();

    station.ajouterVehicule(v1);
    station.ajouterVehicule(v2);
    station.ajouterVehicule(m1);

    cout << "\n--- Premier lavage ---" << endl;
    station.lavageTous();

    v1 = new Moto();

    //maj station
    station.clearParc();
    station.ajouterVehicule(v1);
    station.ajouterVehicule(v2);
    station.ajouterVehicule(m1);

    cout << "\n--- Second lavage (v1 transformee en moto) ---" << endl;
    station.lavageTous();

    return 0;
}
