#include <iostream>
#include <ncurses.h>
#include <string>
#include <curses.h>

using namespace std;

void menuDisplay(const string menuItems[], int itemCount) {
    initscr(); // Inicializa a biblioteca ncurses
    curs_set(0); // Oculta o cursor
    noecho(); // Desativa a exibição das teclas digitadas
    keypad(stdscr, TRUE); // Habilita teclas especiais como as setas

    int selectedItem = 0;

    while (true) {
        clear();

        // Imprimir o menu
        for (int i = 0; i < itemCount; i++) {
            mvprintw(i + 1, 2, menuItems[i].c_str());
        }

        // Destacar o item selecionado
        attron(A_REVERSE);
        mvprintw(selectedItem + 1, 2, menuItems[selectedItem].c_str());
        attroff(A_REVERSE);

        refresh();

        // Detectar a entrada do teclado
        int key = getch();

        // Processar a entrada do teclado
        switch (key) {
            case KEY_UP:
                selectedItem = (selectedItem - 1 + itemCount) % itemCount;
                break;
            case KEY_DOWN:
                selectedItem = (selectedItem + 1) % itemCount;
                break;
            case 10: // Tecla Enter
                endwin(); // Encerra a biblioteca ncurses
                cout << "Você selecionou: " << menuItems[selectedItem] << endl;
                return;
            default:
                break;
        }
    }
}

int main() {

    // sudo yum install ncurses-devel
    
    return 0;
}