#include "player.h"

// ctor
Player::Player(bool is_human, int order) : is_human{is_human}, order{order}, score{0} { }

void Player::leave() {
    this->is_human = false;
}

void Player::showHand() {
    std::cout << "Your hand: ";
    for (auto n : this->hand) {
        std::cout << n << " ";
    }
    std::cout << std::endl;
}

// returns the legal cards
std::vector<Card> Player::legalCards(int topS, int bottomS, int topC, int bottomC,
                                     int topH, int bottomH, int topD, int bottomD) {
    std::vector<Card> c;
    for (auto n : this->hand) {
        if (n.getSuit() == 'S') {
            if (n.getRank() == topS + 1 || n.getRank() == bottomS - 1 || n.getRank() == 7) {
                c.emplace_back(n);
                // you must play S7 if you have it
                if (n.getRank() == 7) {
                    return c;
                }
            }
        }
        else if (n.getSuit() == 'C') {
            if (n.getRank() == topC + 1 || n.getRank() == bottomC - 1 || n.getRank() == 7) {
                c.emplace_back(n);
            }
        }
        else if (n.getSuit() == 'H') {
            if (n.getRank() == topH + 1 || n.getRank() == bottomH - 1 || n.getRank() == 7) {
                c.emplace_back(n);
            }
        }
        if (n.getSuit() == 'D') {
            if (n.getRank() == topD + 1 || n.getRank() == bottomD - 1 || n.getRank() == 7) {
                c.emplace_back(n);
            }
        }
    }
    return c;                                                
}

// returns true if this player's score >= 80
bool Player::reachLimit() {
    return score >= 80;
}

// returns true if hand is empty
bool Player::emptyHand() {
    if (hand.size() == 0) {
        return true;
    }
    return false;
}

int Player::getScore() {
    return this->score;
}

int Player::getOrder() {
    return this->order;
}

bool Player::isHuman() {
    return this->is_human;
}

int Player::getLevel() {
    return this->level;
}

void Player::setLevel(int l) {
    this->level = l;
}
std::vector<Card> Player::getHand() {
    return this->hand;
}

// call this function when a round ends
void Player::roundEnd() {
    int order = this->getOrder() + 1;
    int newScore = 0;
    std::cout << "Player" << order << "'s discards:";
    for (auto n : discarded) {
        std::cout << " " << n;
        newScore += n.getRank();
    }
    std::cout << std::endl << "Player" << order << "'s score:";
    std::cout << " " << this->score << " + " << newScore << " = "; 
    this->score += newScore;
    std::cout << this->score << std::endl;
    discarded.clear();
    hand.clear();
}

void Player::receiveCards(std::vector<Card>& h) {
    hand = h;
}

Card Player::play (Card c, std::vector<Card> legalCards) {

    // if no legal cards to play
    if (legalCards.size() == 0) {
    std::cerr << "Invalid! You have no legal cards to play. You must discard." << std::endl;
        throw InvalidCommand();
    }

    // play c
    for (auto n : legalCards) {
        if (n == c) {
            // remove c from hand
            for (int i = 0; i < this->hand.size(); i++) {
                if (c == hand.at(i)) {
                    hand.erase(hand.begin()+i);
                    std::cout << "Player" << this->getOrder() + 1;
                    std::cout << " plays " << c <<  "." << std::endl << std::endl;
                    return c;
                }
            }
        }   
    }

    // it is not valid to play c
    std::cerr << "Invalid! This card is not legal to play" << std::endl;
    throw InvalidCommand();
    return c;
}

void Player::discard(Card c, std::vector<Card> legalCards) {

    // if legalCards is not empty
    if (legalCards.size() != 0) {
    std::cerr << "Invalid! You have a legal play. You may not discard." << std::endl;
        throw InvalidCommand();
    }

    // make sure c is in hand
    bool exist = false;
    for (auto n : this->hand) {
        if (n == c) {
            exist = true;
            break;
        }
    }
    if (exist == false) {
    std::cerr << "Invalid! This card is not in your hand" << std::endl;
        throw InvalidCommand();
    }

    // discard c
    for (int i = 0; i < this->hand.size(); i++) {
        if (c == hand.at(i)) {
            hand.erase(hand.begin()+i);
            discarded.emplace_back(c);
            std::cout << "Player" << this->getOrder() + 1;
                std::cout << " discards " << c << "." << std::endl << std::endl;
            return;
        }
    }
}




