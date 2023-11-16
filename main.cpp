#include <iostream>
#include <string>
#include <unistd.h>  

#include "./Entities/Entity.cpp"
#include "./Entities/Humans/Human.cpp"
#include "./Entities/Monsters/Ghoul.cpp"
#include "./Events/Battle.cpp"
#include "./Entities/Humans/Witcher.cpp"
#include "./Items/Item.cpp"
#include "./Items/Weapons/Sword.cpp"
#include "./Items/Armors/Armor.cpp"
#include "./Utils/Date.cpp"

#include "./Utils/load_save.h"


int main(void) {

    // criar batalha para testar os itens
    // criar mais itens
    cout << "=========Before battle==========\n";
    Witcher * w1 = new Witcher("Geralt");
    cout << *w1;

    cout << "===============================\n";

    Ghoul * g1 = new Ghoul("Ghoul 1");
    cout << *g1;

    cout << "===============================\n";
    cout << "=========During battle=========\n";
    w1->attack(*g1, STEEL_SWORD);
    cout << *g1;

    return 0;
}
