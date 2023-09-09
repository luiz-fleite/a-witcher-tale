#include <iostream>
#include <string>

#include "human.h"

using std::cout;

Human::Human() {
    name = "Peasant";
    age = 30;
    coins = 50.00;
}

Human::Human(string name, int age=30, double coins=100) {
    setName(name);
    setAge(age);
    setCoins(coins);
}

string Human::getName() {
    return name;
}

int Human::getAge() {
    return age;
}

double Human::getCoins() const {
    return coins;
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

void Human::printInfo() {
    cout << "Name: " << name << "\nAge: " << age << "\nCoins: " << coins << "\n";
}

void Human::talk() {
    cout << name << " says: \"Hello!\"\n";
}

void Human::walk() {
    cout << name << " is walking.\n";
}
