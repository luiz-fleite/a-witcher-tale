#include <iostream>
#include <string>

#include "Human.h"

using std::cout;

Human::Human() {
    //cout << "Creating a new Human...\n";
    name = "Peasant";
    age = 30;
    coins = 50.00;
    health = 50;
    stamina = 50;
    category = CATEGORIES[0];
    level = 1;
    total_defense = 0;
    //equipped.steel_sword = new Sword();
    equipped.steel_sword = 0;
    //equipped.armor = new Armor();
    equipped.armor = 0;

    is_stunned = false;

    update_total_defense();
}

Human::Human(string name, int age, double coins, int health, int stamina, string category) {
    setName(name);
    setAge(age);
    setCoins(coins);
    setHealth(health);
    setStamina(stamina);
    setCategory(category);
    setLevel(1);
    setTotal_defense(0);

    equipped.steel_sword = new Sword();
    equipped.armor = new Armor();

    is_stunned = false;

    update_total_defense();
}

Human::~Human() {
    //cout << "Destroying Human...\n";
    delete equipped.steel_sword;
    delete equipped.armor;
}

Human::Human(const Human &other_human) : Entity(other_human) {
    //cout << "Copying Human...\n";

    if (other_human.equipped.steel_sword == 0) equipped.steel_sword = 0;
    else equipped.steel_sword = new Sword(*other_human.equipped.steel_sword);

    if (other_human.equipped.armor == 0) equipped.armor = 0;
    else equipped.armor = new Armor(*other_human.equipped.armor);

}

void Human::drop_item(string item_type_name) {
    if (item_type_name == "Steel Sword")
        equipped.steel_sword = 0;
    else if (item_type_name == "Armor") {
        setTotal_defense(getTotal_defense() - equipped.armor->getDefense());
        equipped.armor = 0;
        update_total_defense();
    }
    else
        cout << "Item type name not recognized.\n";
}

void Human::print_equipped_items() {
    cout << "Equipped Items:\n";
    cout << "Steel Sword: ";
    if (equipped.steel_sword == 0) cout << "None\n";
    else cout << *equipped.steel_sword << "\n";
    cout << "Armor: ";
    if (equipped.armor == 0) cout << "None\n";
    else cout << *equipped.armor << "\n";
}

void Human::update_total_defense() {
    if (equipped.armor != 0)
        setTotal_defense(getTotal_defense() + equipped.armor->getDefense());
}

void Human::receive_damage(int damage) {
    Entity::receive_damage(damage);
}

ostream &operator<< (ostream &out, const Human &human){
    human.print_info();
    return out;
}
