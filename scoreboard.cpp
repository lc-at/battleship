#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

#include "common.h"
#include "menu.h"
#include "game.h"

void scoreboard_menu(GameData &gd) {
    int menu;
    std::cout << "\n\t\tWhat do you want?\n\n"
              << "\t(1) Sort scoreboard\n"
              << "\t(2) Find my score\n"
              << "\t(3) Back to main menu\n"
              << "\n\t---------------------------------------\n\n"
              << "\tYour choice: ";
    std::cin >> menu;
    switch (menu) {
    case 1:
        clear_screen();
        scoreboard_sorting(gd);
        break;
    case 2:
        clear_screen();
        scoreboard_search(gd);
        break;
    case 3:
        clear_screen();
        print_banner();
        main_menu(gd);
        break;
    default:
        clear_screen();
        std::cout << "\n\tInvalid choice. Please try again.\n";
        view_scoreboard(gd);
    }
}

void scoreboard_sorting(GameData &gd) {
    typedef bool (*sfunc)(const Game &, const Game &);
    int sfunc_i;
    int sort_order;

    sfunc sorting_func[] = {Game::compare_player_name, Game::compare_score,
                            Game::compare_t};

    while (true) {
        std::cout << "\n\t---- Sort Scoreboard by: ----\n\n"
                  << "\t(1) Name\n"
                  << "\t(2) Score\n"
                  << "\t(3) Time\n"
                  << "\n\t-----------------------------\n\n"
                  << "\tYour choice: ";
        std::cin >> sfunc_i;
        clear_screen();
        if (sfunc_i == 69)
            std::cout
                << "Best Programming Tutorial "
                   "Series:\nhttps://www.youtube.com/watch?v=fC7oUOUEEi4\n";
        if (sfunc_i > 0 && sfunc_i < 4)
            break;
        std::cout << "Invalid input. Please try again.\n\n";
    }

    while (true) {
        std::cout << "\n\t--- Scoreboard Sort order ---\n\n"
                  << "\t(1) Ascending\n"
                  << "\t(2) Descending\n"
                  << "\n\t-----------------------------\n\n"
                  << "\tYour choice: ";
        std::cin >> sort_order;
        clear_screen();
        if (sort_order > 0 && sort_order < 3)
            break;
        std::cout << "Invalid input. Please try again.\n\n";
    }

    std::sort(gd.begin(), gd.end(), sorting_func[--sfunc_i]);
    if (sort_order == 2)
        std::reverse(gd.begin(), gd.end());

    view_scoreboard(gd);
}

void print_scoreboard(GameData &gd) {
    char timestr[100];
    std::string trimmed_name;

    std::cout << "\n\t------ The Battleship Scoreboard ------\n\n";

    std::cout << "\t" << std::left << std::setw(16) << "Name" << std::left
              << std::setw(8) << "Score" << std::left << std::setw(10)
              << "Time Played"
              << "\n";

    for (auto it = gd.begin(); it != gd.end(); ++it) {
        std::strftime(timestr, sizeof(timestr), "%D %T",
                      std::localtime(&(it->t)));

        trimmed_name = (it->player_name).substr(0, 14);

        std::cout << "\t";

        std::cout << std::left << std::setw(16) << trimmed_name << std::left
                  << std::setw(8) << it->score << std::left << std::setw(10)
                  << timestr << "\n";
    }

    std::cout << "\n\t---------------------------------------\n";
}

void view_scoreboard(GameData &gd) {
    print_scoreboard(gd);
    scoreboard_menu(gd);
}

void scoreboard_search(GameData &gd) {
    std::string name;
    bool found(false);
    GameData filtered_gd;

    std::cout << "\n\tEnter a player name to search: ";
    std::cin.ignore();
    std::getline(std::cin, name);

    // linear search
    for (auto it = gd.begin(); it != gd.end(); ++it) {
        if (it->player_name == name) {
            filtered_gd.push_back(*it);
            found = true;
        }
    }

    clear_screen();
    if (found)
        print_scoreboard(filtered_gd);
    else
        std::cout << "\n\t" + name + " haven't played this game :(\n";

    search_option(gd);
}

void search_option(GameData &gd) {
    int search_select;

    std::cout << "\n\t---------------------------------------\n\n"
              << "\t\tAnything else?\n\n"
              << "\t(1) Search for another player\n"
              << "\t(2) Back to scoreboard\n"
              << "\n\t---------------------------------------\n\n"
              << "\tYour choice: ";

    std::cin >> search_select;
    switch (search_select) {
    case 1:
        clear_screen();
        scoreboard_search(gd);
        break;
    case 2:
        clear_screen();
        view_scoreboard(gd);
        break;
    default:
        clear_screen();
        std::cout << "\n\tInvalid choice. Please try again.\n";
        search_option(gd);
    }
}