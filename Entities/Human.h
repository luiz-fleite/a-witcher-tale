#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <string>

#include "Entity.h"

using std::ostream;
using std::string;

struct equipped_items {
    Sword* steel_sword; 
    Armor* armor;
};

class Human: public Entity {
    friend ostream &operator<< (ostream &out, const Human &human);
public:
    Human();
    Human(string name,
        int age=30, 
        double coins=100, 
        int max_health=50, 
        int max_stamina=50,
        string category="E");
    Human(const Human &other_human);
    ~Human();

    virtual void equip_item(int item_type, int item_index);
    virtual void unequip_item(int item_type);
    virtual void print_equipped_items();
    
    virtual void update_all_resistances();
    virtual void attack(Entity &entity);
    virtual void receive_damage(int physical_damage, 
                                int fire_damage, 
                                int poison_damage, 
                                int ice_damage, 
                                int silver_damage);

    const Human &operator=(const Human &);
    bool operator==(const Human &other_human) const;
    bool operator!=(const Human &other_human) const;
protected:
    equipped_items equipped;
};

inline void Human::attack(Entity &entity) { cout << "Human is too weak and afraid to attack " << entity.getName() << ".\n"; }

#endif // HUMAN_H
