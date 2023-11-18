#ifndef IGNI_H
#define IGNI_H

#include "Sign.h"


class Igni : public Sign{
public:
    Igni();
    Igni(string name, 
         string description, 
         bool is_unlocked, 
         int stamina_cost, 
         int fire_damage, 
         int area);
    Igni(const Igni &other_Igni);
    ~Igni();

    inline int getFire_damage() const { return fire_damage; }
    inline int getArea() const { return area; }

    void setFire_damage(int fire_damage);
    void setArea(int area);

    void print_info() const;

    virtual map<string, int> cast(int technique);

    const Igni &operator=(const Igni &);
    int operator==(const Igni &other_Igni) const;
    int operator!=(const Igni &other_Igni) const;
private:
    int fire_damage;
    int area;
};


#endif // IGNI_H