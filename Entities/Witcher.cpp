#include <iostream>
#include <string>

#include "Witcher.h"

using std::cout;

Witcher::Witcher() {
    //cout << "Creating a new Witcher...\n";
    name = "Witcher";
    age = 200;
    coins = 150;
    max_health = 100;
    health = max_health;
    max_stamina = 100;
    stamina = max_stamina;
    category = CATEGORIES[0];
    level = 1;
    is_stunned = false;

    date_of_birth = Date(1, 1, 1000 - age);

}

Witcher::Witcher(string name, int age, double coins, int max_health, int max_stamina, string category) {
    setName(name);
    setAge(age);
    setCoins(coins);
    setMax_health(max_health);
    life_regen(max_health);
    setMax_stamina(max_stamina);
    stamina_regen(max_stamina);
    setCategory(category);
    setLevel(1);
    is_stunned = false;

    date_of_birth = Date(1, 1, 1000 - age);
}


Witcher::Witcher(const Witcher &other_witcher) : Human(static_cast<Human>(other_witcher)) {
    //cout << "Copying Witcher...\n";
}

Witcher::~Witcher() {
    //cout << "Destroying Witcher...\n";
    for_each(personal_chest.begin(), personal_chest.end(), [](pair<string, Item*> pair) {
        delete pair.second;
    });
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
                                    stoi(items_atributes_buffer["damage"]));
            add_item(*new_sword);
            // Cleans buffer variables
            delete new_sword;
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
                                    stoi(items_atributes_buffer["defense"]));
            add_item(*new_armor);
            // Cleans buffer variables
            delete new_armor;
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
        items_atributes_buffer["damage"] = to_string(sword->getDamage());
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
        items_atributes_buffer["defense"] = to_string(armor->getDefense());
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

void Witcher::store_item(Item &item) {
    if (Sword * sword = dynamic_cast<Sword *>(&item)) {
        Sword * new_sword = new Sword(*sword);
        personal_chest[new_sword->getName()] = new_sword;
    }
    else if (Armor * armor = dynamic_cast<Armor *>(&item)) {
        Armor * new_armor = new Armor(*armor);
        personal_chest[new_armor->getName()] = new_armor;
    }
    else {
        cout << "Item not stored.\n";
    }
    
}

void Witcher::unstore_item(string item_name) {
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

void Witcher::attack(Entity &entity) {
    if (getStamina() < WITCHER_ATTACK_COST) {
        cout << name << " has no stamina left to attack.\n";
        return;
    }
    setStamina(getStamina() - WITCHER_ATTACK_COST);
    // Dano aleatorio entre MIN_WITCHER_DAMAGE e MAX_WITCHER_DAMAGE
    srand(static_cast<unsigned int>(time(nullptr)));
    int damage = MIN_WITCHER_DAMAGE + rand() % (MAX_WITCHER_DAMAGE - MIN_WITCHER_DAMAGE + 1);
    // Dano aumenta com o level
    damage = damage + (getLevel() / 3);
    // Dano aumenta com a espada equipada
    if (equipped.steel_sword != 0) damage += equipped.steel_sword->getDamage();
    // Dano diminui com a defesa da armadura do alvo
    //damage -= entity.getDefense();
    entity.receive_damage(damage);
    cout << name << " attacked " << entity.getName() << ".\n";
    cout << entity.getName() << " -" << damage << " damage.\n";
    return;
}

ostream &operator<< (ostream &out, const Witcher &witcher){
    out << static_cast<Human>(witcher);
    return out;
}

const Witcher &Witcher::operator=(const Witcher &other_witcher) {
    if (this != &other_witcher) {
        *static_cast< Human * >( this ) = static_cast< Human >( other_witcher );
    }
    return *this;
}

bool Witcher::operator==(const Witcher &other_witcher) const {
    return static_cast< Human >( *this ) == static_cast< Human >( other_witcher );
}

bool Witcher::operator!=(const Witcher &other_witcher) const {
    return static_cast< Human >( *this ) != static_cast< Human >( other_witcher );
}
