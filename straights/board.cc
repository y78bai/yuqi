#include "board.h"
#include <algorithm>
#include <vector>

// return deck
std::vector<Card> Board::getDeck() {
    return this->deck;
}

// 
int Board::getTopS() {
    if (this->spade.size() != 0) {
        return spade.at(spade.size()-1).getRank();
    }
    return -1;
}

int Board::getBottomS() {
    if (this->spade.size() != 0) {
        return spade.at(0).getRank();
    }
    return -1;
}

int Board::getTopC() {
    if (this->club.size() != 0) {
        return club.at(club.size()-1).getRank();
    }
    return -1;
}

int Board::getBottomC() {
    if (this->club.size() != 0) {
        return club.at(0).getRank();
    }
    return -1;
}

int Board::getTopH() {
    if (this->heart.size() != 0) {
        return heart.at(heart.size()-1).getRank();
    }
    return -1;
}

int Board::getBottomH() {
    if (this->heart.size() != 0) {
        return heart.at(0).getRank();
    }
    return -1;
}

int Board::getTopD() {
    if (this->diamond.size() != 0) {
        return diamond.at(diamond.size()-1).getRank();
    }
    return -1;
}

int Board::getBottomD() {
    if (this->diamond.size() != 0) {
        return diamond.at(0).getRank();
    }
    return -1;
}
    
void Board::init() {
    for (int i = 1; i < 14; i++) {
        deck.emplace_back(Card('C', i));
    }
    for (int i = 1; i < 14; i++) {
        deck.emplace_back(Card('D', i));
    }
    for (int i = 1; i < 14; i++) {
        deck.emplace_back(Card('H', i));
    }
    for (int i = 1; i < 14; i++) {
        deck.emplace_back(Card('S', i));
    }
}


void Board::showDeck() {
    int i = 0;
    while (i < 13) {
        std::cout << deck.at(i) << " ";
        i++;
    }
    std::cout << std::endl;
    while (i < 26) {
        std::cout << deck.at(i) << " ";
        i++;
    }
    std::cout << std::endl;
    while (i < 39) {
        std::cout << deck.at(i) << " ";
        i++;
    }
    std::cout << std::endl;
    while (i < 52) {
        std::cout << deck.at(i) << " ";
        i++;
    }
    std::cout << std::endl;
}

void Board::showTable() {
    std::cout << "Cards on the table:" << std::endl;
    std::cout << "Clubs:";
    for (auto n : this->club) {
        std::cout << " ";
        n.printRank();
    }
    std::cout << std::endl << "Diamonds:";
    for (auto n : this->diamond) {
        std::cout << " ";
        n.printRank();
    }
    std::cout << std::endl << "Hearts:";
    for (auto n : this->heart) {
        std::cout << " ";
        n.printRank();
    }
    std::cout << std::endl << "Spades:";
    for (auto n : this->spade) {
        std::cout << " ";
        n.printRank();
    }
    std::cout << std::endl;
}

// return the player who has S7
int Board::newRound(std::default_random_engine rng) {
    spade.clear();
    club.clear();
    heart.clear();
    diamond.clear();

    // shuffle the deck
    std::shuffle(deck.begin(), deck.end(), rng);

    // find the player that has S7
    int i = 0;
    Card c{'S', 7};
    // find out who has S7
    while (true) {
        if (deck.at(i) == c) {
            break;
        }
        i++;
    }
    i = i / 13;
    std::cout << "A new Round begins. It's Player";
    std::cout << i + 1 << "'s turn to play." << std::endl;

    return i;
}

void Board::receiveCard(Card c) {

    // return if rank is invalid
    if (c.getRank() == -1) {
        return;
    }

    // if rank is 7, receive it
    if (c.getRank() == 7) {
        if (c.getSuit() == 'S') { 
            spade.emplace_back(c);
        }
        if (c.getSuit() == 'C') { 
            club.emplace_back(c);
        }
        if (c.getSuit() == 'H') { 
            heart.emplace_back(c);
        }
        if (c.getSuit() == 'D') { 
            diamond.emplace_back(c);
        }
    }

    if (c.getSuit() == 'S') {
        if (c.getRank() == this->getTopS() + 1) {
            this->spade.emplace_back(c);
            return;
        }
        if (c.getRank() == this->getBottomS() - 1) {
            this->spade.insert(spade.begin(), c);
            return;
        }
    }

    if (c.getSuit() == 'C') {
        if (c.getRank() == this->getTopC() + 1) {
            this->club.emplace_back(c);
            return;
        }
        if (c.getRank() == this->getBottomC() - 1) {
            this->club.insert(club.begin(), c);
            return;
        }
    }

    if (c.getSuit() == 'H') {
        if (c.getRank() == this->getTopH() + 1) {
            this->heart.emplace_back(c);
            return;
        }
        if (c.getRank() == this->getBottomH() - 1) {
            this->heart.insert(heart.begin(), c);
            return;
        }
    }

    if (c.getSuit() == 'D') {
        if (c.getRank() == this->getTopD() + 1) {
            this->diamond.emplace_back(c);
            return;
        }
        if (c.getRank() == this->getBottomD() - 1) {
            this->diamond.insert(diamond.begin(), c);
            return;
        }
    }
}
