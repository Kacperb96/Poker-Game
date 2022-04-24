#include "Game.hpp"

bool isFlush(CardSet& cardSet){
    int counter{ 1 };

    for(int i = 1; i < cardSet.size(); i++){
        if(cardSet.at(i - 1).first == cardSet.at(i).first)
            counter++;
    }

    if(counter == 5) return true;
    else return false;
}