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
    for_each(chest_swords.begin(), chest_swords.end(), [](pair<string, Sword*> pair) {
        delete pair.second;
    });
}

void Witcher::store_sword(Sword &sword) {
    Sword * new_sword = new Sword(sword);
    chest_swords[sword.getName()] = new_sword;
}

void Witcher::unstore_sword(string sword_name) {
    chest_swords.erase(sword_name);
}

void Witcher::print_chest_swords() const {
    for (auto const& x : chest_swords)
    {
        cout << x.first  // string (key)
            << ':'
            << *x.second // string's value 
            << "\n";
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
