#ifndef GHOUL_H
#define GHOUL_H

#include <string>
using std::string;

class Ghoul {
public:
    Ghoul();
    Ghoul(string name, int age, double coins);
    Ghoul(const Ghoul &g);

string getName() const;
    int getAge() const;
    double getCoins() const;
    bool getIs_racional() const;
    int getHealth() const;
    int getStamina() const;

    void setName(string name);
    void setAge(int age);
    void setCoins(double coins);
    void setHealth(int health);
    void setStamina(int stamina);

    void print_info();
    void talk();
    void walk();
private:
    string name;
    int age;
    const bool is_rational = false;
    double coins;
    int health;
    int stamina;
};

#endif // GHOUL_H