#include "Game.hpp"

short countCards(CardSet cardSet){
    short counter {0};
    for(std::size_t i = 0; i < cardSet.size(); i++){
        for(std::size_t j = i + 1; j < cardSet.size(); j++){
            if(cardSet[j].first == cardSet[i].first) counter ++;
        }
    }

    return counter;
}

bool onePair(CardSet& cardSet){
    bool result;
    (countCards(cardSet) == 1) ? result = true : result = false;
    return result;
}

bool twoPair(CardSet& cardSet){
    bool result;
    (countCards(cardSet) == 2) ? result = true : result = false;
    return result;
}

bool ThreeOfAKind(CardSet& cardSet){
    short counter{ 1 };

    for(int i = 1; i < cardSet.size(); i++){
        if(cardSet.at(i - 1).first == cardSet.at(i).first)
            counter++;
        if(counter == 3) break;
    }

    if(counter == 3) return true;
    else return false;
}

bool flush(CardSet& cardSet){
    if(std::all_of(cardSet.begin(), cardSet.end(), [&cardSet](Card c){
        return c.second == cardSet[0].second;   
    })) return true;

    else return false;
}

bool straight(CardSet& cardSet){
    short counter { 1 };
    std::sort(cardSet.begin(), cardSet.end());
    
    for(int i = 0; i < cardSet.size(); i++){
        for(int j = 1; j < cardSet.size(); j++){
            if(cardSet[i].first + 1 == cardSet[j].first){
                counter++;
            }
        }
    }

    if(counter == 5) return true;
    return false;
}