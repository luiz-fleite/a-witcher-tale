#include <iostream>
#include <string>

#include "Armor.h"

using std::cout;

Armor::Armor() {
    //cout << "Creating a new Armor...\n";
    name = "Common Armor";
    description = "A common armor. Very used and not very protective.";
    defense = 3;
}

Armor::Armor(string name, string description, int defense) {
    setName(name);
    setDescription(description);
    setDefense(defense);
}

Armor::Armor(const Armor &other_Armor) : Item(static_cast<Item>(other_Armor)) {
    this->defense = other_Armor.defense;
}

Armor::~Armor() {
    //cout << "Destroying Armor...\n";
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
    out << "\n\"" << Armor.description << "\"";
    return out;
}

const Armor &Armor::operator=(const Armor &other_Armor) {
    static_cast<Item &>(*this) = static_cast<const Item &>(other_Armor);
    this->defense = other_Armor.defense;
    return *this;
}

int Armor::operator==(const Armor &other_Armor) const {
    static_cast<const Item &>(*this) == static_cast<const Item &>(other_Armor);
    if (this->defense != other_Armor.defense) return 0;
    return 1;
}

int Armor::operator!=(const Armor &other_Armor) const {
    return !(*this == other_Armor);
}
