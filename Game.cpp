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

bool threeOfAKind(CardSet& cardSet){
    bool result;
    (countCards(cardSet) == 3) ? result = true : result = false;
    return result;
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

bool fullHouse(CardSet& cardSet){
    bool result;
    (countCards(cardSet) == 4) ? result = true : result = false;
    return result;
}

bool quads(CardSet& cardSet){
    bool result;
    (countCards(cardSet) == 6) ? result = true : result = false;
    return result;
}

bool straightFlush(CardSet& cardSet){
    bool result;
    (straight(cardSet) && flush(cardSet)) ? result = true : result = false;
    return result;
}

bool royalFlush(CardSet& cardSet){
    bool result;    
    (straightFlush(cardSet) && cardSet[0].first == 0) ? result = true : result = false;
    return result;
}

CardSet creatingCardDeck(){
    CardSet cardDeck;
    short colourNum {0};
    short cardNum {0};
    do{
        if(colourNum > 3){
            colourNum = 0;
            cardNum++;
        }
        else{
            cardDeck.push_back(std::make_pair(static_cast<Figures>(cardNum), static_cast<Colour>(colourNum)));
            colourNum++;
        }
    }while(cardNum < 13);

    return cardDeck;
}

void drawCards(CardSet& cardSet, CardSet& cardDeck){
    srand(time(NULL));
    int a {0};
    for (int i = 0, it = 52; i < 5; i++, it--){
        a = rand() % it; 
        cardSet.push_back(cardDeck[a]);
        cardDeck.erase(cardDeck.begin() + a);
    }
}

void printCardSet(CardSet &x){
    for (size_t i = 0; i < x.size(); ++i){
        std::cout << x[i].first << x[i].second << "\t";
    }
    std::cout << std::endl;
}