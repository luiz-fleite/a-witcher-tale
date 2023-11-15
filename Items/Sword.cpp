#include <iostream>
#include <string>

#include "Sword.h"

using std::cout;

Sword::Sword() {
    //cout << "Creating a new Sword...\n";
    name = "Common Sword";
    description = "A common sword. Very Used by the common folk.";
    physical_damage = 2;
    fire_damage = 0;
    poison_damage = 0;
    ice_damage = 0;
    silver_damage = 0;

}

Sword::Sword(string name, string description, 
                          int physical_damage, 
                          int fire_damage, 
                          int poison_damage, 
                          int ice_damage, 
                          int silver_damage) {
    setName(name);
    setDescription(description);
    setPhysical_damage(physical_damage);
    setFire_damage(fire_damage);
    setPoison_damage(poison_damage);
    setIce_damage(ice_damage);
    setSilver_damage(silver_damage);

}

Sword::Sword(const Sword &other_sword) : Item(static_cast<Item>(other_sword)){
    this->physical_damage = other_sword.physical_damage;
    this->fire_damage = other_sword.fire_damage;
    this->poison_damage = other_sword.poison_damage;
    this->ice_damage = other_sword.ice_damage;
    this->silver_damage = other_sword.silver_damage;

}

Sword::~Sword() {
    //cout << "Destroying Sword...\n";
}

ostream &operator<< (ostream &out, const Sword &sword){
    out << sword.name << " (+" << sword.physical_damage << " physical damage)\n";
    if (sword.fire_damage > 0) out << " (+" << sword.fire_damage << " fire damage)\n";
    if (sword.poison_damage > 0) out << " (+" << sword.poison_damage << " poison damage)\n";
    if (sword.ice_damage > 0) out << " (+" << sword.ice_damage << " ice damage)\n";
    if (sword.silver_damage > 0) out << " (+" << sword.silver_damage << " silver damage)\n";

    out << "\n\"" << sword.description << "\"";
    return out;
}

const Sword &Sword::operator=(const Sword &other_sword) {
    static_cast<Item>(*this) = static_cast<Item>(other_sword);
    this->physical_damage = other_sword.physical_damage;
    this->fire_damage = other_sword.fire_damage;
    this->poison_damage = other_sword.poison_damage;
    this->ice_damage = other_sword.ice_damage;
    this->silver_damage = other_sword.silver_damage;

    return *this;
}

int Sword::operator==(const Sword &other_sword) const {
    static_cast<Item>(*this) == static_cast<Item>(other_sword);
    if (this->physical_damage != other_sword.physical_damage) return 0;
    if (this->fire_damage != other_sword.fire_damage) return 0;
    if (this->poison_damage != other_sword.poison_damage) return 0;
    if (this->ice_damage != other_sword.ice_damage) return 0;
    if (this->silver_damage != other_sword.silver_damage) return 0;

    return 1;
}

int Sword::operator!=(const Sword &other_sword) const {
    return !(*this == other_sword);
}
