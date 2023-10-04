#ifndef HUMAN_H
#define HUMAN_H

#include <string>
using std::string;

class Human {
public:
    Human();
    Human(string name,
        int age=30, 
        double coins=100, 
        int health=100, 
        int stamina=100,
        string category="E");
    Human(const Human &human);

    string getName() const;
    int getAge() const;
    double getCoins() const;
    int getHealth() const;
    int getStamina() const;
    string getCategory() const;
    int getLevel() const;
    bool getIs_stunned() const;

    void setName(string name);
    void setAge(int age);
    void setCoins(double coins);
    void setHealth(int health);
    void setStamina(int stamina);
    void setCategory(string category);
    void setLevel(int level);
    void setIs_stunned(bool is_stunned);
    
    void print_info() const;
    void talk();
    void walk();
private:
    string name;
    int age;
    double coins;
    int health;
    int stamina;
    string category;
    int level;
    
    bool is_stunned = false;

    const static int MAX_NAME_SIZE = 20;
    const static string CATEGORIES[7];
};

#endif // HUMAN_H
