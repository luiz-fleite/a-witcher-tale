#ifndef ITEM_H
#define ITEM_H

#include <string>
#include <map>

using std::ostream;
using std::string;
using std::cout;
using std::map;
using std::pair;

class Item {
public:
    Item();
    Item(string name, string description);
    Item(const Item &other_Item);
    ~Item();
    
    inline string getName() const { return name; }
    inline string getDescription() const { return description; }
    
    void setName(string name);
    void setDescription(string description);

    virtual void print_info() const;

    virtual map<string, int> use(int technique) = 0;
    
    const Item &operator=(const Item &);
    int operator==(const Item &other_Item) const;
    int operator!=(const Item &other_Item) const;
protected:
    string name;
    string description;
private:
    const static int MAX_NAME_SIZE = 20;
    const static int MAX_DESCRIPTION_SIZE = 100;
};

#endif // ITEM_H
