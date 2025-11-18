#include <iostream>
using namespace std;

class Vehicule{
private:
    int max_speed;
    int mileage;
public:
    Vehicule(){max_speed=240;mileage=0;}
    bool setmax_speed (int _max_speed){
        if (_max_speed>=200){
            max_speed=_max_speed;
            return true;
        }
        max_speed=240;
        return false;
    }
    int getmax_speed() {return max_speed;}
    bool setmileage(int _mileage){
        if (_mileage>=0){
            mileage=_mileage;
            return true;
        }
        mileage=0;
        return false;
    }
    int getmileage(){return mileage;}
};


class Bus : public Vehicule {
private:
    int seat_capacity;
public:
    Bus(){seat_capacity=10;}
    bool setseating_capacity(int _seat_capacity){
        if (_seat_capacity>=10 && _seat_capacity<=50){
            seat_capacity=_seat_capacity;
            return true;
        }
        seat_capacity=50;
        return false;
    }
    int getseating_capacity(){return seat_capacity;}
    void get_info(){
        cout <<"Il s'agit d'un bus d'une capacité de "<<getseating_capacity()
        <<" places, avec une vitesse maximale de "<<getmax_speed()
        <<" kmh et son kilométrage est de "<<getmileage()<<"km.\n";
    }
};

class SchoolBus : public Bus {
private:
    string school_name;
public:
    // Constructeur
    SchoolBus(string sn) {
        school_name = sn;
    }

    // Getter pour school_name
    string getSchoolName() {
        return school_name;
    }

    // Setter pour school_name
    void setSchoolName(string sn) {
        school_name = sn;
    }
};

// Fonction pour compter les SchoolBus
static int countbigbus(SchoolBus t[], int _size) {
    int count = 0;
    // Supposons que le tableau se termine à l'école_name vide
    for (int i = 0; i<_size; i++) {
        if (t[i].getseating_capacity()>=40 && t[i].getmileage()<200000) {
            count++;
        }
    }
    return count;
}























int main() {
    // Création de quelques SchoolBus pour test
    SchoolBus tab[4] = {
        SchoolBus("EcoleA"),
        SchoolBus("EcoleB"),
        SchoolBus("EcoleC"),
        SchoolBus("EcoleD")
    };

    // Initialisation des propriétés
    tab[0].setseating_capacity(42);
    tab[0].setmileage(180000);

    tab[1].setseating_capacity(30);
    tab[1].setmileage(100000);

    tab[2].setseating_capacity(45);
    tab[2].setmileage(250000);

    tab[3].setseating_capacity(50);
    tab[3].setmileage(150000);

    // tab[4] is the sentinel (school_name == "")

    int nb = countbigbus(tab, sizeof(tab)/sizeof(tab[0]));

    std::cout << "Number of big school buses: " << nb << std::endl;
}
