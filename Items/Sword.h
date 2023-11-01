#ifndef SWORD_H
#define SWORD_H

#include <string>

#include "Item.h"

using std::ostream;
using std::string;

class Sword : public Item {
    friend ostream &operator<< (ostream &out, const Sword &sword);
public:
    Sword();
    Sword(string name, string description, int damage=10);
    Sword(const Sword &other_sword);
    ~Sword();
    
    inline int getDamage() const { return damage; }
    
    void setDamage(int damage);

    const Sword &operator=(const Sword &);
    int operator==(const Sword &other_sword) const;
    int operator!=(const Sword &other_sword) const;
private:
    int damage;
};

#endif // SWORD_H
