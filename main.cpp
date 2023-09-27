#include <iostream>
#include <string>

#include "human.h"
#include "human.cpp"

using std::cout;

int main(void) {

    Human h1;
    h1.print_info();
    h1.talk();
    h1.walk();

    cout << "\n";

    Human h2("Claudomiro", 35, 12125.12, 200, 200);
    h2.print_info();
    h2.talk();
    h2.walk();

    cout << "\n";
    
    Human h3("Geralt");
    h3.print_info();
    h3.talk();
    h3.walk();

    cout << "\n";

    Human h4("   ", -35, -12125.12, -100, -100);
    h4.print_info();
    h4.talk();
    h4.walk();

    cout << "\n";

    Human h5("Shortened Too long name", -1, -1, -1, -1);
    h5.print_info();
    h5.talk();
    h5.walk();

    cout << "\n";

    Human h6("    Name with spaces     ", -1, -1, -1, -1);
    h6.print_info();
    h6.talk();
    h6.walk();

    cout << "\n";

    return 0;
}