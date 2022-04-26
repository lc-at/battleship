#include <string>
#include <vector>
#include <ctime>
#include <random>
#include <iostream>

#include "common.h"
#include "savegame.h"
#include "menu.h"
#include "game.h"

void play_game(GameData &gd) {
    Game g;
    Point guessed;
    Point ship;
    int score(0);
    bool board[BOARD_X][BOARD_Y];
    std::string str_p;

    std::cout << "\n\t------ PLAY GAME ------\n";
    std::cout << "\n\tPlayer name: ";
    std::getline(std::cin >> std::ws, g.player_name);

    g.sanitize_player_name();
    ship.randomize();
    clear_screen();

    for (int a = 1; a <= 1.0f / SCORE_STEP; a++) {
        std::cout << "\n\tEnter your guessed coordinate of the ship\n\t(e.g. "
                     "A1, B3)\n\n";
        print_board(board);

        std::cout << "\n\tAttempt #" << a << ": ";
        std::cin >> str_p;
        clear_screen();
        guessed.from_string(str_p);
        if (!guessed.is_valid()) {
            std::cout << "\n\tInvalid input.\n";
            a--;
            continue;
        } else if (guessed.x == ship.x && guessed.y == ship.y) {
            std::cout << "\n\tOh, you have sunken my battleship, " +
                             g.player_name + "!\n";
            score = g.calculate_score(a);
            break;
        }
        board[guessed.x][guessed.y] = 1;
    }

    g.t = time(NULL);
    g.score = score;
    gd.push_back(g);

    if (score == 0) {
        std::cout << "\n\tYou are running out points\n\n\tYour score is 0 :(\n";
    } else {

        std::cout << "\n\tYour score: " << score << '\n';
    }

	if (save_game(gd) != 0)
        std::cout << "\n\tError saving game.\n";

    post_game(gd);
}

void Point::from_string(std::string s) {
    y = toupper(s[0]) - 65;
    x = atoi(&s[1]) - 1;
}

void Point::randomize() {
    std::srand(time(NULL));
    x = std::rand() % BOARD_X;
    y = std::rand() % BOARD_Y;
}

bool Point::is_valid() {
    return x < BOARD_X && y < BOARD_Y && x >= 0 && y >= 0; 
}

int Game::calculate_score(int a) {
    return MAX_SCORE * (1 - SCORE_STEP * a + SCORE_STEP);
}

void Game::sanitize_player_name() {
    for (int i = 0; i < (int)player_name.length(); i++) {
        if (player_name[i] == SAVEFILE_DELIM)
            player_name[i] = '_';
    }
};
