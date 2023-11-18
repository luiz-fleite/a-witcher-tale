#include <iostream>
#include <string>

#include "Weapon.h"

using std::cout;

Weapon::Weapon() {
    //cout << "Creating a new weapon...\n";
    name = "A generic weapon";
    description = "A generic weapon. Very Used by the common folk.";
    physical_damage = 0;
    fire_damage = 0;
    poison_damage = 0;
    ice_damage = 0;
    silver_damage = 0;
}

// Itme is abstract, so we can't use static_cast
Weapon::Weapon(const Weapon &other_weapon) : Item(other_weapon){
    this->physical_damage = other_weapon.physical_damage;
    this->fire_damage = other_weapon.fire_damage;
    this->poison_damage = other_weapon.poison_damage;
    this->ice_damage = other_weapon.ice_damage;
    this->silver_damage = other_weapon.silver_damage;

}

Weapon::~Weapon() {
    //cout << "Destroying weapon...\n";
}

void Weapon::print_info() const {
    cout << name << " (+" << physical_damage << " physical damage)\n";
    if (fire_damage > 0) cout << " (+" << fire_damage << " fire damage)\n";
    if (poison_damage > 0) cout << " (+" << poison_damage << " poison damage)\n";
    if (ice_damage > 0) cout << " (+" << ice_damage << " ice damage)\n";
    if (silver_damage > 0) cout << " (+" << silver_damage << " silver damage)\n";

    cout << "\"" << description << "\"";
}


const Weapon &Weapon::operator=(const Weapon &other_weapon) {
    // Item is abstract, so we can't do this:
    //static_cast<Item>(*this) = static_cast<Item>(other_weapon);
    // So we do this:
    Item::operator=(other_weapon);

    this->physical_damage = other_weapon.physical_damage;
    this->fire_damage = other_weapon.fire_damage;
    this->poison_damage = other_weapon.poison_damage;
    this->ice_damage = other_weapon.ice_damage;
    this->silver_damage = other_weapon.silver_damage;

    return *this;
}

int Weapon::operator==(const Weapon &other_weapon) const {
    // Item is abstract, so we can't do this:
    // static_cast<Item>(*this) == static_cast<Item>(other_weapon);
    // So we do this:
    Item::operator==(other_weapon);

    if (this->physical_damage != other_weapon.physical_damage) return 0;
    if (this->fire_damage != other_weapon.fire_damage) return 0;
    if (this->poison_damage != other_weapon.poison_damage) return 0;
    if (this->ice_damage != other_weapon.ice_damage) return 0;
    if (this->silver_damage != other_weapon.silver_damage) return 0;

    return 1;
}

int Weapon::operator!=(const Weapon &other_weapon) const {
    return !(*this == other_weapon);
}
