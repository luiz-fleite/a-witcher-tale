#ifndef HUMAN_H
#define HUMAN_H

#include <string>
using std::string;

class Human {
public:
    Human();
    Human(string name, int age=30, double coins=100, int health=100, int stamina=100);
    Human(const Human &human);

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
};

#endif // HUMAN_H
