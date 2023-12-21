#include <iostream>
#include <string>

using std::cout;
using std::cin;

enum menu_choices {
    ERROR = -1,
    NEW_GAME = 1,
    LOAD_GAME = 2,
    EXIT = 3
};
int menu() {
    int choice;
    cout << "1. New Game\n";
    cout << "2. Load Game\n";
    cout << "3. Exit\n";
    cout << "Choice: ";
    cin >> choice;
    cin.ignore();
    
    if (choice < 1 || choice > 3) {
        cout << "Invalid choice!\n";
        return ERROR;
    }
    return choice;
}
