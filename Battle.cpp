#include <iostream>
#include <string>
#include <unistd.h>

#include "Battle.h"
#include "Ghoul.h"
#include "Human.h"

using std::cout;

Battle::Battle(Human &human, Ghoul &ghoul) {
    allies[0] = &human;
    enemies[0] = &ghoul;
    for (int i = 1; i < MAX_ALLIES; i++) {
        allies[i] = 0;
    }
    for (int i = 1; i < MAX_ENEMIES; i++) {
        enemies[i] = 0;
    }
}

Battle::Battle(const Battle &battle) {
    for (int i = 0; i < MAX_ALLIES; i++) {
        allies[i] = battle.allies[i];
    }
    for (int i = 0; i < MAX_ENEMIES; i++) {
        enemies[i] = battle.enemies[i];
    }
}

void Battle::getAllies() {
    string names;
    for (int i = 0; i < MAX_ALLIES; i++) {
        if (allies[i] == 0) {
            cout << "Victim " << i + 1 << ": NULL\n";
            continue;
        }
        cout << "Victim " << i + 1 << ": " << allies[i]->getName() << "\n";
    }
    return;
}

void Battle::getEnemies() {
    string names;
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i] == 0) {
            cout << "Attacker " << i + 1 << ": NULL\n";
            continue;
        }
        cout << "Attacker " << i + 1 << ": " << enemies[i]->getName() << "\n";
    }
    return;
}

bool Battle::checkAllies() {
    for (int i = 0; i < MAX_ALLIES; i++) {
        if (allies[i] != 0) {
            return true;
        }
    }
    return false;
}

bool Battle::checkEnemies() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i] != 0) {
            return true;
        }
    }
    return false;
}

void Battle::beginBattle() {
    while (checkAllies() && checkEnemies()) {
        // os turnos das vitimas vem primeiro
        for (int i = 0; i < MAX_ALLIES; i++) {
            // pula o turno de quem morreu ou fugiu ou não existe
            if (allies[i] == 0) {
                continue;
            }
            // pula o turno de quem sofreu o efeito is_stunned
            if (allies[i]->getIs_stunned()) {
                allies[i]->setIs_stunned(false);
                continue;
            }
            // as vitimas não atacam porque ainda não tem um heroi
            // para defende-las, que sera o witcher
            // allies[i]->attack(*enemies[0]);
            // sleep(1);
            // apos o ataque do witcher, o monstro pode morrer
            if (enemies[i]->getHealth() <= 0) {
                cout << enemies[i]->getName() << " is dead!\n";
                enemies[i] = NULL;
                continue;
            }

        }
        // depois começa o turno dos atacantes, nesse caso os monstros
        for (int i = 0; i < MAX_ENEMIES; i++) {
            // pula o turno de quem morreu ou fugiu ou não existe
            if (enemies[i] == 0) {
                continue;
            }
            // pula o turno de quem sofreu o efeito is_stunned
            if (enemies[i]->getIs_stunned()) {
                enemies[i]->setIs_stunned(false);
                continue;
            }
            // cada monstro escolhe uma vitima aleatoria entre 0 e MAX_ALLIES
            // obs: abaixo não é utilizado "do while" porque victim_id não pode
            // ser inicializado dentro do escopo do while
            srand(static_cast<unsigned int>(time(nullptr)));
            int victim_id = rand() % (MAX_ALLIES);
            //cout << "Victim id: " << victim_id << "\n";
            while(allies[victim_id] == 0 && checkAllies()) {
                srand(static_cast<unsigned int>(time(nullptr)));
                victim_id = rand() % (MAX_ALLIES);
                //cout << "victim: " << allies[victim_id] << "\n";
                //cout << "Victim id: " << victim_id << "\n";
            }
            enemies[i]->attack(*allies[victim_id]);
            sleep(1);
            enemies[i]->setStamina(enemies[i]->getStamina() + 3);
            // apos atacar a vitima, verifica se ela morreu
            if (allies[victim_id]->getHealth() <= 0) {
                cout << allies[victim_id]->getName() << " is dead!\n";
                allies[victim_id] = 0;
            }
        }
    }
}
