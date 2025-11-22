#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"
#include "dealer.hpp"
#include "deck.hpp"
#include "print.hpp"
#include "statistics.hpp"
#include <string>


class Game {
    private:
        Player player;
        Dealer dealer;
        Deck deck;
        Statistics s;

    public:
        Game();
        bool dealDealer();
        char compareSum();
        bool checkWins();
        char checkEnd();
        bool startBet();
        bool startGame();
        void beginGame();
        void beginMenu(bool rep, std::string reason);
        void saveGame();
        void loadGame();
        void printStatistics();
        void printInstructions();
        void printTop();
        void printBody();
};

#endif