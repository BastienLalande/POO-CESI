#include <iostream>
using namespace std;

using namespace std;

class CLvoiture {
protected:
    int vitesseMax;
    int vitesse;
    int acceleration;
    static int nbObjets;
public:
    CLvoiture() : vitesseMax(100), vitesse(0), acceleration(1) {
        nbObjets++;
    }
    CLvoiture(int vMax, int accel) {
        vitesseMax = min(vMax, 100);
        acceleration = min(accel, 3);
        vitesse = 0;
        nbObjets++;
    }
    void initialiser(int vMax, int accel) {
        vitesseMax = min(vMax, 100);
        acceleration = min(accel, 3);
        vitesse = 0;
    }
    virtual void accelerer() {
        vitesse += acceleration;
        if (vitesse > vitesseMax) vitesse = vitesseMax;
        cout << "Voiture accelere a " << vitesse << " km/h (max: " << vitesseMax << ")" << endl;
    }
    virtual ~CLvoiture() {}
    static int getNbObjets() { return nbObjets; }
};
int CLvoiture::nbObjets = 0;

class ClvoitureSport : public CLvoiture {
    static int nbObjetsSport;
public:
    ClvoitureSport() : CLvoiture() {
        vitesseMax = 200;
        acceleration = 2;
        nbObjetsSport++;
    }
    ClvoitureSport(int vMax, int accel) : CLvoiture() {
        vitesseMax = min(vMax, 200);
        acceleration = min(accel, 8);
        vitesse = 0;
        nbObjetsSport++;
    }
    void initialiser(int vMax, int accel) {
        vitesseMax = min(vMax, 200);
        acceleration = min(accel, 8);
        vitesse = 0;
    }
    void accelerer() override {
        vitesse += acceleration;
        if (vitesse > vitesseMax) vitesse = vitesseMax;
        cout << "Voiture de sport accelere a " << vitesse << " km/h (max: " << vitesseMax << ")" << endl;
    }
    static int getNbObjetsSport() { return nbObjetsSport; }
};
int ClvoitureSport::nbObjetsSport = 0;

int main() {
    int pause;
	CLvoiture* voiture1 = new ClvoitureSport(500, 9);
	CLvoiture* voiture2 = new CLvoiture(500, 9);
	voiture1->accelerer();
	voiture2->accelerer();
	(voiture1 = voiture2)->accelerer();
	cin >> pause;
	return 0;
}
