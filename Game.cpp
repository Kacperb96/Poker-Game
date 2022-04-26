#include "Game.hpp"

bool flush(CardSet& cardSet){
    if(std::all_of(cardSet.begin(), cardSet.end(), [&cardSet](Card c){
        return c.first == cardSet[0].first;   
    })) return true;

    else return false;
}

bool onePair(CardSet& cardSet){
    for (std::size_t i = 0; i < cardSet.size(); ++i) {
        for (std::size_t j = i + 1; j < cardSet.size(); ++j) {
            if (cardSet[i].second == cardSet[j].second)
                return true;
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

    if(counter == 3) return true;
    else return false;
}