#include "Game.hpp"

bool flush(CardSet& cardSet){
    if(std::all_of(cardSet.begin(), cardSet.end(), [&cardSet](Card c){
        return c.first == cardSet[0].first;   
    })) return true;

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

bool twoPair(CardSet& cardSet){
    short counter{ 0 };

    for(int i = 1; i < cardSet.size(); i++){
        if(cardSet.at(i - 1).second == cardSet.at(i).second)
            counter++;
    }

    std::cout << counter << std::endl;
    if(counter == 2) return true;
    else return false;
}

bool ThreeOfAKind(CardSet& cardSet){
    short counter{ 1 };

    for(int i = 1; i < cardSet.size(); i++){
        if(cardSet.at(i - 1).second == cardSet.at(i).second)
            counter++;
        if(counter == 3) break;
    }

    std::cout << counter << std::endl;
    if(counter == 3) return true;
    else return false;
}