#include <iostream>
#include <string>

#include "Battle.h"
#include "Ghoul.h"
#include "Human.h"

using std::cout;

Battle::Battle(Human &human, Ghoul &ghoul) {
    victims[0] = &human;
    attackers[0] = &ghoul;
    for (int i = 1; i < MAX_VICTIMS; i++) {
        victims[i] = NULL;
    }
    for (int i = 1; i < MAX_ATTACKERS; i++) {
        attackers[i] = NULL;
    }
}

Battle::Battle(const Battle &battle) {
    for (int i = 0; i < MAX_VICTIMS; i++) {
        victims[i] = battle.victims[i];
    }
    for (int i = 0; i < MAX_ATTACKERS; i++) {
        attackers[i] = battle.attackers[i];
    }
}

void Battle::getVictims() {
    string names;
    for (int i = 0; i < MAX_VICTIMS; i++) {
        if (victims[i] == NULL) {
            cout << "Victim " << i + 1 << ": NULL\n";
            continue;
        }
        cout << "Victim " << i + 1 << ": " << victims[i]->getName() << "\n";
    }
    return;
}

void Battle::getAttackers() {
    string names;
    for (int i = 0; i < MAX_ATTACKERS; i++) {
        if (attackers[i] == NULL) {
            cout << "Attacker " << i + 1 << ": NULL\n";
            continue;
        }
        cout << "Attacker " << i + 1 << ": " << attackers[i]->getName() << "\n";
    }
    return;
}

void Battle::BeginBattle() {
    int i = 0;
    int j = 0;
    
}
