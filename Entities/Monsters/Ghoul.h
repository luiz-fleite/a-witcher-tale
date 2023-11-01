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
        int max_health=75, 
        int max_stamina=75, 
        string category="E");
    Ghoul(const Ghoul &other_ghoul): Entity(other_ghoul) { };
    ~Ghoul();

    inline bool getIs_enraged() const { return is_enraged; }

    void setIs_enraged(bool is_enraged);
    
    void update_total_defense();
    void attack(Entity &entity);
    void receive_damage(int damage);
    
    inline void talk() { cout << name << "grawrawrawrawr\n"; }
    inline void walk() { cout << name << "is crawling.\n"; }

    const Ghoul &operator=(const Ghoul &);
    int operator==(const Ghoul &) const;
    int operator!=(const Ghoul &) const;
    bool operator!() const;
private:
    bool is_enraged = false;
    const static int GHOUL_ATTACK_COST = 10;
    const static int MAX_GHOUL_DAMAGE = 7;
    const static int MIN_GHOUL_DAMAGE = 3;
};

#endif // GHOUL_H
