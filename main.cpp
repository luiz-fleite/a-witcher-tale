#include <iostream>
#include <string>
#include <unistd.h>  

#include "./Entities/Entity.cpp"
#include "./Entities/Human.cpp"
#include "./Entities/Monsters/Ghoul.cpp"
#include "./Events/Battle.cpp"
#include "./Entities/Witcher.cpp"
#include "./Items/Item.cpp"
#include "./Items/Sword.cpp"
#include "./Items/Armor.cpp"
#include "./Utils/Date.cpp"
#include "./Utils/load_save.h"

// carregamento de arquivo
using std::cerr;
using std::getline;
#include <fstream>
using std::fstream;
using std::ifstream;
#include <sstream>
using std::istringstream;

int main(void) {

    Witcher w1;
    w1.setName("Geralt");
    cout << "Witcher 1: \n" << w1 << "\n";

    Witcher w2;
    cout << "Witcher 2: \n" <<  w2 << "\n";

    vector<Item*> floor_items;

    Sword * s1 = new Sword();
    Sword * s2 = new Sword("Silver Sword", "Good against monsters", 20);
    Armor * a1 = new Armor();
    Armor * a2 = new Armor("Witcher Armor", "Good against monsters", 10);
    floor_items.push_back(s1);
    floor_items.push_back(s2);
    floor_items.push_back(a1);
    floor_items.push_back(a2);

    cout << "Floor items:\n";
    cout << floor_items.size() << "\n";

    for (int i = 0; i < 4; i++) {
        cout << "Grabbing item " << i << "\n";
        w1.grab_item(floor_items, 0);
    }

    cout << "Witcher 1:\n";
    cout << w1 << "\n";
    w1.print_inventory();
    cout << "Floor items:\n";
    cout << floor_items.size() << "\n";

    cout << "========================\n";
    Sword * s3 = new Sword("Aerondight", "levels up with owner", 100);
    w2.add_item(*s3);
    cout << "Witcher 2:\n";
    cout << w2 << "\n";
    w2.print_inventory();

    w2.drop_item(floor_items, SWORD, 0);
    cout << "Witcher 2 inventory:\n";
    w2.print_inventory();
    cout << "Floor items:\n";
    cout << floor_items.size() << "\n";
    cout << "Witcher 1 grabs the item:\n";
    w1.grab_item(floor_items, 0);
    cout << "Witcher 1 inventory:\n";
    w1.print_inventory();
    cout << "Floor items:\n";
    cout << floor_items.size() << "\n";
    cout << "Witcher 1 trows the item on trash\n";
    w1.remove_item(SWORD, 0);
    cout << "Witcher 1 inventory:\n";
    w1.print_inventory();

    cout << "========================\n";

/*
    w1.print_personal_chest();
    cout << "========================\n";
    cout << "Guardando no bau:\n";
    w1.store_item();
    w1.store_item();
    w1.store_item();
    w1.store_item();
    w1.print_inventory();
    w1.print_personal_chest();
*/

/*
    if (!save_witcher(w1, "./save-files/config-witcher/config_atributes.txt")) {
        cerr << "Error saving witcher.\n";
        return 1;
    }

    Witcher w2;
    if (!load_witcher(w2, "./save-files/config-witcher/config_atributes.txt")) {
        cerr << "Error loading witcher.\n";
        return 1;
    }
    cout << "Witcher 2:\n";
    cout << w2 << "\n";
    w2.print_inventory();
    cout << "========================\n";
*/
    return 0;
}
