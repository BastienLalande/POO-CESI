#include <iostream>
#include <string>

class hero{
    private:
        std::string nom;
        int pv;
        int pa;
    public:
        hero();
        hero(std::string _nom, int _pv, int _pa) : nom(std::move(_nom)), pv(_pv), pa(_pa){}
        int attaque() const{return this->pa;}
        void subitDegat(int _degat){this->pv -= _degat; this->pv = std::max(0, this->pv);}
        bool estVivant() const{return this->pv>0;}
        void affiche() const{
            std::cout << R"(
  ,^.
  |||
  |||       _T_          PV:)"<< this->pv << R"(
  |||   .-.[:|:].-.
  ===_ /\|  "'"  |/
   E]_|\/ \--|-|''''|
   O  `'  '=[:]| A  |
          /""""|  P |
         /"""""`.__.'
        []"/"""\"[]
        | \     / |
        | |     | |
      <\\\)     (///>
            )" << '\n';
        }
};

class creature {
    private:
        int pv;
        int pa;
        int nv;
    public:
        creature();
        creature(int _pv, int _pa, int _niveau) : pv(_pv), pa(_pa), nv(_niveau){}
        int attaque() const {return this->pa*this->nv;}
        void subitDegat(int _degat){this->pv-=_degat;this->pv = std::max(this->pv, 0);}
        bool estVivant() const {return this->pv>0;}
        void affiche() const {
            std::cout << R"(
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
                                                      ``--------..._``--.__
            )" << '\n';
        }
};



int main(){
    std::string input;

    hero player{"Bastoche",100, 8};

    creature enemy{50,8,1};

    player.affiche();
    enemy.affiche();

    while (true) {
        std::cout << R"(
Que voulez vous faire ? :
1: attaquer     2: ne rien faire
-------------------------------------------------------
        )";
        std::cout << "'q' to quit ===>";
        std::getline(std::cin, input);
        if (input == "q") {
            break;
        }

        if (input == "1") {
            enemy.subitDegat(player.attaque());
        }
    }
    return 0;
}
