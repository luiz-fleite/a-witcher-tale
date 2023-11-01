#ifndef ARMOR_H
#define ARMOR_H

#include <string>

#include "Item.h"

using std::ostream;
using std::string;

class Armor : public Item{
    friend ostream &operator<< (ostream &out, const Armor &armor);
public:
    Armor();
    Armor(string name, string description, int defense=5);
    Armor(const Armor &other_armor);
    ~Armor();
    
    inline int getDefense() const { return defense; }
    
    void setDefense(int defense);

    const Armor &operator=(const Armor &);
    int operator==(const Armor &other_armor) const;
    int operator!=(const Armor &other_armor) const;
private:
    int defense;
};

#endif // ARMOR_H
