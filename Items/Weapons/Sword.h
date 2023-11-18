#ifndef SWORD_H
#define SWORD_H

#include "Weapon.h"

using std::ostream;

enum technique {
    FAST_ATTACK = 1,
    STRONG_ATTACK = 2,
    GROUP_ATTACK = 3
};

class Sword : public Weapon {
    friend ostream &operator<< (ostream &out, const Sword &sword);
public:
    Sword();
    Sword(string name, string description, int physical_damage, 
                                           int fire_damage = 0, 
                                           int poison_damage = 0, 
                                           int ice_damage = 0, 
                                           int silver_damage = 0);
    Sword(const Sword &other_sword);
    ~Sword();
 
    virtual map<string, int> use(int technique = FAST_ATTACK);

    const Sword &operator=(const Sword &);
    int operator==(const Sword &other_sword) const;
    int operator!=(const Sword &other_sword) const;
};

#endif // SWORD_H
