/*
Expandir a hierarquia da atividade anterior: três hierarquias de três níveis.
    Sendo que em uma das hierarquias há dois níveis de classes 
    abstratas. Uma das classes abstratas precisa ter pelo menos dois métodos virtuais 
    puros. 

    Para cada lado da hierarquia criar ao menos duas classes concretas. 
        Pelo menos duas classes concretas herdando de uma dessas outras classes 
        concretas. 
        Cada classe, além dos métodos herdados, precisa ter pelo menos um método que tenha 
        alguma funcionalidade, que não seja set e get. 

Para cada classe do seu projeto criar pelo menos três constructores, sendo um o 
constructor de cópia. 
 
Em uma das hierarquias deve haver alocação de memória usando um vector< ptr * >, 
onde ptr é  um ponteiro de uma de suas classes criadas que tem relação de composição. 
 
Ter um atributo static e um atributo const static.  

Fazer a sobrecarga para cada classe dos operadores =, ==, ≠, ! e << (friend) para as 
classes concretas. Usar sempre que possível o static_cast para reaproveitamento de código - mas não é possível usar
para classes abstract.  
 
Criar um vector de ponteiros de uma das classes abstrata e  armazenar nele objetos 
de classes concretas. Usar dynamic_cast e typeid para fazer algo significativo com 
partes dessas classes concretas. 
 
Carregamento e salvamento de  arquivos: é necessário ter a funcionalidade de 
 1. leitura de arquivos para  configuração das suas classes e variáveis de status, 
 2. processamento das variáveis de status e 
 3. salvamento dessas variáveis. 
 
Todos os projetos devem ter um diagrama mostrando a hierarquia. 
Sem o diagrama e os dois videos, o trabalho não será avaliado.*/


//// Geral - parte para revisão
    //Diagrama UML    
    //Organização do código 

////Importante
//// Cada classe, além dos métodos herdados, precisa ter pelo menos um método que tenha 
//alguma funcionalidade, que não seja set e get.

//// Os .h

    /// O .h das classes bases

        //Classe abstract base 1    
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


enum options {
    AUTO = -1
};

enum item_type {
    // NONE = -1,
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

    inline bool getIs_dead() const { return is_dead; }
    inline int getMax_health() const { return max_health; }
    inline int getHealth() const { return health; }
    inline int getMax_stamina() const { return max_stamina; }
    inline int getStamina() const { return stamina; }

    inline string getCategory() const { return category; }
    inline int getLevel() const { return level; }
    inline int getNext_level_xp() const { return next_level_xp; }
    inline int getXp() const { return xp; }
    inline int getXp_reward() const { return xp_reward; }

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

    inline static int getGlobal_danger() { return global_danger; }

    void setName(string name);
    void setAge(int age);
    void setCoins(double coins);

    inline void setIs_dead(bool is_dead) { if (is_dead) {this->health = 0;} this->is_dead = is_dead; }
    void setMax_health(int max_health);
    void setHealth(int health);
    void setMax_stamina(int max_stamina);
    void setStamina(int stamina);

    void setCategory(string category);
    void setLevel(int level);
    inline void setNext_level_xp(int next_level_xp) { if (next_level_xp >= 0) this->next_level_xp = next_level_xp; }
    inline void setXp(int xp) { if (xp >= 0) this->xp = xp; }
    inline void setXp_reward(int xp_reward) { if (xp_reward >= 0) this->xp_reward = xp_reward; else this->xp_reward = 0; }

    inline void setIs_stunned(bool is_stunned) { this->is_stunned = is_stunned; }

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

    inline static void setGlobal_danger(int global_danger) { if (global_danger >= 0) Entity::global_danger = global_danger; }

    // add an item and deletes it
    void add_item(Item &);
    // just deletes an inventory item
    void remove_item(int item_type, int item_index);

    // add an item from a source and deletes it
    void grab_item(vector<Item*> &source_items, int item_index = 0);
    // remove an individual item and put it somewhere
    void drop_item(vector<Item*> &destiny_items, int item_type, int item_index);
    // remove all items and put them somewhere
    virtual void drop_all_items(vector<Item*> &floor_items);

    void print_inventory() const;

    virtual void life_regen(int);
    virtual void stamina_regen(int);
    virtual void gain_xp(int);

    virtual void level_up() = 0;
    virtual void update_atributes() = 0;
    virtual void update_all_resistances() = 0;
    virtual void update_all_weaknesses() = 0;
    
    virtual void attack(Entity &, int, int) = 0;
    virtual void receive_damage(int physical_damage, 
                                int fire_damage = 0, 
                                int poison_damage = 0, 
                                int ice_damage = 0, 
                                int silver_damage = 0);
    bool spend_stamina(int stamina_spent);

    void print_resistances() const;
    void print_weaknesses() const;
    virtual void print_temporary_status() const;

    void print_info() const;

    virtual void talk();
    virtual void walk();

    static void update_global_danger(int higher_level = 0);
    
    const Entity &operator=(const Entity &);
    int operator==(const Entity &) const;
    int operator!=(const Entity &) const;
    bool operator!() const;
protected:
    string name;
    int age;
    double coins;

    bool is_dead = false;
    int max_health;
    int health;
    int max_stamina;
    int stamina;

    string category;
    int level;
    int next_level_xp;
    int xp;
    int xp_reward;
    
    bool is_stunned = false;

    inventory_items inventory;

    int physical_weakness;
    int fire_weakness;
    int poison_weakness;
    int ice_weakness;
    int silver_weakness;

    int total_physical_resistance;
    int total_fire_resistance;
    int total_poison_resistance;
    int total_ice_resistance;
    int total_silver_resistance;

    const static string CATEGORIES[7];
    const static int MAX_NAME_SIZE = 20;
    Date date_of_birth;

    const static int NEXT_LEVEL_XP_LINEAR_COEF = 10;
    const static int NEXT_LEVEL_XP_ANGULAR_COEF = 10;
private:
    static int global_danger;
};

inline void Entity::talk() { cout << name << " says: \"Hello!\"\n"; }

inline void Entity::walk() { cout << name << " is walking.\n"; }


#endif // ENTITY_H

        //Classe abstract base 2
#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <map>

using std::ostream;
using std::string;
using std::cout;
using std::map;
using std::pair;

class Item {
public:
    Item();
    Item(string name, string description);
    Item(const Item &other_Item);
    ~Item();
    
    inline string getName() const { return name; }
    inline string getDescription() const { return description; }
    
    void setName(string name);
    void setDescription(string description);

    virtual void print_info() const;

    virtual map<string, int> use(int technique) = 0;
    
    const Item &operator=(const Item &);
    int operator==(const Item &other_Item) const;
    int operator!=(const Item &other_Item) const;
protected:
    string name;
    string description;
private:
    const static int MAX_NAME_SIZE = 20;
    const static int MAX_DESCRIPTION_SIZE = 100;
};

#endif // ITEM_H


        //Classe abstract base 3
#ifndef SPELL_H
#define SPELL_H

#include <iostream>
using std::cout;
using std::ostream;

#include <string>
using std::string;

#include <map>
using std::map;
using std::pair;


class Spell {
public:
    Spell();
    Spell(const Spell &other_spell);
    ~Spell();
    
    inline string getName() const { return name; }
    inline string getDescription() const { return description; }
    inline bool getIs_unlocked() const { return is_unlocked; }
    
    void setName(string name);
    void setDescription(string description);
    inline void setIs_unlocked(bool is_unlocked) { this->is_unlocked = is_unlocked; }

    virtual void print_info() const;

    virtual map<string, int> cast(int technique) = 0;
    
    const Spell &operator=(const Spell &);
    int operator==(const Spell &other_spell) const;
    int operator!=(const Spell &other_spell) const;
protected:
    string name;
    string description;
    bool is_unlocked;
private:
    const static int MAX_NAME_SIZE = 20;
    const static int MAX_DESCRIPTION_SIZE = 100;
};

#endif // SPELL_H

    /// O .h da hierarquia 1 (abstract base 1)

        //Classe 1 - concrete
#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <string>

#include "../Entity.h"

using std::ostream;


enum attack_options {
    UNARMED = 0,
    // Weapons
    STEEL_SWORD = 1,
    SILVER_SWORD = 2,
    CROSSBOW = 3,
    // Signs
    IGNI = 4
};


struct equipped_items {
    Sword* steel_sword; 
    Armor* armor;
};

class Human: public Entity {
    friend ostream &operator<< (ostream &out, const Human &human);
public:
    Human();
    Human(string name,
        int age = 30, 
        double coins = 100, 
        int level = AUTO,
        string category = "E");
    Human(const Human &other_human);
    ~Human();

    virtual void equip_item(int item_type, int item_index);
    virtual void unequip_item(int item_type);
    virtual void print_equipped_items();

    virtual void level_up();
    virtual void update_atributes();
    virtual void update_all_resistances();
    virtual void update_all_weaknesses();
    
    virtual void attack(Entity &entity, int weapon_type = UNARMED, int technique = 0);
    virtual void receive_damage(int physical_damage, 
                                int fire_damage = 0, 
                                int poison_damage = 0, 
                                int ice_damage = 0, 
                                int silver_damage = 0);

    virtual void drop_all_items(vector<Item*> &floor_items);

    const Human &operator=(const Human &);
    bool operator==(const Human &other_human) const;
    bool operator!=(const Human &other_human) const;
    bool operator!() const;
protected:
    equipped_items equipped;
private:
    const static int HEALTH_LINEAR_COEF = 5;
    const static int HEALTH_ANGULAR_COEF = 3;

    const static int STAMINA_LINEAR_COEF = 5;
    const static int STAMINA_ANGULAR_COEF = 3;
};

inline void Human::attack(Entity &entity, int weapon_type, int technique) { cout << "Human is too weak and afraid to attack " << entity.getName() << ".\n"; }

#endif // HUMAN_H

        //Classe 2 - concrete
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
        int level = AUTO,
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

    void print_temporary_status() const;
    
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

    // Classe 3 - concrete
#ifndef WITCHER_H
#define WITCHER_H

using std::cerr;

#include <string>
using std::getline;
using std::to_string;

#include <fstream>
using std::fstream;
using std::ifstream;
using std::ofstream;

#include <sstream>
using std::istringstream;


#include "Human.h"
#include "../../Spells/Signs/Igni.h"



struct Signs {
    Igni * igni;
};

class Witcher: public Human {
    friend ostream &operator<< (ostream &out, const Witcher &witcher);
public:
    Witcher();
    Witcher(string name,
        int age=200,
        double coins=200, 
        int level = AUTO,
        string category="E");
    Witcher(const Witcher &other_witcher);
    ~Witcher();

    inline void setIs_close_to_chest(bool is_close_to_chest) { this->is_close_to_chest = is_close_to_chest; };

    inline bool getIs_close_to_chest() const { return is_close_to_chest; }

    void load_inventory(string file_name_swords="./save-files/config-witcher/config_swords.txt", 
                        string file_name_armors="./save-files/config-witcher/config_armors.txt");
    void save_inventory(string file_name_swords="./save-files//config-witcher/config_swords.txt", 
                        string file_name_armors="./save-files/config-witcher/config_armors.txt");

    void store_item(int item_type, int item_index);
    void unstore_item(string item_name);
    void print_personal_chest() const;

    void update_atributes();

    // simply attack one entity
    void attack(Entity &entity, int attack_option = UNARMED, int technique = 0);
    // attacks one or more entities
    /*
    void attack(vector<Entity*> &entities, 
                int entity_index = 0, 
                int attack_option = UNARMED, 
                int attack_type = 0);
    */

    const Witcher &operator=(const Witcher &);
    bool operator==(const Witcher &other_witcher) const;
    bool operator!=(const Witcher &other_witcher) const;
    bool operator!() const;
private:
    const static int HEALTH_LINEAR_COEF = 10;
    const static int HEALTH_ANGULAR_COEF = 5;
    
    const static int STAMINA_LINEAR_COEF = 10;
    const static int STAMINA_ANGULAR_COEF = 5;

    Signs signs;

    bool is_close_to_chest;
    map<string, Item*> personal_chest;

    const static int WITCHER_ATTACK_COST = 10;
    const static int MAX_WITCHER_DAMAGE = 10;
    const static int MIN_WITCHER_DAMAGE = 7;
    //static int player_level;
};

#endif // WITCHER_H

        //E assim por diante

    /// O .h da hierarquia 2 (abstract base 2)

        //Classe Abstract 1 que herda da base abstract
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


        //Classe 2 - concrete
#ifndef ARMOR_H
#define ARMOR_H

#include <string>

#include "../Item.h"

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

    virtual map<string, int> use(int technique = 0);

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

        // Classe 3 - concrete
#ifndef SWORD_H
#define SWORD_H

#include "Weapon.h"


using std::ostream;


enum sword_techniques {
    FAST_ATTACK = 1,
    STRONG_ATTACK = 2,
    GROUP_ATTACK = 3,
};


class Sword : public Weapon {
    friend ostream &operator<< (ostream &out, const Sword &sword);
public:
    Sword();
    Sword(string name, string description, int physical_damage, 
                                           int fire_damage = 0, 
                                           int poison_damage = 0, 
                                           int ice_damage = 0, 
                                           int silver_damage = 0,
                                           bool made_of_silver = false);
    Sword(const Sword &other_sword);
    ~Sword();

    inline bool getMade_of_silver() const { return made_of_silver; }

    inline void setMade_of_silver(bool made_of_silver) { this->made_of_silver = made_of_silver; }
 
    virtual map<string, int> use(int technique = FAST_ATTACK);

    const Sword &operator=(const Sword &);
    int operator==(const Sword &other_sword) const;
    int operator!=(const Sword &other_sword) const;
private:
    bool made_of_silver;
};

#endif // SWORD_H


        //E assim por diante

    /// O .h da hierarquia 3 (abstract base 3)

        //Classe 1
#ifndef SPELL_H
#define SPELL_H

#include <iostream>
using std::cout;
using std::ostream;

#include <string>
using std::string;

#include <map>
using std::map;
using std::pair;


class Spell {
public:
    Spell();
    Spell(const Spell &other_spell);
    ~Spell();
    
    inline string getName() const { return name; }
    inline string getDescription() const { return description; }
    inline bool getIs_unlocked() const { return is_unlocked; }
    
    void setName(string name);
    void setDescription(string description);
    inline void setIs_unlocked(bool is_unlocked) { this->is_unlocked = is_unlocked; }

    virtual void print_info() const;

    virtual map<string, int> cast(int technique) = 0;
    
    const Spell &operator=(const Spell &);
    int operator==(const Spell &other_spell) const;
    int operator!=(const Spell &other_spell) const;
protected:
    string name;
    string description;
    bool is_unlocked;
private:
    const static int MAX_NAME_SIZE = 20;
    const static int MAX_DESCRIPTION_SIZE = 100;
};

#endif // SPELL_H

        //Classe 2
#ifndef SIGN_H
#define SIGN_H

#include "../Spell.h"


class Sign : public Spell{
public:
    Sign();
    Sign(const Sign &other_sign);
    ~Sign();

    inline int getStamina_cost() const { return stamina_cost; }

    void setStamina_cost(int stamina_cost);

    void print_info() const;

    virtual map<string, int> cast(int technique) = 0;

    const Sign &operator=(const Sign &);
    int operator==(const Sign &other_sign) const;
    int operator!=(const Sign &other_sign) const;
protected:
    int stamina_cost;
};


#endif // SIGN_H

        //Classe 3
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

        //E assim por diante

////Implementação de constructores default de cópia

    ///Bases abstract

        //Classe abstract base 1    
Entity::Entity(const Entity &other_entity) {
    //cout << "Copying Entity...\n";
    this->name = other_entity.name;
    this->age = other_entity.age;
    this->coins = other_entity.coins;

    this->is_dead = other_entity.is_dead;
    this->max_health = other_entity.max_health;
    this->health = other_entity.health;
    this->max_stamina = other_entity.max_stamina;
    this->stamina = other_entity.stamina;

    this->category = other_entity.category;
    this->level = other_entity.level;
    this->next_level_xp = other_entity.next_level_xp;
    this->xp = other_entity.xp;
    this->xp_reward = other_entity.xp_reward;

    this->is_stunned = other_entity.is_stunned;

    this->physical_weakness = other_entity.physical_weakness;
    this->fire_weakness = other_entity.fire_weakness;
    this->poison_weakness = other_entity.poison_weakness;
    this->ice_weakness = other_entity.ice_weakness;
    this->silver_weakness = other_entity.silver_weakness;

    this->total_physical_resistance = other_entity.total_physical_resistance;
    this->total_fire_resistance = other_entity.total_fire_resistance;
    this->total_poison_resistance = other_entity.total_poison_resistance;
    this->total_ice_resistance = other_entity.total_ice_resistance;
    this->total_silver_resistance = other_entity.total_silver_resistance;

    for (auto sword : other_entity.inventory.swords) {
        Sword * new_sword = new Sword(*sword);
        this->inventory.swords.push_back(new_sword);
    }
    for (auto armor : other_entity.inventory.armors) {
        Armor * new_armor = new Armor(*armor);
        this->inventory.armors.push_back(new_armor);
    }

}
        //Classe abstract base 2
Item::Item(const Item &other_Item) {
    this->name = other_Item.name;
    this->description = other_Item.description;
}

        //Classe abstract base 3
Spell::Spell(const Spell &other_spell) {
    this->name = other_spell.name;
    this->description = other_spell.description;
    this->is_unlocked = other_spell.is_unlocked;
}

    ////Classes concretas - mostrar reaproveitamento de código

        /// Hierarquia 1 (abstract base 1)

            //Classe - concrete 
// O Humano reaproveita os atributos
// protected:
    // relacionados a identidade
    string name;
    int age;
    double coins;
    // vida e estamina
    int max_health;
    int health;
    int max_stamina;
    int stamina;
    // relacionados ao nivel
    string category;
    int level;
    int next_level_xp;
    int xp;
    // status temporario
    bool is_stunned = false;
    // capacidade de possuir um inventario de outras classes
    // descendentes de "item"
    inventory_items inventory;
    struct inventory_items {
    vector<Sword*> swords;
    vector<Armor*> armors;
    };
    // fraquezas
    int physical_weakness;
    int fire_weakness;
    int poison_weakness;
    int ice_weakness;
    int silver_weakness;
    // resistencias
    int total_physical_resistance;
    int total_fire_resistance;
    int total_poison_resistance;
    int total_ice_resistance;
    int total_silver_resistance;
    // e algumas variaveis estaticas que sao comuns a todas as classes
    const static string CATEGORIES[7];
    const static int MAX_NAME_SIZE = 20;
    Date date_of_birth;

    const static int NEXT_LEVEL_XP_LINEAR_COEF = 10;
    const static int NEXT_LEVEL_XP_ANGULAR_COEF = 10;

    // bem como metodos para:
    // regenerar vida e estamina e ganhar xp para subir de nivel
    void life_regen(int);
    void stamina_regen(int);
    void gain_xp(int);

    // metodos para adicionar e remover itens do inventario
    // add an item and deletes it
    void add_item(Item &);
    // just deletes an inventory item
    void remove_item(int item_type, int item_index);

    // add an item from a source and deletes it
    void grab_item(vector<Item*> &source_items, int item_index = 0);
    // remove an item and put it somewhere
    void drop_item(vector<Item*> &destiny_items, int item_type, int item_index);

    // e metodo para receber dano
    void receive_damage(int physical_damage, 
                        int fire_damage = 0, 
                        int poison_damage = 0, 
                        int ice_damage = 0, 
                        int silver_damage = 0);
    // e o ser humano se especializa na capacidade de equipar 
    // itens do inventario
    //protected:
    equipped_items equipped;

    struct equipped_items {
        Sword* steel_sword; 
        Armor* armor;
    };
    // metodos que usam o item ao equipar e removem o bonus ao desequipar
    void Human::equip_item(int item_type, int item_index) {
    if (item_type == SWORD) {
        if (item_index < 0 || item_index >= inventory.swords.size()) {
            cout << "Invalid sword index.\n";
            return;
        }
        if (equipped.steel_sword != 0) {
            cout << "Unequipped " << *equipped.steel_sword << ".\n";
            unequip_item(item_type);
        }
        equipped.steel_sword = new Sword(*inventory.swords[item_index]);
        cout << "Equipped " << *equipped.steel_sword << ".\n";
        delete inventory.swords[item_index];
        inventory.swords.erase(inventory.swords.begin() + item_index);
    }
    else if (item_type == ARMOR) {
        if (item_index < 0 || item_index >= inventory.armors.size()) {
            cout << "Invalid armor index.\n";
            return;
        }
        if (equipped.armor != 0) {
            cout << "Unequipped " << *equipped.armor << ".\n";
            unequip_item(item_type);
        }
        equipped.armor = new Armor(*inventory.armors[item_index]);
        cout << "Equipped " << *equipped.armor << ".\n";
        delete inventory.armors[item_index];
        inventory.armors.erase(inventory.armors.begin() + item_index);
        update_all_resistances();
    }
    else {
        cout << "Item type not recognized.\n";
    }
}

void Human::unequip_item(int item_type) {
    if (item_type == SWORD) {
        if (equipped.steel_sword == 0) {
            cout << "No sword equipped.\n";
            return;
        }
        add_item(*equipped.steel_sword);
        equipped.steel_sword = 0;
    }
    else if (item_type == ARMOR) {
        if (equipped.armor == 0) {
            cout << "No armor equipped.\n";
            return;
        }
        add_item(*equipped.armor);
        equipped.armor = 0;
        update_all_resistances();
    }
    else {
        cout << "Item type not recognized.\n";
    }
}
    // tambem possui sua forma de aumentar seus atributos baseado
    // em coeficientes globais para uma equação linear em função do level
    //private:
    const static int HEALTH_LINEAR_COEF = 5;
    const static int HEALTH_ANGULAR_COEF = 3;

    const static int STAMINA_LINEAR_COEF = 5;
    const static int STAMINA_ANGULAR_COEF = 3;

void Human::level_up() {
    level++;
    
    update_atributes();

    life_regen(max_health);
    stamina_regen(max_stamina);

    }

void Human::update_atributes() {
    next_level_xp = NEXT_LEVEL_XP_LINEAR_COEF + NEXT_LEVEL_XP_ANGULAR_COEF * level;
    max_health = HEALTH_LINEAR_COEF + HEALTH_ANGULAR_COEF * level;
    max_stamina = STAMINA_LINEAR_COEF + STAMINA_ANGULAR_COEF * level;
}
        
            //Classe 2 - concrete
// O Ghoul reaproveita os mesmos atributos e metodos de entity
        // que o humano, pois são descendentes diretos de entity
        // e o ghoul se especializa em seu:
        // attack, que é puramente virtual em entity,
    void Ghoul::attack(Entity &entity, int weapon_type) {
    if (!spend_stamina(GHOUL_ATTACK_COST)) {
        return;
    }
    cout << name << " attacked " << entity.getName() << ".\n";
    // Dano aleatorio entre MIN_GHOUL_DAMAGE e MAX_GHOUL_DAMAGE
    srand(static_cast<unsigned int>(time(nullptr)));
    int damage = MIN_GHOUL_DAMAGE + rand() % (MAX_GHOUL_DAMAGE - MIN_GHOUL_DAMAGE + 1);
    // depois de gerar o dano aleatorio adiciona o level do Ghoul

    damage = damage + getLevel();
    entity.receive_damage(damage);

    return;
}
        // e receive_damage no qual pode se enfurecer caso chegue em 10% de vida
        // ganhando um bonus de defesa
    void Ghoul::receive_damage(int physical_damage, int fire_damage, int poison_damage, int ice_damage, int silver_damage) {
    Entity::receive_damage(physical_damage, fire_damage, poison_damage, ice_damage, silver_damage);
    
    if (getHealth() < getMax_health() * 0.1 && !is_enraged) {
        if (!is_enraged) {
            setIs_enraged(true);
        }
    }
    
    return;
}
            // Classe 3 - concrete
// O Witcher deriva de Human, todos os seus atributos protected
        // e se especializa em:
        // possuir um bau pessoal de itens
        map<string, Item*> personal_chest;
        // que só pode acessar ao estar perto dele
        bool is_close_to_chest;
        // podendo guardar itens
        void Witcher::store_item(int item_type, int item_index) {
    if (!is_close_to_chest) {
        cout << "You are not close to the personal chest.\n";
        return;
    }
    // Checks if item_type is valid for existing items
    if (item_type < 0 || item_type > 1) {
        cout << "Item type not found.\n";
        return;
    }
    // Checks if item_index is valid for corresponding inventory section
    if (item_type == SWORD) {
        if (item_index < 0 || item_index >= inventory.swords.size() ) {
            cout << "Item not found.\n";
            return;
        }
        personal_chest[this->inventory.swords[item_index]->getName()] = this->inventory.swords[item_index];
    }
    else if (item_type == ARMOR) {
        if (item_index < 0 || item_index >= inventory.armors.size() ) {
            cout << "Item not found.\n";
            return;
        }
        personal_chest[this->inventory.armors[item_index]->getName()] = this->inventory.armors[item_index];
    }
    else {
        cout << "Item not found.\n";
        return;
    }
}
        // e retirar itens
        void Witcher::unstore_item(string item_name) {
    if (!is_close_to_chest) {
        cout << "You are not close to the personal chest.\n";
        return;
    }
    if (personal_chest.find(item_name) == personal_chest.end()) {
        cout << "Item not found.\n";
        return;
    }
    if (Sword * sword = dynamic_cast<Sword *>(personal_chest[item_name])) {
        this->inventory.swords.push_back(sword);
        delete sword;
    }
    else if (Armor * armor = dynamic_cast<Armor *>(personal_chest[item_name])) {
        this->inventory.armors.push_back(armor);
        delete armor;
    }
    else {
        cout << "Item not deleted.\n";
    }
    personal_chest.erase(item_name);
}

void Witcher::print_personal_chest() const {
    for (auto const& x : personal_chest)
    {
        cout << x.first << ':'; // string (key)
        x.second->print_info(); // string's value 
        cout << "\n";
    }
}
        // tambem evolui atributos baseado em equação linear
        // em função do nivel
    //private:
    const static int HEALTH_LINEAR_COEF = 10;
    const static int HEALTH_ANGULAR_COEF = 5;
    
    const static int STAMINA_LINEAR_COEF = 10;
    const static int STAMINA_ANGULAR_COEF = 5;

void Witcher::update_atributes() {
    max_health = HEALTH_LINEAR_COEF + HEALTH_ANGULAR_COEF * level;
    max_stamina = STAMINA_LINEAR_COEF + STAMINA_ANGULAR_COEF * level;
}

        // possui metodo de salvar e carregar seu inventario

void Witcher::save_inventory(string name_file_swords, string name_file_armors) {
    // First creates a buffer map to store the atributes of each item
    map<string, string> items_atributes_buffer;
    // First save the swords
    ofstream output_file(name_file_swords);
    if (!output_file.is_open()) {
        cerr << "Error opening file." << '\n';
        return; // Exit with an error code
    }

    for (auto sword : this->inventory.swords) {
        items_atributes_buffer["name"] = sword->getName();
        items_atributes_buffer["description"] = sword->getDescription();
        items_atributes_buffer["physical_damage"] = to_string(sword->getPhysical_damage());
        items_atributes_buffer["fire_damage"] = to_string(sword->getFire_damage());
        items_atributes_buffer["poison_damage"] = to_string(sword->getPoison_damage());
        items_atributes_buffer["ice_damage"] = to_string(sword->getIce_damage());
        items_atributes_buffer["silver_damage"] = to_string(sword->getSilver_damage());
        // Convert string spaces from string atributes to underscores
        // so that the file can be read again
        for (auto &x : items_atributes_buffer) {
            replace(x.second.begin(), x.second.end(), ' ', '_');
        }
        // Stores values in buffer iteratively
        for (auto const& x : items_atributes_buffer) {
            output_file << x.first << " = " << x.second << '\n';
        }
        // Stores next item separator
        output_file << "next = item\n";
        items_atributes_buffer.clear();
    }
    // Closes swords file
    output_file.close();

    // Then save the armors
    // Reuse same ofstream variable
    output_file.open(name_file_armors);
        if (!output_file.is_open()) {
        cerr << "Error opening file." << '\n';
        return; // Exit with an error code
    }

    for (auto armor : this->inventory.armors) {
        items_atributes_buffer["name"] = armor->getName();
        items_atributes_buffer["description"] = armor->getDescription();
        items_atributes_buffer["physical_defense"] = to_string(armor->getPhysical_defense());
        items_atributes_buffer["fire_defense"] = to_string(armor->getFire_defense());
        items_atributes_buffer["poison_defense"] = to_string(armor->getPoison_defense());
        items_atributes_buffer["ice_defense"] = to_string(armor->getIce_defense());
        items_atributes_buffer["silver_defense"] = to_string(armor->getSilver_defense());
        // Convert string spaces from string atributes to underscores
        // so that the file can be read again
        for (auto &x : items_atributes_buffer) {
            replace(x.second.begin(), x.second.end(), ' ', '_');
        }
        // Stores values in buffer iteratively
        for (auto const& x : items_atributes_buffer) {
            output_file << x.first << " = " << x.second << '\n';
        }
        // Stores next item separator
        output_file << "next = item\n";
        items_atributes_buffer.clear();
    }

    // Closes armors file
    output_file.close();
}

void Witcher::load_inventory(string name_file_swords, string name_file_armors) {

    // First creates a buffer map to store the atributes of each item
    map<string, string> items_atributes_buffer;
    // First load the swords
    ifstream input_file(name_file_swords);
    if (!input_file.is_open()) {
        cerr << "Error opening  " << name_file_swords << " file." << '\n';
        return; // Exit with an error code
    }
    // Unpacking variables
    string line;
    string atribute_name;
    char equal_sign;
    string value;

    while (getline(input_file, line)) {
        istringstream line_stream(line);
        line_stream >> atribute_name >> equal_sign >> value;
        // Skips to next sword and stores the previous one
        // reusing the same buffer for all swords
        if (atribute_name == "next" && equal_sign == '=' && value == "item") {
            // Converts underscores from string atributes to spaces
            // so that the string turns back to original form
            for (auto &x : items_atributes_buffer) {
                replace(x.second.begin(), x.second.end(), '_', ' ');
            }
            // Creates a temporary sword and adds it to the inventory
            Sword * new_sword = new Sword(items_atributes_buffer["name"], 
                                    items_atributes_buffer["description"], 
                                    stoi(items_atributes_buffer["physical_damage"]),
                                    stoi(items_atributes_buffer["fire_damage"]),
                                    stoi(items_atributes_buffer["poison_damage"]),
                                    stoi(items_atributes_buffer["ice_damage"]),
                                    stoi(items_atributes_buffer["silver_damage"]));
            // add_item already cleans "new_sword" buffer
            add_item(*new_sword);
            // Cleans buffer variable
            items_atributes_buffer.clear();
        }
        // Stores values in buffer iteratively
        items_atributes_buffer[atribute_name] = value;
    }
    // Closes swords file
    input_file.close();

    // Then load the armors
    // Reuse same ifstream variable
    input_file.open(name_file_armors);
        if (!input_file.is_open()) {
        cerr << "Error opening " << name_file_armors << " file." << '\n';
        return; // Exit with an error code
    }

    while (getline(input_file, line)) {
        istringstream line_stream(line);
        // Reuses same unpacking variables
        line_stream >> atribute_name >> equal_sign >> value;
        // Skips to next armor and stores the previous one
        // reusing the same buffer for all armors
        if (atribute_name == "next" && equal_sign == '=' && value == "item") {
            // Converts underscores from string atributes to spaces
            // so that the string turns back to original form
            for (auto &x : items_atributes_buffer) {
                replace(x.second.begin(), x.second.end(), '_', ' ');
            }
            // Creates a temporary armor and adds it to the inventory
            Armor * new_armor = new Armor(items_atributes_buffer["name"], 
                                    items_atributes_buffer["description"], 
                                    stoi(items_atributes_buffer["physical_defense"]), 
                                    stoi(items_atributes_buffer["fire_defense"]),
                                    stoi(items_atributes_buffer["poison_defense"]),
                                    stoi(items_atributes_buffer["ice_defense"]),
                                    stoi(items_atributes_buffer["silver_defense"]));
            // add_item already cleans "new_armor" buffer
            add_item(*new_armor);
            // Cleans buffer variable
            items_atributes_buffer.clear();
        }
        // Stores values in buffer iteratively
        // Reuses same map
        items_atributes_buffer[atribute_name] = value;
    }
    // Closes armors file
    input_file.close();

    return;
}
        // tambem se especializa no seu ataque possuindo diversas
        // formas de atacar
void Witcher::attack(Entity &entity, int attack_option, int technique) {

    if (!entity) {
        cout << entity.getName() << "is already dead.\n";
        return;
    }

    cout << name << " attacked " << entity.getName() << ".\n";

    // testing stunned inside attack, must be removed later
    if (is_stunned) {
        cout << name << " is stunned and can't attack.\n";
        is_stunned = false;
        return;
    }

    // prepare damage buffer variables to update each damage type
    // and stamina spent acording to what is choosed to attack
    int total_physical_damage = 0;
    int total_fire_damage = 0;
    int total_poison_damage = 0;
    int total_ice_damage = 0;
    int total_silver_damage = 0;

    int stamina_spent = 0;

    map<string, int> sword_info_buffer;
    map<string, int> sign_info_buffer;

    // Random unarmed base damage MIN_WITCHER_DAMAGE and MAX_WITCHER_DAMAGE
    srand(static_cast<unsigned int>(time(nullptr)));
    int bonus_witcher_damage = MIN_WITCHER_DAMAGE + rand() % (MAX_WITCHER_DAMAGE - MIN_WITCHER_DAMAGE + 1);
    // cout << "bonus_witcher_damage: " << bonus_witcher_damage << "\n";

    // First checks if the witcher is unarmed
    switch (attack_option)
    {
    case STEEL_SWORD:
        if (equipped.steel_sword == 0) {
            attack_option = UNARMED;
        }
        break;
    case IGNI:
        if (signs.igni == 0) {
            attack_option = UNARMED;
        }
        if (signs.igni->getIs_unlocked() == false) {
            attack_option = UNARMED;
        }
        break;
    default:
        // If attack_option is invalid, witcher is unarmed
        attack_option = UNARMED;
        break;
    }

    // Then puts each damage type to damage buffer variables
    // according to the respective attack option choosed
    switch (attack_option)
    {
    case UNARMED:
        // Always check stamina first
        if (!spend_stamina(WITCHER_ATTACK_COST)) {
            return;
        }

        cout << name << " is attacking " << entity.getName() << " with his fists.\n";

        total_physical_damage += bonus_witcher_damage;

        break;
    case STEEL_SWORD:
        // uses sword to calculate stamina and damage
        sword_info_buffer = equipped.steel_sword->use();
        
        // Always check stamina first
        if (!spend_stamina(sword_info_buffer["stamina_cost"])) {
            return;
        }
        
        // base damage
        total_physical_damage += bonus_witcher_damage;

        // item damage
        total_physical_damage += sword_info_buffer["physical_damage"];
        // cout << "total_physical_damage: " << sword_info_buffer["physical_damage"] << "\n";

        total_fire_damage += sword_info_buffer["fire_damage"];
        // cout << "total_fire_damage: " << sword_info_buffer["fire_damage"] << "\n";

        total_poison_damage += sword_info_buffer["poison_damage"];
        // cout << "total_poison_damage: " << sword_info_buffer["poison_damage"] << "\n";

        total_ice_damage += sword_info_buffer["ice_damage"];
        // cout << "total_ice_damage: " << sword_info_buffer["ice_damage"] << "\n";

        total_silver_damage += sword_info_buffer["silver_damage"];
        // cout << "total_silver_damage: " << sword_info_buffer["silver_damage"] << "\n";

        break;
    case IGNI:
        cout << "Witcher is casting igni.\n";
        
        // uses igni to calculate stamina and damage
        sign_info_buffer = signs.igni->cast();
        
        // Always check stamina first
        if (!spend_stamina(sign_info_buffer["stamina_cost"])) {
            return;
        }
        
        // sign damage
        total_fire_damage += sign_info_buffer["fire_damage"];
        // cout << "total_fire_damage: " << igni_info_buffer["fire_damage"] << "\n";
        
        break;
    
    }
    

    // After calculating all damage especifically
    // sends it to attacked entity

    entity.receive_damage(total_physical_damage, 
                          total_fire_damage, 
                          total_poison_damage, 
                          total_ice_damage, 
                          total_silver_damage);

    if (!entity) {
        gain_xp(entity.getXp_reward());
        this->coins += entity.getCoins();
        entity.setCoins(0);
    }
    return;
}

            //E assim por diante

        /// Hierarquia 2 (abstract base 1)

            //Classe 1 Abstract 1 que herda da base abstract
                // a classe weapon tambem é abstrata e herda de item as propriedades
        // de possuir nome e descrição
    //protected:
    string name;
    string description;
    // e se especializa em possuir multiplos tipos de dano, pois
    // isso é caracteristico de armas
    //protected:
    int physical_damage;
    int fire_damage;
    int poison_damage;
    int ice_damage;
    int silver_damage;

            //Classe 2 - concrete
// a classe armor herda de item as mesmas caracteristicas que weapon
        // pois descendem diretamente de item
        // e armor se especializa em possuir multiplos tipos de defesa,
        // pois isso é caracteristico desse tipo de item
    // private:
    int physical_defense = 0;
    int fire_defense = 0;
    int poison_defense = 0;
    int ice_defense = 0;
    int silver_defense = 0;

    // e ao ativar seu metodo use() retorna um map com os valores
    // de defesa que serão adicionados ao usuario da armadura
    map<string, int> Armor::use(int technique) {
    // cout << "Using Armor...\n";
    map<string, int> defenses;

    defenses["physical_defense"] = physical_defense;
    defenses["fire_defense"] = fire_defense;
    defenses["poison_defense"] = poison_defense;
    defenses["ice_defense"] = ice_defense;
    defenses["silver_defense"] = silver_defense;
    
    return defenses;
}           
            // Classe 3 - concrete
// a classe sword herda de weapon a capacidade de posuir danos
        // e se especializa em possuir um metodo use() que receber como parametro
        // um determinado tipo de tecnica para aumentar o dano de um determinado
        // usuario
        map<string, int> Sword::use(int technique) {
    // cout << "Using Sword...\n";
    // cout << "Technique: " << technique << "\n";

    map<string, int> info_buffer;
    info_buffer["physical_damage"] = physical_damage;
    info_buffer["fire_damage"] = fire_damage;
    info_buffer["poison_damage"] = poison_damage;
    info_buffer["ice_damage"] = ice_damage;
    info_buffer["silver_damage"] = silver_damage;
    info_buffer["stamina_cost"] = 0;
    info_buffer["area"] = 1;

    switch (technique) {
        case FAST_ATTACK:
            cout << "Fast attack\n";
            info_buffer["stamina_cost"] += 4;
            info_buffer["physical_damage"] -= 1;
            break;
        case STRONG_ATTACK:
            cout << "Strong attack\n";
            info_buffer["stamina_cost"] += 8;
            info_buffer["physical_damage"] += 2;
            break;
        case GROUP_ATTACK:
            cout << "Group attack\n";
            info_buffer["stamina_cost"] += 12;
            info_buffer["physical_damage"] -= 2;
            info_buffer["area"] = 3;
            break;
        default:
            cout << "Invalid attack\n";
            break;
    }

    return info_buffer;
}

            //E assim por diante

        /// Hierarquia 2 (abstract base 1)

            //Classe Abstract 1 
        // a classe sign herda de spell as propriedades de possuir nome,
        // descrição e se estar desbloqueada ou não, para usuários q chegaram
        // a um determinado nivel de conhecimento
    //protected:
    string name;
    string description;
    bool is_unlocked;
        // e se especializa em possuir um custo de estamina para ser ativada
        // pois essa classe de feitiços é considerada simples e não usa um 
        // atributo místico como mana
    // protected:
    int stamina_cost;
        // a partir disso, ela da origem a diversos sinais de propriedades
        // completamente diferentes

         ////Classe 2 - concrete
        // a classe igni herda de sign as mesmas propriedades
        // e se especializa em possuir um dano de fogo e uma area de efeito
    //private:
    int fire_damage;
    int area;
        // e um metodo para conceder esse dano ao usuario
        map<string, int> Igni::cast(int technique) {

    map<string, int> sign_info;

    sign_info["is_unlocked"] = is_unlocked;
    sign_info["fire_damage"] = fire_damage;
    sign_info["area"] = area;
    sign_info["stamina_cost"] = stamina_cost;

    return sign_info;
}

            //E assim por diante

//// Mostrar implementação dos métodos virtuais puros nas classes concretas
 /// Mostrar reaproveitamente de código da base

    /// Hierarquia 1
         //Base - métodos virtuais puros
        // A classe abstrata Entity possui os seguinte metodos virtuais:
    virtual void level_up() = 0;
    virtual void update_atributes() = 0;
    virtual void update_all_resistances() = 0;
    virtual void update_all_weaknesses() = 0;
    virtual void attack(Entity &, int, int) = 0;

         //Classe concrete 1
         // Human implementa da seguinte forma

void Human::update_all_resistances() {
    if (equipped.armor != 0) {
        map<string, int> defenses_buffer = equipped.armor->use();
        setTotal_physical_resistance(defenses_buffer["physical_defense"]);
        setTotal_fire_resistance(defenses_buffer["fire_defense"]);
        setTotal_poison_resistance(defenses_buffer["poison_defense"]);
        setTotal_ice_resistance(defenses_buffer["ice_defense"]);
        setTotal_silver_resistance(defenses_buffer["silver_defense"]);
    }
    else {
        setTotal_physical_resistance(0);
        setTotal_fire_resistance(0);
        setTotal_poison_resistance(0);
        setTotal_ice_resistance(0);
        setTotal_silver_resistance(0);
    }
}

void Human::update_all_weaknesses() {
    physical_weakness = 1;
    fire_weakness = 1;
    poison_weakness = 1;
    ice_weakness = 1;
    silver_weakness = 0;
}

void Human::level_up() {
    level++;
    cout << "Level up! " << name << " is now level " << this->level << ".\n";
    Entity::update_global_danger(level);

    update_atributes();

    life_regen(max_health);
    stamina_regen(max_stamina);

}

void Human::update_atributes() {
    next_level_xp = NEXT_LEVEL_XP_LINEAR_COEF + NEXT_LEVEL_XP_ANGULAR_COEF * level;
    max_health = HEALTH_LINEAR_COEF + HEALTH_ANGULAR_COEF * level;
    max_stamina = STAMINA_LINEAR_COEF + STAMINA_ANGULAR_COEF * level;
    xp_reward = level * NEXT_LEVEL_XP_ANGULAR_COEF / 2;
}

void Human::receive_damage(int physical_damage, int fire_damage, int poison_damage, int ice_damage, int silver_damage) {
    Entity::receive_damage(physical_damage, fire_damage, poison_damage, ice_damage, silver_damage);
}

inline void Human::attack(Entity &entity, int weapon_type, int technique) { cout << "Human is too weak and afraid to attack " << entity.getName() << ".\n"; }


         //Classe concrete 2
        // Ghoul implementa da seguinte forma:

void Ghoul::level_up() {
    level++;
    Entity::update_global_danger(level);

    update_atributes();

    life_regen(max_health);
    stamina_regen(max_stamina);

}

void Ghoul::update_atributes() {
    next_level_xp = NEXT_LEVEL_XP_LINEAR_COEF + NEXT_LEVEL_XP_ANGULAR_COEF * level;
    max_health = HEALTH_LINEAR_COEF + HEALTH_ANGULAR_COEF * level;
    max_stamina = STAMINA_LINEAR_COEF + STAMINA_ANGULAR_COEF * level;
    xp_reward = level * NEXT_LEVEL_XP_ANGULAR_COEF / 2;
}

void Ghoul::update_all_resistances() {
    total_physical_resistance = 0;
    total_fire_resistance = 0;
    total_poison_resistance = 0;
    total_ice_resistance = 0;
    total_silver_resistance = 0;

    if (is_enraged) {
        setTotal_physical_resistance(getTotal_physical_resistance() + 1);
    }
}

void Ghoul::update_all_weaknesses() {
    physical_weakness = 1;
    fire_weakness = 1;
    poison_weakness = 1;
    ice_weakness = 1;
    silver_weakness = 1;
}

void Ghoul::attack(Entity &entity, int weapon_type, int technique) {
    if (!spend_stamina(GHOUL_ATTACK_COST)) {
        return;
    }
    cout << name << " attacked " << entity.getName() << ".\n";
    // Dano aleatorio entre MIN_GHOUL_DAMAGE e MAX_GHOUL_DAMAGE
    srand(static_cast<unsigned int>(time(nullptr)));
    int damage = MIN_GHOUL_DAMAGE + rand() % (MAX_GHOUL_DAMAGE - MIN_GHOUL_DAMAGE + 1);
    // depois de gerar o dano aleatorio adiciona o level do Ghoul

    damage = damage + getLevel();
    entity.receive_damage(damage);

    return;
}

void Ghoul::receive_damage(int physical_damage, int fire_damage, int poison_damage, int ice_damage, int silver_damage) {
    Entity::receive_damage(physical_damage, fire_damage, poison_damage, ice_damage, silver_damage);

    if (getHealth() < getMax_health() * 0.1 && !this->is_dead) {
        if (!is_enraged) {
            setIs_enraged(true);
        }
    }
    return;
}

        // Classe 3 - concrete
        // Witcher implementa da seguinte forma:

void Witcher::update_atributes() {
    next_level_xp = NEXT_LEVEL_XP_LINEAR_COEF + NEXT_LEVEL_XP_ANGULAR_COEF * level;
    max_health = HEALTH_LINEAR_COEF + HEALTH_ANGULAR_COEF * level;
    max_stamina = STAMINA_LINEAR_COEF + STAMINA_ANGULAR_COEF * level;
    xp_reward = NEXT_LEVEL_XP_ANGULAR_COEF * level / 2;
}

void Witcher::attack(Entity &entity, int attack_option, int technique) {

    if (!entity) {
        cout << entity.getName() << "is already dead.\n";
        return;
    }

    cout << name << " attacked " << entity.getName() << ".\n";

    // testing stunned inside attack, must be removed later
    if (is_stunned) {
        cout << name << " is stunned and can't attack.\n";
        is_stunned = false;
        return;
    }

    // prepare damage buffer variables to update each damage type
    // and stamina spent acording to what is choosed to attack
    int total_physical_damage = 0;
    int total_fire_damage = 0;
    int total_poison_damage = 0;
    int total_ice_damage = 0;
    int total_silver_damage = 0;

    int stamina_spent = 0;

    map<string, int> sword_info_buffer;
    map<string, int> sign_info_buffer;

    // Random unarmed base damage MIN_WITCHER_DAMAGE and MAX_WITCHER_DAMAGE
    srand(static_cast<unsigned int>(time(nullptr)));
    int bonus_witcher_damage = MIN_WITCHER_DAMAGE + rand() % (MAX_WITCHER_DAMAGE - MIN_WITCHER_DAMAGE + 1);
    // cout << "bonus_witcher_damage: " << bonus_witcher_damage << "\n";

    // First checks if the witcher is unarmed
    switch (attack_option)
    {
    case STEEL_SWORD:
        if (equipped.steel_sword == 0) {
            attack_option = UNARMED;
        }
        break;
    case IGNI:
        if (signs.igni == 0) {
            attack_option = UNARMED;
        }
        if (signs.igni->getIs_unlocked() == false) {
            attack_option = UNARMED;
        }
        break;
    default:
        // If attack_option is invalid, witcher is unarmed
        attack_option = UNARMED;
        break;
    }

    // Then puts each damage type to damage buffer variables
    // according to the respective attack option choosed
    switch (attack_option)
    {
    case UNARMED:
        // Always check stamina first
        if (!spend_stamina(WITCHER_ATTACK_COST)) {
            return;
        }

        cout << name << " is attacking " << entity.getName() << " with his fists.\n";

        total_physical_damage += bonus_witcher_damage;

        break;
    case STEEL_SWORD:
        // uses sword to calculate stamina and damage
        sword_info_buffer = equipped.steel_sword->use();
        
        // Always check stamina first
        if (!spend_stamina(sword_info_buffer["stamina_cost"])) {
            return;
        }
        
        // base damage
        total_physical_damage += bonus_witcher_damage;

        // item damage
        total_physical_damage += sword_info_buffer["physical_damage"];
        // cout << "total_physical_damage: " << sword_info_buffer["physical_damage"] << "\n";

        total_fire_damage += sword_info_buffer["fire_damage"];
        // cout << "total_fire_damage: " << sword_info_buffer["fire_damage"] << "\n";

        total_poison_damage += sword_info_buffer["poison_damage"];
        // cout << "total_poison_damage: " << sword_info_buffer["poison_damage"] << "\n";

        total_ice_damage += sword_info_buffer["ice_damage"];
        // cout << "total_ice_damage: " << sword_info_buffer["ice_damage"] << "\n";

        total_silver_damage += sword_info_buffer["silver_damage"];
        // cout << "total_silver_damage: " << sword_info_buffer["silver_damage"] << "\n";

        break;
    case IGNI:
        cout << "Witcher is casting igni.\n";
        
        // uses igni to calculate stamina and damage
        sign_info_buffer = signs.igni->cast();
        
        // Always check stamina first
        if (!spend_stamina(sign_info_buffer["stamina_cost"])) {
            return;
        }
        
        // sign damage
        total_fire_damage += sign_info_buffer["fire_damage"];
        // cout << "total_fire_damage: " << igni_info_buffer["fire_damage"] << "\n";
        
        break;
    
    }
    

    // After calculating all damage especifically
    // sends it to attacked entity

    entity.receive_damage(total_physical_damage, 
                          total_fire_damage, 
                          total_poison_damage, 
                          total_ice_damage, 
                          total_silver_damage);

    if (!entity) {
        gain_xp(entity.getXp_reward());
        this->coins += entity.getCoins();
        entity.setCoins(0);
    }
    return;
}

         //E assim por diante

    /// Hierarquia 2

         //Base - métodos virtuais puros
         // Item possui o seguinte método virtual puro:
        virtual map<string, int> use(int technique) = 0;
  
         //Classe concrete 1
        // Armor implementa da seguinte forma:

map<string, int> Armor::use(int technique) {
    // cout << "Using Armor...\n";
    map<string, int> defenses;

    defenses["physical_defense"] = physical_defense;
    defenses["fire_defense"] = fire_defense;
    defenses["poison_defense"] = poison_defense;
    defenses["ice_defense"] = ice_defense;
    defenses["silver_defense"] = silver_defense;
    
    return defenses;
}

         //Classe concrete 2

map<string, int> Sword::use(int technique) {
    // cout << "Using Sword...\n";
    // cout << "Technique: " << technique << "\n";

    map<string, int> info_buffer;
    info_buffer["physical_damage"] = physical_damage;
    info_buffer["fire_damage"] = fire_damage;
    info_buffer["poison_damage"] = poison_damage;
    info_buffer["ice_damage"] = ice_damage;
    info_buffer["silver_damage"] = silver_damage;
    info_buffer["stamina_cost"] = 0;
    info_buffer["area"] = 1;

    switch (technique) {
        case FAST_ATTACK:
            cout << "Fast attack\n";
            info_buffer["stamina_cost"] += 4;
            info_buffer["physical_damage"] -= 1;
            break;
        case STRONG_ATTACK:
            cout << "Strong attack\n";
            info_buffer["stamina_cost"] += 8;
            info_buffer["physical_damage"] += 2;
            break;
        case GROUP_ATTACK:
            cout << "Group attack\n";
            info_buffer["stamina_cost"] += 12;
            info_buffer["physical_damage"] -= 2;
            info_buffer["area"] = 3;
            break;
        default:
            cout << "Invalid attack\n";
            break;
    }

    return info_buffer;
}

         //E assim por diante


    /// Hierarquia 3

         //Base - métodos virtuais puros
        // Spell possui o seguinte método virtual puro:
        virtual map<string, int> cast(int technique) = 0;
         //Classe Abstract 1
        // Sign não implementa mas mantem o método abstrato
        virtual map<string, int> cast(int technique) = 0;
         //Classe concrete 2
        // Igni implementa da seguinte forma:
        virtual map<string, int> cast(int technique = FIRE_BALL);
    map<string, int> Igni::cast(int technique) {

    map<string, int> sign_info;

    sign_info["is_unlocked"] = is_unlocked;
    sign_info["fire_damage"] = fire_damage;
    sign_info["area"] = area;
    sign_info["stamina_cost"] = stamina_cost;

    return sign_info;
}
         //E assim por diante

//// Em uma das hierarquias deve haver alocação de memória usando um vector< ptr * >, 
// onde ptr é um ponteiro de uma de
//suas classes criadas que tem relação de composição.

    /// Mostrar .h com este vector (com apenas ele presente) usando "..." para omitir
    //o resto
    #ifndef ENTITY_H
#define ENTITY_H

...

enum options {
    AUTO = -1
};

enum item_type {
    // NONE = -1,
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

    ...

    // add an item and deletes it
    void add_item(Item &);
    // just deletes an inventory item
    void remove_item(int item_type, int item_index);

    // add an item from a source and deletes it
    void grab_item(vector<Item*> &source_items, int item_index = 0);
    // remove an individual item and put it somewhere
    void drop_item(vector<Item*> &destiny_items, int item_type, int item_index);
    // remove all items and put them somewhere
    virtual void drop_all_items(vector<Item*> &floor_items);

    ...

protected:
    ... 
    inventory_items inventory;
...
};
#endif // ENTITY_H

#ifndef HUMAN_H
#define HUMAN_H

#include <iostream>
#include <string>

#include "../Entity.h"

...

enum attack_options {
    UNARMED = 0,
    // Weapons
    STEEL_SWORD = 1,
    SILVER_SWORD = 2,
    CROSSBOW = 3,
    // Signs
    IGNI = 4
};


struct equipped_items {
    Sword* steel_sword; 
    Armor* armor;
};

class Human: public Entity {
    ...
public:

    ...

    virtual void equip_item(int item_type, int item_index);
    virtual void unequip_item(int item_type);
    virtual void print_equipped_items();

    ...

    virtual void drop_all_items(vector<Item*> &floor_items);

protected:
    equipped_items equipped;
...

#endif // HUMAN_H


    /// Mostrar inicialização do vector 
    // o inventario começa vazio, mas alguns personagens começam com itens Equipped
    // uma struct q se comunica com o inventory
    Witcher::Witcher(string name, 
                 int age, 
                 double coins, 
                 int level,
                 string category) {
                
    ...

    equipped.steel_sword = new Sword("Witcher Sword", "An special sword good against monsters", 5, 1, 1, 1, 6);
    equipped.armor = new Armor("Witcher Armor", "An special armor that protects agains monsters", 7, 3, 2, 2, 2);
    
    ...
}

    /// Mostrar o método que aplica new nele
    // os métodos que acessam o inventario são:

void Entity::add_item(Item &item) {
    // First checks if Entity is dead:
    if (!*this) {
        cout << this->name << " is dead. Cannot add item.\n";
        return;
    }
    // adds to inventory acording to item type
    if (Sword * sword = dynamic_cast<Sword *>(&item)) {
        Sword * new_sword = new Sword(*sword);
        inventory.swords.push_back(new_sword);
    }
    if (Armor * armor = dynamic_cast<Armor *>(&item)) {
        Armor * new_armor = new Armor(*armor);
        inventory.armors.push_back(new_armor);
    }
    // and deletes the item from the source
    delete &item;
}

void Entity::remove_item(int item_type, int item_index) {
    // deletes item and updates the inventory indexes
    // according to item type
    if (item_type == SWORD) {
        if (item_index < 0 || item_index >= inventory.swords.size()) {
            cout << "Invalid sword index.\n";
            return;
        }
        delete inventory.swords[item_index];
        inventory.swords.erase(inventory.swords.begin() + item_index);
    }
    else if (item_type == ARMOR) {
        if (item_index < 0 || item_index >= inventory.armors.size()) {
            cout << "Invalid armor index.\n";
            return;
        }
        delete inventory.armors[item_index];
        inventory.armors.erase(inventory.armors.begin() + item_index);
    }
    else {
        cout << "Invalid item type.\n";
        return;
    }
}

void Entity::grab_item(vector<Item *> &source_items, int item_index) {
    // First checks if Entity is dead:
    if (!*this) {
        cout << this->name << " is dead. Cannot grab item.\n";
        return;
    }
    if (item_index < 0 || item_index >= source_items.size()) {
        cout << "Invalid item index.\n";
        return;
    }
    // prints the action message
    cout << this->name << " grabs " << source_items[item_index]->getName() << ".\n";
    // adds to inventory and deletes the item from source
    add_item(*source_items[item_index]);
    // updates the source indexes
    source_items.erase(source_items.begin() + item_index);
}

void Entity::drop_item(vector<Item *> &destiny_items, int item_type, int item_index) {
    // adds to destiny acording to item type
    if (item_type == SWORD) {
        if (item_index < 0 || item_index >= inventory.swords.size()) {
            cout << "Invalid sword index.\n";
            return;
        }
        Sword * dropped_sword = new Sword(*inventory.swords[item_index]);
        destiny_items.push_back(dropped_sword);
    }
    else if (item_type == ARMOR) {
        if (item_index < 0 || item_index >= inventory.armors.size()) {
            cout << "Invalid armor index.\n";
            return;
        }
        Armor * dropped_armor = new Armor(*inventory.armors[item_index]);
        destiny_items.push_back(dropped_armor);
    }
    else {
        cout << "Invalid item type.\n";
        return;
    }
    // removes from inventory
    remove_item(item_type, item_index);
}

void Entity::drop_all_items(vector<Item *> &floor_items) {
    // dropping by accessing the inventory directly
    // (may be changed latter to use the drop_item function)

    // drops all items with safe memory deallocation
    for (auto sword : inventory.swords) {
        drop_item(floor_items, SWORD, 0);
    }
    for (auto armor : inventory.armors) {
        drop_item(floor_items, ARMOR, 0);
    }

    // clears inventory
    inventory.swords.clear();
    inventory.armors.clear();
}

void Human::equip_item(int item_type, int item_index) {
    if (item_type == SWORD) {
        if (item_index < 0 || item_index >= inventory.swords.size()) {
            cout << "Invalid sword index.\n";
            return;
        }
        if (equipped.steel_sword != 0) {
            cout << "Unequipped " << *equipped.steel_sword << ".\n";
            unequip_item(item_type);
        }
        equipped.steel_sword = new Sword(*inventory.swords[item_index]);
        cout << "Equipped " << *equipped.steel_sword << ".\n";
        delete inventory.swords[item_index];
        inventory.swords.erase(inventory.swords.begin() + item_index);
    }
    else if (item_type == ARMOR) {
        if (item_index < 0 || item_index >= inventory.armors.size()) {
            cout << "Invalid armor index.\n";
            return;
        }
        if (equipped.armor != 0) {
            cout << "Unequipped " << *equipped.armor << ".\n";
            unequip_item(item_type);
        }
        equipped.armor = new Armor(*inventory.armors[item_index]);
        cout << "Equipped " << *equipped.armor << ".\n";
        delete inventory.armors[item_index];
        inventory.armors.erase(inventory.armors.begin() + item_index);
        update_all_resistances();
    }
    else {
        cout << "Item type not recognized.\n";
    }
}

void Human::unequip_item(int item_type) {
    if (item_type == SWORD) {
        if (equipped.steel_sword == 0) {
            cout << "No sword equipped.\n";
            return;
        }
        add_item(*equipped.steel_sword);
        equipped.steel_sword = 0;
    }
    else if (item_type == ARMOR) {
        if (equipped.armor == 0) {
            cout << "No armor equipped.\n";
            return;
        }
        add_item(*equipped.armor);
        equipped.armor = 0;
        update_all_resistances();
    }
    else {
        cout << "Item type not recognized.\n";
    }
}

    /// Mostrar método em que ele é usado efetivamente
    // preenchimento, set e get serão ignorados
    // O objetivo do inventário é armazenar itens e gerenciar o que é equipado
    // e o que não é, dessa forma o jogador só pode usar aquilo que está equipado.
    // outra importancia do inventario é permitir que uma Entity obtenha os itens da
    // caso ela seja derrotada, portanto os métodos abaixo representam o uso efetivo
    // do inventario:
    void Entity::add_item(Item &item) {
    // First checks if Entity is dead:
    if (!*this) {
        cout << this->name << " is dead. Cannot add item.\n";
        return;
    }
    // adds to inventory acording to item type
    if (Sword * sword = dynamic_cast<Sword *>(&item)) {
        Sword * new_sword = new Sword(*sword);
        inventory.swords.push_back(new_sword);
    }
    if (Armor * armor = dynamic_cast<Armor *>(&item)) {
        Armor * new_armor = new Armor(*armor);
        inventory.armors.push_back(new_armor);
    }
    // and deletes the item from the source
    delete &item;
}

void Entity::remove_item(int item_type, int item_index) {
    // deletes item and updates the inventory indexes
    // according to item type
    if (item_type == SWORD) {
        if (item_index < 0 || item_index >= inventory.swords.size()) {
            cout << "Invalid sword index.\n";
            return;
        }
        delete inventory.swords[item_index];
        inventory.swords.erase(inventory.swords.begin() + item_index);
    }
    else if (item_type == ARMOR) {
        if (item_index < 0 || item_index >= inventory.armors.size()) {
            cout << "Invalid armor index.\n";
            return;
        }
        delete inventory.armors[item_index];
        inventory.armors.erase(inventory.armors.begin() + item_index);
    }
    else {
        cout << "Invalid item type.\n";
        return;
    }
}

void Entity::grab_item(vector<Item *> &source_items, int item_index) {
    // First checks if Entity is dead:
    if (!*this) {
        cout << this->name << " is dead. Cannot grab item.\n";
        return;
    }
    if (item_index < 0 || item_index >= source_items.size()) {
        cout << "Invalid item index.\n";
        return;
    }
    // prints the action message
    cout << this->name << " grabs " << source_items[item_index]->getName() << ".\n";
    // adds to inventory and deletes the item from source
    add_item(*source_items[item_index]);
    // updates the source indexes
    source_items.erase(source_items.begin() + item_index);
}

void Entity::drop_item(vector<Item *> &destiny_items, int item_type, int item_index) {
    // adds to destiny acording to item type
    if (item_type == SWORD) {
        if (item_index < 0 || item_index >= inventory.swords.size()) {
            cout << "Invalid sword index.\n";
            return;
        }
        Sword * dropped_sword = new Sword(*inventory.swords[item_index]);
        destiny_items.push_back(dropped_sword);
    }
    else if (item_type == ARMOR) {
        if (item_index < 0 || item_index >= inventory.armors.size()) {
            cout << "Invalid armor index.\n";
            return;
        }
        Armor * dropped_armor = new Armor(*inventory.armors[item_index]);
        destiny_items.push_back(dropped_armor);
    }
    else {
        cout << "Invalid item type.\n";
        return;
    }
    // removes from inventory
    remove_item(item_type, item_index);
}

void Entity::drop_all_items(vector<Item *> &floor_items) {
    // dropping by accessing the inventory directly
    // (may be changed latter to use the drop_item function)

    // drops all items with safe memory deallocation
    for (auto sword : inventory.swords) {
        drop_item(floor_items, SWORD, 0);
    }
    for (auto armor : inventory.armors) {
        drop_item(floor_items, ARMOR, 0);
    }

    // clears inventory
    inventory.swords.clear();
    inventory.armors.clear();
}

void Human::equip_item(int item_type, int item_index) {
    if (item_type == SWORD) {
        if (item_index < 0 || item_index >= inventory.swords.size()) {
            cout << "Invalid sword index.\n";
            return;
        }
        if (equipped.steel_sword != 0) {
            cout << "Unequipped " << *equipped.steel_sword << ".\n";
            unequip_item(item_type);
        }
        equipped.steel_sword = new Sword(*inventory.swords[item_index]);
        cout << "Equipped " << *equipped.steel_sword << ".\n";
        delete inventory.swords[item_index];
        inventory.swords.erase(inventory.swords.begin() + item_index);
    }
    else if (item_type == ARMOR) {
        if (item_index < 0 || item_index >= inventory.armors.size()) {
            cout << "Invalid armor index.\n";
            return;
        }
        if (equipped.armor != 0) {
            cout << "Unequipped " << *equipped.armor << ".\n";
            unequip_item(item_type);
        }
        equipped.armor = new Armor(*inventory.armors[item_index]);
        cout << "Equipped " << *equipped.armor << ".\n";
        delete inventory.armors[item_index];
        inventory.armors.erase(inventory.armors.begin() + item_index);
        update_all_resistances();
    }
    else {
        cout << "Item type not recognized.\n";
    }
}

void Human::unequip_item(int item_type) {
    if (item_type == SWORD) {
        if (equipped.steel_sword == 0) {
            cout << "No sword equipped.\n";
            return;
        }
        add_item(*equipped.steel_sword);
        equipped.steel_sword = 0;
    }
    else if (item_type == ARMOR) {
        if (equipped.armor == 0) {
            cout << "No armor equipped.\n";
            return;
        }
        add_item(*equipped.armor);
        equipped.armor = 0;
        update_all_resistances();
    }
    else {
        cout << "Item type not recognized.\n";
    }
}

void Human::print_equipped_items() {
    cout << "==========Equipped Items==========\n";
    bool check_if_empty = true;

    if (equipped.steel_sword != 0) {
        cout << "==========Steel Sword==========\n";
        cout << *equipped.steel_sword << "\n";
        check_if_empty = false;
    }
    
    cout << "==========Armor==========\n";
    if (equipped.armor != 0) {
        cout << *equipped.armor << "\n";
        check_if_empty = false;
    }

    if (check_if_empty) cout << "None\n";
}


    ///Mostrar destructor e desalocação
    // o inventario é desalocado no destrutor da classe Entity:
    Entity::~Entity() {
    //cout << "Destroying Entity...\n";
    for_each(inventory.swords.begin(), inventory.swords.end(), [](Sword * sword) { delete sword; });
    for_each(inventory.armors.begin(), inventory.armors.end(), [](Armor * armor) { delete armor; });
}

    /// Mostrar o uso (indireto) deste vector
    // o inventario é usado indiretamente quando uma Entity é derrotada e seus itens
    // são colocados no chão, isso é feito pelo método drop_all_items:
    void Entity::drop_all_items(vector<Item *> &floor_items) {
    // dropping by accessing the inventory directly
    // (may be changed latter to use the drop_item function)

    // drops all items with safe memory deallocation
    for (auto sword : inventory.swords) {
        drop_item(floor_items, SWORD, 0);
    }
    for (auto armor : inventory.armors) {
        drop_item(floor_items, ARMOR, 0);
    }

    // clears inventory
    inventory.swords.clear();
    inventory.armors.clear();
}


//// Ter um atributo static e um atributo const static.

    /// .h mostrando apenas eles e o método que os manipula
#ifndef ENTITY_H
#define ENTITY_H

enum options {
    AUTO = -1
};

...

class Entity {
public:
    ...

    inline static int getGlobal_danger() { return global_danger; }

    ...

    inline static void setGlobal_danger(int global_danger) { if (global_danger >= 0) Entity::global_danger = global_danger; }

    ...

    virtual void gain_xp(int);

    ...

    static void update_global_danger(int higher_level = 0);
    
    ...
protected:
    ...

    const static string CATEGORIES[7];
    const static int MAX_NAME_SIZE = 20;
    ...

    const static int NEXT_LEVEL_XP_LINEAR_COEF = 10;
    const static int NEXT_LEVEL_XP_ANGULAR_COEF = 10;
private:
    static int global_danger;
};

...

#endif // ENTITY_H

#ifndef HUMAN_H
#define HUMAN_H

...

#include "../Entity.h"

...

class Human: public Entity {
    ...
public:
    ...

    virtual void level_up();
    virtual void update_atributes();
    virtual void update_all_resistances();
    virtual void update_all_weaknesses();
    
    ...

protected:
    ...
private:

    // todas as entidades concretas possuem seus proprios coeficientes de atributos
    // para obedecer sua propria equação da reta personalizada
    const static int HEALTH_LINEAR_COEF = 5;
    const static int HEALTH_ANGULAR_COEF = 3;

    const static int STAMINA_LINEAR_COEF = 5;
    const static int STAMINA_ANGULAR_COEF = 3;
};

...

#endif // HUMAN_H

#ifndef WITCHER_H
#define WITCHER_H

...

#include "Human.h"

...

class Witcher: public Human {
    friend ostream &operator<< (ostream &out, const Witcher &witcher);
public:
    ...

    void update_atributes();

    // simply attack one entity
    void attack(Entity &entity, int attack_option = UNARMED, int technique = 0);

    ...

private:
    const static int HEALTH_LINEAR_COEF = 10;
    const static int HEALTH_ANGULAR_COEF = 5;
    
    const static int STAMINA_LINEAR_COEF = 10;
    const static int STAMINA_ANGULAR_COEF = 5;

    ...

    const static int WITCHER_ATTACK_COST = 10;
    const static int MAX_WITCHER_DAMAGE = 10;
    const static int MIN_WITCHER_DAMAGE = 7;
};

#endif // WITCHER_H

#ifndef GHOUL_H
#define GHOUL_H

...

#include "../Entity.h"

...

class Ghoul: public Entity {
    ...
public:

    ...
    
    void level_up();
    void update_atributes();
    void update_all_resistances();
    void update_all_weaknesses();

    void attack(Entity &entity, int weapon_type = UNARMED, int technique = 0);

    ...

private:
    const static int HEALTH_LINEAR_COEF = 5;
    const static int HEALTH_ANGULAR_COEF = 2;

    const static int STAMINA_LINEAR_COEF = 5;
    const static int STAMINA_ANGULAR_COEF = 2;

    ...

    const static int GHOUL_ATTACK_COST = 10;
    const static int MAX_GHOUL_DAMAGE = 7;
    const static int MIN_GHOUL_DAMAGE = 3;
};

#endif // GHOUL_H
    
    /// Inicialização no .cpp

    //...

#include "Entity.h"

//...

const string Entity::CATEGORIES[7] = {"F", "E", "D", "C", "B", "A", "S"};

// o valor 10 significa que todas as entidades que usarem o construtor que recebe
// parâmetros, mas sem escolher um level, o valor padrão será o global_danger
// que nesse caso é 10, portanto todas as entidades começam com level 10, a grosso modo
int Entity::global_danger = 10;

    /// Mostra método(s) em que são usados efetivamente

    //...

#include "Entity.h"

//...

// o nome de todas as entidades é validado e filtrado
// pelo atirbuto const static MAX_NAME_SIZE de Entity
// esse método tambem é igual pras outras hierarquias
//void Entity::setName(string name) {
    name.erase(0, name.find_first_not_of(' '));
    name.erase(name.find_last_not_of(' ') + 1);
    if (name == "") {
        cout << "Name cannot be empty.\n";
        this->name = "Empty_Name";
        return;
    }
    if (name.length() > MAX_NAME_SIZE) {
        cout << "Max name size is " << MAX_NAME_SIZE << " characters. Name shortened.\n";
        this->name = name.substr(0, MAX_NAME_SIZE);
        return;
    }
    this->name = name;
}

// ...

// para setar uma categoria deve ser válida de acordo com o atributo
// const static CATEGORIES da classe Entity
void Entity::setCategory(string category) {
    if (category == "") {
        cout << "Category cannot be empty.\n";
        this->category = "Empty_Category";
        return;
    }
    for (int i = 0; i < 7; i++) {
        if (category == CATEGORIES[i]) {
            this->category = category;
            return;
        }
    }
    cout << "Invalid category.\n";
    this->category = "Invalid_Category";
    return;
}

// aqui o level obedece um upperbound (limite superior) inteiro de acordo com a categoria
// estabelecida, que é um atributo const static da classe Entity
void Entity::setLevel(int level) {
    if (level < 0) {
        cout << "Level cannot be negative.\n";
        this->level = 0;
        return;
    }
    // filtra o level de acordo com a categoria
    char category_test = this->category[0];
    switch (category_test) {
        case 'F':
            if (level > 10) {
                cout << "Level cannot be greater than 10 for category F.\n";
                this->level = 10;
                return;
            }
            break;
        case 'E':
            if (level > 20) {
                cout << "Level cannot be greater than 20 for category E.\n";
                this->level = 20;
                return;
            }
            break;
        case 'D':
            if (level > 30) {
                cout << "Level cannot be greater than 30 for category D.\n";
                this->level = 30;
                return;
            }
            break;
        case 'C':
            if (level > 40) {
                cout << "Level cannot be greater than 40 for category C.\n";
                this->level = 40;
                return;
            }
            break;
        case 'B':
            if (level > 50) {
                cout << "Level cannot be greater than 50 for category B.\n";
                this->level = 50;
                return;
            }
            break;
        case 'A':
            if (level > 60) {
                cout << "Level cannot be greater than 60 for category A.\n";
                this->level = 60;
                return;
            }
            break;
        case 'S':
            if (level > 70) {
                cout << "Level cannot be greater than 70 for category S.\n";
                this->level = 70;
                return;
            }
            break;
        default:
            cout << "Invalid category.\n";
            break;
    }
    // se passou pelos filtros, seta o level
    this->level = level;
}

//...

// Este método chama level_up() e usa o atributo next_level_xp, que cresce de acordo
// com a equação da reta, portanto depende dos coeficientes const static das entidades concretas
// e o metodo level_up() atualiza o next_level_xp na equação da reta
void Entity::gain_xp(int xp_gained) {
    // checks if Entity is dead:
    if (!*this) {
        cout << this->name << " is dead. Cannot gain xp.\n";
        return;
    }

    // xp are never negative
    if (xp_gained < 0) {
        cout << "XP cannot be negative.\n";
        return;
    }
    // adds xp gained to the current xp
    this->xp += xp_gained;
    // checks if it has reached the next level
    if (this->xp >= next_level_xp) {
        // spends just the necessary amount of xp
        // to level up
        this->xp -= next_level_xp;
        level_up();
        // by calling gain_xp again inside this conditional, 
        // it will keep checking if it has reached the next level,
        // and leveling up until its not necessary anymore
        gain_xp(0);
    }
}

//...

// Toda a vez que o jogador witcher sobre de nivel ele chama o método estático update global danger
// que atualiza o atributo global_danger de acordo com o level do jogador
// como existe um construtor para todas as entidades concretas que, caso vc não forneça o level
// que vc deseja pra instância ele pegará o global_danger para definir aquela entidade,
// isso significa que o jogador sempre encontrará entidades concretas de level igual ou superior
// ao dele
void Entity::update_global_danger(int higher_level) {
    if (higher_level > global_danger) {
        global_danger = higher_level;
        cout << "Creatures are getting stronger!\n";
        // cout << "Global danger level is now " << global_danger << ".\n";
    }
}

//...

// se for enviado o sinal de AUTO, que é igual a -1 e esta selecionado como valor padrão,
// para o construtor de Human (o que também foi implementado nas outras entidades concretas)
// o level será o global_danger, que é atualizado pelo método update_global_danger chamado
// pelo jogador. E no construtor tambem são chamados metodos que atualizam os atributos, os
// quais seguem a equação da reta, ja mencionada, determinada pelos coeficientes const static
// de cada entidade concreta (que são diferentes para cada uma)
Human::Human(string name, 
            int age, 
            double coins, 
            int level,
            string category) {
                
    //...

    if (level == AUTO)
        level = Entity::getGlobal_danger();

    setLevel(level);
    setXp(0);
    update_atributes();

    //...

    update_all_resistances();
    update_all_weaknesses();
}

// para o humano, sua defesa segue sempre a defesa da armadura que está usando
// caso não equipe nada, está nú. E não possui defesa.
void Human::update_all_resistances() {
    if (equipped.armor != 0) {
        map<string, int> defenses_buffer = equipped.armor->use();
        setTotal_physical_resistance(defenses_buffer["physical_defense"]);
        setTotal_fire_resistance(defenses_buffer["fire_defense"]);
        setTotal_poison_resistance(defenses_buffer["poison_defense"]);
        setTotal_ice_resistance(defenses_buffer["ice_defense"]);
        setTotal_silver_resistance(defenses_buffer["silver_defense"]);
    }
    else {
        setTotal_physical_resistance(0);
        setTotal_fire_resistance(0);
        setTotal_poison_resistance(0);
        setTotal_ice_resistance(0);
        setTotal_silver_resistance(0);
    }
}

// O Humano naturalmente possui fraquezas comuns, mas não é
// vulnerável à prata como os monstros
void Human::update_all_weaknesses() {
    physical_weakness = 1;
    fire_weakness = 1;
    poison_weakness = 1;
    ice_weakness = 1;
    silver_weakness = 0;
}

// Aqui como mencionado antes, o método level_up() atualiza o valor do global_danger caso seja
// maior que a ultima entidade concreta que subiu de nivel, e atualiza os atributos de acordo
// com a equação da reta através do método update_atributes()
void Human::level_up() {
    level++;
    cout << "Level up! " << name << " is now level " << this->level << ".\n";
    Entity::update_global_danger(level);

    update_atributes();

    life_regen(max_health);
    stamina_regen(max_stamina);

}

// Aqui é onde a equação da reta é usada para atualizar os atributos de acordo com o level
// e os seus atributos coeficientes const static especificos
void Human::update_atributes() {
    next_level_xp = NEXT_LEVEL_XP_LINEAR_COEF + NEXT_LEVEL_XP_ANGULAR_COEF * level;
    max_health = HEALTH_LINEAR_COEF + HEALTH_ANGULAR_COEF * level;
    max_stamina = STAMINA_LINEAR_COEF + STAMINA_ANGULAR_COEF * level;
    xp_reward = level * NEXT_LEVEL_XP_ANGULAR_COEF / 2;
}

// Até agora, o witcher atualiza os atirbutos de forma semelhante ao Human, mas
// com seus próprios valores numéricos de coeficientes const static
void Witcher::update_atributes() {
    next_level_xp = NEXT_LEVEL_XP_LINEAR_COEF + NEXT_LEVEL_XP_ANGULAR_COEF * level;
    max_health = HEALTH_LINEAR_COEF + HEALTH_ANGULAR_COEF * level;
    max_stamina = STAMINA_LINEAR_COEF + STAMINA_ANGULAR_COEF * level;
    xp_reward = NEXT_LEVEL_XP_ANGULAR_COEF * level / 2;
}

// O Ghoul tambem sobe de nivel por ser uma entidade concreta
void Ghoul::level_up() {
    level++;
    Entity::update_global_danger(level);

    update_atributes();

    life_regen(max_health);
    stamina_regen(max_stamina);

}

// O Ghoul tambem atualiza seus atributos de acordo com a sua
// própria equação da reta
void Ghoul::update_atributes() {
    next_level_xp = NEXT_LEVEL_XP_LINEAR_COEF + NEXT_LEVEL_XP_ANGULAR_COEF * level;
    max_health = HEALTH_LINEAR_COEF + HEALTH_ANGULAR_COEF * level;
    max_stamina = STAMINA_LINEAR_COEF + STAMINA_ANGULAR_COEF * level;
    xp_reward = level * NEXT_LEVEL_XP_ANGULAR_COEF / 2;
}

// Aqui o Ghoul atualiza suas resistências baseado em estar enfurecido ou não
// oq acontece caso esteja vivo e com 10% de vida, ganhando +1 de resistencia fisica
void Ghoul::update_all_resistances() {
    total_physical_resistance = 0;
    total_fire_resistance = 0;
    total_poison_resistance = 0;
    total_ice_resistance = 0;
    total_silver_resistance = 0;

    if (is_enraged) {
        setTotal_physical_resistance(getTotal_physical_resistance() + 1);
    }
}

// O Ghoul, como mencionado antes, é um monstro e, portanto, possui fraqueza contra prata
// diferentemente das entidades concretas que não são monstros
void Ghoul::update_all_weaknesses() {
    physical_weakness = 1;
    fire_weakness = 1;
    poison_weakness = 1;
    ice_weakness = 1;
    silver_weakness = 1;
}

//// Fazer a sobrecarga para todas as classes dos operadores =, ==, ≠ e << (friend)
/*
//Base abstract
// const Entity &Entity::operator=(const Entity &assigned_entity) {
    if (this != &assigned_entity) {
        this->name = assigned_entity.name;
        this->age = assigned_entity.age;

        ...

        // primeiro limpa o vetor para preenche-lo
        for (auto sword : this->inventory.swords) {
            delete sword;
        }
        ...
    }

    return *this; // permite a forma a = b = c
}


//Class concrete
//const Human &Human::operator=(const Human &other_human) {
    if (this != &other_human) {
        // forma não permitida pela classe abstrata
        //*static_cast< Entity * >( this ) = static_cast< Entity >( other_human );
        Entity::operator=(other_human);
        if (other_human.equipped.steel_sword == 0) equipped.steel_sword = 0;
        else equipped.steel_sword = new Sword(*other_human.equipped.steel_sword);

        ...
        
    }
    return *this;
}
*/
     /// Operator=
        /// Hierarquia 1
             //Base

const Entity &Entity::operator=(const Entity &assigned_entity) {
    if (this != &assigned_entity) {
        this->name = assigned_entity.name;
        this->age = assigned_entity.age;
        this->coins = assigned_entity.coins;

        this->is_dead = assigned_entity.is_dead;
        this->max_health = assigned_entity.max_health;
        this->health = assigned_entity.health;
        this->max_stamina = assigned_entity.max_stamina;
        this->stamina = assigned_entity.stamina;

        this->category = assigned_entity.category;
        this->level = assigned_entity.level;
        this->next_level_xp = assigned_entity.next_level_xp;
        this->xp = assigned_entity.xp;
        this->xp_reward = assigned_entity.xp_reward;

        this->is_stunned = assigned_entity.is_stunned;

        this->physical_weakness = assigned_entity.physical_weakness;
        this->fire_weakness = assigned_entity.fire_weakness;
        this->poison_weakness = assigned_entity.poison_weakness;
        this->ice_weakness = assigned_entity.ice_weakness;
        this->silver_weakness = assigned_entity.silver_weakness;

        this->total_physical_resistance = assigned_entity.total_physical_resistance;
        this->total_fire_resistance = assigned_entity.total_fire_resistance;
        this->total_poison_resistance = assigned_entity.total_poison_resistance;
        this->total_ice_resistance = assigned_entity.total_ice_resistance;
        this->total_silver_resistance = assigned_entity.total_silver_resistance;

        // primeiro limpa o vetor para preenche-lo
        for (auto sword : this->inventory.swords) {
            delete sword;
        }
        this->inventory.swords.clear();
        for (auto sword : assigned_entity.inventory.swords) {
            Sword * new_sword = new Sword(*sword);
            this->inventory.swords.push_back(new_sword);
        }
        for (auto armor : this->inventory.armors) {
            delete armor;
        }
        this->inventory.armors.clear();
        for (auto armor : assigned_entity.inventory.armors) {
            Armor * new_armor = new Armor(*armor);
            this->inventory.armors.push_back(new_armor);
        }
    }

    return *this; // permite a forma a = b = c
}
             //Derivadas da Base 1 - não é permitido static_cast pela abstrata

const Human &Human::operator=(const Human &other_human) {
    if (this != &other_human) {
        // forma não permitida pela classe abstrata
        //*static_cast< Entity * >( this ) = static_cast< Entity >( other_human );
        // forma sugerida pela IA
        Entity::operator=(other_human);
        if (other_human.equipped.steel_sword == 0) equipped.steel_sword = 0;
        else {
            delete equipped.steel_sword;
            equipped.steel_sword = new Sword(*other_human.equipped.steel_sword);
        }

        if (other_human.equipped.armor == 0) equipped.armor = 0;
        else {
            delete equipped.armor;
            equipped.armor = new Armor(*other_human.equipped.armor);
        }
    }
    return *this;
}

             //Derivadas da Derivada - mostrar uso static_cast

    const Witcher &Witcher::operator=(const Witcher &other_witcher) {
    if (this != &other_witcher) {
        *static_cast< Human * >( this ) = static_cast< Human >( other_witcher );
        delete this->signs.igni;
        this->signs.igni = other_witcher.signs.igni;
        this->is_close_to_chest = other_witcher.is_close_to_chest;
    }
    return *this;
}

            // Derivada da Base 1
const Ghoul &Ghoul::operator=(const Ghoul &other_ghoul) {
    if (this == &other_ghoul) {
        return *this;
    }
    Entity::operator=(other_ghoul);
    this->is_enraged = other_ghoul.is_enraged;
    
    return *this;
}


             //e assim por diante

        /// Hierarquia 2
             //Base
    const Item &Item::operator=(const Item &other_Item) {
    this->name = other_Item.name;
    this->description = other_Item.description;
    return *this;
}
             //Derivadas da Base 2 - não é permitido static_cast pela abstrata
const Weapon &Weapon::operator=(const Weapon &other_weapon) {
    // Item is abstract, so we can't do this:
    //static_cast<Item>(*this) = static_cast<Item>(other_weapon);
    // So we do this:
    Item::operator=(other_weapon);

    this->physical_damage = other_weapon.physical_damage;
    this->fire_damage = other_weapon.fire_damage;
    this->poison_damage = other_weapon.poison_damage;
    this->ice_damage = other_weapon.ice_damage;
    this->silver_damage = other_weapon.silver_damage;

    return *this;
}
             //Derivadas da Derivada - não é permitido static_cast pela abstrata
const Sword &Sword::operator=(const Sword &other_sword) {
    // Weapon is abstract, so we can't do this:
    //static_cast<Weapon>(*this) = static_cast<Weapon>(other_sword);
    // So we do this:
    Weapon::operator=(other_sword);
    made_of_silver = other_sword.made_of_silver;

    return *this;
}

            // Derivada da Base 2 - não é permitido static_cast pela abstrata
const Armor &Armor::operator=(const Armor &other_Armor) {
    // forma não permitida pela classe abstrata Item
    //static_cast<Item &>(*this) = static_cast<const Item &>(other_Armor);
    Item::operator=(other_Armor);
    this->physical_defense = other_Armor.physical_defense;
    this->fire_defense = other_Armor.fire_defense;
    this->poison_defense = other_Armor.poison_defense;
    this->ice_defense = other_Armor.ice_defense;
    this->silver_defense = other_Armor.silver_defense;

    return *this;
}

             //e assim por diante


        /// Hierarquia 3
             //Base
    const Spell &Spell::operator=(const Spell &other_spell) {
    this->name = other_spell.name;
    this->description = other_spell.description;
    return *this;
}
             //Derivadas da Base 3 - não é permitido static_cast pela abstrata
const Sign &Sign::operator=(const Sign &other_sign) {
    if (this != &other_sign) {
        Spell::operator=(other_sign);
        this->is_unlocked = other_sign.is_unlocked;
        this->stamina_cost = other_sign.stamina_cost;
    }
    return *this;
}

             //Derivadas da Derivada - não é permitido static_cast pela abstrata
const Igni &Igni::operator=(const Igni &other_igni) {
    if (this != &other_igni) {
        Sign::operator=(other_igni);
        this->fire_damage = other_igni.fire_damage;
        this->area = other_igni.area;
    }
    return *this;
}
             //e assim por diante


     //// Operators== e !=
         // Hierarquia 1
             //Base

int Entity::operator==(const Entity &other_entity) const {
    // atributes check
    if (this->name != other_entity.name) return 0;
    if (this->age != other_entity.age) return 0;
    if (this->coins != other_entity.coins) return 0;

    if (this->is_dead != other_entity.is_dead) return 0;
    if (this->max_health != other_entity.max_health) return 0;
    if (this->health != other_entity.health) return 0;
    if (this->max_stamina != other_entity.max_stamina) return 0;
    if (this->stamina != other_entity.stamina) return 0;

    if (this->category != other_entity.category) return 0;
    if (this->level != other_entity.level) return 0;
    if (this->next_level_xp != other_entity.next_level_xp) return 0;
    if (this->xp != other_entity.xp) return 0;
    if (this->xp_reward != other_entity.xp_reward) return 0;

    if (this->physical_weakness != other_entity.physical_weakness) return 0;
    if (this->fire_weakness != other_entity.fire_weakness) return 0;
    if (this->poison_weakness != other_entity.poison_weakness) return 0;
    if (this->ice_weakness != other_entity.ice_weakness) return 0;
    if (this->silver_weakness != other_entity.silver_weakness) return 0;

    if (this->total_physical_resistance != other_entity.total_physical_resistance) return 0;
    if (this->total_fire_resistance != other_entity.total_fire_resistance) return 0;
    if (this->total_poison_resistance != other_entity.total_poison_resistance) return 0;
    if (this->total_ice_resistance != other_entity.total_ice_resistance) return 0;
    if (this->total_silver_resistance != other_entity.total_silver_resistance) return 0;
    
    if (this->is_stunned != other_entity.is_stunned) return 0;

    // inventory check
    //if (this->inventory.swords.empty() != other_entity.inventory.swords.empty()) return 0;
    if (this->inventory.swords.size() != other_entity.inventory.swords.size()) return 0;
    if (this->inventory.armors.size() != other_entity.inventory.armors.size()) return 0;
    
    for (auto sword : inventory.swords) {
        for (auto other_sword : other_entity.inventory.swords) {
            if (*sword != *other_sword) {
                return 0;
            }
        }
    }
    for (auto armor : inventory.armors) {
        for (auto other_armor : other_entity.inventory.armors) {
            if (*armor != *other_armor) {
                return 0;
            }
        }
    }
    return 1;
}

int Entity::operator!=(const Entity &other_entity) const {
    return !(*this == other_entity);
}
             //Derivadas da Base 1 - não é permitido static_cast pela abstrata

bool Human::operator==(const Human &other_human) const {
    Entity::operator==(other_human);

    // First checks if its empty
    if (equipped.steel_sword == 0 && other_human.equipped.steel_sword != 0) return false;
    if (equipped.steel_sword != 0 && other_human.equipped.steel_sword == 0) return false;
    // Then checks if its equal
    if (equipped.steel_sword != 0 && other_human.equipped.steel_sword != 0) {
        if (*equipped.steel_sword != *other_human.equipped.steel_sword) return false;
    }

    // First checks if its empty
    if (equipped.armor == 0 && other_human.equipped.armor != 0) return false;
    if (equipped.armor != 0 && other_human.equipped.armor == 0) return false;
    // Then checks if its equal
    if (equipped.armor != 0 && other_human.equipped.armor != 0) {
        if (*equipped.armor != *other_human.equipped.armor) return false;
    }

    return true;
}

bool Human::operator!=(const Human &other_human) const {
    return !(*this == other_human);
}
             //Derivadas da Derivada - mostrar uso static_cast
bool Witcher::operator==(const Witcher &other_witcher) const {
    static_cast< Human >( *this ) == static_cast< Human >( other_witcher );

    if (signs.igni != other_witcher.signs.igni) return false;
    if (is_close_to_chest != other_witcher.is_close_to_chest) return false;

    return true;
}

bool Witcher::operator!=(const Witcher &other_witcher) const {
    return !(*this == other_witcher);
}

            // Derivada da Base 1

int Ghoul::operator==(const Ghoul &other_ghoul) const {
    Entity::operator==(other_ghoul);
    if (this->is_enraged != other_ghoul.is_enraged) { return 0; }
    return 1;
}

int Ghoul::operator!=(const Ghoul &other_ghoul) const {
    return Entity::operator!=(other_ghoul);
}

             //e assim por diante
// BONUS: a hierarquia de Entity tambem possui a sobrecarga do operador unário de negação !
// que retorna true se a entidade estiver morta e false caso contrário
// imitando especificamente o comportamento declarado em Entity
bool Entity::operator!() const {
    return (is_dead);
}
bool Human::operator!() const {
    return Entity::operator!();
}
bool Witcher::operator!() const {
    return Entity::operator!();
}
bool Ghoul::operator!() const {
    return Entity::operator!();
}

         //// Hierarquia 2
             //Base

int Item::operator==(const Item &other_Item) const {
    if (this->name != other_Item.name) return 0;
    if (this->description != other_Item.description) return 0;
    return 1;
}

int Item::operator!=(const Item &other_Item) const {
    return !(*this == other_Item);
}

             //Derivadas da Base 2 - não é permitido static_cast pela abstrata
int Weapon::operator==(const Weapon &other_weapon) const {
    // Item is abstract, so we can't do this:
    // static_cast<Item>(*this) == static_cast<Item>(other_weapon);
    // So we do this:
    Item::operator==(other_weapon);

    if (this->physical_damage != other_weapon.physical_damage) return 0;
    if (this->fire_damage != other_weapon.fire_damage) return 0;
    if (this->poison_damage != other_weapon.poison_damage) return 0;
    if (this->ice_damage != other_weapon.ice_damage) return 0;
    if (this->silver_damage != other_weapon.silver_damage) return 0;

    return 1;
}

int Weapon::operator!=(const Weapon &other_weapon) const {
    return !(*this == other_weapon);
}

             //Derivadas da Derivada - não é permitido static_cast pela abstrata
int Sword::operator==(const Sword &other_sword) const {
    // Weapon is abstract, so we can't do this:
    // static_cast<Weapon>(*this) == static_cast<Weapon>(other_sword);
    // So we do this:
    Weapon::operator==(other_sword);
    if (this->made_of_silver != other_sword.made_of_silver) return 0;

    return 1;
}

int Sword::operator!=(const Sword &other_sword) const {
    return !(*this == other_sword);
}

            //Derivadas da Base 2 - não é permitido static_cast pela abstrata
int Armor::operator==(const Armor &other_Armor) const {
    // forma não permitida pela classe abstrata Item
    //static_cast<const Item &>(*this) == static_cast<const Item &>(other_Armor);
    Item::operator==(other_Armor);
    if (this->physical_defense != other_Armor.physical_defense) return 0;
    if (this->fire_defense != other_Armor.fire_defense) return 0;
    if (this->poison_defense != other_Armor.poison_defense) return 0;
    if (this->ice_defense != other_Armor.ice_defense) return 0;
    if (this->silver_defense != other_Armor.silver_defense) return 0;
    
    return 1;
}

int Armor::operator!=(const Armor &other_Armor) const {
    return !(*this == other_Armor);
}

             //e assim por diante

        //// Hierarquia 3
             //Base
int Spell::operator==(const Spell &other_spell) const {
    if (this->name != other_spell.name) return 0;
    if (this->description != other_spell.description) return 0;
    return 1;
}

int Spell::operator!=(const Spell &other_spell) const {
    return !(*this == other_spell);
}
             //Derivadas da Base 3 - não é permitido static_cast pela abstrata
int Sign::operator==(const Sign &other_sign) const {
    Spell::operator==(other_sign);

    if (this->stamina_cost == other_sign.stamina_cost) return 0;

    return 1;
}

int Sign::operator!=(const Sign &other_sign) const {
    return !(*this == other_sign);
}
             //Derivadas da Derivada - não é permitido static_cast pela abstrata
int Igni::operator==(const Igni &other_igni) const {
    Sign::operator==(other_igni);

    if (this->fire_damage != other_igni.fire_damage) return 0;
    if (this->area != other_igni.area) return 0;

    return 1;
}

int Igni::operator!=(const Igni &other_igni) const {
    return !(*this == other_igni);
}

             //e assim por diante


     //// Operator<<
        //// Hierarquia 1
             //Base
            // Entity
            // classe abstrata não possui cout, apenas print

void Entity::print_info() const{
    cout << "==========Identity==========\n";
    cout << "Name: " << this->name << "\n";
    cout << "Age: " << this->age << "\n";
    cout << "Date of birth: ";
    this->date_of_birth.print();
    cout << "\n";
    cout << "==========Atributes==========\n";
    cout << "Category: " << this->category << "\n";
    cout << "Level: " << this->level << "\n";
    cout << "XP: " << this->xp << "/" << this->next_level_xp << "\n";

    if (this->xp_reward != 0)
        cout << "XP reward: " << this->xp_reward << "\n";

    string buffer = (this->is_dead) ? " (DEAD) " : "";
    cout << "Health: " << this->health << "/" << this->max_health << buffer << "\n";

    cout << "Stamina: " << this->stamina << "/" << this->max_stamina << "\n";
    print_resistances();
    print_weaknesses();
    print_temporary_status();
    print_inventory();
}

void Entity::print_resistances() const {
    cout << "==========Resistences==========\n";
    if (this->total_physical_resistance != 0)
        cout << "Physical: +" << this->total_physical_resistance << "\n";
    if (this->total_fire_resistance != 0)
        cout << "Fire: +" << this->total_fire_resistance << "\n";
    if (this->total_poison_resistance != 0)
        cout << "Poison: +" << this->total_poison_resistance << "\n";
    if (this->total_ice_resistance != 0)
        cout << "Ice: +" << this->total_ice_resistance << "\n";
    if (this->total_silver_resistance != 0)
        cout << "Silver: +" << this->total_silver_resistance << "\n";
}

void Entity::print_weaknesses() const {
    cout << "==========Weaknesses==========\n";
    cout << "Physical: " << this->physical_weakness << "x\n";
    cout << "Fire: " << this->fire_weakness << "x\n";
    cout << "Poison: " << this->poison_weakness << "x\n";
    cout << "Ice: " << this->ice_weakness << "x\n";
    cout << "Silver: " << this->silver_weakness << "x\n";
}

void Entity::print_temporary_status() const {
    cout << "==========Temporary status==========\n";
    string buffer = (this->is_stunned) ? "true" : "false";
    cout << "Stunned: " << buffer << "\n";
}

void Entity::print_inventory() const {
    cout << "==========Inventory of " << this->name << "==========\n";
    cout << "Coins: " << this->coins << "\n";
    cout << "==========Swords==========\n";

    int counter = 0;
    if (inventory.swords.empty()) {
        cout << "None\n";
    }
    for (auto sword : inventory.swords) {
        cout << ++counter << ". " << *sword << "\n";
    }

    cout << "==========Armors==========\n";

    counter = 0;
    if (inventory.armors.empty()) {
        cout << "None\n";
    }
    for (auto armor : inventory.armors) {
        cout << ++counter << ". " << *armor << "\n";
    }
}

             //Derivadas da Base 1 - não é permitido static_cast pela abstrata

ostream &operator<< (ostream &out, const Human &human){
    // Chama o método print_info() da classe base abstrata
    human.print_info();

    // Em seguida printa seus atributos especializados
    out << "==========Equipped Items==========\n";

    bool check_if_empty = true;

    if (human.equipped.steel_sword != 0) {
        out << "==========Steel Sword==========\n";
        out << *human.equipped.steel_sword << "\n";
        check_if_empty = false;
    }
    
    out << "==========Armor==========\n";
    if (human.equipped.armor != 0) {
        out << *human.equipped.armor << "\n";
        check_if_empty = false;
    }

    if (check_if_empty) out << "None\n";

    return out;
}

              //Derivadas da Derivada - mostrar uso static_cast

ostream &operator<< (ostream &out, const Witcher &witcher) {
    out << static_cast<Human>(witcher);
    out << "==========Witcher Signs==========\n";
    out << *witcher.signs.igni << "\n";

    return out;
}

            //Derivadas da Base 1 - não é permitido static_cast pela abstrata
ostream &operator<<(ostream &out, const Ghoul &ghoul) {
    // Chama o método print_info() da classe base abstrata
    ghoul.print_info();

    // Em seguida printa seus atributos especializados
    out << "Enraged: " << ghoul.is_enraged << "\n";
    
    return out;
}

             //e assim por diante


        //// Hierarquia 2
             //Base
             // Item
            // classe abstrata não possui cout, apenas print
    void Item::print_info() const {
    cout << "Name: " << name << '\n';
    cout << "Description: " << description << '\n';
}

             //Derivadas da Base 2 - não é permitido static_cast pela abstrata
            // Weapon
            // Weapon é classe abstrata também e não possui cout, apenas print
void Weapon::print_info() const {
    cout << name << " (+" << physical_damage << " physical damage)\n";
    if (fire_damage > 0) cout << " (+" << fire_damage << " fire damage)\n";
    if (poison_damage > 0) cout << " (+" << poison_damage << " poison damage)\n";
    if (ice_damage > 0) cout << " (+" << ice_damage << " ice damage)\n";
    if (silver_damage > 0) cout << " (+" << silver_damage << " silver damage)\n";

    cout << "\"" << description << "\"";
}

              //Derivadas da Derivada - não é permitido static_cast pela abstrata
            // Sword
            // Sword usa cout com sua própria personalização
ostream &operator<< (ostream &out, const Sword &sword){
    out << sword.name << " (+" << sword.physical_damage << " physical damage)\n";
    if (sword.fire_damage > 0) out << " (+" << sword.fire_damage << " fire damage)\n";
    if (sword.poison_damage > 0) out << " (+" << sword.poison_damage << " poison damage)\n";
    if (sword.ice_damage > 0) out << " (+" << sword.ice_damage << " ice damage)\n";
    if (sword.silver_damage > 0) out << " (+" << sword.silver_damage << " silver damage)\n";

    out << "\"" << sword.description << "\"";
    return out;
}

            //Derivadas da Base 2 - não é permitido static_cast pela abstrata
            // Armor
            // Armor usa cout com sua própria personalização
ostream &operator<< (ostream &out, const Armor &Armor){
    out << Armor.name << " (+" << Armor.physical_defense << " physical defense)\n";
    if (Armor.fire_defense > 0) out << " (+" << Armor.fire_defense << " fire defense)\n";
    if (Armor.poison_defense > 0) out << " (+" << Armor.poison_defense << " poison defense)\n";
    if (Armor.ice_defense > 0) out << " (+" << Armor.ice_defense << " ice defense)\n";
    if (Armor.silver_defense > 0) out << " (+" << Armor.silver_defense << " silver defense)\n";

    out << "\"" << Armor.description << "\"";
    return out;
}

             //e assim por diante


       //// Hierarquia 3

             //Base
             // Spell
            // classe abstrata não possui cout, apenas print
void Spell::print_info() const {
    cout << "==========" << name << "==========\n";
    cout << "\"" << description << "\"\n";
}

             //Derivadas da Base 3 - não é permitido static_cast pela abstrata
            // Sign
            // Sign é classe abstrata também e não possui cout, apenas print
void Sign::print_info() const {
    // Chama o método print_info() da classe base abstrata
    Spell::print_info();

    // Em seguida printa seus atributos especializados
    string buffer = (is_unlocked) ? "true" : "false";

    cout << "Is unlocked: " << buffer << "\n";

    cout << "Stamina cost: " << stamina_cost << "\n";
    
}


              //Derivadas da Derivada - não é permitido static_cast pela abstrata
            // Igni

ostream &operator<<(ostream &out, const Igni &igni) {
    // Chama o método print_info() da classe base abstrata
    igni.print_info();

    // Em seguida printa seus atributos especializados
    out << "Fire damage: " << igni.fire_damage << "\n";
    out << "Area: " << igni.area << "\n";

    return out;
}

             //e assim por diante

            

//// Carregamento e salvamento de arquivos
    // É necessário ter a funcionalidade: 
    //1. leitura de arquivos para configuração das suas classes e variáveis de status, 
    //2. processamento das variáveis de status e 
      bool load_witcher( Witcher &loaded_witcher, 
                   string name_file = "save-files/config-witcher/config_atributes.txt" ) {
    cout << "Loading witcher...\n";
    // First creates a buffer map to store the atributes of wicther
    map<string, string> atributes_buffer;

    // Open the file for reading
    ifstream input_file(name_file);
    if (!input_file.is_open()) {
        cerr << "Error opening " << name_file << " file." << '\n';
        return false; // Exit with an error code
    }

    string line;
    string atribute_name;
    char equal_sign;
    string value;

    // Check first line if a witcher was saved or not:
    // Do all the checks to see if the file is valid
    // First get the line
    if (!(getline(input_file, line))) {
        return false;
    }
    // Then put it in a istringstream to manipulate it
    istringstream iss(line);
    // Check if it has the number of specifiers I want
    if (!(iss >> atribute_name >> equal_sign >> value)) {
        cerr << "Error parsing line: (unexpected arguments number)" << line << '\n';
        return false;
    }
    // Check if the specifiers are the ones I want
    if (!(atribute_name == "Witcher" && equal_sign == '=')) {
        cerr << "Error parsing line: (incorrect separators)" << line << '\n';
        return false;
    }
    // Check if the value is valid on my convention
    if (!(value == "1" || value == "0")) {
        cerr << "Error parsing line: (expected \"0\" or \"1\")" << line << '\n';
        return false;
    }
    // Finally checks if a Witcher was already saved before:
    if (value == "0") {
        cout << "No Witcher was saved yet.\n";
        return false;
    }
    // If a Witcher was saved before, then load it:
    while (getline(input_file, line)) 
    {
        // cout << "Parsing line: " << line << "\n";
        // Do the checks above but for every line
        // in a generic way
        istringstream iss(line);
        if (!(iss >> atribute_name >> equal_sign >> value)) {
        cerr << "Error parsing line: (unexpected arguments number) " << line << '\n';
        return false;
        }
        
        if (!(equal_sign == '=')) {
            cerr << "Error parsing line: (incorrect separator) " << line << '\n';
            return false;
        }

        // Remove leading and trailing whitespaces from the value
        value = value.substr(value.find_first_not_of(" \t"));
        value = value.substr(0, value.find_last_not_of(" \t") + 1);
        
        // putting values inside the map
        atributes_buffer[atribute_name] = value;
    }
    // Converts underscores from string atributes to spaces
    // so that the string turns back to original form
    for (auto &x : atributes_buffer) {
        replace(x.second.begin(), x.second.end(), '_', ' ');
    }

    input_file.close();

    if (atributes_buffer.empty()) {
        cerr << "No variables found.\n";
        return false;
    }

    // Then set the atributes to witcher
    loaded_witcher.setName(atributes_buffer["name"]);
    loaded_witcher.setAge(stoi(atributes_buffer["age"]));
    loaded_witcher.setCoins(stod(atributes_buffer["coins"]));

    // Sets the atributes to its level
    loaded_witcher.setCategory(atributes_buffer["category"]);
    loaded_witcher.setLevel(stoi(atributes_buffer["level"]));
    loaded_witcher.update_atributes();

    // Recovers the current health and stamina
    loaded_witcher.setHealth(stoi(atributes_buffer["health"]));
    loaded_witcher.setStamina(stoi(atributes_buffer["stamina"]));

    // Then load the inventory
    cout << "Loading inventory...\n";
    loaded_witcher.load_inventory();

    return true;
}

void Witcher::load_inventory(string name_file_swords, string name_file_armors) {

    // First creates a buffer map to store the atributes of each item
    map<string, string> items_atributes_buffer;
    // First load the swords
    ifstream input_file(name_file_swords);
    if (!input_file.is_open()) {
        cerr << "Error opening  " << name_file_swords << " file." << '\n';
        return; // Exit with an error code
    }
    // Unpacking variables
    string line;
    string atribute_name;
    char equal_sign;
    string value;

    while (getline(input_file, line)) {
        istringstream line_stream(line);
        line_stream >> atribute_name >> equal_sign >> value;
        // Skips to next sword and stores the previous one
        // reusing the same buffer for all swords
        if (atribute_name == "next" && equal_sign == '=' && value == "item") {
            // Converts underscores from string atributes to spaces
            // so that the string turns back to original form
            for (auto &x : items_atributes_buffer) {
                replace(x.second.begin(), x.second.end(), '_', ' ');
            }
            // Creates a temporary sword and adds it to the inventory
            Sword * new_sword = new Sword(items_atributes_buffer["name"], 
                                    items_atributes_buffer["description"], 
                                    stoi(items_atributes_buffer["physical_damage"]),
                                    stoi(items_atributes_buffer["fire_damage"]),
                                    stoi(items_atributes_buffer["poison_damage"]),
                                    stoi(items_atributes_buffer["ice_damage"]),
                                    stoi(items_atributes_buffer["silver_damage"]));
            // add_item already cleans "new_sword" buffer
            add_item(*new_sword);
            // Cleans buffer variable
            items_atributes_buffer.clear();
        }
        // Stores values in buffer iteratively
        items_atributes_buffer[atribute_name] = value;
    }
    // Closes swords file
    input_file.close();

    // Then load the armors
    // Reuse same ifstream variable
    input_file.open(name_file_armors);
        if (!input_file.is_open()) {
        cerr << "Error opening " << name_file_armors << " file." << '\n';
        return; // Exit with an error code
    }

    while (getline(input_file, line)) {
        istringstream line_stream(line);
        // Reuses same unpacking variables
        line_stream >> atribute_name >> equal_sign >> value;
        // Skips to next armor and stores the previous one
        // reusing the same buffer for all armors
        if (atribute_name == "next" && equal_sign == '=' && value == "item") {
            // Converts underscores from string atributes to spaces
            // so that the string turns back to original form
            for (auto &x : items_atributes_buffer) {
                replace(x.second.begin(), x.second.end(), '_', ' ');
            }
            // Creates a temporary armor and adds it to the inventory
            Armor * new_armor = new Armor(items_atributes_buffer["name"], 
                                    items_atributes_buffer["description"], 
                                    stoi(items_atributes_buffer["physical_defense"]), 
                                    stoi(items_atributes_buffer["fire_defense"]),
                                    stoi(items_atributes_buffer["poison_defense"]),
                                    stoi(items_atributes_buffer["ice_defense"]),
                                    stoi(items_atributes_buffer["silver_defense"]));
            // add_item already cleans "new_armor" buffer
            add_item(*new_armor);
            // Cleans buffer variable
            items_atributes_buffer.clear();
        }
        // Stores values in buffer iteratively
        // Reuses same map
        items_atributes_buffer[atribute_name] = value;
    }
    // Closes armors file
    input_file.close();

    return;
}

      //3. salvamento dessas variáveis. 

bool save_witcher( Witcher &saved_witcher, 
                   string name_file = "save-files/config-witcher/config_atributes.txt" )
{
    // unequip all items, to they're saved in the inventory
    for (int i = 0; i < TOTAL_ITEM_TYPES; i++) {
        saved_witcher.unequip_item(i);
    }
    // creates a buffer map to store the atributes of wicther
    map<string, string> atributes;
    // save the witcher atributes
    // update the atributes map
    atributes["name"] = saved_witcher.getName();
    atributes["age"] = to_string(saved_witcher.getAge());
    atributes["coins"] = to_string(saved_witcher.getCoins());

    // save level and category
    atributes["category"] = saved_witcher.getCategory();
    atributes["level"] = to_string(saved_witcher.getLevel());

    // saves current health and stamina
    atributes["health"] = to_string(saved_witcher.getHealth());
    atributes["stamina"] = to_string(saved_witcher.getStamina());

    // converts spaces to underscores in string atributes
    // so that the string can be saved in a file
    for (auto &x : atributes) {
        replace(x.second.begin(), x.second.end(), ' ', '_');
    }
    
    // Open the file for writing
    ofstream output_file(name_file, std::ios::out | std::ios::trunc);
    if (!output_file.is_open()) {
        cerr << "Erro ao abrir aquivo para escrita!" << '\n';
        return false; //
    }
    // First writes that there is a witcher saved
    output_file << "Witcher = 1\n";
    // Then writes all the atributes according to their type
    for (const auto& pair : atributes) {
        output_file << pair.first << " = " << pair.second << '\n';
    }
    // Then closes the file
    output_file.close();

    // Then save the witcher inventory
    saved_witcher.save_inventory();

    cout << "Witcher " << saved_witcher.getName() << " has been saved.\n";

    return true;
}

void Witcher::save_inventory(string name_file_swords, string name_file_armors) {
    // First creates a buffer map to store the atributes of each item
    map<string, string> items_atributes_buffer;
    // First save the swords
    ofstream output_file(name_file_swords);
    if (!output_file.is_open()) {
        cerr << "Error opening file." << '\n';
        return; // Exit with an error code
    }

    for (auto sword : this->inventory.swords) {
        items_atributes_buffer["name"] = sword->getName();
        items_atributes_buffer["description"] = sword->getDescription();
        items_atributes_buffer["physical_damage"] = to_string(sword->getPhysical_damage());
        items_atributes_buffer["fire_damage"] = to_string(sword->getFire_damage());
        items_atributes_buffer["poison_damage"] = to_string(sword->getPoison_damage());
        items_atributes_buffer["ice_damage"] = to_string(sword->getIce_damage());
        items_atributes_buffer["silver_damage"] = to_string(sword->getSilver_damage());
        // Convert string spaces from string atributes to underscores
        // so that the file can be read again
        for (auto &x : items_atributes_buffer) {
            replace(x.second.begin(), x.second.end(), ' ', '_');
        }
        // Stores values in buffer iteratively
        for (auto const& x : items_atributes_buffer) {
            output_file << x.first << " = " << x.second << '\n';
        }
        // Stores next item separator
        output_file << "next = item\n";
        items_atributes_buffer.clear();
    }
    // Closes swords file
    output_file.close();

    // Then save the armors
    // Reuse same ofstream variable
    output_file.open(name_file_armors);
        if (!output_file.is_open()) {
        cerr << "Error opening file." << '\n';
        return; // Exit with an error code
    }

    for (auto armor : this->inventory.armors) {
        items_atributes_buffer["name"] = armor->getName();
        items_atributes_buffer["description"] = armor->getDescription();
        items_atributes_buffer["physical_defense"] = to_string(armor->getPhysical_defense());
        items_atributes_buffer["fire_defense"] = to_string(armor->getFire_defense());
        items_atributes_buffer["poison_defense"] = to_string(armor->getPoison_defense());
        items_atributes_buffer["ice_defense"] = to_string(armor->getIce_defense());
        items_atributes_buffer["silver_defense"] = to_string(armor->getSilver_defense());
        // Convert string spaces from string atributes to underscores
        // so that the file can be read again
        for (auto &x : items_atributes_buffer) {
            replace(x.second.begin(), x.second.end(), ' ', '_');
        }
        // Stores values in buffer iteratively
        for (auto const& x : items_atributes_buffer) {
            output_file << x.first << " = " << x.second << '\n';
        }
        // Stores next item separator
        output_file << "next = item\n";
        items_atributes_buffer.clear();
    }

    // Closes armors file
    output_file.close();
}

///Sem o diagrama UML, a saída do programa e o vídeo, o trabalho não será avaliado.

    //Link arquivo de configuração no repositório
    // os 3 arquivos de configuração se encontram no diretório:
    // Link : https://github.com/luiz-fleite/a-witcher-tale/tree/main/save-files/config-witcher
    // Caminhos relativos:
    // save-files/config-witcher
    // o path dos arquivos é:
    // save-files/config-witcher/config_armors.txt
    // save-files/config-witcher/config_atributes.txt
    // save-files/config-witcher/config_swords.txt

    //Link vídeo mostrando a execução do código usando o arquivo de configuração
    // https://drive.google.com/drive/folders/19zTKEHwtlts1WFDu0uHt2Zwy0f5eKu12?usp=sharing
