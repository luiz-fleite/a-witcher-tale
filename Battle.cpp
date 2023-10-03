#include <iostream>
#include <string>
#include <unistd.h>

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
        if (victims[i] != 0) {
            return true;
        }
    }
    return false;
}

bool Battle::checkAttackers() {
    for (int i = 0; i < MAX_ATTACKERS; i++) {
        if (attackers[i] != 0) {
            return true;
        }
    }
    return false;
}

void Battle::beginBattle() {
    while (checkVictims() && checkAttackers()) {
        // os turnos das vitimas vem primeiro
        for (int i = 0; i < MAX_VICTIMS; i++) {
            // pula o turno de quem morreu ou fugiu ou não existe
            if (victims[i] == 0) {
                continue;
            }
            // pula o turno de quem sofreu o efeito is_stunned
            if (victims[i]->getIs_stunned()) {
                victims[i]->setIs_stunned(false);
                continue;
            }
            // as vitimas não atacam porque ainda não tem um heroi
            // para defende-las, que sera o witcher
            // victims[i]->attack(*attackers[0]);
            // sleep(1);
            // apos o ataque do witcher, o monstro pode morrer
            if (attackers[i]->getHealth() <= 0) {
                cout << attackers[i]->getName() << " is dead!\n";
                attackers[i] = NULL;
                continue;
            }

        }
        // depois começa o turno dos atacantes, nesse caso os monstros
        for (int i = 0; i < MAX_ATTACKERS; i++) {
            // pula o turno de quem morreu ou fugiu ou não existe
            if (attackers[i] == 0) {
                continue;
            }
            // pula o turno de quem sofreu o efeito is_stunned
            if (attackers[i]->getIs_stunned()) {
                attackers[i]->setIs_stunned(false);
                continue;
            }
            // cada monstro escolhe uma vitima aleatoria entre 0 e MAX_VICTIMS
            // obs: abaixo não é utilizado "do while" porque victim_id não pode
            // ser inicializado dentro do escopo do while
            srand(static_cast<unsigned int>(time(nullptr)));
            int victim_id = rand() % (MAX_VICTIMS);
            //cout << "Victim id: " << victim_id << "\n";
            while(victims[victim_id] == 0 && checkVictims()) {
                srand(static_cast<unsigned int>(time(nullptr)));
                victim_id = rand() % (MAX_VICTIMS);
                //cout << "victim: " << victims[victim_id] << "\n";
                //cout << "Victim id: " << victim_id << "\n";
            }
            attackers[i]->attack(*victims[victim_id]);
            sleep(1);
            attackers[i]->setStamina(attackers[i]->getStamina() + 3);
            // apos atacar a vitima, verifica se ela morreu
            if (victims[victim_id]->getHealth() <= 0) {
                cout << victims[victim_id]->getName() << " is dead!\n";
                victims[victim_id] = 0;
            }
        }
    }
}
