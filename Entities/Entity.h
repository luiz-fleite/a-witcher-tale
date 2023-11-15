#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

#include "../Items/Weapons/Sword.h"
#include "../Items/Armors/Armor.h"
#include "../Utils/Date.h"

using std::cout;
using std::string;
using std::vector;
using std::map;
using std::pair;
using std::for_each;

enum item_type {
    SWORD = 0,
    ARMOR = 1,
    TOTAL_ITEM_TYPES = 2
};

struct inventory_items {
    vector<Sword*> swords;
    vector<Armor*> armors;
};

class Entity {
public:
    Entity();
    Entity(const Entity &other_entity);
    ~Entity();

    inline string getName() const{ return name; }
    inline int getAge() const{ return age; }
    inline double getCoins() const { return coins; }
    inline int getMax_health() const { return max_health; }
    inline int getHealth() const { return health; }
    inline int getMax_stamina() const { return max_stamina; }
    inline int getStamina() const { return stamina; }
    inline string getCategory() const { return category; }
    inline int getLevel() const { return level; }
    inline bool getIs_stunned() const { return is_stunned; }
    inline int getPhysical_weakness() const { return physical_weakness; }
    inline int getFire_weakness() const { return fire_weakness; }
    inline int getPoison_weakness() const { return poison_weakness; }
    inline int getIce_weakness() const { return ice_weakness; }
    inline int getSilver_weakness() const { return silver_weakness; }
    inline int getTotal_physical_resistance() const { return total_physical_resistance; }
    inline int getTotal_fire_resistance() const { return total_fire_resistance; }
    inline int getTotal_poison_resistance() const { return total_poison_resistance; }
    inline int getTotal_ice_resistance() const { return total_ice_resistance; }
    inline int getTotal_silver_resistance() const { return total_silver_resistance; }

    void setName(string name);
    void setAge(int age);
    void setCoins(double coins);
    void setMax_health(int max_health);
    void setHealth(int health);
    void setMax_stamina(int max_stamina);
    void setStamina(int stamina);
    void setCategory(string category);
    void setLevel(int level);
    inline void setIs_stunned(bool is_stunned) { this->is_stunned = is_stunned; }
    //void setDate_of_birth(Date &date_of_birth);
    inline void setPhysical_weakness(int physical_weakness) {if (physical_weakness >= 0) this->physical_weakness = physical_weakness;}
    inline void setFire_weakness(int fire_weakness) {if (fire_weakness >= 0) this->fire_weakness = fire_weakness;}
    inline void setPoison_weakness(int poison_weakness) {if (poison_weakness >= 0) this->poison_weakness = poison_weakness;}
    inline void setIce_weakness(int ice_weakness) {if (ice_weakness >= 0) this->ice_weakness = ice_weakness;}
    inline void setSilver_weakness(int silver_weakness) {if (silver_weakness >= 0) this->silver_weakness = silver_weakness;}
    inline void setTotal_physical_resistance(int total_physical_resistance) {if (total_physical_resistance >= 0) this->total_physical_resistance = total_physical_resistance;}
    inline void setTotal_fire_resistance(int total_fire_resistance) {if (total_fire_resistance >= 0) this->total_fire_resistance = total_fire_resistance;}
    inline void setTotal_poison_resistance(int total_poison_resistance) {if (total_poison_resistance >= 0) this->total_poison_resistance = total_poison_resistance;}
    inline void setTotal_ice_resistance(int total_ice_resistance) {if (total_ice_resistance >= 0) this->total_ice_resistance = total_ice_resistance;}
    inline void setTotal_silver_resistance(int total_silver_resistance) {if (total_silver_resistance >= 0) this->total_silver_resistance = total_silver_resistance;}

    // add an item and deletes it
    void add_item(Item &);
    // just deletes an inventory item
    void remove_item(int item_type, int item_index);

    // add an item from a source and deletes it
    void grab_item(vector<Item*> &source_items, int item_index);
    // remove an item and put it somewhere
    void drop_item(vector<Item*> &destiny_items, int item_type, int item_index);

    void print_inventory() const;

    virtual void life_regen(int);
    virtual void stamina_regen(int);
    //virtual void level_up() = 0;
    //virtual void update_atributes() = 0;
    virtual void update_all_resistances() = 0;
    virtual void attack(Entity &) = 0;
    virtual void receive_damage(int physical_damage, 
                                int fire_damage = 0, 
                                int poison_damage = 0, 
                                int ice_damage = 0, 
                                int silver_damage = 0);

    void print_resistances() const;
    void print_weaknesses() const;
    void print_info() const;
    virtual void talk();
    virtual void walk();

    //void update_global_level();
    
    const Entity &operator=(const Entity &);
    int operator==(const Entity &) const;
    int operator!=(const Entity &) const;
    bool operator!() const;
protected:
    string name;
    int age;
    double coins;
    int max_health;
    int health;
    int max_stamina;
    int stamina;
    string category;
    int level;
    //int next_level_xp;
    //int xp;
    bool is_stunned = false;

    inventory_items inventory;

    int physical_weakness = 1;
    int fire_weakness = 1;
    int poison_weakness = 1;
    int ice_weakness = 1;
    int silver_weakness = 0;

    int total_physical_resistance = 0;
    int total_fire_resistance = 0;
    int total_poison_resistance = 0;
    int total_ice_resistance = 0;
    int total_silver_resistance = 0;

    const static string CATEGORIES[7];
    const static int MAX_NAME_SIZE = 20;
    Date date_of_birth;
private:
    //static int global_danger;
};

inline void Entity::talk() { cout << name << " says: \"Hello!\"\n"; }

inline void Entity::walk() { cout << name << " is walking.\n"; }


#endif // ENTITY_H
