#include <fstream>
#include "game.h"
#include "savegame.h"

int save_game(GameData &gd) {
    std::ofstream save_file(SAVEFILE_NAME);
    if (!save_file.is_open())
        return 1; // error occured

    for (GameData::iterator it = gd.begin(); it != gd.end(); ++it) {
        save_file << it->player_name << SAVEFILE_DELIM << it->score
                  << SAVEFILE_DELIM << it->t << '\n';
    }

    save_file.close();
    return 0;
}

int load_game(GameData &gd) {
    std::ifstream save_file(SAVEFILE_NAME);
    std::string data_line;
    std::string tokens[3];
    size_t pos;

    Game g;
    bool err(0);

    if (!save_file.is_open())
        return 1; // error occured

    while (std::getline(save_file, data_line)) {
        for (int i = 0; i < 3; i++) {
            pos = data_line.find(SAVEFILE_DELIM);
            if (pos == std::string::npos) {
                tokens[i] = data_line;
                break;
            }
            tokens[i] = data_line.substr(0, pos);
            data_line.erase(0, pos + 1);
        }

        // checking for corrupted data
        for (int i = 0; i < 3; i++) {
            if (tokens[i].length() == 0) {
                err = true;
                break;
            }
        }
        if (err)
            break;

        g.player_name = tokens[0];
        g.score = std::stoi(tokens[1]);
        g.t = std::stoll(tokens[2]);

        gd.push_back(g);
    }

    save_file.close();
    return (int)err;
}