#ifndef PLAYER_H
#define PLAYER_H 
#include <vector>
#include "card.h"


class Player {
    private:
    bool is_human;
    int level; // for computer plays only
    int order;
    int score;
    std::vector<Card> hand;
    std::vector<Card> discarded;

    public:
    Player(bool is_human, int order);
    int getOrder();
    int getScore();
    bool isHuman();
    int getLevel();
    void setLevel(int l);
    std::vector<Card> getHand();
    void leave();
    Card play(Card c, std::vector<Card> legalCards); 
    void discard(Card c, std::vector<Card> legalCards);
    bool reachLimit();
    bool emptyHand();
    void showHand();
    std::vector<Card> legalCards(int topS, int bottomS, int topC, int bottomC,
                                 int topH, int bottomH, int topD, int bottomD);
    void roundEnd();
    void receiveCards(std::vector<Card>& h);
};

class InvalidCommand;

#endif
