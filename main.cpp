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

// carregamento de arquivo
using std::cerr;
using std::getline;
#include <fstream>
using std::fstream;
using std::ifstream;
#include <sstream>
using std::istringstream;

int main(void) {

    Witcher * w1 = new Witcher("Geralt");
    cout << *w1;

    if (!save_witcher(*w1)) {
        cerr << "Error saving witcher.\n";
        return 1;
    }

    Witcher * w2 = new Witcher();

    if (!load_witcher(*w2)) {
        cerr << "Error loading witcher.\n";
        return 1;
    }
    
    cout << "==========After loading:==========\n";
    cout << *w2;

    return 0;
}
