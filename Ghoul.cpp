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
    name = "Ghoul";
    age = 100;
    coins = 15;
    health = 50;
    stamina = 50;
    bool is_stunned = false;
}

Ghoul::Ghoul(string name, int age, double coins, int health, int stamina) {
    setName(name);
    setAge(age);
    setCoins(coins);
    setHealth(health);
    setStamina(stamina);
    is_stunned = false;
}

Ghoul::Ghoul(const Ghoul &ghoul) {
    this->name = ghoul.name;
    this->age = ghoul.age;
    this->coins = ghoul.coins;
    this->health = ghoul.health;
    this->stamina = ghoul.stamina;
    this->is_stunned = ghoul.is_stunned;
}

string Ghoul::getName() const{
    return name;
}

int Ghoul::getAge() const{
    return age;
}

double Ghoul::getCoins() const {
    return coins;
}

int Ghoul::getHealth() const {
    return health;
}

int Ghoul::getStamina() const {
    return stamina;
}

bool Ghoul::getIs_stunned() const {
    return is_stunned;
}

void Ghoul::setName(string name) {
    
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

void Ghoul::setAge(int age) {
    if (age < 0) {
        cout << "Age cannot be negative. Age set to 0.\n";
        this->age = 0;
        return;
    }
    this->age = age;
}

void Ghoul::setCoins(double coins) {
    if (coins < 0) {
        cout << "Coins cannot be negative. Coins set to 0.\n";
        this->coins = 0;
        return;
    }
    this->coins = coins;
}

void Ghoul::setHealth(int health) {
    if (health < 0) {
        cout << "Health cannot be negative. Health set to 0.\n";
        this->health = 0;
        return;
    }
    this->health = health;
}

void Ghoul::setStamina(int stamina) {
    if (stamina < 0) {
        cout << "Stamina cannot be negative. Stamina set to 0.\n";
        this->stamina = 0;
        return;
    }
    this->stamina = stamina;
}

void Ghoul::setIs_stunned(bool is_stunned) {
    this->is_stunned = is_stunned;
}

void Ghoul::print_info() const {
    cout << "Name: " << getName() << "\nAge: " << getAge() << "\nCoins: " << getCoins() << "\nHealth: " << getHealth() << "\nStamina: " << getStamina() << "\n";
    cout << "Temporary status:\n" << "Is stunned: " << getIs_stunned() << "\n";
}

void Ghoul::attack(Human &human) {
    if (getStamina() < GHOUL_ATTACK_COST) {
        cout << name << " has no stamina left to attack.\n";
        return;
    }
    setStamina(getStamina() - GHOUL_ATTACK_COST);

    srand(static_cast<unsigned int>(time(nullptr)));
    int damage = MIN_GHOUL_DAMAGE + rand() % (MAX_GHOUL_DAMAGE - MIN_GHOUL_DAMAGE + 1);
    human.setHealth(human.getHealth() - damage);
    cout << name << " attacked " << human.getName() << ".\n";
    cout << human.getName() << " -" << damage << " damage.\n";
    return;
}

void Ghoul::talk() {
    cout << name << "grawrawrawrawr\n";
}

void Ghoul::walk() {
    cout << name << "is walking.\n";
}
