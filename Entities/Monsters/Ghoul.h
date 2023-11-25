#ifndef GHOUL_H
#define GHOUL_H

#include <string>

#include "../Entity.h"

using std::string;

class Ghoul: public Entity {
    friend ostream &operator<<(ostream &out, const Ghoul &ghoul);
public:
    Ghoul();
    Ghoul(string name, 
        int age=200, 
        double coins=30, 
        int level = 10,
        string category="E");
    Ghoul(const Ghoul &other_ghoul);
    ~Ghoul();

    inline bool getIs_enraged() const { return is_enraged; }

    void setIs_enraged(bool is_enraged);
    
    void level_up();
    void update_atributes();
    void update_all_resistances();
    void update_all_weaknesses();

    void attack(Entity &entity, int weapon_type = UNARMED, int technique = 0);
    void receive_damage(int physical_damage, 
                        int fire_damage, 
                        int poison_damage, 
                        int ice_damage, 
                        int silver_damage);
    
    inline void talk() { cout << name << "grawrawrawrawr\n"; }
    inline void walk() { cout << name << "is crawling.\n"; }

    const Ghoul &operator=(const Ghoul &);
    int operator==(const Ghoul &) const;
    int operator!=(const Ghoul &) const;
    bool operator!() const;
private:
    const static int HEALTH_LINEAR_COEF = 5;
    const static int HEALTH_ANGULAR_COEF = 2;

    const static int STAMINA_LINEAR_COEF = 5;
    const static int STAMINA_ANGULAR_COEF = 2;

    bool is_enraged = false;

    int silver_weakness = 1;

    const static int GHOUL_ATTACK_COST = 10;
    const static int MAX_GHOUL_DAMAGE = 7;
    const static int MIN_GHOUL_DAMAGE = 3;
};

#endif // GHOUL_H
