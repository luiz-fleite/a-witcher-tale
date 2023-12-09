#include <iostream>
#include <string>
#include <unistd.h>  

#include "./Entities/Entity.cpp"

#include "./Entities/Humans/Human.cpp"
#include "./Entities/Humans/Witcher.cpp"

#include "./Entities/Monsters/Ghoul.cpp"

#include "./Events/Battle.cpp"

#include "./Items/Item.cpp"
#include "./Items/Weapons/Weapon.cpp"
#include "./Items/Weapons/Sword.cpp"
#include "./Items/Armors/Armor.cpp"

#include "./Spells/Spell.cpp"
#include "./Spells/Signs/Sign.cpp"
#include "./Spells/Signs/Igni.cpp"

#include "./Utils/Date.cpp"

#include "./Utils/load_save.h"


int main(void) {


    cout << "=========Before battle==========\n";
    Witcher * w1 = new Witcher("Geralt");
    cout << *w1;

    cout << "===============================\n";

    Ghoul * g1 = new Ghoul("Ghoul 1");
    Sword * s1 = new Sword("Sharpened sword", "Well sharpened steel sword", 10, 10, 10);
    Armor * a1 = new Armor("Steel armor", "Well crafted steel armor", 10, 10, 10);
    g1->add_item(*s1);
    g1->add_item(*a1);
    cout << *g1;

    cout << "===============================\n";
    vector <Item *> floor_items;
    cout << "Floor items: " << floor_items.size() << "\n";

    cout << "===============================\n";
    cout << "=========During battle=========\n";
    Battle * b1 = new Battle(*w1, *g1);
    b1->begin();
    b1->get_floor_items(floor_items);
    cout << "===============================\n";
    cout << "=========After battle==========\n";
    cout << *w1 << *g1;

    cout << "===============================\n";

    cout << "Floor items: " << floor_items.size() << "\n";


    return 0;
}
