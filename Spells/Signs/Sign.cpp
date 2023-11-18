
#include "Sign.h"


Sign::Sign() {
    this->name = "Sign";
    this->description = "A sign spell.";
    this->is_unlocked = false;
    this->stamina_cost = 0;
}

Sign::Sign(const Sign &other_sign) : Spell(other_sign) {
    this->is_unlocked = other_sign.is_unlocked;
    this->stamina_cost = other_sign.stamina_cost;
}

Sign::~Sign() {
    // cout << "Sign destructor called.\n";
}

void Sign::setStamina_cost(int stamina_cost) {
    if (stamina_cost < 0) {
        cout << "Stamina cost cannot be negative.\n";
        this->stamina_cost = 0;
        return;
    }
    this->stamina_cost = stamina_cost;
}

void Sign::print_info() const {
    Spell::print_info();
    cout << "Is unlocked: " << is_unlocked << "\n";
    cout << "Stamina cost: " << stamina_cost << "\n";
}

const Sign &Sign::operator=(const Sign &other_sign) {
    if (this != &other_sign) {
        Spell::operator=(other_sign);
        this->is_unlocked = other_sign.is_unlocked;
        this->stamina_cost = other_sign.stamina_cost;
    }
    return *this;
}

int Sign::operator==(const Sign &other_sign) const {
    Spell::operator==(other_sign);

    if (this->is_unlocked != other_sign.is_unlocked) return 0;
    if (this->stamina_cost == other_sign.stamina_cost) return 0;

    return 1;
}

int Sign::operator!=(const Sign &other_sign) const {
    return !(*this == other_sign);
}