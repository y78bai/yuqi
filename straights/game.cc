#include "game.h"

Game::Game() {
    Board b;
    b.init();
    this->board = b;
    Player p1{true, 0};
    Player p2{true, 1};
    Player p3{true, 2};
    Player p4{true, 3};
    std::vector<Player> p;
    p.emplace_back(p1);
    p.emplace_back(p2);
    p.emplace_back(p3);
    p.emplace_back(p4);
    this->players = p;
}

int Game::get_whoFirst() {
    return this->whoFirst;
}

Player& Game::getPlayer(int i) {
    return this->players.at(i);
}

Board& Game::getBoard() {
    return this->board;
}

void Game::newRound(std::default_random_engine rng) {
    int i = this->board.newRound(rng); 
    this->whoFirst = i;
}

void Game::deliverCards() {
    std::vector<Card> deck = this->getBoard().getDeck();
    std::vector<Card> h;

    // player 0
    for (int i = 0; i < 13; i++) {
        h.emplace_back(deck.at(i));
    }
    this->getPlayer(0).receiveCards(h);
    h.clear();
        // player 1
    for (int i = 13; i < 26; i++) {
        h.emplace_back(deck.at(i));
    }
    this->getPlayer(1).receiveCards(h);
    h.clear();
    // player 2
    for (int i = 26; i < 39; i++) {
        h.emplace_back(deck.at(i));
    }
    this->getPlayer(2).receiveCards(h);
    h.clear();
    // player 3
    for (int i = 39; i < 52; i++) {
        h.emplace_back(deck.at(i));
    }
    this->getPlayer(3).receiveCards(h);
    h.clear();
}
