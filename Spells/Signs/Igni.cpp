
#include "Igni.h"


Igni::Igni() {
    this->name = "Igni";
    this->description = "A fire spell that deals damage to 3 enemies at a time.";
    this->is_unlocked = false;
    this->stamina_cost = 6;
    this->fire_damage = 8;
    this->area = 3;
}

Igni::Igni(string name, 
           string description, 
           bool is_unlocked, 
           int stamina_cost, 
           int fire_damage, 
           int area) {
    this->name = name;
    this->description = description;
    this->is_unlocked = is_unlocked;
    this->stamina_cost = stamina_cost;
    this->fire_damage = fire_damage;
    this->area = area;
}

Igni::Igni(const Igni &other_igni) : Sign(other_igni) {
    this->fire_damage = other_igni.fire_damage;
    this->area = other_igni.area;
}

Igni::~Igni() {
    // cout << "Igni destructor called.\n";
}

void Igni::setFire_damage(int fire_damage) {
    if (fire_damage < 0) {
        cout << "Fire damage cannot be negative.\n";
        this->fire_damage = 0;
        return;
    }
    this->fire_damage = fire_damage;
}

void Igni::setArea(int area) {
    if (area < 0) {
        cout << "Area cannot be negative.\n";
        this->area = 0;
        return;
    }
    this->area = area;
}

void Igni::print_info() const {
    Sign::print_info();
    cout << "Fire damage: " << fire_damage << "\n";
    cout << "Area: " << area << "\n";
}

map<string, int> Igni::cast(int technique) {

    map<string, int> sign_info;

    sign_info["is_unlocked"] = is_unlocked;
    sign_info["fire_damage"] = fire_damage;
    sign_info["area"] = area;
    sign_info["stamina_cost"] = stamina_cost;

    return sign_info;
}

ostream &operator<<(ostream &out, const Igni &igni) {
    out << igni.name << "\n";
    out << igni.description << "\n";
    out << igni.is_unlocked << "\n";
    out << igni.stamina_cost << "\n";
    out << igni.fire_damage << "\n";
    out << igni.area << "\n";

    return out;
}

const Igni &Igni::operator=(const Igni &other_igni) {
    if (this != &other_igni) {
        Sign::operator=(other_igni);
        this->fire_damage = other_igni.fire_damage;
        this->area = other_igni.area;
    }
    return *this;
}

int Igni::operator==(const Igni &other_igni) const {
    Sign::operator==(other_igni);

    if (this->fire_damage != other_igni.fire_damage) return 0;
    if (this->area != other_igni.area) return 0;

    return 1;
}

int Igni::operator!=(const Igni &other_igni) const {
    return !(*this == other_igni);
}
