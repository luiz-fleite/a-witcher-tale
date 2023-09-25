#include <iostream>
#include <string>

#include "human.h"
#include "human.cpp"

using std::cout;
using std::endl;

int main(void) {

    Human h1;
    h1.print_info();
    h1.talk();
    h1.walk();

    cout << endl;

    Human h2("Claudomiro", 35, 12125.12, 200, 200);
    h2.print_info();
    h2.talk();
    h2.walk();

    cout << endl;
    
    Human h3("Geralt");
    h3.print_info();
    h3.talk();
    h3.walk();

    cout << endl;

    Human h4("", -35, -12125.12, -100, -100);
    h4.print_info();
    h4.talk();
    h4.walk();

    return 0;
}