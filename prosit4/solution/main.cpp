#include <iostream>
#include <cmath>
using namespace std;

class CLpoint {
private:
    double x;
    double y;
public:
    CLpoint(double _x, double _y) : x(_x), y(_y) {}
    double getX() const { return x; }
    double getY() const { return y; }
    void setX(double _x) { x = _x; }
    void setY(double _y) { y = _y; }
    virtual void afficherCoordo(){
    cout << x << " " << y << endl;
    }
};

class CLpoint3D : public CLpoint {
private:
    double z;
public:
    CLpoint3D(double _x, double _y, double _z)
    : CLpoint(_x, _y), z(_z) {}
    double getZ() const { return z; }
    void setZ(double _z) { z = _z; }
    void afficherCoordo() override {
        cout << getX() << " " << getY() << " " << z << endl;
    }
};

class CLParcours {
protected:
    CLpoint** points;
    int nb_points;
    int index;
public:
    CLParcours(int _nb_points):nb_points(_nb_points),index(0){
        points = new CLpoint*[_nb_points];
    }
    ~CLParcours(){delete [] points;}
    void ajouterPoint(CLpoint* _p){
        if(index < nb_points) {
            points[index++] = _p;
        }
    }
    virtual double calculDistance()=0;
    void message(){
        cout<<calculDistance()<<'\n';
    }
};

class CLparcours2D: public CLParcours{
public:
    CLparcours2D(int _nb_points):CLParcours(_nb_points){}
    double calculDistance() override {
    double dist = 0.0;
    for (int i = 0; i < index - 1; ++i) {
        CLpoint* p1 = points[i];
        CLpoint* p2 = points[i+1];
        double dx = p2->getX() - p1->getX();
        double dy = p2->getY() - p1->getY();
        dist += sqrt(dx*dx + dy*dy);
    }
    return dist;
    }
};

class CLparcours3D: public CLParcours{
    public:
        CLparcours3D(int _nb_points):CLParcours(_nb_points){}
        double calculDistance() override {
        double dist = 0.0;
        for (int i = 0; i < index - 1; ++i) {
            CLpoint3D* p1 = static_cast<CLpoint3D*>(points[i]);
            CLpoint3D* p2 = static_cast<CLpoint3D*>(points[i+1]);
            double dx = p2->getX() - p1->getX();
            double dy = p2->getY() - p1->getY();
            double dz = p2->getZ() - p1->getZ();
            dist += sqrt(dx*dx + dy*dy + dz*dz);
        }
        return dist;
        }
    };

int main()
{
	int pause;
	CLpoint* p1;
	CLpoint* p2;
	CLpoint* p3;
	CLParcours* parcours;
	p1 = new CLpoint(0.0, 0.0);
	p2 = new CLpoint(1.0, 1.0);
	p3 = new CLpoint(2.0, 2.0);
	parcours = new CLparcours2D(3);
	parcours->ajouterPoint(p1);
	parcours->ajouterPoint(p2);
	parcours->ajouterPoint(p3);
	cout << parcours->calculDistance() << endl;
	parcours->message();
	p1 = new CLpoint3D(0.0, 0.0, 0.0);
	p2 = new CLpoint3D(1.0, 1.0, 1.0);
	p3 = new CLpoint3D(2.0, 2.0, 2.2);
	parcours = new CLparcours3D(3);
	parcours->ajouterPoint(p1);
	parcours->ajouterPoint(p2);
	parcours->ajouterPoint(p3);
	cout << parcours->calculDistance() << endl;
	parcours->message();
	p1 = new CLpoint(0.0, 0.0);
	p2 = new CLpoint3D(1.0, 1.0, 1.0);
	(p1 = p2)->afficherCoordo();
	cin >> pause;

    return 0;
}
