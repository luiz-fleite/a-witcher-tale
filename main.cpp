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

#include "./Utils/ui.h"

int main(void) {

    cout << "Welcome to \"A Witcher Tale\"!\n";

    Witcher player;
    Witcher * witcher_buffer = new Witcher("Geralt", 200, 200, 10, "S");
    string name_buffer;

    int choice = menu();
    if (choice == ERROR) {
        cout << "Invalid choice!\n";
        return 1;
    }
    else if (choice == NEW_GAME) {
        cout << "Starting new game...\n";
        cout << "Insert your name: ";
        getline(cin, name_buffer);
        cin.ignore();
        player = *witcher_buffer;

        player.setName(name_buffer);

        cout << "Welcome, " << player.getName() << "!\n";
    }
    else if (choice == LOAD_GAME) {
        cout << "Loading game...\n";
        load_witcher(player);
        cout << "Welcome back, " << player.getName() << "!\n";

    }
    else {
        cout << "Invalid choice!\n";
        return 1;
    }

    cout << "This is your character:\n\n";
    cout << player << "\n\n";

    cout << "Você acorda em um frio quarto de pedra, a luz fraca mal iluminando as paredes desgastadas de Kaer Morhen, a fortaleza dos bruxos. Ao se levantar, você percebe que está vestido com o característico manto dos witchers, e a lembrança de treinamentos rigorosos e mutações começa a ecoar em sua mente.";

    cout << "Ao explorar os corredores familiares da fortaleza, você encontra Vesemir, o velho mentor dos bruxos, que informa sobre a terrível ameaça que assola Kaer Morhen. Ghouls, criaturas necrófagas conhecidas por sua fome insaciável, invadiram os arredores da fortaleza. Os witchers, sua irmandade, estão prontos para enfrentar a ameaça, mas a batalha será feroz.";

    cout << "Você é convocado para se juntar aos witchers na linha de frente. Os sons distantes de uivos e arranhões ecoam pelos corredores enquanto você se equipa com sua espada de prata e poções preparadas para o combate. A atmosfera tensa em Kaer Morhen é palpável, pois a noite se aproxima e os ghouls se preparam para o ataque final.";
    cout << "\n\n";

    cout << "1. Pausar jogo\n";
    cout << "2. Gerenciar inventário\n";
    cout << "3. Explorar Kaer Morhen\n";
    cout << "4. Pronto para ir para a linha de frente.\n";
    cout << "Escolha: \n";
    cin >> choice;
    cin.ignore();

    if (choice == 1) {
        cout << "1. Salvar jogo\n";
        cout << "2. Sair do jogo\n";
        cout << "3. Sair e salvar.\n";
        cout << "Escolha: \n";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            if (save_witcher(player)) {
                cout << "Jogo salvo com sucesso!\n";
            }
            else {
                cout << "Erro ao salvar jogo!\n";
            }

        }
        else if (choice == 2) {
            cout << "Saindo do jogo...\n";
            return 0;
        }
        else if (choice == 3) {
            if (save_witcher(player)) {
                cout << "Jogo salvo com sucesso!\n";
            }
            else {
                cout << "Erro ao salvar jogo!\n";
            }

            cout << "Saindo do jogo...\n";
            return 0;
        }
        else {
            cout << "Opção inválida!\n";
            return 1;
        }
    }

    if (choice == 2) {
        player.print_inventory();
        player.print_equipped_items();

        cout << "1. Ver inventário.\n";
        cout << "2. Equipar espada.\n";
        cout << "3. Equipar armadura.\n";
        cout << "Escolha: \n";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            player.print_inventory();
            player.print_equipped_items();

        }
        else if (choice == 2) {
            cout << "Escolha a espada: \n";
            cin >> choice;
            cin.ignore();
            player.equip_item(SWORD, choice);
        }
        else if (choice == 3) {
            cout << "Escolha a armadura: \n";
            cin >> choice;
            cin.ignore();

            player.equip_item(ARMOR, choice);
        }
        else {
            cout << "Opção inválida!\n";
            return 1;
        }
    }

    if (choice == 3) {
        cout << "Explorando Kaer Morhen...\n";
        cout << "Você encontra um equipamento de bruxo!\n";
        Sword * sword1 = new Sword("Espada de prata", "Uma espada feita de prata especial contra monstros.", 6, 2, 2, 10);
        player.add_item(*sword1);
        player.print_inventory();
    }

    cout << "Você se junta aos witchers na linha de frente.\n";
    cout << "A batalha começa!\n";
    Ghoul * ghoul1 = new Ghoul("Ghoul 1");
    Ghoul * ghoul2 = new Ghoul("Ghoul 2");
    Ghoul * ghoul3 = new Ghoul("Ghoul 3");
    Sword * sword1 = new Sword("Aerondight", "Uma misteriosa espada mágica muito poderosa", 100, 100, 100, 100);
    Armor * armor1 = new Armor("Armadura da escola do lobo", "Uma armadura especial anti-monstro feita para bruxos da escola do lobo", 100, 100, 100, 100);
    ghoul1->add_item(*sword1);
    ghoul3->add_item(*armor1);

    vector <Item *> floor_items;

    Battle * battle1 = new Battle(player, *ghoul1);
    battle1->add_enemy(*ghoul2);
    battle1->add_enemy(*ghoul3);
    

    battle1->begin();

    battle1->get_floor_items(floor_items);

    if (!player) {
        cout << "GAME OVER\n";
    cout << "Parabéns, você completou a primeira aventura de \"A Witcher Tale\", essa é apenas uma versão alfa do jogo, feita com muito amor.";
    cout << "Ajude o pobre desenvolvedor ;-;\n";
    cout << "playlists pra ouvir enquanto joga (e dá a nota):\n\n";
    cout << "https://www.youtube.com/watch?v=K6ZJQjFLD58 \n";
    cout << "https://www.youtube.com/watch?v=HRpHG9Gd1qw \n";
    cout << "https://www.youtube.com/watch?v=perTTMRpc_U \n";
    cout << "https://www.youtube.com/watch?v=TNM31H0BtWE \n\n";
    cout << "E lembre-se! Como disse um sábio uma vez: \n \"Na senda do coração, como a água que flui suavemente, o amor e a misericórdia são as pontes que atravessamos para encontrar a paz. No jardim do entendimento, floresce a compaixão, nutrindo a alma como a chuva alimenta a terra seca. A verdadeira grandeza está na capacidade de amar incondicionalmente e estender a mão da misericórdia, pois, assim como a lua suaviza as águas agitadas, o amor e a misericórdia acalmam as tormentas do coração.\"\n    - Chat Generative Pre-trained Transformer v.3.5 \n\n";

        return 0;
    }

    cout << "Você se destaca na batalha, enfrentando os ghouls com habilidade afiada. A adrenalina pulsa em suas veias, enquanto o clangor de espadas, o uivo dos monstros e a magia dos bruxos se entrelaçam em uma sinfonia caótica.";

    cout << "À medida que a poeira da batalha assenta, você percebe que a vitória é de vocês, mas Kaer Morhen sofreu ferimentos profundos. Vesemir agradece a todos por sua bravura, mas adverte que a ameaça dos ghouls é apenas o começo de uma jornada mais sombria.";
    cout << "\n\n";
    cout << "Após a batalha, você encontra os itens que os ghouls deixaram para trás:\n";
    
    cout << floor_items.size() << "\n";

    cout << "\n\n";
    cout << "1. Pausar jogo.\n";
    cout << "2. Pegar os itens.\n";
    cout << "Escolha: \n";
    cin >> choice;
    cin.ignore();
    if (choice == 1) {
        cout << "1. Salvar jogo\n";
        cout << "2. Sair do jogo\n";
        cout << "3. Sair e salvar.\n";
        cout << "Escolha: \n";
        cin >> choice;
        cin.ignore();
        if (choice == 1) {
            if (save_witcher(player)) {
                cout << "Jogo salvo com sucesso!\n";
            }
            else {
                cout << "Erro ao salvar jogo!\n";
            }

        }
        else if (choice == 2) {
            cout << "Saindo do jogo...\n";
            return 0;
        }
        else if (choice == 3) {
            if (save_witcher(player)) {
                cout << "Jogo salvo com sucesso!\n";
            }
            else {
                cout << "Erro ao salvar jogo!\n";
            }

            cout << "Saindo do jogo...\n";
            return 0;
        }
        else {
            cout << "Opção inválida!\n";
            return 1;
        }
    }
    else if (choice == 2) {
        for (int i = 0; i < floor_items.size(); i++) {
            player.grab_item(floor_items);
        }
        player.print_inventory();
    }
    else {
        cout << "Opção inválida!\n";
        return 1;
    }

    cout << "O destino dos witchers agora está em suas mãos. A estrada está aberta, cheia de perigos e escolhas. Aonde você irá a partir daqui, Witcher?\n";
    cout << "\n\n";
    cout << "Parabéns, você completou a primeira aventura de \"A Witcher Tale\", essa é apenas uma versão alfa do jogo, feita com muito amor.";
    cout << "Ajude o pobre desenvolvedor ;-;\n";
    cout << "playlists pra ouvir enquanto joga (e dá a nota):\n\n";
    cout << "https://www.youtube.com/watch?v=K6ZJQjFLD58 \n";
    cout << "https://www.youtube.com/watch?v=HRpHG9Gd1qw \n";
    cout << "https://www.youtube.com/watch?v=perTTMRpc_U \n";
    cout << "https://www.youtube.com/watch?v=TNM31H0BtWE \n\n";
    cout << "E lembre-se! Como disse um sábio uma vez: \n \"Na senda do coração, como a água que flui suavemente, o amor e a misericórdia são as pontes que atravessamos para encontrar a paz. No jardim do entendimento, floresce a compaixão, nutrindo a alma como a chuva alimenta a terra seca. A verdadeira grandeza está na capacidade de amar incondicionalmente e estender a mão da misericórdia, pois, assim como a lua suaviza as águas agitadas, o amor e a misericórdia acalmam as tormentas do coração.\"\n    - Chat Generative Pre-trained Transformer v.3.5\n\n";


    return 0;
}
