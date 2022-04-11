#ifndef GAME_H
#define GAME_H 
#include <random>
#include <queue>
#include "board.h"
#include "player.h"
#include "board.h"


class Game {
    private:
    int whoFirst;
    Board board;
    std::vector<Player> players;

    public:
    Game();
    int get_whoFirst();
    Board& getBoard();
    Player& getPlayer(int i);
    void newRound(std::default_random_engine rng);
    void deliverCards();
};

#endif
