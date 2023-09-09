#ifndef HUMAN_H
#define HUMAN_H

#include <string>
using std::string;

class Human {
public:
    Human();
    Human(string name, int age, double coins);
    string getName();
    int getAge();
    double getCoins() const;
    void setName(string name);
    void setAge(int age);
    void setCoins(double coins);
    void printInfo();
    void talk();
    void walk();
private:
    string name;
    int age;
    double coins;
};

#endif // HUMAN_H