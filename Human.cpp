#include <iostream>
#include <string>

#include "Human.h"

using std::cout;

Human::Human() {
    cout << "Creating a new Human...\n";
    name = "Peasant";
    age = 30;
    coins = 50.00;
    health = 50;
    stamina = 50;
    category = CATEGORIES[0];
    level = 1;
    is_stunned = false;
}

Human::Human(string name, int age, double coins, int health, int stamina, string category) {
    setName(name);
    setAge(age);
    setCoins(coins);
    setHealth(health);
    setStamina(stamina);
    setCategory(category);
    setLevel(1);
    // não é usado set para is_stunned na inicialização para deixar
    // claro que o valor nunca é escolhido pelo jogador, sendo o 
    // padrão false modificado apenas no combate
    is_stunned = false;
}

Human::~Human() {
    cout << "Destroying Human...\n";
}

