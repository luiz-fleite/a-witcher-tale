#include <iostream>
#include <string>

#include "Witcher.h"

using std::cout;

Witcher::Witcher() {
    cout << "Creating a new Witcher...\n";
    name = "Witcher";
    age = 200;
    coins = 150;
    health = 150;
    stamina = 150;
    category = CATEGORIES[0];
    level = 1;
    is_stunned = false;

}

Witcher::Witcher(string name, int age, double coins, int health, int stamina, string category) {
    setName(name);
    setAge(age);
    setCoins(coins);
    setHealth(health);
    setStamina(stamina);
    setCategory(category);
    setLevel(1);
    is_stunned = false;

}

Witcher::Witcher(const Witcher &other_witcher) : Human(other_witcher) {
    this->max_swords = other_witcher.max_swords;
    this->count_swords = other_witcher.count_swords;

    this->swordsPtr = new Sword[this->max_swords];
    for (int i = 0; i < this->count_swords; i++) {
        this->swordsPtr[i] = other_witcher.swordsPtr[i];
    }
}

Witcher::~Witcher() {
    cout << "Destroying Witcher...\n";
    delete [] swordsPtr;
}

void Witcher::print_swords() const {
    cout << "Swords:\n";
    for (int i = 0; i < count_swords; i++) {
        cout << i + 1 << ". ";
        swordsPtr[i].print_info();
    }
}

void Witcher::addSword(Sword &sword) {
    if (count_swords == max_swords) {
        resize_swords(max_swords + 1);
    }
    if (count_swords == 0) {
        swordsPtr = new Sword[max_swords];
    }
    swordsPtr[count_swords++] = sword;
}

void Witcher::resize_swords(int new_size) {
    Sword *new_swordsPtr = new Sword[new_size];
    for (int i = 0; i < count_swords; i++) {
        new_swordsPtr[i] = swordsPtr[i];
    }
    delete[] swordsPtr;
    swordsPtr = new_swordsPtr;
    max_swords = new_size;
}

void Witcher::attack(Entity &entity) {
    if (getStamina() < WITCHER_ATTACK_COST) {
        cout << name << " has no stamina left to attack.\n";
        return;
    }
    setStamina(getStamina() - WITCHER_ATTACK_COST);
    // Dano aleatorio entre MIN_WITCHER_DAMAGE e MAX_WITCHER_DAMAGE
    srand(static_cast<unsigned int>(time(nullptr)));
    int damage = MIN_WITCHER_DAMAGE + rand() % (MAX_WITCHER_DAMAGE - MIN_WITCHER_DAMAGE + 1);
    // depois de gerar o dano aleatorio adiciona o level do Witcher
    // para nivelar o jogo ao nivel desejado
    // o valor é propositalmente arredondado para baixo
    damage = damage + (getLevel() / 3) + swordsPtr->getDamage();
    entity.setHealth(entity.getHealth() - damage);
    cout << name << " attacked " << entity.getName() << ".\n";
    cout << entity.getName() << " -" << damage << " damage.\n";
    return;
}
