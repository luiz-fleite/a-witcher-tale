#include <iostream>
#include <string>

#include "Sword.h"

using std::cout;

Sword::Sword() {
    //cout << "Creating a new Sword...\n";
    name = "Common Sword";
    damage = 10;
}

Sword::Sword(string name, int damage) {
    setName(name);
    setDamage(damage);
}

Sword::Sword(const Sword &other_sword) {
    this->name = other_sword.name;
    this->damage = other_sword.damage;
}

Sword::~Sword() {
    //cout << "Destroying Sword...\n";
}

void Sword::setName(string name) {
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

void Sword::setDamage(int damage) {
    if (damage < 0) {
        cout << "Damage cannot be negative.\n";
        this->damage = 0;
        return;
    }
    this->damage = damage;
}

ostream &operator<< (ostream &out, const Sword &sword){
    out << sword.name << " (+" << sword.damage << " damage)";
    return out;
}
