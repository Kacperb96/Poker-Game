#include "Game.hpp"

bool isFlush(CardDeck& deck){
    int counter{ 1 };

    for(int i = 1; i < deck.size(); i++){
        if(deck.at(i - 1).first == deck.at(i).first)
            counter++;
    }

    if(counter == 5) return true;
    else return false;
}