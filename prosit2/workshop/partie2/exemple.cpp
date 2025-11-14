#include <iostream>
using namespace std;

class Creature {
public:
    Creature() {
        cout << "A creature has been created" << endl;
    } // Constructeur par défaut sans paramètre
    Creature(const Creature& c) {
        // Constructeur par copie
        cout << "A creature has been duplicated" << endl;
    }
    ~Creature() {
        // Destructeur
        cout << "A Creature has been destroyed" << endl;
    }
};

/* CODE 1
void foo(Creature c) {
    cout << "foo" << endl;
}

int main(int argc, char const* argv[])
{
    Creature ogre;
    Creature shrek = ogre;
    cout << "before foo" << endl;
    foo(shrek);
    cout << "after foo" << endl;
    return 0;
}*/


 /* CODE 2
void foo(Creature& c) {
    cout << "foo" << endl;
    Creature a = c;
}

int main(int argc, char const* argv[])
{
    Creature ogre;
    cout << "before foo" << endl;
    foo(ogre);
    cout << "after foo" << endl;
    return 0;
}*/

/* CODE 3
void bar(Creature* c) {
    cout << "bar" << endl;
    delete c;
}

int main(int argc, char const* argv[])
{
    Creature ogre;
    Creature* shrek = new Creature(ogre);
    cout << "before bar" << endl;
    bar(shrek);
    cout << "after bar" << endl;
    return 0;
}*/


/* CODE 4
Creature foo(Creature& c) {
    cout << "foo" << endl;
    Creature local = c;
    return c;
}


int main(int argc, char const* argv[])
{
    Creature ogre;
    cout << "before foo" << endl;
    Creature shrek = foo(ogre);
    cout << "after foo" << endl;
    return 0;
}
*/
