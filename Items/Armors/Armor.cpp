#include <iostream>
#include <string>

#include "Armor.h"

using std::cout;

Armor::Armor() {
    //cout << "Creating a new Armor...\n";
    name = "Common Armor";
    description = "A common armor. Very used and not very protective.";
    physical_defense = 1;
    fire_defense = 0;
    poison_defense = 0;
    ice_defense = 0;
    silver_defense = 0;
}

Armor::Armor(string name, string description, 
                          int physical_defense, 
                          int fire_defense, 
                          int poison_defense, 
                          int ice_defense, 
                          int silver_defense) {
    setName(name);
    setDescription(description);
    setPhysical_defense(physical_defense);
    setFire_defense(fire_defense);
    setPoison_defense(poison_defense);
    setIce_defense(ice_defense);
    setSilver_defense(silver_defense);

}

// Item is abstract, so we can't use static_cast
Armor::Armor(const Armor &other_Armor) : Item(other_Armor) {
    this->physical_defense = other_Armor.physical_defense;
    this->fire_defense = other_Armor.fire_defense;
    this->poison_defense = other_Armor.poison_defense;
    this->ice_defense = other_Armor.ice_defense;
    this->silver_defense = other_Armor.silver_defense;

}

Armor::~Armor() {
    //cout << "Destroying Armor...\n";
}

map<string, int> Armor::use(int technique) {
    // cout << "Using Armor...\n";
    map<string, int> defenses;

    defenses["physical_defense"] = physical_defense;
    defenses["fire_defense"] = fire_defense;
    defenses["poison_defense"] = poison_defense;
    defenses["ice_defense"] = ice_defense;
    defenses["silver_defense"] = silver_defense;
    
    return defenses;
}

ostream &operator<< (ostream &out, const Armor &Armor){
    out << Armor.name << " (+" << Armor.physical_defense << " physical defense)\n";
    if (Armor.fire_defense > 0) out << " (+" << Armor.fire_defense << " fire defense)\n";
    if (Armor.poison_defense > 0) out << " (+" << Armor.poison_defense << " poison defense)\n";
    if (Armor.ice_defense > 0) out << " (+" << Armor.ice_defense << " ice defense)\n";
    if (Armor.silver_defense > 0) out << " (+" << Armor.silver_defense << " silver defense)\n";

    out << "\"" << Armor.description << "\"";
    return out;
}

const Armor &Armor::operator=(const Armor &other_Armor) {
    // forma não permitida pela classe abstrata Item
    //static_cast<Item &>(*this) = static_cast<const Item &>(other_Armor);
    Item::operator=(other_Armor);
    this->physical_defense = other_Armor.physical_defense;
    this->fire_defense = other_Armor.fire_defense;
    this->poison_defense = other_Armor.poison_defense;
    this->ice_defense = other_Armor.ice_defense;
    this->silver_defense = other_Armor.silver_defense;

    return *this;
}

int Armor::operator==(const Armor &other_Armor) const {
    // forma não permitida pela classe abstrata Item
    //static_cast<const Item &>(*this) == static_cast<const Item &>(other_Armor);
    Item::operator==(other_Armor);
    if (this->physical_defense != other_Armor.physical_defense) return 0;
    if (this->fire_defense != other_Armor.fire_defense) return 0;
    if (this->poison_defense != other_Armor.poison_defense) return 0;
    if (this->ice_defense != other_Armor.ice_defense) return 0;
    if (this->silver_defense != other_Armor.silver_defense) return 0;
    
    return 1;
}

int Armor::operator!=(const Armor &other_Armor) const {
    return !(*this == other_Armor);
}
