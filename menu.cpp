#include "menu.h"
#include "savegame.h"

#include <string>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <iostream>
#include <ctime>

void post_game(GameData &gd) {
    int choice;

    std::cout << "\n\t------------------------------\n\n";
    std::cout << "\t\t(1) Play again\n";
    std::cout << "\t\t(2) Back to main menu\n";
    std::cout << "\n\t------------------------------\n\n";
    std::cout << "\tYour choice: ";
    std::cin >> choice;

      clear_screen();

      switch (choice) {
      case 1:
          play_game(gd);
          break;
      case 2:
          print_banner();
          main_menu(gd);
          break;
      default:
          std::cout << "\n\tInvalid choice. Please try again.\n";
          post_game(gd);
      }
}

void print_board(bool (&board)[BOARD_X][BOARD_Y], std::string indent) {
    for (int y = 0; y < BOARD_Y + 1; y++) {
        std::cout << indent;
        if (y != 0)
            std::cout << (char)(64 + y);
        std::cout << '\t';
        for (int x = 0; x < BOARD_X; x++) {
            if (y == 0)
                std::cout << x + 1;
            else if (board[x][y - 1])
                std::cout << ' ';
            else
                std::cout << BLOCK;
            std::cout << ' ';
        }
        std::cout << '\n';
    }
}

void print_banner() {
    std::cout << "\n"
              << "\t   ___       __  __  __        __   _    \n"
              << "\t  / _ )___ _/ /_/ /_/ /__ ___ / /  (_)_\n"
              << "\t / _  / _ `/ __/ __/ / -_|_-</ _ \\/ / _ \\ \n"
              << "\t/____/\\_,_/\\__/\\__/_/\\__/___/_//_/_/ .__/\n"
              << "\t                                  /_/   \n";
}

void main_menu(GameData &gd) {
    int choice;
    
      std::cout << "\n";
      std::cout << "\t---------- MAIN MENU ----------\n\n";
      std::cout << "\t\tPlease pick an option:\n\n";
      std::cout << "\t\t(1) Play Battleship\n";
      std::cout << "\t\t(2) View scoreboard\n";
      std::cout << "\t\t(3) Exit\n\n";
      std::cout << "\t-------------------------------\n\n";
      std::cout << "\t\tYour choice: ";
      std::cin >> choice;

      clear_screen();

      switch (choice) {
      case 1:
          play_game(gd);
          break;
      case 2:
          view_scoreboard(gd);
          break;
      case 3:
          print_banner();
          std::cout << "\n\t\t--------------------------\n"
                    << "\n\t\t\tThanks for Playing\n"
                    << "\n\t\t\t  See you later!\n"
                    << "\n\t\t--------------------------\n\n";
          return;
      default:
          print_banner();
          std::cout << "\n\tInvalid choice. Please try again.\n";
          main_menu(gd);
      }
}

void clear_screen() {
#ifdef WINDOWS
    std::system("cls");
#else
    std::system("clear");
#endif
}