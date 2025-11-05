#include <iostream>
#include <string>

class hero{
    private:
        std::string nom;
        int pv;
        int pa;
    public:
        hero();
        hero(std::string _nom, int _pv, int _pa){
            this->nom = _nom;
            this->pv = _pv;
            this->pa = _pa;
        }
        int attaque(){return this->pa;}
        void subitDegat(int _degat){this->pv-=_degat;if(this->pv<0)this->pv=0;}
        bool estVivant(){if (this->pv>0) return 1; else return 0;}
        void affiche(){
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
            )" << std::endl;
        }
};

class creature {
    private:
        int pv;
        int pa;
        int nv;
    public:
        creature();
        creature(int _pv, int _pa, int _niveau){
            this->nv = _niveau;
            this->pv = _pv;
            this->pa = _pa;
        }
        int attaque(){return this->pa;}
        void subitDegat(int _degat){this->pv-=_degat;if(this->pv<0)this->pv=0;}
        bool estVivant(){if (this->pv>0) return 1; else return 0;}
        void affiche(){
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
            )" << std::endl;
        }
};



int main(){
    std::cout << "---" << std::endl;
    hero h{"Hrun",10,8};
    creature c{10,10,1};
    h.affiche();
    c.affiche();

    c.subitDegat(h.attaque());
    h.subitDegat(c.attaque());

    h.affiche();
    c.affiche();
    std::cout << "---" << std::endl;
    return 0;
}