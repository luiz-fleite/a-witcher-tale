#ifndef BATTLE_H
#define BATTLE_H

#include <string>

#include "Human.h"
#include "Ghoul.h"

using std::string;

class Battle {
    const static int MAX_VICTIMS = 2;
    const static int MAX_ATTACKERS = 5;
public:
    Battle(Human &human, Ghoul &ghoul);
    Battle(const Battle &battle);
    void getVictims();
    void getAttackers();
    
    void BeginBattle();
    void EndBattle();
    
private:
    Human* victims[MAX_VICTIMS];
    Ghoul* attackers[MAX_ATTACKERS];
    
};

#endif // BATTLE_H
