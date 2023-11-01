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

// carregamento de arquivo
using std::cerr;
using std::getline;
#include <fstream>
using std::fstream;
using std::ifstream;
#include <sstream>
using std::istringstream;

int main(void) {

    // O jogador começa em sua casa, em Kaer Morhen
    // E tem acesso ao seu baú pessoal de espadas
    Witcher w1 = Witcher("Geralt");
    cout << w1;
    Sword s1;
    Sword s2 = Sword("Silver Sword", "Good against monsters", 10);
    Armor a1 = Armor();
    w1.add_item(s1);
    w1.add_item(s2);
    w1.add_item(a1);
    w1.print_inventory();
    w1.equip_sword(0);
    w1.equip_armor(0);
    w1.print_equipped_items();
    cout << "\n";


/*
    ifstream inputFile("./Items/swords_chest.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening file." << '\n';
        return 1; // Exit with an error code
    }

    string line;    
    string variableName;
    char equalsSign;
    double value;
    while (getline(inputFile, line)) 
    {
        istringstream iss(line);
        if (iss >> variableName >> equalsSign >> value && equalsSign == '=') {
            Sword * loaded_sword = new Sword(variableName, value);
            w1.store_sword(*loaded_sword);
            delete loaded_sword;
        }
        else {
            cerr << "Error parsing line: " << line << '\n';
        }
    }

    inputFile.close();

    w1.print_chest_swords();
*/

    

    return 0;
}
