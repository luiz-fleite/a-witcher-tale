#ifndef SPELL_H
#define SPELL_H

#include <iostream>
using std::cout;
using std::ostream;

#include <string>
using std::string;

#include <map>
using std::map;
using std::pair;


class Spell {
public:
    Spell();
    Spell(const Spell &other_spell);
    ~Spell();
    
    inline string getName() const { return name; }
    inline string getDescription() const { return description; }
    
    void setName(string name);
    void setDescription(string description);

    virtual void print_info() const;

    virtual map<string, int> cast(int technique) = 0;
    
    const Spell &operator=(const Spell &);
    int operator==(const Spell &other_spell) const;
    int operator!=(const Spell &other_spell) const;
protected:
    string name;
    string description;
private:
    const static int MAX_NAME_SIZE = 20;
    const static int MAX_DESCRIPTION_SIZE = 100;
};

#endif // SPELL_H
