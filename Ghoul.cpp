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
    health = 50;
    stamina = 50;
    category = CATEGORIES[0];
    level = 1;
    bool is_stunned = false;
}

Ghoul::Ghoul(string name, int age, double coins, int health, int stamina, string category) {
    setName(name);
    setAge(age);
    setCoins(coins);
    setHealth(health);
    setStamina(stamina);
    setCategory(category);
    setLevel(1);
    is_stunned = false;
}

Ghoul::~Ghoul() {
    //cout << "Destroying Ghoul...\n";
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
    entity.setHealth(entity.getHealth() - damage);
    cout << name << " attacked " << entity.getName() << ".\n";
    cout << entity.getName() << " -" << damage << " damage.\n";
    return;
}
