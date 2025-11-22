#include "header/human.hpp"
#include <iostream>

Human::Human() {
    sum = 0;
}

int Human::getSum() {
    return sum;
}

void Human::switchAce() {
    if(sum > 21) {
        for(int i = 0; i < hand.size(); i++) {
            if(hand[i].getNumber() == 1 && !(hand[i].getBlock())){
                hand[i].setBlock(true);
                sum -= 10;
                return;
            }
        }
    }
}

void Human::addCard(Card c) {
    hand.push_back(c);
    if(c.getNumber() > 10) {
        c.setNumber(10);
    }
    else if(c.getNumber() == 1) {
        c.setNumber(11);
    }
    sum += c.getNumber();
}

void Human::clearCards() {
    hand.clear();
    sum = 0;
}

void Human::printCards() {
    std::cout<<"\n";
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < hand.size(); j++) {
            switch(i) {
                case 0: std::cout<<".------."; break;
                case 1: std::cout<<"|"<<hand[j].getPrintNumber()<<".--. |"; break;
                case 2: hand[j].printCardL1(); break;
                case 3: hand[j].printCardL2(); break;
                case 4: std::cout<<"| '--'"<<hand[j].getPrintNumber()<<"|"; break;
                case 5: std::cout<<"`------'";
            }
        }
        std::cout<<"\n";
    }
}