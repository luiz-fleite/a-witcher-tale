#include <iostream>
#include <string>
#include <unistd.h>  

#include "./Entities/Entity.cpp"

#include "./Entities/Humans/Human.cpp"
#include "./Entities/Humans/Witcher.cpp"

#include "./Entities/Monsters/Ghoul.cpp"

#include "./Events/Battle.cpp"

#include "./Items/Item.cpp"
#include "./Items/Weapons/Weapon.cpp"
#include "./Items/Weapons/Sword.cpp"
#include "./Items/Armors/Armor.cpp"

#include "./Spells/Spell.cpp"
#include "./Spells/Signs/Sign.cpp"
#include "./Spells/Signs/Igni.cpp"

#include "./Utils/Date.cpp"

#include "./Utils/load_save.h"

// #include "./Utils/ui.h"

int main(void) {

    cout << "=========Before battle==========\n";

    cout << "O jogador começa como Geralt e se prepara para enfrentar 3 Ghouls.\n";

    Witcher * w1 = new Witcher("Geralt");
    cout << *w1;

    cout << "===============================\n";

    Ghoul * g1 = new Ghoul("Ghoul 1");
    Sword * s1 = new Sword("Sharpened sword", "Well sharpened steel sword", 10, 10, 10);
    g1->add_item(*s1);
    cout << *g1;

    cout << "===============================\n";

    Ghoul * g2 = new Ghoul("Ghoul 2");
    Armor * a1 = new Armor("Steel armor", "Well crafted steel armor", 10, 10, 10);
    g2->add_item(*a1);
    cout << *g2;

    cout << "===============================\n";

    Ghoul * g3 = new Ghoul("Ghoul 3");
    Sword * s2 = new Sword("Broken sword", "A rusty broken steel sword", 1);
    g3->add_item(*s2);
    cout << *g3;

    cout << "===============================\n";

    cout << "Inicialmente não há itens no chão.\n";

    vector <Item *> floor_items;
    cout << "Floor items: " << floor_items.size() << "\n";

    cout << "===============================\n";
    cout << "=========During battle=========\n";
    Battle * b1 = new Battle(*w1, *g1);
    b1->add_enemy(*g2);
    b1->add_enemy(*g3);

    b1->begin();

    b1->get_floor_items(floor_items);

    cout << "===============================\n";
    cout << "=========After battle==========\n";
    cout << "Depois da batalha Geralt vence os 3 Ghouls, \n";
    cout << "ganha 150 de xp e sobe de nivel e ganha as recompensas em moedas.\n";
 
    
    cout << *w1 << *g1 << *g2 << *g3;

    cout << "===============================\n";

    cout << "E os itens dos Ghouls caem no chão.\n";
    cout << "Floor items: " << floor_items.size() << "\n";

    cout << "===============================\n";

    cout << "Após isso, Geralt recupera todos os itens do chão.\n";
    while (!floor_items.empty()) {
        w1->grab_item(floor_items);
    }
    
    cout << "Floor items: " << floor_items.size() << "\n";

    cout << "===============================\n";

    cout << "E os itens são adicionados ao inventário de Geralt.\n";
    cout << *w1;

    cout << "O Geralt compara os itens novos com os equipados e percebe que são melhores.\n";
    cout << "Então ele equipa os novos itens.\n";
    w1->equip_item(SWORD, 1);
    w1->equip_item(ARMOR, 0);
    cout << *w1;

    cout << "===============================\n";

    cout << "Depois disso, Geralt encontra um novo Ghoul mais forte que o anteriores, \n";
    cout << "pois o jogador subiu de nivel e as novas criaturas geradas \n";
    cout << "devem acompanhar seu nivel, e o jogador é atacado e foge.\n";

    Ghoul * g4 = new Ghoul("Ghoul 4");
    cout << *g4;
    g4->attack(*w1);

    cout << "===============================\n";

    cout << "Em seguida, o jogador percebe que precisa salvar o jogo para \n";
    cout << "preservar seus itens e voltar uma outra hora.\n";

    if (save_witcher(*w1)) {
        cout << "Jogo salvo com sucesso!\n";
    }
    else {
        cout << "Erro ao salvar o jogo!\n";
    }

    delete w1;
    delete g1;
    delete g2;
    delete g3;

    cout << "===============================\n";
    cout << "Depois de um tempo o jogador retorna para jogar novamente e carrega o jogo.\n";
    Witcher * w2 = new Witcher();
    if (load_witcher(*w2)) {
        cout << "Jogo carregado com sucesso!\n";
    }
    else {
        cout << "Erro ao carregar o jogo!\n";
    }
    cout << *w2;
    cout << "Como é possível observar, o jogador esta com todos os atributos "; 
    cout << "e itens salvos com sucesso.\n";

    return 0;
}
