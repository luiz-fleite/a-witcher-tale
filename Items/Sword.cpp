#include <iostream>
#include <string>

#include "Sword.h"

using std::cout;

Sword::Sword() {
    //cout << "Creating a new Sword...\n";
    name = "Common Sword";
    description = "A common sword. Very Used by the common folk.";
    damage = 10;
}

Sword::Sword(string name, string description, int damage) {
    setName(name);
    setDescription(description);
    setDamage(damage);
}

Sword::Sword(const Sword &other_sword) : Item(static_cast<Item>(other_sword)){
    this->damage = other_sword.damage;
}

Sword::~Sword() {
    //cout << "Destroying Sword...\n";
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
    out << "\n\"" << sword.description << "\"";
    return out;
}

const Sword &Sword::operator=(const Sword &other_sword) {
    static_cast<Item>(*this) = static_cast<Item>(other_sword);
    this->damage = other_sword.damage;
    return *this;
}

int Sword::operator==(const Sword &other_sword) const {
    static_cast<Item>(*this) == static_cast<Item>(other_sword);
    if (this->damage != other_sword.damage) return 0;
    return 1;
}

int Sword::operator!=(const Sword &other_sword) const {
    return !(*this == other_sword);
}
