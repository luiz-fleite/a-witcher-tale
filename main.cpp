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


int main(void) {

    // criar batalha para testar os itens
    // criar mais itens
    cout << "=========Before battle==========\n";
    Witcher * w1 = new Witcher("Geralt");
    cout << *w1;

    cout << "===============================\n";

    Ghoul * g1 = new Ghoul("Ghoul 1");
    cout << *g1;

    cout << "===============================\n";
    cout << "=========During battle=========\n";
    cout << "O witcher começa atacando o ghoul com seu sinal igni. Dando dano de fogo.\n";
    w1->attack(*g1, IGNI);
    cout << "O ghoul ataca o witcher com suas garras. Dando dano físico.\n";
    g1->attack(*w1);
    cout << "O witcher ataca o ghoul com sua espada de aço. Dando dano físico.\n";
    w1->attack(*g1, STEEL_SWORD);
    cout << "===============================\n";
    cout << "=========After battle==========\n";
    cout << *w1 << *g1;
    cout << "===============================\n";
    cout << "Após isso uma espada e uma armadura de aço caem no chão como recompensa para o witcher.\n";
    cout << "E ele as pega.\n";
    Sword * s1 = new Sword("Espada de aço", "Uma espada de aço afiada", 10, 10, 10);
    Armor * a1 = new Armor("Armadura de aço", "Uma armadura de aço resistente", 10, 10, 10);
    vector <Item*> floor_items;
    floor_items.push_back(s1);
    floor_items.push_back(a1);

    w1->grab_item(floor_items);
    w1->grab_item(floor_items);

    cout << *w1;
    cout << "===============================\n";
    cout << "Agora o witcher esta cansado de jogar e salva o jogo para voltar uma outra hora.\n";
    if (save_witcher(*w1)) {
        cout << "Jogo salvo com sucesso.\n";
    } else {
        cout << "Erro ao salvar o jogo.\n";
    }
    delete w1;

    cout << "===============================\n";
    cout << "Depois de um tempo o witcher volta pra continuar seu progresso.\n";
    cout << "Ele carrega o jogo salvo anteriormente.\n";
    Witcher * w2 = new Witcher();
    if (load_witcher(*w2)) {
        cout << "Jogo carregado com sucesso.\n";
    } else {
        cout << "Erro ao carregar o jogo.\n";
    }
    cout << *w2;
    cout << "===============================\n";
    cout << "Após isso é possível perceber que todos os seus atributos foram salvos.\n";
    cout << "A vida e a estamina estão decrementada, e todos os seus itens estão no inventario.\n";

    return 0;
}
