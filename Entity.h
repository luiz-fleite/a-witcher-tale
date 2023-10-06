#ifndef ENTITY_H
#define ENTITY_H

#include <string>

using std::string;

class Entity {
public:
    string getName() const;
    int getAge() const;
    double getCoins() const;
    int getHealth() const;
    int getStamina() const;
    string getCategory() const;
    int getLevel() const;
    bool getIs_stunned() const;

    void setName(string name);
    void setAge(int age);
    void setCoins(double coins);
    void setHealth(int health);
    void setStamina(int stamina);
    void setCategory(string category);
    void setLevel(int level);
    void setIs_stunned(bool is_stunned);

    void print_info() const;
    virtual void attack(Entity &) = 0;
    virtual void talk();
    virtual void walk();
protected:
    string name;
    int age;
    double coins;
    int health;
    int stamina;
    string category;
    int level;
    bool is_stunned = false;

    const static string CATEGORIES[7];
    const static int MAX_NAME_SIZE = 20;
};

#endif // ENTITY_H
