#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <string>
#include <vector>

#include "Entity.h"
#include "../Items/Sword.h"
#include "../Items/Armor.h"

using std::ostream;
using std::string;
using std::vector;

struct equipped_items {
    Sword* steel_sword; // steel_swordPtr ?
    Armor* armor;
};

class Human: public Entity {
    friend ostream &operator<< (ostream &out, const Human &human);
public:
    Human();
    Human(string name,
        int age=30, 
        double coins=100, 
        int health=100, 
        int stamina=100,
        string category="E");
    Human(const Human &other_human);
    ~Human();

    void drop_item(string item_type_name);
    virtual void print_equipped_items();
    
    virtual void update_total_defense();
    virtual void attack(Entity &entity);
    virtual void receive_damage(int damage);
protected:
    equipped_items equipped;
};

inline void Human::attack(Entity &entity) { cout << "Human is too weak and afraid to attack " << entity.getName() << ".\n"; }

#endif // HUMAN_H
