#ifndef ARMOR_H
#define ARMOR_H

#include <string>

using std::ostream;
using std::string;

class Armor {
    friend ostream &operator<< (ostream &out, const Armor &armor);
public:
    Armor();
    Armor(string name, int defense=5);
    Armor(const Armor &other_armor);
    ~Armor();
    
    inline string getName() const { return name; }
    inline int getDefense() const { return defense; }
    //inline string getCategory() const { return category; }
    
    void setName(string name);
    void setDefense(int defense);
    //void setCategory(string category);

    const Armor &operator=(const Armor &);
    int operator==(const Armor &other_armor) const;
    int operator!=(const Armor &other_armor) const;
private:
    string name;
    int defense;
    //string category;

    //const static string CATEGORIES[7];
    const static int MAX_NAME_SIZE = 20;
};

#endif // ARMOR_H
