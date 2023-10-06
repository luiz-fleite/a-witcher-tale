#include <iostream>
#include <string>

#include "Entity.h"

using std::cout;

const string Entity::CATEGORIES[7] = {"F", "E", "D", "C", "B", "A", "S"};

inline string Entity::getName() const{ return name; }

inline int Entity::getAge() const{ return age; }

inline double Entity::getCoins() const { return coins; }

inline int Entity::getHealth() const { return health; }

inline int Entity::getStamina() const { return stamina; }

inline string Entity::getCategory() const { return category; }

inline int Entity::getLevel() const { return level; }

inline bool Entity::getIs_stunned() const { return is_stunned; }

void Entity::setName(string name) {
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

void Entity::setAge(int age) {
    if (age < 0) {
        cout << "Age cannot be negative.\n";
        this->age = 0;
        return;
    }
    this->age = age;
}

void Entity::setCoins(double coins) {
    if (coins < 0) {
        cout << "Coins cannot be negative.\n";
        this->coins = 0;
        return;
    }
    this->coins = coins;
}

void Entity::setHealth(int health) {
    if (health < 0) {
        cout << "Health cannot be negative.\n";
        this->health = 0;
        return;
    }
    this->health = health;
}

void Entity::setStamina(int stamina) {
    if (stamina < 0) {
        cout << "Stamina cannot be negative.\n";
        this->stamina = 0;
        return;
    }
    this->stamina = stamina;
}

void Entity::setCategory(string category) {
    if (category == "") {
        cout << "Category cannot be empty.\n";
        this->category = "Empty_Category";
        return;
    }
    for (int i = 0; i < 7; i++) {
        if (category == CATEGORIES[i]) {
            this->category = category;
            return;
        }
    }
    cout << "Invalid category.\n";
    this->category = "Invalid_Category";
    return;
}

void Entity::setLevel(int level) {
    if (level < 1) {
        cout << "Level cannot be less than 1.\n";
        this->level = 1;
        return;
    }
    if (getCategory() == "F" && level > 10) {
        cout << "Level cannot be greater than 10 for category F.\n";
        this->level = 10;
        return;
    }
    if (getCategory() == "E" && level > 20) {
        cout << "Level cannot be greater than 20 for category E.\n";
        this->level = 20;
        return;
    }
    this->level = level;
}

inline void Entity::setIs_stunned(bool is_stunned) { this->is_stunned = is_stunned; }

void Entity::print_info() const{
    cout << "Name: " << this->name << "\nCategory: " << this->category << "\nLevel: " << this->level << "\nAge: " << this->age << "\nCoins: " << this->coins << "\nHealth: " << this->health << "\nStamina: " << this->stamina << "\n";
    cout << "Temporary status:\n" << "Is stunned: " << this->is_stunned << "\n";
}

inline void Entity::talk() { cout << name << " says: \"Hello!\"\n"; }

inline void Entity::walk() { cout << name << " is walking.\n"; }
