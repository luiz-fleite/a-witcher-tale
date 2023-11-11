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

    cout << "Witcher 1:\n";
    Witcher witcher1;
    witcher1.setName("Geralt");
    cout << witcher1 << '\n';
    witcher1.print_equipped_items();
    witcher1.print_inventory();
    cout << "============================\n";
    vector<Item *> floor_items;
    Sword * s1 = new Sword();
    Sword * s2 = new Sword("Silver Sword", "Good against monsters", 20);
    Sword * s3 = new Sword("Steel Sword", "Good against humans", 15);
    floor_items.push_back(s1);
    floor_items.push_back(s2);
    floor_items.push_back(s3);
    cout << "Floor items:\n";
    cout << floor_items.size() << '\n';
    cout << "============================\n";
    cout << "Witcher 1 grabs the swords:\n";
    witcher1.grab_item(floor_items, 1);
    witcher1.grab_item(floor_items, 0);
    witcher1.grab_item(floor_items, 0);
    witcher1.print_equipped_items();
    witcher1.print_inventory();
    cout << "Floor items:\n";
    cout << floor_items.size() << '\n';
    cout << "============================\n";
    cout << "Witcher 1 equips the sword:\n";
    witcher1.equip_item(SWORD, 0);
    witcher1.print_equipped_items();
    witcher1.print_inventory();
    cout << "============================\n";
    cout << "Witcher 1 unequips the sword:\n";
    witcher1.unequip_item(SWORD);
    witcher1.print_equipped_items();
    witcher1.print_inventory();
    cout << "============================\n";
    cout << "Witcher 1 equips the sword:\n";
    witcher1.equip_item(SWORD, 0);
    witcher1.print_equipped_items();
    witcher1.print_inventory();
    cout << "============================\n";
    cout << "Witcher 1 swaps equipped sword:\n";
    witcher1.equip_item(SWORD, 1);
    witcher1.print_equipped_items();
    witcher1.print_inventory();
    cout << "============================\n";

    return 0;
}
