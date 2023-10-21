#ifndef WITCHER_H
#define WITCHER_H

#include <string>

#include "Human.h"
#include "../Items/Sword.h"

using std::string;

class Witcher: public Human {
public:
    Witcher();
    Witcher(string name,
        int age=200,
        double coins=200, 
        int health=200, 
        int stamina=200,
        string category="E");
    Witcher(const Witcher &other_witcher);
    ~Witcher();

    void print_swords() const;
    void addSword(Sword &sword);
    
    virtual void attack(Entity &entity);
private:
    const static int WITCHER_ATTACK_COST = 10;
    const static int MAX_WITCHER_DAMAGE = 10;
    const static int MIN_WITCHER_DAMAGE = 7;

    int max_swords = 2;
    int count_swords = 0;
    Sword *swordsPtr;
    void resize_swords(int new_size);
};

#endif // WITCHER_H
