#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Ghoul.h"

using std::cout;
using std::srand;
using std::rand;


Ghoul::Ghoul() {
    //cout << "Creating a new Ghoul...\n";
    name = "Ghoul";
    age = 100;
    coins = 15;

    category = CATEGORIES[0];
    level = 0;
    xp = 0;

    update_atributes();
    life_regen(max_health);
    stamina_regen(max_stamina);

    update_all_resistances();
    update_all_weaknesses();

    bool is_stunned = false;
}

Ghoul::Ghoul(string name, 
             int age, 
             double coins, 
             int level,
             string category) {

    setName(name);
    setAge(age);
    setCoins(coins);

    setCategory(category);
    setLevel(level);
    setXp(0);

    update_atributes();
    life_regen(max_health);
    stamina_regen(max_stamina);

    update_all_resistances();
    update_all_weaknesses();

    is_stunned = false;
}

Ghoul::~Ghoul() {
    //cout << "Destroying Ghoul...\n";
    for_each(inventory.swords.begin(), inventory.swords.end(), [](Sword *s) { delete s; });
    for_each(inventory.armors.begin(), inventory.armors.end(), [](Armor *a) { delete a; });
}

void Ghoul::setIs_enraged(bool is_enraged) {
    this->is_enraged = is_enraged;
    update_all_resistances();
    cout << name << " is enraged!\n";
}

void Ghoul::level_up() {
    level++;
    
    update_atributes();

    life_regen(max_health);
    stamina_regen(max_stamina);

}

void Ghoul::update_atributes() {
    next_level_xp = NEXT_LEVEL_XP_LINEAR_COEF + NEXT_LEVEL_XP_ANGULAR_COEF * level;
    max_health = HEALTH_LINEAR_COEF + HEALTH_ANGULAR_COEF * level;
    max_stamina = STAMINA_LINEAR_COEF + STAMINA_ANGULAR_COEF * level;
}

void Ghoul::update_all_resistances() {
    total_physical_resistance = 0;
    total_fire_resistance = 0;
    total_poison_resistance = 0;
    total_ice_resistance = 0;
    total_silver_resistance = 0;

    if (is_enraged) {
        setTotal_physical_resistance(getTotal_physical_resistance() + 1);
    }
}

void Ghoul::update_all_weaknesses() {
    physical_weakness = 1;
    fire_weakness = 1;
    poison_weakness = 1;
    ice_weakness = 1;
    silver_weakness = 1;
}

void Ghoul::attack(Entity &entity, int weapon_type) {
    if (!spend_stamina(GHOUL_ATTACK_COST)) {
        return;
    }
    cout << name << " attacked " << entity.getName() << ".\n";
    // Dano aleatorio entre MIN_GHOUL_DAMAGE e MAX_GHOUL_DAMAGE
    srand(static_cast<unsigned int>(time(nullptr)));
    int damage = MIN_GHOUL_DAMAGE + rand() % (MAX_GHOUL_DAMAGE - MIN_GHOUL_DAMAGE + 1);
    // depois de gerar o dano aleatorio adiciona o level do Ghoul

    damage = damage + getLevel();
    entity.receive_damage(damage);

    return;
}

void Ghoul::receive_damage(int physical_damage, int fire_damage, int poison_damage, int ice_damage, int silver_damage) {
    Entity::receive_damage(physical_damage, fire_damage, poison_damage, ice_damage, silver_damage);
    if (getHealth() < getMax_health() * 0.1) {
        if (!is_enraged) {
            setIs_enraged(true);
        }
    }
    return;
}

ostream &operator<<(ostream &out, const Ghoul &ghoul) {
    ghoul.print_info();
    out << "Enraged: " << ghoul.is_enraged << "\n";
    
    return out;
}

const Ghoul &Ghoul::operator=(const Ghoul &other_ghoul) {
    if (this == &other_ghoul) {
        return *this;
    }
    Entity::operator=(other_ghoul);
    this->is_enraged = other_ghoul.is_enraged;
    
    return *this;
}

int Ghoul::operator==(const Ghoul &other_ghoul) const {
    Entity::operator==(other_ghoul);
    if (this->is_enraged != other_ghoul.is_enraged) { return 0; }
    return 1;
}

int Ghoul::operator!=(const Ghoul &other_ghoul) const {
    return Entity::operator!=(other_ghoul);
}

bool Ghoul::operator!() const {
    return (this->getHealth() <= 0);
}
