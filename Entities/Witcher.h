#ifndef WITCHER_H
#define WITCHER_H

#include <string>

#include "Human.h"

using std::string;

class Witcher: public Human {
    friend ostream &operator<< (ostream &out, const Witcher &witcher);
public:
    Witcher();
    Witcher(string name,
        int age=200,
        double coins=200, 
        int health=200, 
        int stamina=200,
        string category="E");
    Witcher(const Witcher &other_witcher);
    ~Witcher();

    void store_sword(Sword &sword);
    void unstore_sword(string sword_name);
    void print_chest_swords() const;

    virtual void attack(Entity &entity);

    const Witcher &operator=(const Witcher &);
    bool operator==(const Witcher &other_witcher) const;
    bool operator!=(const Witcher &other_witcher) const;
private:
    map<string, Sword*> chest_swords;
    const static int WITCHER_ATTACK_COST = 10;
    const static int MAX_WITCHER_DAMAGE = 10;
    const static int MIN_WITCHER_DAMAGE = 7;
    static int player_level;
};

#endif // WITCHER_H
