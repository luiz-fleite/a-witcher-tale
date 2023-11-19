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
    made_of_silver = false;

}

Sword::Sword(string name, string description, 
                          int physical_damage, 
                          int fire_damage, 
                          int poison_damage, 
                          int ice_damage, 
                          int silver_damage,
                          bool made_of_silver) {
    setName(name);
    setDescription(description);
    setPhysical_damage(physical_damage);
    setFire_damage(fire_damage);
    setPoison_damage(poison_damage);
    setIce_damage(ice_damage);
    setSilver_damage(silver_damage);
    setMade_of_silver(made_of_silver);
}

// Weapon is abstract, so we can't use static_cast
Sword::Sword(const Sword &other_sword) : Weapon(other_sword){
    //cout << "Copying Sword...\n";
    made_of_silver = other_sword.made_of_silver;

}

Sword::~Sword() {
    //cout << "Destroying Sword...\n";
}

map<string, int> Sword::use(int technique) {
    // cout << "Using Sword...\n";
    // cout << "Technique: " << technique << "\n";

    map<string, int> info_buffer;
    info_buffer["physical_damage"] = physical_damage;
    info_buffer["fire_damage"] = fire_damage;
    info_buffer["poison_damage"] = poison_damage;
    info_buffer["ice_damage"] = ice_damage;
    info_buffer["silver_damage"] = silver_damage;
    info_buffer["stamina_cost"] = 0;
    info_buffer["area"] = 1;

    switch (technique) {
        case FAST_ATTACK:
            cout << "Fast attack\n";
            info_buffer["stamina_cost"] += 4;
            info_buffer["physical_damage"] -= 1;
            break;
        case STRONG_ATTACK:
            cout << "Strong attack\n";
            info_buffer["stamina_cost"] += 8;
            info_buffer["physical_damage"] += 2;
            break;
        case GROUP_ATTACK:
            cout << "Group attack\n";
            info_buffer["stamina_cost"] += 12;
            info_buffer["physical_damage"] -= 2;
            info_buffer["area"] = 3;
            break;
        default:
            cout << "Invalid attack\n";
            break;
    }

    return info_buffer;
}

ostream &operator<< (ostream &out, const Sword &sword){
    out << sword.name << " (+" << sword.physical_damage << " physical damage)\n";
    if (sword.fire_damage > 0) out << " (+" << sword.fire_damage << " fire damage)\n";
    if (sword.poison_damage > 0) out << " (+" << sword.poison_damage << " poison damage)\n";
    if (sword.ice_damage > 0) out << " (+" << sword.ice_damage << " ice damage)\n";
    if (sword.silver_damage > 0) out << " (+" << sword.silver_damage << " silver damage)\n";

    out << "\"" << sword.description << "\"";
    return out;
}

const Sword &Sword::operator=(const Sword &other_sword) {
    // Weapon is abstract, so we can't do this:
    //static_cast<Weapon>(*this) = static_cast<Weapon>(other_sword);
    // So we do this:
    Weapon::operator=(other_sword);
    made_of_silver = other_sword.made_of_silver;

    return *this;
}

int Sword::operator==(const Sword &other_sword) const {
    // Weapon is abstract, so we can't do this:
    // static_cast<Weapon>(*this) == static_cast<Weapon>(other_sword);
    // So we do this:
    Weapon::operator==(other_sword);
    if (this->made_of_silver != other_sword.made_of_silver) return 0;

    return 1;
}

int Sword::operator!=(const Sword &other_sword) const {
    return !(*this == other_sword);
}
