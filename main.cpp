#include <iostream>
#include <string>
#include <unistd.h>  

#include "./Entities/Entity.cpp"
#include "./Entities/Human.cpp"
#include "./Entities/Monsters/Ghoul.cpp"
#include "./Events/Battle.cpp"
#include "./Entities/Witcher.cpp"
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
    Sword * s2 = new Sword("Silver Sword", 10);
    w1.add_sword(*s2);
    w1.equip_sword(0);
    w1.print_equipped_items();

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

    // Ele sai de sua casa e entra em uma caverna
    // misteriosa onde tem um ghoul
    vector <Sword*> cave_floor_swords;
    Ghoul *g1 = new Ghoul();
    cout << *g1 << "\n";
    Sword * s1 = new Sword("Ancient Sword", 20);
    g1->add_sword(*s1);
    g1->print_inventory();

    // O jogador entra em batalha com o ghoul
    w1.attack(*g1);
    //sleep(1);
    g1->attack(w1);
    //sleep(1);

    // se o ghoul morre ele dropa a espada no chão
    // e é deletado para liberar memória
    cout << "dropa espada\n";
    g1->drop_sword(0, cave_floor_swords);
    cout << "deleta ghoul\n";
    delete g1;
    cout << "ghoul deletado\n";

    // o jogador pega a espada do chão
    cout << "endereço da espada: " << cave_floor_swords[0] << "\n";
    cout << "espada: " << *cave_floor_swords[0] << "\n";
    cout << "pega espada\n";
    w1.add_sword(*cave_floor_swords[0]);
    cout << "espada pega\n";
    cout << w1 << "\n";
    w1.print_inventory();

    // Testes de operadores
    Witcher w2 = Witcher("Vesemir");
    cout << "Testes de operadores\n";
    cout << "Witcher1 == Witcher1: " << (w1 == w1) << "\n";
    cout << "Witcher1 != Witcher1: " << (w1 != w1) << "\n";
    cout << "Witcher1 == Witcher2: " << (w1 == w2) << "\n";
    cout << "Witcher1 != Witcher2: " << (w1 != w2) << "\n";
    cout << "Witcher1 = Witcher2\n";
    w1 = w2;
    cout << "Witcher1 == Witcher2: " << (w1 == w2) << "\n";

    return 0;
}
