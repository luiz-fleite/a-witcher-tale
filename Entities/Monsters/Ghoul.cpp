#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "Ghoul.h"

using std::cout;
using std::srand;
using std::rand;
using std::time;


Ghoul::Ghoul() {
    //cout << "Creating a new Ghoul...\n";
    name = "Ghoul";
    age = 100;
    coins = 15;
    max_health = 50;
    health = max_health;
    max_stamina = 50;
    stamina = max_stamina;
    category = CATEGORIES[0];
    level = 1;
    bool is_stunned = false;
}

Ghoul::Ghoul(string name, int age, double coins, int max_health, int max_stamina, string category) {
    setName(name);
    setAge(age);
    setCoins(coins);
    setMax_health(max_health);
    life_regen(max_health);
    setMax_stamina(max_stamina);
    stamina_regen(max_stamina);
    setCategory(category);
    setLevel(1);
    is_stunned = false;
}

Ghoul::~Ghoul() {
    //cout << "Destroying Ghoul...\n";
    for_each(inventory.swords.begin(), inventory.swords.end(), [](Sword *s) { delete s; });
    for_each(inventory.armors.begin(), inventory.armors.end(), [](Armor *a) { delete a; });
}

void Ghoul::setIs_enraged(bool is_enraged) {
    this->is_enraged = is_enraged;
    update_total_defense();
    cout << name << " is enraged!\n";
}

void Ghoul::update_total_defense() {
    if (is_enraged) {
        setTotal_defense(getTotal_defense() + 5);
    }
}

void Ghoul::attack(Entity &entity) {
    if (getStamina() < GHOUL_ATTACK_COST) {
        cout << name << " has no stamina left to attack.\n";
        return;
    }
    setStamina(getStamina() - GHOUL_ATTACK_COST);
    // Dano aleatorio entre MIN_GHOUL_DAMAGE e MAX_GHOUL_DAMAGE
    srand(static_cast<unsigned int>(time(nullptr)));
    int damage = MIN_GHOUL_DAMAGE + rand() % (MAX_GHOUL_DAMAGE - MIN_GHOUL_DAMAGE + 1);
    // depois de gerar o dano aleatorio adiciona o level do Ghoul
    // para nivelar o jogo ao nivel desejado
    // o valor é propositalmente arredondado para baixo
    damage = damage + (getLevel() / 3);
    entity.receive_damage(damage);
    cout << name << " attacked " << entity.getName() << ".\n";
    cout << entity.getName() << " -" << damage << " damage.\n";
    return;
}

void Ghoul::receive_damage(int damage) {
    Entity::receive_damage(damage);
    if (getHealth() < getMax_health() * 0.1) {
        if (!is_enraged) {
            setIs_enraged(true);
        }
    }
    return;
}

ostream &operator<<(ostream &out, const Ghoul &ghoul) {
    ghoul.print_info();
    return out;
}

const Ghoul &Ghoul::operator=(const Ghoul &other_ghoul) {
    if (this == &other_ghoul) {
        return *this;
    }
    Entity::operator=(other_ghoul);
    return *this;
}

int Ghoul::operator==(const Ghoul &other_ghoul) const {
    return Entity::operator==(other_ghoul);
}

int Ghoul::operator!=(const Ghoul &other_ghoul) const {
    return Entity::operator!=(other_ghoul);
}

bool Ghoul::operator!() const {
    return (this->getHealth() <= 0);
}
