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

const short onePair(CardSet& cardSet){
    short result;
    (countCards(cardSet) == 1) ? result = 2 : result = 0;
    return result;
}

const short twoPair(CardSet& cardSet){
    short result;
    (countCards(cardSet) == 2) ? result = 3 : result = 0;
    return result;
}

const short threeOfAKind(CardSet& cardSet){
    short result;
    (countCards(cardSet) == 3) ? result = 4 : result = 0;
    return result;
}

const short flush(CardSet& cardSet){
    if(std::all_of(cardSet.begin(), cardSet.end(), [&cardSet](Card c){
        return c.second == cardSet[0].second;   
    })) return 6;

    else return 0;
}

const short straight(CardSet& cardSet){
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

const short fullHouse(CardSet& cardSet){
    short result;
    (countCards(cardSet) == 4) ? result = 7 : result = 0;
    return result;
}

const short quads(CardSet& cardSet){
    short result;
    (countCards(cardSet) == 6) ? result = 8 : result = 0;
    return result;
}

const short straightFlush(CardSet& cardSet){
    short result;
    (straight(cardSet) && flush(cardSet)) ? result = 9 : result = 0;
    return result;
}

const short royalFlush(CardSet& cardSet){
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

std::string cardsCombination(CardSet& cardSet){
    int counter = 0;
    std::string result;
    if(onePair(cardSet) == 2) {result = "One Pair\n"; counter++;}
    else if(twoPair(cardSet) == 3) {result = "Two pair\n"; counter += 2;}
    else if(threeOfAKind(cardSet) == 4){result = "Three of a kind\n"; counter += 3;}
    else if(straight(cardSet) == 5) {result = "Straight\n"; counter += 4;} 
    else if(flush(cardSet) == 6) {result = "Flush\n"; counter += 5;}
    else if(fullHouse(cardSet) == 7) {result = "Full house\n"; counter += 6;}
    else if(quads(cardSet) == 8) {result = "Four of a kind\n"; counter += 7;}
    else if(straightFlush(cardSet) == 9) {result = "Straight flush\n"; counter += 8;}
    else if(royalFlush(cardSet) == 10) {result = "Royal flush\n"; counter += 9;}
    else result = "High card\n";
    std::cout << result << std::endl;

    return result;
}