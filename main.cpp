#include <iostream>
#include <string>
#include <unistd.h>  

#include "./Entities/Entity.cpp"
#include "./Entities/Human.cpp"
#include "./Entities/Monsters/Ghoul.cpp"
#include "./Events/Battle.cpp"
#include "./Entities/Witcher.cpp"
#include "./Items/Sword.cpp"
#include "./Items/Armor.cpp"
#include "./Utils/Date.cpp"

using std::cout;

int main(void) {
    Witcher w1 = Witcher();
    cout << w1 << "\n";

/*
    cout << "====Before first battle====\n";
    Witcher w1;
    w1.print_info();
    Sword s1;
    w1.addSword(s1);
    Sword s2("Silver Sword", 20);
    w1.addSword(s2);
    w1.print_swords();

    cout << "\n";

    Witcher w2(w1);
    w2.setName("Geralt");

    cout << "\n";

    Human h1;
    h1.print_info();

    cout << "\n";

    Ghoul g1;
    g1.print_info();

    cout << "\n";
    cout << "====First Battle:====\n";
    // durante a batalha o primeiro aldeão é atacado pelo
    // primeiro ghoul e o witcher tenta protege-lo

    cout << "\n";

    Battle b1(w1, g1);
    b1.print_allies();
    b1.print_enemies();
    b1.beginBattle();

    cout << "\n";
    cout << "====After first battle:====\n";
    // após a primeira batalha o witcher matou o ghoul e 
    // o aldeão sobreviveu. O witcher ganha uma nova espada e 
    // ocorre resize em seu vetor de espadas. A copia do witcher
    // fica intacta. 
    cout << "\n";

    Sword s3("Steel Sword", 15);
    w1.addSword(s3);
    w1.print_info();
    w1.print_swords();

    cout << "\n";

    g1.print_info();

    cout << "\n";

    h1.print_info();

    cout << "\n";

    w2.print_info();
    w2.print_swords();
*/
    return 0;
}
