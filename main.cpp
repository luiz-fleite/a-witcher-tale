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

    Witcher * w1 = new Witcher("Max Neuralink");
    w1->receive_damage(13);
    w1->setStamina(27);
    cout << *w1 << "\n";

    if (!save_witcher(*w1))
        cerr << "Erro ao salvar o witcher!\n";
    
    delete w1;

    Witcher * w2 = new Witcher();
    if (!load_witcher(*w2))
        cerr << "Erro ao carregar o witcher!\n";
    
    cout << *w2 << "\n";


    return 0;
}
