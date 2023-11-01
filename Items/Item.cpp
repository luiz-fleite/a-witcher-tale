#include <iostream>
#include <string>

#include "Item.h"

using std::cout;

Item::Item() {
    //cout << "Creating a new Item...\n";
    name = "Item";
    description = "A generic item.";
}

Item::Item(string name, string description) {
    setName(name);
    setDescription(description);
}

Item::Item(const Item &other_Item) {
    this->name = other_Item.name;
    this->description = other_Item.description;
}

Item::~Item() {
    //cout << "Destroying Item...\n";
}

void Item::setName(string name) {
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

void Item::setDescription(string description) {
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

void Item::print_info() const {
    cout << "Name: " << name << '\n';
    cout << "Description: " << description << '\n';
}

const Item &Item::operator=(const Item &other_Item) {
    this->name = other_Item.name;
    this->description = other_Item.description;
    return *this;
}

int Item::operator==(const Item &other_Item) const {
    if (this->name != other_Item.name) return 0;
    if (this->description != other_Item.description) return 0;
    return 1;
}

int Item::operator!=(const Item &other_Item) const {
    return !(*this == other_Item);
}
