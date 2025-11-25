
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <sstream>
#include <cmath>

using namespace std;

namespace math {

    // ============================
    // Classe Monomial
    // ============================
    class Monomial {
    private:
        double coefficient;
        map<string, int> variables; // ex: x^2 y^3

    public:
        // Constructeur
        Monomial(double coeff = 0.0, const map<string,int>& vars = {})
            : coefficient(coeff), variables(vars) {}

        // Affichage
        string toString() const {
            ostringstream oss;
            oss << coefficient;
            for (map<string,int>::const_iterator it = variables.begin(); it != variables.end(); ++it) {
                oss << "*" << it->first;
                if (it->second > 1) oss << "^" << it->second;
            }
            return oss.str();
        }

        // evaluation pour des valeurs données
        double evaluate(const map<string,double>& values) const {
            double result = coefficient;
            for (map<string, int>::const_iterator it = variables.begin(); it != variables.end(); ++it) {
                const string& var = it->first;
                int power = it->second;
                map<string, double>::const_iterator vIt = values.find(var);
                if (vIt != values.end()) {
                    result *= pow(vIt->second, power);
                }
            }
            return result;
        }

        // Derivation par rapport a une variable
        Monomial derive(const string& var) const {
            auto it = variables.find(var);
            if (it == variables.end()) {
                return Monomial(0.0); // derivee nulle
            }
            double newCoeff = coefficient * it->second;
            auto newVars = variables;
            if (--newVars[var] == 0) {
                newVars.erase(var);
            }
            return Monomial(newCoeff, newVars);
        }
    };

    // ============================
    // Classe Polynomial
    // ============================
    class Polynomial {
    private:
        vector<Monomial> terms;

    public:
        Polynomial() = default;

        // Ajouter un monôme
        Polynomial addMonomial(const Monomial& m) const {
            Polynomial newPoly = *this;
            newPoly.terms.push_back(m);
            return newPoly;
        }

        // Deriver par rapport a une variable
        Polynomial derive(const string& var) const {
            Polynomial result;
            for (const auto& term : terms) {
                Monomial d = term.derive(var);
                if (d.evaluate({}) != 0.0) { // eviter les termes nuls
                    result = result.addMonomial(d);
                }
            }
            return result;
        }

        // Affichage
        string toString() const {
            if (terms.empty()) return "0";
            ostringstream oss;
            for (size_t i = 0; i < terms.size(); ++i) {
                if (i > 0) oss << " + ";
                oss << terms[i].toString();
            }
            return oss.str();
        }
    };

} // namespace math

// ============================
// Programme principal
// ============================
int main() {
    using namespace math;

    Monomial m1(3, {{"x",2}});
    Monomial m2(2, {{"x",1},{"y",1}});
    Polynomial P;
    P = P.addMonomial(m1).addMonomial(m2);

    cout << "Polynome : " << P.toString() << endl;

    auto dP = P.derive("x");
    cout << "Derivee par rapport a x : " << dP.toString() << endl;

    map<string,double> values = {{"x",2},{"y",3}};
    cout << "evaluation en x=2, y=3 : " << m2.evaluate(values) << endl;

    return 0;
}
