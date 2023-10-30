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

    date_of_birth = Date(1, 1, 1000 - age);

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

    date_of_birth = Date(1, 1, 1000 - age);

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

void Human::equip_sword(int sword_index) {
    if (sword_index < 0 || sword_index >= inventory.swords.size()) {
        cout << "Invalid sword index.\n";
        return;
    }
    if (equipped.steel_sword != 0) {
        add_sword(*equipped.steel_sword);
        cout << "Unequipped " << *equipped.steel_sword << ".\n";
    }
    equipped.steel_sword = inventory.swords[sword_index];
    inventory.swords.erase(inventory.swords.begin() + sword_index);
    cout << "Equipped " << *equipped.steel_sword << ".\n";
}

void Human::equip_armor(int armor_index) {
    if (armor_index < 0 || armor_index >= inventory.armors.size()) {
        cout << "Invalid armor index.\n";
        return;
    }
    if (equipped.armor != 0) {
        add_armor(*equipped.armor);
        cout << "Unequipped " << *equipped.armor << ".\n";
    }
    equipped.armor = inventory.armors[armor_index];
    inventory.armors.erase(inventory.armors.begin() + armor_index);
    cout << "Equipped " << *equipped.armor << ".\n";
    update_total_defense();
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
        setTotal_defense(equipped.armor->getDefense());
    else
        setTotal_defense(0);
}

void Human::receive_damage(int damage) {
    Entity::receive_damage(damage);
}

ostream &operator<< (ostream &out, const Human &human){
    human.print_info();
    return out;
}

const Human &Human::operator=(const Human &other_human) {
    if (this != &other_human) {
        // forma não permitida pela classe abstrata
        //*static_cast< Entity * >( this ) = static_cast< Entity >( other_human );
        // forma sugerida pela IA
        Entity::operator=(other_human);
        if (other_human.equipped.steel_sword == 0) equipped.steel_sword = 0;
        else equipped.steel_sword = new Sword(*other_human.equipped.steel_sword);

        if (other_human.equipped.armor == 0) equipped.armor = 0;
        else equipped.armor = new Armor(*other_human.equipped.armor);
    }
    return *this;
}

bool Human::operator==(const Human &other_human) const {
    if (!Entity::operator==(other_human)) return false;
    return true;
}

bool Human::operator!=(const Human &other_human) const {
    return !(*this == other_human);
}
