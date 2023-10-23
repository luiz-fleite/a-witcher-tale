#include <iostream>
#include <string>

#include "Armor.h"

using std::cout;

Armor::Armor() {
    //cout << "Creating a new Armor...\n";
    name = "Common Armor";
    defense = 3;
}

Armor::Armor(string name, int defense) {
    setName(name);
    setDefense(defense);
}

Armor::Armor(const Armor &other_Armor) {
    this->name = other_Armor.name;
    this->defense = other_Armor.defense;
}

Armor::~Armor() {
    //cout << "Destroying Armor...\n";
}

void Armor::setName(string name) {
    name.erase(0, name.find_first_not_of(' '));
    name.erase(name.find_last_not_of(' ') + 1);
    if (name == "") {
        cout << "Name cannot be empty.\n";
        this->name = "Empty_Name";
        return;
    }
    if (name.length() > MAX_NAME_SIZE) {
        cout << "Max name size is " << MAX_NAME_SIZE << " characters. Name shortened.\n";
        this->name = name.substr(0, MAX_NAME_SIZE);
        return;
    }
    this->name = name;
}

void Armor::setDefense(int defense) {
    if (defense < 0) {
        cout << "defense cannot be negative.\n";
        this->defense = 0;
        return;
    }
    this->defense = defense;
}

ostream &operator<< (ostream &out, const Armor &Armor){
    out << Armor.name << " (+" << Armor.defense << " defense)";
    return out;
}
