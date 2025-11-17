#ifndef FORME_H
#define FORME_H

#include <cmath>
#include <vector>
#include <stdexcept>
# define M_PI 3.14159265358979323846 /* pi */

using namespace std;

class Point {
public:
    vector<double> pos;
    Point(const vector<double>& _pos) : pos(_pos) {
        if (pos.size() < 2) pos.resize(2);
    }
    ~Point() = default;
};

class Forme {
public:
    virtual ~Forme() = default;
    virtual double aire() const = 0;
    virtual double perimetre() const = 0;
};

class Polygone : public Forme {
// pour les segments tous les sommets adjacents sont relier entre eux ex:(p1--p2--p3 et p3--p1)
protected:
    vector<Point> sommets;
public:
    Polygone(const vector<Point>& _pts): sommets(_pts) {
        if (sommets.size() < 3) throw invalid_argument("Un polygone requiert au moins 3 sommets");
    }
    const vector<Point>& getSommets() const { return sommets; }

    double perimetre() const override {
        double perim = 0.0;
        for (size_t i = 0; i < sommets.size(); ++i) {
            size_t next = (i + 1) % sommets.size();
            double dx = sommets[i].pos[0] - sommets[next].pos[0];
            double dy = sommets[i].pos[1] - sommets[next].pos[1];
            perim += std::sqrt(dx*dx + dy*dy);
        }
        return perim;
    }
};

class Triangle : public Polygone {
public:
    Triangle(const Point& p1, const Point& p2, const Point& p3)
        : Polygone(vector<Point>{p1, p2, p3}) {}

    double aire() const override {
        double x1 = sommets[0].pos[0], y1 = sommets[0].pos[1];
        double x2 = sommets[1].pos[0], y2 = sommets[1].pos[1];
        double x3 = sommets[2].pos[0], y3 = sommets[2].pos[1];
        return 0.5 * std::fabs(x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2));
    }
};

class Rectangle : public Polygone {
public:
    Rectangle(const Point& p1, const Point& p3)
        : Polygone(vector<Point>{
            p1,
            Point({p3.pos[0], p1.pos[1]}),
            p3,
            Point({p1.pos[0], p3.pos[1]})
        }) {}
    double aire() const override {
        double largeur = std::fabs(sommets[1].pos[0] - sommets[0].pos[0]);
        double hauteur = std::fabs(sommets[3].pos[1] - sommets[0].pos[1]);
        return largeur * hauteur;
    }
};


class Carre : public Rectangle {
public:
    Carre(const Point& p1, double cote)
        : Rectangle(p1, Point({p1.pos[0] + cote, p1.pos[1] + cote})) {}
};

class Cercle : public Forme {
protected:
    Point centre;
    double rayon;
public:
    Cercle(const Point& c, double r) : centre(c), rayon(r) {}
    double perimetre() const override {return 2 * M_PI * rayon;}
    double aire() const override {return M_PI * rayon * rayon;}
};

#endif // FORME_H
