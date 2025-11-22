#include "header/deck.hpp"
#include <iostream>
#include <algorithm>

void Deck::initializeDeck() {
    deck.clear();
    char suits[] = {'S', 'H', 'D', 'C'};
    for (int i = 0; i < 4; i++) {
        for(int j = 0; j < 13; j++) {
            Card c(j + 1, suits[i]);
            deck.push_back(c);
        }
    }
    std::random_shuffle(deck.begin(), deck.end());
}

int Deck::getSize() {
    return deck.size();
}

Card Deck::deal() {
    int val = (rand() % (deck.size()));
    Card t = deck[val];
    deck.erase(deck.begin() + val);
    return t;
}