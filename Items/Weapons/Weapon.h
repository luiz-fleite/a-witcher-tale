#ifndef WEAPON_H
#define WEAPON_H

#include <string>

#include "../Item.h"


using std::ostream;
using std::string;


class Weapon : public Item {
public:
    Weapon();
    Weapon(const Weapon &other_Weapon);
    ~Weapon();
    
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

    virtual void print_info() const;

    virtual map<string, int> use(int technique) = 0;

    const Weapon &operator=(const Weapon &);
    int operator==(const Weapon &other_Weapon) const;
    int operator!=(const Weapon &other_Weapon) const;
protected:
    int physical_damage;
    int fire_damage;
    int poison_damage;
    int ice_damage;
    int silver_damage;
};

#endif // WEAPON_H
