#include <iostream>
#include "forme.h"
using namespace std;

int main() {
    Point p1({0,0});
    Point p2({1,0});
    Point p3({0,1});

    Triangle t(p1, p2, p3);

    cout << "Aire du triangle : " << t.aire() << endl;
    cout << "Perimetre du triangle : " << t.perimetre() << endl;

    // Test Rectangle
    Point r1({0, 0});
    Point r3({3, 2});
    Rectangle rect(r1, r3);
    cout << "Aire du rectangle : " << rect.aire() << endl;
    cout << "Perimetre du rectangle : " << rect.perimetre() << endl;

    // Test Carre
    Point c1({1, 1});
    double cote = 4.0;
    Carre carre(c1, cote);
    cout << "Aire du carre : " << carre.aire() << endl;
    cout << "Perimetre du carre : " << carre.perimetre() << endl;

    // Test Cercle
    Point centre({2, 2});
    double rayon = 1.5;
    Cercle cercle(centre, rayon);
    cout << "Aire du cercle : " << cercle.aire() << endl;
    cout << "Perimetre du cercle : " << cercle.perimetre() << endl;

    return 0;
}
