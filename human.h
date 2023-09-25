#ifndef HUMAN_H
#define HUMAN_H

#include <string>
using std::string;

class Human {
public:
    Human();
    Human(string name, int age=30, double coins=100, int health=100, int stamina=100);
    Human(const Human &h);

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
    const bool is_rational = true;
    double coins;
    int health;
    int stamina;
};

#endif // HUMAN_H