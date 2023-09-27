#include <iostream>
#include <string>
#include <unistd.h>  

#include "human.h"
#include "human.cpp"
#include "ghoul.h"
#include "ghoul.cpp"

using std::cout;

int main(void) {

    cout << "====Before battle:====\n";
    // antes da batalha um aldeão e um ghoul são criados
    // e cada um é copiado

    Human h1;
    h1.print_info();

    cout << "\n";

    Human h2(h1);
    h2.setName("Other peasant");
    h2.print_info();

    cout << "\n";

    // o homem constante não pode ser atacado pois
    // se tentar decrementar sua vida o programa
    // retorna um erro, mas ele pode ser usado para representar
    // um personagem importante para o jogo que não pode desaparecer
    // ou ser modificado, pois do contrário o jogo não funcionaria,
    // como não chegar ao fim da história por exemplo
    const Human h3("Constant Man", 35, 200, 125, 125);
    h3.print_info();

    cout << "\n";

    Ghoul g1;
    g1.print_info();

    cout << "\n";

    Ghoul g2(g1);
    g2.setName("Other ghoul");
    g2.print_info();

    cout << "\n";
    cout << "====During battle:====\n";
    // durante a batalha o primeiro aldeão é atacado pelo
    // primeiro ghoul ate q ele morra ou o ghoul canse

    while(h1.getHealth() > 0 && g1.getStamina() > 0) {
        g1.attack(h1);
        sleep(1);
    }
    
    g1.attack(h1);
    
    cout << "\n";
    cout << "====After battle:====\n";
    // depois da batalha o aldeão atacado está com menos vida
    // e o ghoul com menos stamina
    // mas as copias de cada um estão intactas

    h1.print_info();

    cout << "\n";

    g1.print_info();

    cout << "\n";
    
    g2.print_info();

    cout << "\n";

    h2.print_info();

    cout << "\n";

    h3.print_info();

    return 0;
}