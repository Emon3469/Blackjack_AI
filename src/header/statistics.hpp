#ifndef STATISTICS_HPP
#define STATISTICS_HPP

#include "player.hpp"
#include "color.hpp"
#include <string>

class PlayerSet {
    private:
        std::string name;
        int cash, wins, losses;

    public:
        PlayerSet();
        std::string getName();
        int getCash();
        int getWins();
        int getLosses();
        void setValues(std::string nm, int c, int w, int l);
};

class Statistics {
    private:
        PlayerSet p[3];
    
    public:
        Statistics();
        bool check(Player p1);
        void print();
        void saveStats();
        void loadStats();
};

#endif