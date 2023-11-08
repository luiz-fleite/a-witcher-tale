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

    if (!load_witcher(buffer_atributes, "./Utils/config_witcher.txt")) {
        cerr << "Error loading witcher.\n";
        return 1;
    }

    Witcher w1(buffer_atributes["name"], 
        stoi(buffer_atributes["age"]), 
        stod(buffer_atributes["coins"]), 
        stoi(buffer_atributes["max_health"]), 
        stoi(buffer_atributes["max_stamina"]), 
        buffer_atributes["category"]);
    w1.setHealth(stoi(buffer_atributes["health"]));
    w1.setStamina(stoi(buffer_atributes["stamina"]));

    cout << w1 << "\n";

    Witcher w2;
    cout << "Witcher 2:\n";
    cout << w2 << "\n";

    if (!save_witcher(w2, buffer_atributes, "./Utils/config_witcher1.txt")) {
        cerr << "Error saving witcher.\n";
        return 1;
    }

    if (!load_witcher(buffer_atributes, "./Utils/config_witcher1.txt")) {
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
    cout << "Witcher 3:\n";
    cout << w3 << "\n";

/*
    Witcher w1 = Witcher("Geralt");
    cout << w1;
    
    cout << "\n";
*/  

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
            Sword * loaded_sword = new Sword(variableName, "Sword", value);
            w1.store_item(*loaded_sword);
            delete loaded_sword;
        }
        else {
            cerr << "Error parsing line: " << line << '\n';
        }
    }

    inputFile.close();

    w1.print_personal_chest();
*/
    

    return 0;
}
