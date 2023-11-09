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

map<string, string> buffer_atributes;

int main(void) {

    Witcher w1;
    if (!load_witcher(w1, "./save-files/config_witcher.txt")) {
        cerr << "Error loading witcher.\n";
        return 1;
    }

    cout << w1 << "\n";
    w1.print_inventory();
    cout << "========================\n";

/*
    Witcher w2;
    Sword s1;
    Sword s2("Silver Sword", "Good against monsters", 20);
    Armor a1;
    Armor a2("Witcher Armor", "Good against monsters", 10);
    w2.add_item(s1);
    w2.add_item(s2);
    w2.add_item(a1);
    w2.add_item(a2);
    cout << "Witcher 2:\n";
    cout << w2 << "\n";
    w2.print_inventory();
    cout << "========================\n";

    if (!save_witcher(w2, buffer_atributes, "./save-files/config_witcher1.txt")) {
        cerr << "Error saving witcher.\n";
        return 1;
    }

    if (!load_witcher(buffer_atributes, "./save-files/config_witcher1.txt")) {
        cerr << "Error loading witcher.\n";
        return 1;
    }

    Witcher w3(buffer_atributes["name"], 
        stoi(buffer_atributes["age"]), 
        stod(buffer_atributes["coins"]), 
        stoi(buffer_atributes["max_health"]), 
        stoi(buffer_atributes["max_stamina"]), 
        buffer_atributes["category"]);
    w3.setHealth(stoi(buffer_atributes["health"]));
    w3.setStamina(stoi(buffer_atributes["stamina"]));

    w3.load_inventory("./save-files/config_witcher_swords1", "./save-files/config_witcher_armors1");
    cout << "Witcher 3:\n";
    cout << w3 << "\n";
    w3.print_inventory();

*/

    return 0;
}
