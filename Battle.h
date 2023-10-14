#ifndef BATTLE_H
#define BATTLE_H

#include <string>

#include "Entity.h"
#include "Human.h"
#include "Ghoul.h"

using std::string;

class Battle {
public:
    Battle(Entity &allie, Entity &enemy);
    Battle(const Battle &battle);
    
    void print_allies();
    void print_enemies();
    void add_ally(Entity &allie);
    void add_enemy(Entity &enemy);
    bool check_allies();
    bool check_enemies();
    void beginBattle();
private:
    const static int MAX_ALLIES = 2;
    const static int MAX_ENEMIES = 5;
    Entity* allies[MAX_ALLIES];
    Entity* enemies[MAX_ENEMIES];
};

#endif // BATTLE_H
