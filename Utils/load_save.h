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

#include "../Entities/Witcher.h"

bool load_witcher( Witcher &loaded_witcher, string name_file ) {
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
    loaded_witcher.setMax_health(stoi(atributes_buffer["max_health"]));
    loaded_witcher.setHealth(stoi(atributes_buffer["health"]));
    loaded_witcher.setMax_stamina(stoi(atributes_buffer["max_stamina"]));
    loaded_witcher.setStamina(stoi(atributes_buffer["stamina"]));
    loaded_witcher.setCategory(atributes_buffer["category"]);
    loaded_witcher.setLevel(stoi(atributes_buffer["level"]));
    // Then load the inventory
    loaded_witcher.load_inventory();

    return true;
}

bool save_witcher( Witcher &witcher, string name_file )
{
    map<string, string> atributes;
    // First save the witcher atributes
    // First update the atributes map
    atributes["name"] = witcher.getName();
    atributes["age"] = to_string(witcher.getAge());
    atributes["coins"] = to_string(witcher.getCoins());
    atributes["max_health"] = to_string(witcher.getMax_health());
    atributes["health"] = to_string(witcher.getHealth());
    atributes["max_stamina"] = to_string(witcher.getMax_stamina());
    atributes["stamina"] = to_string(witcher.getStamina());
    atributes["category"] = witcher.getCategory();
    atributes["level"] = to_string(witcher.getLevel());
    atributes["physical_weakness"] = to_string(witcher.getPhysical_weakness());
    atributes["fire_weakness"] = to_string(witcher.getFire_weakness());
    atributes["poison_weakness"] = to_string(witcher.getPoison_weakness());
    atributes["ice_weakness"] = to_string(witcher.getIce_weakness());
    atributes["silver_weakness"] = to_string(witcher.getSilver_weakness());
    atributes["total_physical_resistance"] = to_string(witcher.getTotal_physical_resistance());
    atributes["total_fire_resistance"] = to_string(witcher.getTotal_fire_resistance());
    atributes["total_poison_resistance"] = to_string(witcher.getTotal_poison_resistance());
    atributes["total_ice_resistance"] = to_string(witcher.getTotal_ice_resistance());
    atributes["total_silver_resistance"] = to_string(witcher.getTotal_silver_resistance());

    
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
    witcher.save_inventory();

    cout << "Witcher " << atributes["name"] << " has been saved.\n";

    return true;
}
