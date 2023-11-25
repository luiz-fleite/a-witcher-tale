#ifndef IGNI_H
#define IGNI_H

#include "Sign.h"

using std::ostream;


enum igni_techniques {
    FIRE_BALL = 0,
    BURST_FIRE = 1,
};


class Igni : public Sign{
    friend ostream &operator<<(ostream &out, const Igni &igni);
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

    virtual map<string, int> cast(int technique = FIRE_BALL);

    const Igni &operator=(const Igni &);
    int operator==(const Igni &other_Igni) const;
    int operator!=(const Igni &other_Igni) const;
private:
    int fire_damage;
    int area;
};

#endif // IGNI_H