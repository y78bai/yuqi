#include <iostream>
#include <algorithm>
#include <chrono>
#include <random>
#include "card.h"
#include "player.h"
#include "game.h"
#include "board.h"


int main(int argc, char * argv[]) {
    
    // set seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    if ( argc > 1 ) {
            try {
                    seed = std::stoi( std::string{ argv[1] } );
            } catch( std::invalid_argument & e ) {
                    std::cerr << e.what() << std::endl;
                    return 1;
            } catch( std::out_of_range & e ) {
                    std::cerr << e.what() << std::endl;
                    return -1;
            } // catch
    } // if
    std::default_random_engine rng{seed};

    Game g;
    char ch;
    for (int i = 0; i < 4; i++) {
        std::cout << "Is player" << i + 1 << " a human or a computer?" << std::endl;
        std::cout << "Press 1, 2, or 3 to set the level of computer;" << std::endl;
        std::cout << "Press any other key if this is a human" << std::endl;
        std::cin >> ch;
        if (ch == '1') {
            g.getPlayer(i).leave();
            g.getPlayer(i).setLevel(1);
        }
        if (ch == '2') {
            g.getPlayer(i).leave();
            g.getPlayer(i).setLevel(2);
        }
        if (ch == '3') {
            g.getPlayer(i).leave();
            g.getPlayer(i).setLevel(3);
        }
    }

    // for each round
    while (!g.getPlayer(0).reachLimit() && !g.getPlayer(1).reachLimit() &&
           !g.getPlayer(2).reachLimit() && !g.getPlayer(3).reachLimit()) {
            
        // for each round:
        g.newRound(rng);

        // deliver cards to players
        g.deliverCards();

        // t is the player of current round
        int t = g.get_whoFirst();  

        // while this round is still going
        while (g.getPlayer(0).emptyHand() == false || g.getPlayer(1).emptyHand() == false ||
               g.getPlayer(2).emptyHand() == false || g.getPlayer(3).emptyHand() == false) {

            g.getBoard().showTable();

            // current player p
            Player& p =  g.getPlayer(t);
            p.showHand();

            int topS = g.getBoard().getTopS();
            int topC = g.getBoard().getTopC();
            int topH = g.getBoard().getTopH();
            int topD = g.getBoard().getTopD();
            int bottomS = g.getBoard().getBottomS();
            int bottomC = g.getBoard().getBottomC();
            int bottomH = g.getBoard().getBottomH();
            int bottomD = g.getBoard().getBottomD();

            std::vector<Card> legalCards = p.legalCards(topS, bottomS, topC, bottomC,
                                                        topH, bottomH, topD, bottomD);

            // print legal cards
            std::cout << "Legal plays:";
            for (auto n : legalCards) {
                std::cout << " " << n;
            }
            std::cout << std::endl;
             

            Card c{'A', -1};
            int i = t;

            std::string cmd;

            while (t == i) {
                
                // for a computer player
                if (p.isHuman() == false) {
                    if (p.getLevel() == 1) {
                        if (legalCards.size() != 0) { // play a card
                            c = p.play(getMax(legalCards), legalCards);
                            g.getBoard().receiveCard(c);
                        }
                        else { // no legal cards, then discard
                            p.discard(getMax(p.getHand()), legalCards);
                        }
                    }

                    else if (p.getLevel() == 3) {
                        if (legalCards.size() != 0) { // play a card
                            c = p.play(getMin(legalCards), legalCards);
                            g.getBoard().receiveCard(c);
                        }
                        else { // no legal cards, then discard
                            p.discard(getMin(p.getHand()), legalCards);
                        }
                    }

                    else { // normal
                        if (legalCards.size() != 0) { // play a card
                            c = p.play(legalCards.at(0), legalCards);
                            g.getBoard().receiveCard(c);
                        }
                        else { // no legal cards, then discard
                            p.discard(p.getHand().at(0), legalCards);
                        }
                    }
                    t = (t + 1) % 4;
                }


                // for a human player (isHuman == true)
                else {
                    std::cin >> cmd;
                    if (cmd == "play") {
                
                        // player chooses a card
                        try { 
                            std::cin >> c;
                        }
                        catch (InvalidCommand &i) { }

                        // try to play c
                        try {
                            Card card = p.play(c, legalCards);            
                            g.getBoard().receiveCard(c);
                            // move on to next player
                            t = (t + 1) % 4;
                        }
                        catch (InvalidCommand &i) { }
                    }

                    else if (cmd == "discard") {
                
                        // player chooses a card
                        try { 
                            std::cin >> c;
                        }
                        catch (InvalidCommand &i) { }

                        // try to play c
                        try {
                            p.discard(c, legalCards);            
                            // move on to next player
                            t = (t + 1) % 4;
                        }
                        catch (InvalidCommand &i) { }
                    }

                    else if (cmd == "deck") {
                        g.getBoard().showDeck();
                    }

                    else if (cmd == "quit") {
                        return 0;
                    }

                    else if (cmd == "ragequit") {
                        // a normal computer will take over
                        std::cout << "Player" << t + 1 << " ragequits. A level-2 computer will take over" << std::endl;
                        p.leave();
                    }
                }
            }
        }
        for (int i = 0; i < 4; i++) {
            g.getPlayer(i).roundEnd();
        }      
    }
    int p0 = g.getPlayer(0).getScore();
    int p1 = g.getPlayer(1).getScore();
    int p2 = g.getPlayer(2).getScore();
    int p3 = g.getPlayer(3).getScore();
    int win = std::min(p0 , std::min(p1, std::min(p2, p3)));
    for (int i = 0; i < 4; i++) {
        if (g.getPlayer(i).getScore() == win) {
            std::cout << "Player" << i + 1 << " wins!" << std::endl;
        }
    }   
}

