#ifndef BATTLESHIP__SAVEGAME_H
#define BATTLESHIP__SAVEGAME_H

#include "common.h"
#include "game.h"

int load_game(GameData &gd);
int save_game(GameData &gd);

#endif