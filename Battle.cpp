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
        victims[i] = 0;
    }
    for (int i = 1; i < MAX_ATTACKERS; i++) {
        attackers[i] = 0;
    }
}
// INCOMPLETO   
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
        if (victims[i] == 0) {
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
        if (attackers[i] == 0) {
            cout << "Attacker " << i + 1 << ": NULL\n";
            continue;
        }
        cout << "Attacker " << i + 1 << ": " << attackers[i]->getName() << "\n";
    }
    return;
}

bool Battle::checkVictims() {
    for (int i = 0; i < MAX_VICTIMS; i++) {
        if (victims[i] != NULL) {
            return true;
        }
    }
    return false;
}

bool Battle::checkAttackers() {
    for (int i = 0; i < MAX_ATTACKERS; i++) {
        if (attackers[i] != NULL) {
            return true;
        }
    }
    return false;
}

void Battle::beginBattle() {
    while (checkVictims() || checkAttackers()) {
        // os turnos das vitimas vem primeiro
        for (int i = 0; i < MAX_VICTIMS; i++) {
            if (victims[i] == NULL) {
                continue;
            }
            // as vitimas não atacam porque ainda não tem um heroi
            // para defende-las, que sera o witcher
            // victims[i]->attack(*attackers[0]);
            // apos o ataque do witcher, o monstro pode morrer
            if (attackers[i]->getHealth() <= 0) {
                cout << attackers[i]->getName() << " is dead!\n";
                attackers[i] = NULL;
                continue;
            }

        }
        // depois começa o turno dos atacantes, nesse caso os monstros
        for (int i = 0; i < MAX_ATTACKERS; i++) {
            if (attackers[i] == NULL) {
                continue;
            }
            // cada monstro escolhe uma vitima aleatoria entre 0 e MAX_VICTIMS
            srand(static_cast<unsigned int>(time(nullptr)));
            int victim_id = 0 + rand() % (MAX_VICTIMS - 0 + 1);
            attackers[i]->attack(*victims[victim_id]);
            // apos atacar a vitima, verifica se ela morreu
            if (victims[victim_id]->getHealth() <= 0) {
                cout << victims[victim_id]->getName() << " is dead!\n";
                victims[victim_id] = NULL;
                continue;
            }
        }
    }
}

