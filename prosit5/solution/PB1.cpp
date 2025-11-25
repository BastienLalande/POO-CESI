
#include <vector>
#include <string>

using namespace std;

class Monome {
private:
    double coefficient;
    string variable;
public:
    Monome(double _coeff, string _var_name) : coefficient(_coeff), variable(_var_name) {}
};

class Polynome {
private:
    vector<Monome> monomes;
public:
    void addMonome(const Monome& m) {
        monomes.push_back(m);
    }
};

int main() {
    // Create a polynomial: P(x, y) = 2x + 3y
    Polynome p;

    // First monome: 2x
    Monome m1(2.0,"x");
    p.addMonome(m1);

    // Second monome: 3y^2
    Monome m2(3.0, "y");
    p.addMonome(m2);

    return 0;
}
