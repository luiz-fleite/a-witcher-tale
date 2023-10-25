#include <iostream>
#include <string>

#include "Entity.h"

using std::cout;

const string Entity::CATEGORIES[7] = {"F", "E", "D", "C", "B", "A", "S"};

Entity::Entity() {
    //cout << "Creating a new Entity...\n";
    name = "Entity";
    age = 0;
    coins = 0;
    health = 0;
    stamina = 0;
    category = "_";
    level = 0;
    total_defense = 0;
    is_stunned = false;
}

Entity::Entity(const Entity &other_entity) {
    this->name = other_entity.name;
    this->age = other_entity.age;
    this->coins = other_entity.coins;
    this->health = other_entity.health;
    this->stamina = other_entity.stamina;
    this->category = other_entity.category;
    this->level = other_entity.level;
    this->total_defense = other_entity.total_defense;
    this->is_stunned = other_entity.is_stunned;
}

Entity::~Entity() {
    //cout << "Destroying Entity...\n";
}

void Entity::setName(string name) {
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

void Entity::setAge(int age) {
    if (age < 0) {
        cout << "Age cannot be negative.\n";
        this->age = 0;
        return;
    }
    this->age = age;
}

void Entity::setCoins(double coins) {
    if (coins < 0) {
        cout << "Coins cannot be negative.\n";
        this->coins = 0;
        return;
    }
    this->coins = coins;
}

void Entity::setHealth(int health) {
    if (health < 0) {
        //cout << "Health cannot be negative.\n";
        this->health = 0;
        return;
    }
    this->health = health;
}

void Entity::setStamina(int stamina) {
    if (stamina < 0) {
        cout << "Stamina cannot be negative.\n";
        this->stamina = 0;
        return;
    }
    this->stamina = stamina;
}

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

void Entity::setTotal_defense(int total_defense) {
    if (total_defense < 0) {
        cout << "Total defense cannot be negative.\n";
        this->total_defense = 0;
        return;
    }
    this->total_defense = total_defense;
}


void Entity::add_sword(Sword &sword) {
    Sword * new_sword = new Sword(sword);
    inventory.swords.push_back(new_sword);
}

void Entity::add_armor(Armor &armor) {
    Armor * new_armor = new Armor(armor);
    inventory.armors.push_back(new_armor);
}

void Entity::drop_sword(int index) {
    if (index < 0 || index >= inventory.swords.size()) {
        cout << "Invalid index.\n";
        return;
    }
    inventory.swords.erase(inventory.swords.begin() + index);
}

void Entity::drop_armor(int index) {
    if (index < 0 || index >= inventory.armors.size()) {
        cout << "Invalid index.\n";
        return;
    }
    inventory.armors.erase(inventory.armors.begin() + index);
}

void Entity::print_inventory() const {
    cout << "Inventory of " << this->name << ":\n";
    cout << "Swords:\n";
    for (auto sword : inventory.swords) {
        cout << *sword << "\n";
    }
    cout << "Armors:\n";
    for (auto armor : inventory.armors) {
        cout << *armor << "\n";
    }
}

void Entity::receive_damage(int damage) {
    if (damage < 0) {
        cout << "Damage cannot be negative.\n";
        return;
    }
    damage -= this->total_defense;
    if (damage <= 0) {
        cout << this->name << " received no damage.\n";
        return;
    }
    if (damage >= getHealth()) {
        damage = getHealth();
    }
    setHealth(getHealth() - damage);
    if (getHealth() == 0) {
        cout << name << " died.\n";
    }
    return;
}

void Entity::print_info() const{
    cout << "Name: " << this->name << "\n";
    cout << "Category: " << this->category << "\n";
    cout << "Level: " << this->level << "\n";
    cout << "Age: " << this->age << "\n";
    cout << "Coins: " << this->coins << "\n";
    cout << "Health: " << this->health << "\n";
    cout << "Stamina: " << this->stamina << "\n";
    cout << "Total defense: " << this->total_defense << "\n";
    cout << "Temporary status:\n" << "Is stunned: " << this->is_stunned << "\n";
}
