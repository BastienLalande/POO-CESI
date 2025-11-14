#include <iostream>

using namespace std;

class Creature {
    private:
        int pv;
        int pa;
        int nv;
    public:
        static int cpt;
        Creature(){cpt++;}
        Creature(int _pv, int _pa, int _niveau) : pv(_pv), pa(_pa), nv(_niveau){cpt++;}
        Creature(const Creature& c){cpt++;}
        ~Creature(){cpt--;cout<<"creature destroy\n";}
        int attaque() const {return this->pa*this->nv;}
        void subitDegat(int _degat){this->pv-=_degat;this->pv = std::max(this->pv, 0);}
        bool estVivant() const {return this->pv>0;}
        void affiche() const {cout << R"(
                                                       ____________
                                 (`-..________....---''  ____..._.-`
                                  \\`._______.._,.---'''     ,'
                                  ; )`.      __..-'`-.      /   PV:)"<< this->pv << R"(
                                 / /     _.-' _,.;;._ `-._,'
                                / /   ,-' _.-'  //   ``--._``._
                              ,','_.-' ,-' _.- (( =-    -. `-._`-._____
                            ,;.''__..-'   _..--.\\.--'````--.._``-.`-._`.
             _          |\,' .-''        ```-'`---'`-...__,._  ``-.`-.`-.`.
  _     _.-,'(__)\__)\-'' `     ___  .          `     \      `--._
,',)---' /|)          `     `      ``-.   `     /     /     `     `-.
\_____--.  '`  `               __..-.  \     . (   < _...-----..._   `.
 \_,--..__. \\ .-`.\----'';``,..-.__ \  \      ,`_. `.,-'`--'`---''`.  )
           `.\`.\  `_.-..' ,'   _,-..'  /..,-''(, ,' ; ( _______`___..'__
                   ((,(,__(    ((,(,__,'  ``'-- `'`.(\  `.,..______
                                                      ``--------..._``--.__)" << '\n';}
};
int Creature::cpt=0;

void foo() {
    Creature c3;
    cout << "Nombre de creatures: " << Creature::cpt << endl;
}

void test1() {
    cout << "Test 1: \n";
    Creature c1;
    Creature c2(10, 2, 2);
    cout << "Nombre de creatures: " << Creature::cpt << endl;
    foo();
    cout << "Nombre de creatures: " << Creature::cpt << endl;
}

void bar(Creature c1) {
    Creature c2;
    cout << "Nombre de creatures: " << Creature::cpt << endl;
}

void test2() {
    cout << "Test 2: \n";
    Creature c1;
    Creature c2(10, 2, 2);
    cout << "Nombre de creatures: " << Creature::cpt << endl;
    bar(c2);
    cout << "Nombre de creatures: " << Creature::cpt << endl;
}
int main() {
    test1();
    test2();
}
