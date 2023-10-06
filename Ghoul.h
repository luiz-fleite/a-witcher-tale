#ifndef GHOUL_H
#define GHOUL_H

#include <string>

#include "Entity.h"

using std::string;

class Ghoul: public Entity {
public:
    Ghoul();
    Ghoul(string name, 
        int age=200, 
        double coins=30, 
        int health=75, 
        int stamina=75, 
        string category="E");
    Ghoul(const Ghoul &ghoul);
    // O método attack() recebe a referencia de um objeto tipo "Entity" para poder subtrair
    // o atributo "health", e por isso não pode ser passado como "const".
    void attack(Entity &entity);
    void talk();
    void walk();
private:
    const static int GHOUL_ATTACK_COST = 10;
    const static int MAX_GHOUL_DAMAGE = 7;
    const static int MIN_GHOUL_DAMAGE = 3;
};

#endif // GHOUL_H
