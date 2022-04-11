#include "card.h"
#include <algorithm>

// ctor
Card::Card(char suit, int rank) : suit{suit}, rank{rank} {}

char Card::getSuit() {
    return this->suit;
}
    
int Card::getRank() {
    return this->rank;
}

void Card::printRank() {
    int rank = this->getRank();
    if (rank >= 2 && rank <= 9) {
        std::cout << rank;
    } else if (rank == 1) {
        std::cout << 'A';
    } else if (rank == 10) {
        std::cout << 'T';
    } else if (rank == 11) {
        std::cout << 'J';
    } else if (rank == 12) {
        std::cout << 'Q';
    } else if (rank == 13) {
        std::cout << 'K';
    }
}

void Card::setRank(int r) {
    this->rank = r;
}
void Card::setSuit(char s) {
    this->suit = s;
}

std::istream& operator>>(std::istream &in, Card& c) {
    char r;
    char s;
    in >> r >> s;
    c.setSuit(s);
    if (r == 'A') {
        c.setRank(1);
        return in;
    }
    if (r == 'T') {
        c.setRank(10);
        return in;
    }
    if (r == 'J') {
        c.setRank(11);
        return in;
    }
    if (r == 'Q') {
        c.setRank(12);
        return in;
    }
    if (r == 'K') {
        c.setRank(13);
        return in;
    }
    if (r >= '2' && r <= '9') {
        c.setRank(r-'0');
        return in;
    }
    return in;
}


std::ostream &operator<<(std::ostream &out, Card& c) {
    int rank = c.getRank();
    if (rank >= 2 && rank <= 9) {
        out << rank;
    } else if (rank == 1) {
        out << 'A';
    } else if (rank == 10) {
        out << 'T';
    } else if (rank == 11) {
        out << 'J';
    } else if (rank == 12) {
        out << 'Q';
    } else if (rank == 13) {
        out << 'K';
    }
    out << c.getSuit();
    return out;
}

bool Card::operator==(Card& other) {
    return (this->getRank() == other.getRank() && 
            this->getSuit() == other.getSuit() );
}

bool my_compare(Card a, Card b) {
    return a.getRank() < b.getRank();
}

Card getMin(std::vector<Card> c) {
    // std::vector<Card> other = c;
    std::sort(c.begin(), c.end(), my_compare);
    return c.front();
}

Card getMax(std::vector<Card> c) {
    // std::vector<Card> other = c;
    std::sort(c.begin(), c.end(), my_compare);
    return c.back();
}
