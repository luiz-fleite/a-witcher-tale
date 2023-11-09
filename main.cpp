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
    Sword s1;
    Sword s2("Silver Sword", "Good against monsters", 20);
    Armor a1;
    Armor a2("Witcher Armor", "Good against monsters", 10);
    w1.add_item(s1);
    w1.add_item(s2);
    w1.add_item(a1);
    w1.add_item(a2);
    cout << "Witcher 2:\n";
    cout << w1 << "\n";
    w1.print_inventory();
    cout << "========================\n";

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

    return 0;
}
