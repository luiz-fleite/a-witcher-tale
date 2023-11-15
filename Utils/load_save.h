#include <iostream>
using std::cerr;
using std::cin;
using std::cout;

#include <string>
using std::string;
using std::getline;
using std::to_string;

#include <fstream>
using std::fstream;
using std::ifstream;
using std::ofstream;

#include <sstream>
using std::istringstream;

#include <map>
using std::map;

#include "../Entities/Humans/Witcher.h"

bool load_witcher( Witcher &loaded_witcher, 
                   string name_file = "save-files/config-witcher/config_atributes.txt" ) {
    cout << "Loading witcher...\n";
    // First creates a buffer map to store the atributes of wicther
    map<string, string> atributes_buffer;

    // Open the file for reading
    ifstream input_file(name_file);
    if (!input_file.is_open()) {
        cerr << "Error opening " << name_file << " file." << '\n';
        return false; // Exit with an error code
    }

    string line;
    string atribute_name;
    char equal_sign;
    string value;

    // Check first line if a witcher was saved or not:
    // Do all the checks to see if the file is valid
    // First get the line
    if (!(getline(input_file, line))) {
        return false;
    }
    // Then put it in a istringstream to manipulate it
    istringstream iss(line);
    // Check if it has the number of specifiers I want
    if (!(iss >> atribute_name >> equal_sign >> value)) {
        cerr << "Error parsing line: (unexpected arguments number)" << line << '\n';
        return false;
    }
    // Check if the specifiers are the ones I want
    if (!(atribute_name == "Witcher" && equal_sign == '=')) {
        cerr << "Error parsing line: (incorrect separators)" << line << '\n';
        return false;
    }
    // Check if the value is valid on my convention
    if (!(value == "1" || value == "0")) {
        cerr << "Error parsing line: (expected \"0\" or \"1\")" << line << '\n';
        return false;
    }
    // Finally checks if a Witcher was already saved before:
    if (value == "0") {
        cout << "No Witcher was saved yet.\n";
        return false;
    }
    // If a Witcher was saved before, then load it:
    while (getline(input_file, line)) 
    {
        // cout << "Parsing line: " << line << "\n";
        // Do the checks above but for every line
        // in a generic way
        istringstream iss(line);
        if (!(iss >> atribute_name >> equal_sign >> value)) {
        cerr << "Error parsing line: (unexpected arguments number) " << line << '\n';
        return false;
        }
        
        if (!(equal_sign == '=')) {
            cerr << "Error parsing line: (incorrect separator) " << line << '\n';
            return false;
        }

        // Remove leading and trailing whitespaces from the value
        value = value.substr(value.find_first_not_of(" \t"));
        value = value.substr(0, value.find_last_not_of(" \t") + 1);
        
        // putting values inside the map
        atributes_buffer[atribute_name] = value;
    }
    // Converts underscores from string atributes to spaces
    // so that the string turns back to original form
    for (auto &x : atributes_buffer) {
        replace(x.second.begin(), x.second.end(), '_', ' ');
    }

    input_file.close();

    if (atributes_buffer.empty()) {
        cerr << "No variables found.\n";
        return false;
    }

    // Then set the atributes to witcher
    loaded_witcher.setName(atributes_buffer["name"]);
    loaded_witcher.setAge(stoi(atributes_buffer["age"]));
    loaded_witcher.setCoins(stod(atributes_buffer["coins"]));

    // Sets the atributes to its level
    loaded_witcher.setCategory(atributes_buffer["category"]);
    loaded_witcher.setLevel(stoi(atributes_buffer["level"]));
    loaded_witcher.update_atributes();

    // Recovers the current health and stamina
    loaded_witcher.setHealth(stoi(atributes_buffer["health"]));
    loaded_witcher.setStamina(stoi(atributes_buffer["stamina"]));

    // Then load the inventory
    cout << "Loading inventory...\n";
    loaded_witcher.load_inventory();

    return true;
}

bool save_witcher( Witcher &saved_witcher, 
                   string name_file = "save-files/config-witcher/config_atributes.txt" )
{
    // unequip all items, to they're saved in the inventory
    for (int i = 0; i < TOTAL_ITEM_TYPES; i++) {
        saved_witcher.unequip_item(i);
    }
    // creates a buffer map to store the atributes of wicther
    map<string, string> atributes;
    // save the witcher atributes
    // update the atributes map
    atributes["name"] = saved_witcher.getName();
    atributes["age"] = to_string(saved_witcher.getAge());
    atributes["coins"] = to_string(saved_witcher.getCoins());

    // save level and category
    atributes["category"] = saved_witcher.getCategory();
    atributes["level"] = to_string(saved_witcher.getLevel());

    // saves current health and stamina
    atributes["health"] = to_string(saved_witcher.getHealth());
    atributes["stamina"] = to_string(saved_witcher.getStamina());

    // converts spaces to underscores in string atributes
    // so that the string can be saved in a file
    for (auto &x : atributes) {
        replace(x.second.begin(), x.second.end(), ' ', '_');
    }
    
    // Open the file for writing
    ofstream output_file(name_file, std::ios::out | std::ios::trunc);
    if (!output_file.is_open()) {
        cerr << "Erro ao abrir aquivo para escrita!" << '\n';
        return false; //
    }
    // First writes that there is a witcher saved
    output_file << "Witcher = 1\n";
    // Then writes all the atributes according to their type
    for (const auto& pair : atributes) {
        output_file << pair.first << " = " << pair.second << '\n';
    }
    // Then closes the file
    output_file.close();

    // Then save the witcher inventory
    saved_witcher.save_inventory();

    cout << "Witcher " << saved_witcher.getName() << " has been saved.\n";

    return true;
}
