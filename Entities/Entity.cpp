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
    max_health = 0;
    health = 0;
    max_stamina = 0;
    stamina = 0;
    category = "_";
    level = 0;
    next_level_xp = 10;
    xp = 0;
    is_stunned = false;
}

Entity::Entity(const Entity &other_entity) {
    //cout << "Copying Entity...\n";
    this->name = other_entity.name;
    this->age = other_entity.age;
    this->coins = other_entity.coins;

    this->max_health = other_entity.max_health;
    this->health = other_entity.health;
    this->max_stamina = other_entity.max_stamina;
    this->stamina = other_entity.stamina;

    this->category = other_entity.category;
    this->level = other_entity.level;
    this->next_level_xp = other_entity.next_level_xp;
    this->xp = other_entity.xp;

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

Entity::~Entity() {
    //cout << "Destroying Entity...\n";
    for_each(inventory.swords.begin(), inventory.swords.end(), [](Sword * sword) { delete sword; });
    for_each(inventory.armors.begin(), inventory.armors.end(), [](Armor * armor) { delete armor; });
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

void Entity::setMax_health(int max_health) {
    if (max_health < 0) {
        cout << "Max health cannot be negative.\n";
        this->max_health = 0;
        return;
    }
    this->max_health = max_health;
}

void Entity::setMax_stamina(int max_stamina) {
    if (max_stamina < 0) {
        cout << "Max stamina cannot be negative.\n";
        this->max_stamina = 0;
        return;
    }
    this->max_stamina = max_stamina;
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

void Entity::add_item(Item &item) {
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

void Entity::print_inventory() const {
    cout << "Inventory of " << this->name << ":\n";
    cout << "Swords:\n";

    int counter = 0;
    if (inventory.swords.empty()) {
        cout << "None\n";
    }
    for (auto sword : inventory.swords) {
        cout << ++counter << ". " << *sword << "\n";
    }

    cout << "Armors:\n";
    counter = 0;
    if (inventory.armors.empty()) {
        cout << "None\n";
    }
    for (auto armor : inventory.armors) {
        cout << ++counter << ". " << *armor << "\n";
    }
}

void Entity::life_regen(int life_regen) {
    if (life_regen < 0) {
        cout << "Life regen cannot be negative.\n";
        return;
    }
    if (getHealth() + life_regen > max_health) {
        setHealth(max_health);
        return;
    }
    this->health += life_regen;
}

void Entity::stamina_regen(int stamina_regen) {
    if (stamina_regen < 0) {
        cout << "Stamina regen cannot be negative.\n";
        return;
    }
    if (getStamina() + stamina_regen > max_stamina) {
        setStamina(max_stamina);
        return;
    }
    this->stamina += stamina_regen;
}

void Entity::gain_xp(int xp_gained) {
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

void Entity::receive_damage(int physical_damage, int fire_damage, int poison_damage, int ice_damage, int silver_damage) {
    if (physical_damage < 0 || fire_damage < 0 || poison_damage < 0 || ice_damage < 0 || silver_damage < 0) {
        cout << "Damage cannot be negative.\n";
        return;
    }
    
    int total_damage;

    int total_physical_damage = physical_damage * physical_weakness - total_physical_resistance;
    if (total_physical_damage < 0)
        total_physical_damage = 0;
    total_damage += total_physical_damage;

    int total_fire_damage = fire_damage * fire_weakness - total_fire_resistance;
    if (total_fire_damage < 0)
        total_fire_damage = 0;
    total_damage += total_fire_damage;

    int total_poison_damage = poison_damage * poison_weakness - total_poison_resistance;
    if (total_poison_damage < 0)
        total_poison_damage = 0;
    total_damage += total_poison_damage;

    int total_ice_damage = ice_damage * ice_weakness - total_ice_resistance;
    if (total_ice_damage < 0)
        total_ice_damage = 0;
    total_damage += total_ice_damage;

    int total_silver_damage = silver_damage * silver_weakness - total_silver_resistance;
    if (total_silver_damage < 0)
        total_silver_damage = 0;
    total_damage += total_silver_damage;

    if (total_damage <= 0) {
        cout << this->name << " received no damage.\n";
        return;
    }

    if (total_damage >= getHealth()) {
        total_damage = getHealth();
    }

    cout << this->name << " -" << total_damage << " damage.\n";

    setHealth(getHealth() - total_damage);

    if (getHealth() == 0) {
        cout << name << " died.\n";
    }

    return;
}

void Entity::print_resistances() const {
    cout << "Resistences:\n";
    cout << "Physical: " << this->total_physical_resistance << "\n";
    cout << "Fire: " << this->total_fire_resistance << "\n";
    cout << "Poison: " << this->total_poison_resistance << "\n";
    cout << "Ice: " << this->total_ice_resistance << "\n";
    cout << "Silver: " << this->total_silver_resistance << "\n";
}

void Entity::print_weaknesses() const {
    cout << "Weaknesses:\n";
    cout << "Physical: " << this->physical_weakness << "\n";
    cout << "Fire: " << this->fire_weakness << "\n";
    cout << "Poison: " << this->poison_weakness << "\n";
    cout << "Ice: " << this->ice_weakness << "\n";
    cout << "Silver: " << this->silver_weakness << "\n";
}

void Entity::print_info() const{
    cout << "Name: " << this->name << "\n";
    cout << "Category: " << this->category << "\n";
    cout << "Level: " << this->level << "\n";
    cout << "Age: " << this->age << "\n";
    cout << "Date of birth: ";
    this->date_of_birth.print();
    cout << "\n";
    cout << "Coins: " << this->coins << "\n";
    cout << "Health: " << this->health << "/" << this->max_health << "\n";
    cout << "Stamina: " << this->stamina << "/" << this->max_stamina << "\n";
    print_resistances();
    print_weaknesses();
    cout << "Temporary status: \n";
    cout << "Stunned: " << this->is_stunned << "\n";
    print_inventory();
}

const Entity &Entity::operator=(const Entity &assigned_entity) {
    if (this != &assigned_entity) {
        this->name = assigned_entity.name;
        this->age = assigned_entity.age;
        this->coins = assigned_entity.coins;

        this->max_health = assigned_entity.max_health;
        this->health = assigned_entity.health;
        this->max_stamina = assigned_entity.max_stamina;
        this->stamina = assigned_entity.stamina;

        this->category = assigned_entity.category;
        this->level = assigned_entity.level;
        this->next_level_xp = assigned_entity.next_level_xp;
        this->xp = assigned_entity.xp;

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

int Entity::operator==(const Entity &other_entity) const {
    // atributes check
    if (this->name != other_entity.name) return 0;
    if (this->age != other_entity.age) return 0;
    if (this->coins != other_entity.coins) return 0;

    if (this->max_health != other_entity.max_health) return 0;
    if (this->health != other_entity.health) return 0;
    if (this->max_stamina != other_entity.max_stamina) return 0;
    if (this->stamina != other_entity.stamina) return 0;

    if (this->category != other_entity.category) return 0;
    if (this->level != other_entity.level) return 0;
    if (this->next_level_xp != other_entity.next_level_xp) return 0;
    if (this->xp != other_entity.xp) return 0;

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

bool Entity::operator!() const {
    return (this->health >= 0);
}
