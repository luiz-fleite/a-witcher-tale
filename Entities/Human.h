#ifndef HUMAN_H
#define HUMAN_H

#include <string>

#include "Entity.h"

using std::string;

class Human: public Entity {
public:
    Human();
    Human(string name,
        int age=30, 
        double coins=100, 
        int health=100, 
        int stamina=100,
        string category="E");
    Human(const Human &other_human) : Entity(other_human) { };
    ~Human();
    
    virtual void attack(Entity &entity);
};

inline void Human::attack(Entity &entity) { cout << "Human is too weak and afraid to attack " << entity.getName() << ".\n"; }

#endif // HUMAN_H
