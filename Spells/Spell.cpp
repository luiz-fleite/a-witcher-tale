
#include "Spell.h"


Spell::Spell() {
    //cout << "Creating a new Spell...\n";
    name = "Spell";
    description = "A generic Spell.";
}

Spell::Spell(const Spell &other_spell) {
    this->name = other_spell.name;
    this->description = other_spell.description;
}

Spell::~Spell() {
    //cout << "Destroying Spell...\n";
}

void Spell::setName(string name) {
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

void Spell::setDescription(string description) {
    description.erase(0, description.find_first_not_of(' '));
    description.erase(description.find_last_not_of(' ') + 1);
    if (description == "") {
        cout << "Description cannot be empty.\n";
        this->description = "Empty_Description";
        return;
    }
    if (description.length() > MAX_DESCRIPTION_SIZE) {
        cout << "Max description size is " << MAX_DESCRIPTION_SIZE << " characters. Description shortened.\n";
        this->description = description.substr(0, MAX_DESCRIPTION_SIZE);
        return;
    }
    this->description = description;
}

void Spell::print_info() const {
    cout << "Name: " << name << '\n';
    cout << "Description: " << description << '\n';
}

const Spell &Spell::operator=(const Spell &other_spell) {
    this->name = other_spell.name;
    this->description = other_spell.description;
    return *this;
}

int Spell::operator==(const Spell &other_spell) const {
    if (this->name != other_spell.name) return 0;
    if (this->description != other_spell.description) return 0;
    return 1;
}

int Spell::operator!=(const Spell &other_spell) const {
    return !(*this == other_spell);
}
