#include <iostream>
#include <list>
using namespace std;

class Piece {
private:
    int nb_windows;
    string couleur;
public:
    Piece(int _nb_w, string _couleur):nb_windows(_nb_w), couleur(_couleur){}
    ~Piece()=default;
    // Getters
    int getNbWindows() const {
        return nb_windows;
    }
    string getCouleur() const {
        return couleur;
    }

    // Setters
    void setNbWindows(int _nb_w) {
        nb_windows = _nb_w;
    }
    void setCouleur(const string& _couleur) {
        couleur = _couleur;
    }
};

class Salle_de_bain : public Piece{
private:
    bool has_Shower;
public:
    Salle_de_bain(int _nb_w, string _couleur, bool _has_shower)
        : Piece(_nb_w, _couleur), has_Shower(_has_shower) {}
    // Getter pour has_Shower
    bool getHasShower() const {
        return has_Shower;
    }

    // Setter pour has_Shower
    void setHasShower(bool _has_shower) {
        has_Shower = _has_shower;
    }
};

class Chambre : public Piece{
private:
    int nb_beds;
public:
    Chambre(int _nb_w, string _couleur, int _nb_beds)
        : Piece(_nb_w, _couleur), nb_beds(_nb_beds) {}
    // Getter pour nb_beds
    int getNbBeds() const {
        return nb_beds;
    }

    // Setter pour nb_beds
    void setNbBeds(int _nb_beds) {
        nb_beds = _nb_beds;
    }
};

class Maison {
private:
    list<Piece> pieces;
public:
    Maison(list<Piece> _pieces):pieces(_pieces){}
    ~Maison()=default;
    int getNbOfBathroom(){
        int count = 0;
        for (const Piece& p : pieces) {
            if (typeid(p) == typeid(Salle_de_bain)) {
                count++;
            }
        }
        return count;
    }
    int getNbOfBedroom (){
        int count = 0;
        for (const Piece& p : pieces) {
            if (typeid(p) == typeid(Chambre)) {
                count++;
            }
        }
        return count;
    }
};
























int main() {
    // Création des pièces
    Piece piece1(2, "bleu");
    Piece piece2(1, "vert");
    Chambre chambre(2, "rouge", 1); // 2 fenêtres, couleur rouge, 1 lit
    Salle_de_bain salle_de_bain1(2, "blanc",true);
    Salle_de_bain salle_de_bain2(1, "gris", false);

    // Création de la liste de pièces
    list<Piece> liste_pieces = {
        piece1,
        piece2,
        salle_de_bain1,
        salle_de_bain2,
        chambre};

    // Création de la maison avec ces pièces
    Maison maison(liste_pieces);
    // Compter le nombre de salles de bain (bathroom) et de chambres (bedroom)

    cout << "Nombre de chambres (bedrooms) : " << maison.getNbOfBedroom() << endl;
    cout << "Nombre de salles de bain (bathrooms) : " << maison.getNbOfBathroom() << endl;
}
