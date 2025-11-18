#include <iostream>
using namespace std;

class Objet {
public:
    virtual double aire() = 0;
    virtual double perimetre() = 0;
    virtual void afficheInfo() = 0;
    virtual ~Objet() = default;
};

class Rectangle : public Objet{
private:
    double largeur;
    double longueur;
public:
    Rectangle(double _largeur, double _longueur):largeur(_largeur),longueur(_longueur){}
    double getLargeur(){return largeur;}
    double getLongueur(){return longueur;}
    double aire() {
        return largeur*longueur;
    }
    double perimetre() {
        return 2*(largeur+longueur);
    }
    void afficheInfo() {
        cout << "largeur : " << largeur << "    longueur : " << longueur << "\n";
    }
};


class Carre : public Objet{
private:
    double cote;
public:
    Carre(double _cote):cote(_cote){}
    double getCote(){return cote;}
    double aire() {
        return cote*cote;
    }
    double perimetre() {
        return 4*cote;
    }
    void afficheInfo() {
        cout << "cote : " << cote << "\n";
    }
};
