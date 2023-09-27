#ifndef GHOUL_H
#define GHOUL_H

#include <string>

#include "Human.h"

using std::string;

class Ghoul {
public:
    Ghoul();
    Ghoul(string name, int age=200, double coins=30, int health=75, int stamina=75);
    Ghoul(const Ghoul &g);

    string getName() const;
    int getAge() const;
    double getCoins() const;
    int getHealth() const;
    int getStamina() const;
    bool getIs_stunned() const;

    void setName(string name);
    void setAge(int age);
    void setCoins(double coins);
    void setHealth(int health);
    void setStamina(int stamina);
    void setIs_stunned(bool is_stunned);

    void print_info() const;
    // O método attack() recebe a referencia de um objeto tipo "Human" para poder subtrair
    // o atributo "health", e por isso não pode ser passado como "const".
    void attack(Human &h);
    void talk();
    void walk();
private:
    string name;
    int age;
    double coins;
    int health;
    int stamina;
    bool is_stunned = false;
    const int MAX_NAME_SIZE = 20;
    const int GHOUL_ATTACK_COST = 10;
    const int MAX_GHOUL_DAMAGE = 7;
    const int MIN_GHOUL_DAMAGE = 3;
};

#endif // GHOUL_H
