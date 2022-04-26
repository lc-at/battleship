#ifndef BATTLESHIP__MENU_H
#define BATTLESHIP__MENU_H

#include "common.h"
#include "game.h"

void print_banner();
void clear_screen();
void main_menu(GameData &gd);
void print_board(bool (&board)[BOARD_X][BOARD_Y], std::string indent = "\t");

void post_game(GameData &gd);
void search_option(GameData &gd);
void view_scoreboard(GameData &gd);

void scoreboard_sorting(GameData &gd);
void scoreboard_search(GameData &gd);
void scoreboard_menu(GameData &gd);

#endif