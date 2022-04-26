#include <iostream>
#include "game.h"
#include "savegame.h"
#include "menu.h"

int main() {
    GameData gd;

    if (load_game(gd) != 0) {
        std::cout << "Savefile corrupted. Exiting.\n";
        return 1;
    }

    clear_screen();
    print_banner();

    std::cout << "\n\t\tPress ENTER to Continue ";
    std::cin.get();
    std::cout << '\n';

    clear_screen();
    print_banner();

    std::cout << "\n\tHi, player! Welcome to the game :)\n";
    main_menu(gd);

    return 0;
}


