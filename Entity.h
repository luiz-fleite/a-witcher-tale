#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>

using std::cout;
using std::string;

class Entity {
public:
    Entity();
    Entity(const Entity &other_entity);

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


inline string Entity::getName() const{ return name; }

inline int Entity::getAge() const{ return age; }

inline double Entity::getCoins() const { return coins; }

inline int Entity::getHealth() const { return health; }

inline int Entity::getStamina() const { return stamina; }

inline string Entity::getCategory() const { return category; }

inline int Entity::getLevel() const { return level; }

inline bool Entity::getIs_stunned() const { return is_stunned; }

inline void Entity::setIs_stunned(bool is_stunned) { this->is_stunned = is_stunned; }

inline void Entity::talk() { cout << name << " says: \"Hello!\"\n"; }

inline void Entity::walk() { cout << name << " is walking.\n"; }


#endif // ENTITY_H
