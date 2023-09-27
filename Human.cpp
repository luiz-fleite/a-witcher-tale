#include <iostream>
#include <string>

#include "Human.h"

using std::cout;

Human::Human() {
    name = "Peasant";
    age = 30;
    coins = 50.00;
    health = 50;
    stamina = 50;
    is_stunned = false;
}

Human::Human(string name, int age, double coins, int health, int stamina) {
    setName(name);
    setAge(age);
    setCoins(coins);
    setHealth(health);
    setStamina(stamina);
    // não é usado set para is_stunned na inicialização para deixar
    // claro que o valor nunca é escolhido pelo jogador, sendo o 
    // padrão false modificado apenas no combate
    is_stunned = false;
}

Human::Human(const Human &human) {
    this->name = human.name;
    this->age = human.age;
    this->coins = human.coins;
    this->health = human.health;
    this->stamina = human.stamina;
    this->is_stunned = human.is_stunned;
}

string Human::getName() const{
    return name;
}

int Human::getAge() const{
    return age;
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

bool Human::getIs_stunned() const {
    return is_stunned;
}

void Human::setName(string name) {
    name.erase(0, name.find_first_not_of(' '));
    name.erase(name.find_last_not_of(' ') + 1);
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

void Human::setIs_stunned(bool is_stunned) {
    this->is_stunned = is_stunned;
}

void Human::print_info() const{
    cout << "Name: " << getName() << "\nAge: " << getAge() << "\nCoins: " << getCoins() << "\nHealth: " << getHealth() << "\nStamina: " << getStamina() << "\n";
    cout << "Temporary status:\n" << "Is stunned: " << getIs_stunned() << "\n";
}

void Human::talk() {
    cout << name << " says: \"Hello!\"\n";
}

void Human::walk() {
    cout << name << " is walking.\n";
}
