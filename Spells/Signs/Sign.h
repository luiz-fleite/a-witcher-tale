#ifndef SIGN_H
#define SIGN_H

#include "../Spell.h"


class Sign : public Spell{
public:
    Sign();
    Sign(const Sign &other_sign);
    ~Sign();

    inline bool getIs_unlocked() const { return is_unlocked; }
    inline int getStamina_cost() const { return stamina_cost; }

    inline void setIs_unlocked(bool is_unlocked) { this->is_unlocked = is_unlocked; }
    void setStamina_cost(int stamina_cost);

    void print_info() const;

    virtual map<string, int> cast(int technique) = 0;

    const Sign &operator=(const Sign &);
    int operator==(const Sign &other_sign) const;
    int operator!=(const Sign &other_sign) const;
protected:
    bool is_unlocked;
    int stamina_cost;
};


#endif // SIGN_H