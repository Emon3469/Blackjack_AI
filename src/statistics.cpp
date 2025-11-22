#include "header/statistics.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>

PlayerSet::PlayerSet() {
    name = "N/A";
    cash = 0;
    wins = 0;
    losses = 0;
}

std::string PlayerSet::getName() {
    return name;
}

int PlayerSet::getCash() {
    return cash;
}

int PlayerSet::getWins() {
    return wins;
}

int PlayerSet::getLosses() {
    return losses;
}

void PlayerSet::setValues(std::string nm, int c, int w, int l) {
    name = nm;
    cash = c;
    wins = w;
    losses = l;
}

Statistics::Statistics() {
    std::fstream temp;
    temp.open("data/statistics.bin", std::ios::in | std::ios::binary);
    if(temp.fail()) {
        saveStats();
    }
    else {
        temp.close();
        loadStats();
    }
}

bool Statistics::check(Player p1) {
    bool rewrite = false;
    if(p1.getCash() > p[0].getCash()) {
        p[0].setValues(p1.getName(), p1.getCash(), p1.getWins(), p1.getLosses());
        rewrite = true;
    }
    if(p1.getWins() > p[1].getWins()) {
        p[1].setValues(p1.getName(), p1.getCash(), p1.getWins(), p1.getLosses());
        rewrite = true;
    }
    if(p1.getLosses() > p[2].getLosses()) {
        p[2].setValues(p1.getName(), p1.getCash(), p1.getWins(), p1.getLosses());
        rewrite = true;
    }
    return rewrite;
}

void Statistics::print() {
    int maxLength = std::max(std::max(p[0].getName().length(), p[1].getName().length()), p[2].getName().length());
    for(int i = 0; i < 3; i++) {
        switch(i) {
            case 0: std::cout<<"MAX CASH  ||||||||| "; break;
            case 1: std::cout<<"MAX WINS  ||||||||| "; break;
            case 2: std::cout<<"MAX LOSES ||||||||| ";
        }
        std::cout<<std::setw(maxLength+1)<<p[i].getName()<<"\t | \t"<<lightGreen<<"Cash: "<<std::setw(7)<<p[i].getCash()<<"\t | \t"<<yellow<<"Wins: "<<std::setw(5)<<p[i].getWins()<<"\t | \t"<<lightRed<<"Loses: "<<std::setw(5)<<p[i].getLosses()<<def<<"\n";
    }
}

void Statistics::saveStats() {
    std::fstream f1;
    f1.open("data/statistics.bin", std::ios::out | std::ios::binary);
    for(int i = 0; i < 3; i++) {
        std::string sName = p[i].getName();
        int nameSize = sName.size();
        int sCash = p[i].getCash();
        int sWins = p[i].getWins();
        int sLosses = p[i].getLosses();
        f1.write((char*)&nameSize, sizeof(nameSize));
        f1.write(sName.c_str(), sName.size());
        f1.write((char*)&sCash, sizeof(sCash));
        f1.write((char*)&sWins, sizeof(sWins));
        f1.write((char*)&sLosses, sizeof(sLosses));
    }
    f1.close();
}

void Statistics::loadStats() {
    std::fstream f1;
    f1.open("data/statistics.bin", std::ios::in | std::ios::binary);
    for(int i = 0; i < 3; i++) {
        std::string sName;
        int nameSize;
        int sCash;
        int sWins;
        int sLosses;
        f1.read((char*)&nameSize, sizeof(nameSize));
        sName.resize(nameSize);
        f1.read(&sName[0], sName.size());
        f1.read((char*)&sCash, sizeof(sCash));
        f1.read((char*)&sWins, sizeof(sWins));
        f1.read((char*)&sLosses, sizeof(sLosses));
        p[i].setValues(sName, sCash, sWins, sLosses);
    }
    f1.close();
}