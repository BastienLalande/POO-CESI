#include <string>
#include <vector>

using namespace std;

class Expression{
public:
    virtual ~Expression() = default;
    virtual Expression* derive() const = 0;
};

class Monome : public Expression {
private:
    double coefficient;
    string variable;
public:
    Monome(double _coeff, string _var_name) : coefficient(_coeff), variable(_var_name) {}
    ~Monome() override = default;
    Expression* derive() const override {
        if (variable.empty()) {
            return new Monome(0, "");
        } else {
            return new Monome(coefficient, "");
        }
    }
};

class Polynome : public Expression {
private:
    vector<Monome> monomes;
public:
    Polynome(vector<Monome> _monome):monomes(_monome){}
    ~Polynome() override = default;
    void addMonome(const Monome& m) {
        monomes.push_back(m);
    }
    Expression* derive() const override {
    vector<Monome> derivedMonomes;
    for (const auto& m : monomes) {
        Expression* d = m.derive();
        Monome* mono_ptr = dynamic_cast<Monome*>(d);
        if (mono_ptr != nullptr) {
            derivedMonomes.push_back(*mono_ptr);
            delete mono_ptr;
        } else if (d != nullptr) {
            delete d;
        }
    }
    return new Polynome(derivedMonomes);
    }
};


int main() {
    // Création de deux monômes : 2x et 3y
    Monome m1(2.0, "x");
    Monome m2(3.0, "y");

    Polynome p({m1, m2});

    // Ajout d'un autre monôme
    Monome m3(5.0, "z");
    p.addMonome(m3);

    return 0;
}
