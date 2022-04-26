#ifndef BATTLESHIP__GAME_H
#define BATTLESHIP__GAME_H

#include <vector>
#include <string>
#include <ctime>

struct Point {
    int x;
    int y;
    void from_string(std::string s);
    void randomize();
    bool is_valid();
};

struct Game {
    int score;
    time_t t;
    std::string player_name;
    int calculate_score(int a);
    void sanitize_player_name();

	static bool compare_player_name(const Game &a, const Game &b) {
		return a.player_name < b.player_name;
	};
    static bool compare_score(const Game &a, const Game &b) {
        return a.score > b.score;
    };
	static bool compare_t(const Game &a, const Game &b) {
		return a.t > b.t;
	}
};

typedef std::vector<Game> GameData;

void play_game(GameData &gd);

#endif