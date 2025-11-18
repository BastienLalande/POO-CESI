#include "Rectangle_Carre.cpp"
#include <list>

class GestionObjets {
private:
    list<Objet*> objets;
    int max_objets;

public:
    // Constructeur avec nombre d'objets maximal à gérer
    GestionObjets(int _nb_objets) : max_objets(_nb_objets) { }

    // Destructeur pour supprimer proprement les objets
    ~GestionObjets() {
        for (Objet* obj : objets) {
            delete obj;
        }
        objets.clear();
    }

    // Méthode pour ajouter un objet à la fin
    bool ajouterObjet(Objet* obj) {
        if ((int)objets.size() >= max_objets) {
            return false; // Impossible d'ajouter, collection pleine
        }
        objets.push_back(obj);
        return true;
    }

    // Méthode surchargée pour insérer un objet à une position spécifique (index à partir de 0)
    bool ajouterObjet(Objet* obj, int index) {
        if ((int)objets.size() >= max_objets || index < 0 || index > (int)objets.size()) {
            return false;
        }
        auto it = objets.begin();
        advance(it, index);
        objets.insert(it, obj);
        return true;
    }

    // Afficher les infos de tous les objets stockés
    void afficherInfos() {
        int i = 0;
        for (Objet* obj : objets) {
            cout << "Objet #" << i+1 << " : ";
            obj->afficheInfo();
            i++;
        }
    }

};


int main() {
    // Création d'un objet Rectangle et d'un objet Carre
    Rectangle rect(4.0, 6.0);
    Carre carre(5.0);
    Carre carre2(1);

    // Affichage des informations du rectangle
    cout << "Rectangle :" << endl;
    rect.afficheInfo();
    cout << "Aire : " << rect.aire() << endl;
    cout << "Perimetre : " << rect.perimetre() << endl << endl;

    // Affichage des informations du carré
    cout << "Carre :" << endl;
    carre.afficheInfo();
    cout << "Aire : " << carre.aire() << endl;
    cout << "Perimetre : " << carre.perimetre() << endl;

    GestionObjets gestionnaire(3);
    gestionnaire.ajouterObjet(&carre);
    gestionnaire.ajouterObjet(&rect, 1);
    gestionnaire.ajouterObjet(&carre2);

    gestionnaire.afficherInfos();

    return 0;
}
