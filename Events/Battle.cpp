#include <iostream>
#include <string>
#include <unistd.h>

#include "Battle.h"

using std::cout;

Battle::Battle(Entity &ally, Entity &enemy) {
    allies.push_back(&ally);
    enemies.push_back(&enemy);
}

Battle::Battle(const Battle &other_battle) {
    for (auto ally : other_battle.allies) {
        allies.push_back(ally);
    }
    for (auto enemy : other_battle.enemies) {
        enemies.push_back(enemy);
    }
    for (auto dead : other_battle.deads) {
        deads.push_back(dead);
    }
}

Battle::~Battle() {
    //cout << "End Battle...\n";
}

void Battle::print_allies() {
    if (allies.size() == 0) {
        cout << "There is no allies.\n";
        return;
    }
    for (int i = 0; i < allies.size(); i++) {
        cout << "Allie " << i << ": " << allies[i]->getName() << "\n";
    }
    return;
}

void Battle::print_enemies() {
    if (enemies.size() == 0) {
        cout << "There is no enemies.\n";
        return;
    }
    for (int i = 0; i < enemies.size(); i++) {
        cout << "Enemy " << i << ": " << enemies[i]->getName() << "\n";
    }
    return;
}

void Battle::add_ally(Entity &ally) {
    allies.push_back(&ally);
    return;
}

void Battle::add_enemy(Entity &enemy) {
    enemies.push_back(&enemy);
    return;
}

void Battle::begin() {
    while (allies.size() != 0 && enemies.size() != 0) {

        // os turnos dos aliados vem primeiro
        for (int i = 0; i < allies.size(); i++) {
            // pula o turno de quem sofreu o efeito is_stunned
            if (allies[i]->getIs_stunned()) {
                allies[i]->setIs_stunned(false);
                continue;
            }

            // cada aliado escolhe uma vitima aleatoria entre 0 e enemies.size()
            srand(static_cast<unsigned int>(time(nullptr)));
            int enemy_id = rand() % (enemies.size());
            //cout << "enemy id: " << enemy_id << "\n";

            // regeneração padrão de stamina temporario
            allies[i]->stamina_regen(6);

            allies[i]->attack(*enemies[enemy_id], 1, 0);
            // sleep(1);

            // apos atacar a vitima, verifica se ela morreu
            if (!*enemies[enemy_id]) {
                deads.push_back(enemies[enemy_id]);
                enemies.erase(enemies.begin() + enemy_id);
                // verifica se o aliado morto era o ultimo e
                // a batalha deve acabar entre os turnos dos inimigos
                if (!enemies.size()) {
                    break;
                }
            }
        }
        // depois começa o turno dos atacantes, nesse caso os monstros
        for (int i = 0; i < enemies.size(); i++) {

            // pula o turno de quem sofreu o efeito is_stunned
            if (enemies[i]->getIs_stunned()) {
                enemies[i]->setIs_stunned(false);
                continue;
            }

            // cada monstro escolhe uma vitima aleatoria entre 0 e allies.size()
            srand(static_cast<unsigned int>(time(nullptr)));
            int ally_id = rand() % (allies.size());
            //cout << "ally id: " << ally_id << "\n";

            enemies[i]->attack(*allies[ally_id], 0, 0);
            // sleep(1);

            // apos atacar a vitima, verifica se ela morreu
            if (!*allies[ally_id]) {
                deads.push_back(allies[ally_id]);
                allies.erase(allies.begin() + ally_id);
                // verifica se o aliado morto era o ultimo e
                // a batalha deve acabar entre os turnos dos inimigos
                if (!allies.size()) {
                    break;
                }
            }
        }
    }
    if (allies.size()) {
        cout << "Allies won!\n";
    }
    else if (enemies.size()) {
        cout << "Enemies won!\n";
    }
    else {
        cout << "Draw!\n";
    }
    // drops all items from deads
    for (auto dead : deads) {
        dead->drop_all_items(this->floor_items);
    }
    return;
}

void Battle::get_floor_items(vector<Item*> &floor_items) {
    for (auto item : this->floor_items) {
        floor_items.push_back(item);
    }
    return;
}
