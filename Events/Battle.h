#ifndef BATTLE_H // QUEBRADO TEMPORARIAMENTE
#define BATTLE_H

#include <string>

#include "../Entities/Entity.h"

using std::string;

class Battle {
public:
    Battle(Entity &allie, Entity &enemy);
    Battle(const Battle &battle);
    ~Battle();
    
    void print_allies();
    void print_enemies();
    void add_ally(Entity &allie);
    void add_enemy(Entity &enemy);
    void begin();
    void get_floor_items(vector<Item*> &floor_items);
private:
    vector<Entity *> allies;
    vector<Entity *> enemies;
    vector<Entity *> deads;
    vector<Item *> floor_items;
}; 

#endif // BATTLE_H
