#include <iostream>
#include <string>
#include <unistd.h>  

#include "Entity.h"
#include "Entity.cpp"
#include "Human.h"
#include "Human.cpp"
#include "Ghoul.h"
#include "Ghoul.cpp"
#include "Battle.h"
#include "Battle.cpp"

using std::cout;

int main(void) {

    cout << "====First Battle:====\n";
    // durante a batalha o primeiro aldeão é atacado pelo
    // primeiro ghoul ate q ele morra

    Human h1;
    h1.print_info();

    cout << "\n";

    Ghoul g1;
    g1.print_info();

    cout << "\n";

    Human h2 = Human(h1);
    h2.print_info();

    cout << "\n";

    Ghoul g2 = Ghoul(g1);
    g2.print_info();

    cout << "\n";

    h1.attack(g1);
    g1.attack(h1);
    g2.attack(g1);
    h1.print_info();
    h2.print_info();
    g1.print_info();
    g2.print_info();

/*
    Battle b1(h1, g1);
    b1.print_allies();
    b1.print_enemies();
    b1.beginBattle();

    cout << "\n";
    cout << "====After first battle:====\n";

    cout << "\n";

    h1.print_info();

    cout << "\n";

    g1.print_info();
*/
    return 0;
}
