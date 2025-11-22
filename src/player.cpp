#include "header/player.hpp"
#include <iostream>

Player::Player() {
    name = "Player";
    bet = 0;
    cash = 1000;
    wins = 0;
    losses = 0;
}

std::string Player::getName() {
    return name;
}

int Player::getBet() {
    return bet;
}

int Player::getCash() {
    return cash;
}

int Player::getWins() {
    return wins;
}

int Player::getLosses() {
    return losses;
}

void Player::setName(std::string s) {
    name = s;
}

void Player::setBet(int b) {
    cash -= b;
    bet = b;
}

void Player::addCash(int c) {
    cash += c;
}

void Player::incrementWins() {
    wins+=1;
}

void Player::incrementLosses() {
    losses+=1;
}

void Player::clearCards() {
    Human::clearCards();
    bet = 0;
}