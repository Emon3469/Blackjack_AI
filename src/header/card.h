#ifndef CARD_H
#define CARD_H

class Card {
    private:
        char number;
        char suit;
        bool block;

    public:
        Card();
        Card(int n, char s);
        int getNumber();
        char getSuit();
        bool getBlock();
        void setNumber(int n);
        void setSuit(char c);
        void setBlock(bool b);

        char getPrintNumber();
        void printCardL1();
        void printCardL2();
};

#endif