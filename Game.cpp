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

short onePair(CardSet& cardSet){
    short result;
    (countCards(cardSet) == 1) ? result = 2 : result = 0;
    return result;
}

short twoPair(CardSet& cardSet){
    short result;
    (countCards(cardSet) == 2) ? result = 3 : result = 0;
    return result;
}

short threeOfAKind(CardSet& cardSet){
    short result;
    (countCards(cardSet) == 3) ? result = 4 : result = 0;
    return result;
}

short flush(CardSet& cardSet){
    if(std::all_of(cardSet.begin(), cardSet.end(), [&cardSet](Card c){
        return c.second == cardSet[0].second;   
    })) return 6;

    else return 0;
}

short straight(CardSet& cardSet){
    short counter { 1 };
    std::sort(cardSet.begin(), cardSet.end());
    
    for(int i = 0; i < cardSet.size(); i++){
        for(int j = 1; j < cardSet.size(); j++){
            if(cardSet[i].first + 1 == cardSet[j].first){
                counter++;
            }
        }
    }

    if(counter == 5) return 5;
    return 0;
}

short fullHouse(CardSet& cardSet){
    short result;
    (countCards(cardSet) == 4) ? result = 7 : result = 0;
    return result;
}

short quads(CardSet& cardSet){
    short result;
    (countCards(cardSet) == 6) ? result = 8 : result = 0;
    return result;
}

short straightFlush(CardSet& cardSet){
    short result;
    (straight(cardSet) && flush(cardSet)) ? result = 9 : result = 0;
    return result;
}

short royalFlush(CardSet& cardSet){
    short result;    
    (straightFlush(cardSet) && cardSet[0].first == 0) ? result = 10 : result = 0;
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

void cardCombination(CardSet& cardSet){
    if(onePair(cardSet) == 2) std::cout << "One Pair\n";
    else if(twoPair(cardSet) == 3) std::cout << "Two pair\n";
    else if(threeOfAKind(cardSet) == 4) std::cout << "Three of a kind\n";
    else if(straight(cardSet) == 5) std::cout << "Straight\n";
    else if(flush(cardSet) == 6) std::cout << "Flush\n";
    else if(fullHouse(cardSet) == 7) std::cout << "Full house\n";
    else if(quads(cardSet) == 8) std::cout << "Four of a kind\n";
    else if(straightFlush(cardSet) == 9) std::cout << "Straight flush\n";
    else if(royalFlush(cardSet) == 10) std::cout << "Royal flush\n";
    else std::cout << "High card\n";
}