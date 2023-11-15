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
    Armor(string name, string description, int physical_defense, 
                                           int fire_defense = 0, 
                                           int poison_defense = 0, 
                                           int ice_defense = 0, 
                                           int silver_defense = 0);
    Armor(const Armor &other_armor);
    ~Armor();
    
    inline int getPhysical_defense() const { return physical_defense; }
    inline int getFire_defense() const { return fire_defense; }
    inline int getPoison_defense() const { return poison_defense; }
    inline int getIce_defense() const { return ice_defense; }
    inline int getSilver_defense() const { return silver_defense; }

    inline void setPhysical_defense(int physical_defense) { this->physical_defense = physical_defense; }
    inline void setFire_defense(int fire_defense) { this->fire_defense = fire_defense; }
    inline void setPoison_defense(int poison_defense) { this->poison_defense = poison_defense; }
    inline void setIce_defense(int ice_defense) { this->ice_defense = ice_defense; }
    inline void setSilver_defense(int silver_defense) { this->silver_defense = silver_defense; }

    const Armor &operator=(const Armor &);
    int operator==(const Armor &other_armor) const;
    int operator!=(const Armor &other_armor) const;
private:
    int physical_defense = 0;
    int fire_defense = 0;
    int poison_defense = 0;
    int ice_defense = 0;
    int silver_defense = 0;

};

#endif // ARMOR_H
