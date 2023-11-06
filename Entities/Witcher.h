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
        int max_health=150, 
        int max_stamina=150,
        string category="E");
    Witcher(const Witcher &other_witcher);
    ~Witcher();

    void store_item(Item &item);
    void unstore_item(string item_name);
    void print_personal_chest() const;

    virtual void attack(Entity &entity);

    const Witcher &operator=(const Witcher &);
    bool operator==(const Witcher &other_witcher) const;
    bool operator!=(const Witcher &other_witcher) const;
private:
    map<string, Item*> personal_chest;
    const static int WITCHER_ATTACK_COST = 10;
    const static int MAX_WITCHER_DAMAGE = 10;
    const static int MIN_WITCHER_DAMAGE = 7;
    //static int player_level;
};

#endif // WITCHER_H
