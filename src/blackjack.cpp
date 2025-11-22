#include "header/blackjack.hpp"
#include<iostream>
#include<time.h>

int main(){
    srand(time(NULL));

    Game game;
    game.beginMenu(false, "");

    return 0;
}