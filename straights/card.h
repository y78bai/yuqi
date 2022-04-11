#ifndef CARD_H
#define CARD_H 
#include <vector>
#include <iostream>

class Card {
    private:
    char suit;
    int rank;

    public:
    char getSuit();
    int getRank();
    Card(char suit, int rank);
    void setRank(int r);
    void setSuit(char s);
    void printRank();
    bool operator==(Card& other);
};

std::istream& operator>>(std::istream &in, Card& c);

std::ostream& operator<<(std::ostream &out, Card& c);

bool my_compare(Card a, Card b);

Card getMin(std::vector<Card> c);

Card getMax(std::vector<Card> c);

class InvalidCommand {};

#endif
