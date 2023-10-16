#include <iostream>
#include <string>
#include <unistd.h>

#include "Battle.h"
#include "Ghoul.h"
#include "Human.h"

using std::cout;

Battle::Battle(Entity &ally, Entity &enemy) {
    allies[0] = &ally;
    enemies[0] = &enemy;
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

Battle::~Battle() {
    //cout << "End Battle...\n";
}

void Battle::print_allies() {
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

void Battle::print_enemies() {
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

void Battle::add_ally(Entity &ally) {
    for (int i = 0; i < MAX_ALLIES; i++) {
        if (allies[i] == 0) {
            allies[i] = &ally;
            return;
        }
    }
    cout << "Allies is full!\n";
    return;
}

void Battle::add_enemy(Entity &enemy) {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i] == 0) {
            enemies[i] = &enemy;
            return;
        }
    }
    cout << "Enemies is full!\n";
    return;
}

bool Battle::check_allies() {
    for (int i = 0; i < MAX_ALLIES; i++) {
        if (allies[i] != 0) {
            return true;
        }
    }
    return false;
}

bool Battle::check_enemies() {
    for (int i = 0; i < MAX_ENEMIES; i++) {
        if (enemies[i] != 0) {
            return true;
        }
    }
    return false;
}

void Battle::beginBattle() {
    while (check_allies() && check_enemies()) {
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
            // cada aliado escolhe uma vitima aleatoria entre 0 e MAX_ENEMIES
            // obs: abaixo não é utilizado "do while" porque allie_id não pode
            // ser inicializado dentro do escopo do while
            srand(static_cast<unsigned int>(time(nullptr)));
            int enemy_id = rand() % (MAX_ENEMIES);
            //cout << "enemy id: " << enemy_id << "\n";
            while(enemies[enemy_id] == 0 && check_enemies()) {
                srand(static_cast<unsigned int>(time(nullptr)));
                enemy_id = rand() % (MAX_ENEMIES);
                //cout << "enemy: " << enemies[enemy_id] << "\n";
                //cout << "enemy id: " << enemy_id << "\n";
            }
            allies[i]->attack(*enemies[enemy_id]);
            sleep(1);
            allies[i]->setStamina(enemies[i]->getStamina() + 5);
            // apos atacar a vitima, verifica se ela morreu
            if (enemies[enemy_id]->getHealth() <= 0) {
                cout << enemies[enemy_id]->getName() << " is dead!\n";
                enemies[enemy_id] = 0;
                // verifica se o aliado morto era o ultimo e
                // a batalha deve acabar entre os turnos dos inimigos
                if (!check_enemies()) {
                    break;
                }
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
            srand(static_cast<unsigned int>(time(nullptr)));
            int ally_id = rand() % (MAX_ALLIES);
            //cout << "ally id: " << ally_id << "\n";
            while(allies[ally_id] == 0 && check_allies()) {
                srand(static_cast<unsigned int>(time(nullptr)));
                ally_id = rand() % (MAX_ALLIES);
                //cout << "ally: " << allies[ally_id] << "\n";
                //cout << "ally id: " << ally_id << "\n";
            }
            enemies[i]->attack(*allies[ally_id]);
            sleep(1);
            enemies[i]->setStamina(enemies[i]->getStamina() + 5);
            // apos atacar a vitima, verifica se ela morreu
            if (allies[ally_id]->getHealth() <= 0) {
                cout << allies[ally_id]->getName() << " is dead!\n";
                allies[ally_id] = 0;
                // verifica se o aliado morto era o ultimo e
                // a batalha deve acabar entre os turnos dos inimigos
                if (!check_allies()) {
                    break;
                }
            }
        }
    }
}
