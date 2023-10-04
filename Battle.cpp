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
            cout << "Allie " << i + 1 << ": NULL\n";
            continue;
        }
        cout << "Allie " << i + 1 << ": " << allies[i]->getName() << "\n";
    }
    return;
}

void Battle::getEnemies() {
    string names;
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i] == 0) {
            cout << "Enemie " << i + 1 << ": NULL\n";
            continue;
        }
        cout << "Enemie " << i + 1 << ": " << enemies[i]->getName() << "\n";
    }
    return;
}

void Battle::addAllies(Human &human) {
    for (int i = 0; i < MAX_ALLIES; i++) {
        if (allies[i] == 0) {
            allies[i] = &human;
            return;
        }
    }
    cout << "Allies is full!\n";
    return;
}

void Battle::addEnemies(Ghoul &ghoul) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i] == 0) {
            enemies[i] = &ghoul;
            return;
        }
    }
    cout << "Enemies is full!\n";
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
        // os turnos dos aliados vem primeiro
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
            // os aliados não atacam porque ainda não tem um heroi
            // para defende-los, que sera o witcher
            // allies[i]->attack(*enemies[0]);
            // sleep(1);
            // apos o ataque do witcher, o monstro pode morrer
            //if (enemies[i]->getHealth() <= 0) {
            //    cout << enemies[i]->getName() << " is dead!\n";
            //    enemies[i] = NULL;
            //    continue;
            //}
        }
        // verifica se a batalha deve acabar entre os turnos dos times
        if (!checkAllies() || !checkEnemies()) {
            break;
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
            // obs: abaixo não é utilizado "do while" porque allie_id não pode
            // ser inicializado dentro do escopo do while
            srand(static_cast<unsigned int>(time(nullptr)));
            int allie_id = rand() % (MAX_ALLIES);
            //cout << "allie id: " << allie_id << "\n";
            while(allies[allie_id] == 0 && checkAllies()) {
                srand(static_cast<unsigned int>(time(nullptr)));
                allie_id = rand() % (MAX_ALLIES);
                //cout << "allie: " << allies[allie_id] << "\n";
                //cout << "allie id: " << allie_id << "\n";
            }
            enemies[i]->attack(*allies[allie_id]);
            sleep(1);
            enemies[i]->setStamina(enemies[i]->getStamina() + 3);
            // apos atacar a vitima, verifica se ela morreu
            if (allies[allie_id]->getHealth() <= 0) {
                cout << allies[allie_id]->getName() << " is dead!\n";
                allies[allie_id] = 0;
                // verifica se o aliado morto era o ultimo e
                // a batalha deve acabar entre os turnos dos inimigos
                if (!checkAllies()) {
                    break;
                }
            }
        }
    }
}
