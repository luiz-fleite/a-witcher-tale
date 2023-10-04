#include <iostream>
#include <string>
#include <unistd.h>  

#include "Human.h"
#include "Human.cpp"
#include "Ghoul.h"
#include "Ghoul.cpp"
#include "Battle.h"
#include "Battle.cpp"

using std::cout;

int main(void) {

    cout << "====First Battle:====\n";
    // durante a batalha o primeiro aldeão é atacado pelo
    // primeiro ghoul ate q ele morra

    Human h1;
    h1.print_info();

    cout << "\n";

    Ghoul g1;
    g1.print_info();

    cout << "\n";

    Battle b1(h1, g1);
    b1.getAllies();
    b1.getEnemies();
    b1.beginBattle();

    cout << "\n";
    cout << "====After first battle:====\n";

    cout << "\n";

    h1.print_info();

    cout << "\n";

    g1.print_info();

    cout << "\n";
    cout << "====Seccond Battle:====\n";
    // testando a batalha com o maximo de aldeões e ghouls de niveis maiores
    h1.setName("Peasant 1");
    // regenera o primeiro aldeão e o copia para
    // preencher o vetor de aliados
    h1.setHealth(50);
    Human h2;
    h2.setName("Peasant 2");

    g1.setName("Ghoul 1");
    // regenera a stamina do ghoul e aumenta seu level, depois o copia
    // para preencher o vetor de inimigos
    g1.setStamina(50);
    g1.setLevel(10);
    Ghoul g2;
    g2.setName("Ghoul 2");
    Ghoul g3;
    g3.setName("Ghoul 3");
    Ghoul g4;
    g4.setName("Ghoul 4");
    Ghoul g5;
    g5.setName("Ghoul 5");

    Battle b2(h1, g1);
    b2.addAllies(h2);
    b2.addEnemies(g2);
    b2.addEnemies(g3);
    b2.addEnemies(g4);
    b2.addEnemies(g5);
    b2.getAllies();
    b2.getEnemies();
    // é possivel ver na saida o aumento de dano dos ghouls devido
    // ao aumento de level
    b2.beginBattle();
    
    cout << "\n";
    cout << "====After seccond battle:====\n";
    // os aldeões morreram porque não puderam revidar
    h1.print_info();

    cout << "\n";

    h2.print_info();

    cout << "\n";
    // os ghouls acabam com menos stamina do que começaram
    g1.print_info();

    cout << "\n";

    return 0;
}
