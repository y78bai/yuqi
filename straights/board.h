#ifndef BOARD_H
#define BOARD_H 
#include <vector>
#include <random>
#include "card.h"

// test 123
class Board {
    private:
    std::vector<Card> deck;
    std::vector<Card> spade;
    std::vector<Card> club;
    std::vector<Card> heart;
    std::vector<Card> diamond;
    
    public:
    std::vector<Card> getDeck();
    int getTopS();
    int getBottomS();
    int getTopC();
    int getBottomC();
    int getTopH();
    int getBottomH();
    int getTopD();
    int getBottomD();
    void init();
    void showDeck(); 
    void showTable();
    int newRound(std::default_random_engine rng);
    void receiveCard(Card c);
};

#endif
