#include <iostream>
#include <string>
#include <unistd.h>  

#include "Human.h"
#include "Human.cpp"
#include "Ghoul.h"
#include "Ghoul.cpp"
#include "Battle.h"
#include "Battle.cpp"

using std::cout;

int main(void) {

    cout << "====Before battle:====\n";
    // antes da batalha um aldeão e um ghoul são criados

    Human h1;
    h1.print_info();

    cout << "\n";

    Ghoul g1;
    g1.print_info();

    cout << "\n";

    cout << "====During battle:====\n";
    // durante a batalha o primeiro aldeão é atacado pelo
    // primeiro ghoul ate q ele morra ou o ghoul canse

    Battle b1(h1, g1);
    b1.getVictims();
    cout << "\n";
    b1.getAttackers();
    
    cout << "\n";
    cout << "====After battle:====\n";

    h1.print_info();

    cout << "\n";

    g1.print_info();

    cout << "\n";

    return 0;
}
