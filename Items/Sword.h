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
    Sword(string name, string description, int physical_damage, 
                                           int fire_damage = 0, 
                                           int poison_damage = 0, 
                                           int ice_damage = 0, 
                                           int silver_damage = 0);
    Sword(const Sword &other_sword);
    ~Sword();
    
    inline int getPhysical_damage() const { return physical_damage; }
    inline int getFire_damage() const { return fire_damage; }
    inline int getPoison_damage() const { return poison_damage; }
    inline int getIce_damage() const { return ice_damage; }
    inline int getSilver_damage() const { return silver_damage; }

    inline void setPhysical_damage(int physical_damage) { this->physical_damage = physical_damage; }
    inline void setFire_damage(int fire_damage) { this->fire_damage = fire_damage; }
    inline void setPoison_damage(int poison_damage) { this->poison_damage = poison_damage; }
    inline void setIce_damage(int ice_damage) { this->ice_damage = ice_damage; }
    inline void setSilver_damage(int silver_damage) { this->silver_damage = silver_damage; }

    const Sword &operator=(const Sword &);
    int operator==(const Sword &other_sword) const;
    int operator!=(const Sword &other_sword) const;
private:
    int physical_damage;
    int fire_damage;
    int poison_damage;
    int ice_damage;
    int silver_damage;
};

#endif // SWORD_H
