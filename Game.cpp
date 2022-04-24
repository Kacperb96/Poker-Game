#include "Game.hpp"

bool flush(CardSet& cardSet){
    short counter{ 1 };

    for(int i = 1; i < cardSet.size(); i++){
        if(cardSet.at(i - 1).first == cardSet.at(i).first)
            counter++;
    }

    if(counter == 5) return true;
    else return false;
}

bool onePair(CardSet& cardSet){
    for(int i = 1; i < cardSet.size(); i++){
        if(cardSet.at(i - 1).second == cardSet.at(i).second){
            return true;
            break;
        }
    }
    return false;
}