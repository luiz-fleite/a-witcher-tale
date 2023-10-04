#ifndef BATTLE_H
#define BATTLE_H

#include <string>

#include "Human.h"
#include "Ghoul.h"

using std::string;

class Battle {
public:
    Battle(Human &human, Ghoul &ghoul);
    Battle(const Battle &battle);
    void getAllies();
    void getEnemies();
    bool checkAllies();
    bool checkEnemies();
    void beginBattle();
    
private:
    const static int MAX_ALLIES = 2;
    const static int MAX_ENEMIES = 5;
    Human* allies[MAX_ALLIES];
    Ghoul* enemies[MAX_ENEMIES];
};

#endif // BATTLE_H
