#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "human.hpp"
#include <string>

class Player : public Human {
    private:
        std::string name;
        int cash, bet;
        int wins, losses;

    public:
        Player();
        std::string getName();
        int getBet();
        int getCash();
        int getWins();
        int getLosses();
        void setName(std::string s);
        void setBet(int b);
        void addCash(int c);
        void incrementWins();
        void incrementLosses();
        void clearCards();
};

#endif