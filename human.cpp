#include <iostream>
#include <string>

#include "human.h"

using std::cout;

Human::Human() {
    name = "Peasant";
    age = 30;
    coins = 50.00;
    health = 50;
    stamina = 50;
}

Human::Human(string name, int age=30, double coins=100, int health=100, int stamina=100) {
    setName(name);
    setAge(age);
    setCoins(coins);
    setHealth(health);
    setStamina(stamina);
}

Human::Human(const Human &h) {
    this->name = h.name;
    this->age = h.age;
    this->coins = h.coins;
}

string Human::getName() const{
    return name;
}

int Human::getAge() const{
    return age;
}

bool Human::getIs_racional() const{
    return is_rational;
}

double Human::getCoins() const {
    return coins;
}

int Human::getHealth() const {
    return health;
}

int Human::getStamina() const {
    return stamina;
}

void Human::setName(string name) {
    if (name == "") {
        cout << "Name cannot be empty.\n";
        this->name = "Empty_Name";
        return;
    }
    this->name = name;
}

void Human::setAge(int age) {
    if (age < 0) {
        cout << "Age cannot be negative.\n";
        this->age = 0;
        return;
    }
    this->age = age;
}

void Human::setCoins(double coins) {
    if (coins < 0) {
        cout << "Coins cannot be negative.\n";
        this->coins = 0;
        return;
    }
    this->coins = coins;
}

void Human::setHealth(int health) {
    if (health < 0) {
        cout << "Health cannot be negative.\n";
        this->health = 0;
        return;
    }
    this->health = health;
}

void Human::setStamina(int stamina) {
    if (stamina < 0) {
        cout << "Stamina cannot be negative.\n";
        this->stamina = 0;
        return;
    }
    this->stamina = stamina;
}

void Human::print_info() {
    cout << "Name: " << getName() << "\nAge: " << getAge() << "\nRational: " << getIs_racional() << "\nCoins: " << getCoins() << "\nHealth: " << getHealth() << "\nStamina: " << getStamina() << "\n";
}

void Human::talk() {
    cout << name << " says: \"Hello!\"\n";
}

void Human::walk() {
    cout << name << " is walking.\n";
}
