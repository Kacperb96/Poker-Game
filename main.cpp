#include "Game.hpp"

int main(){
    std::cout << "Hello from Main" << std::endl;
    CardSet cardSet;
    CardSet cardDeck = creatingCardDeck();
    
    
    for(int i = 0; i < 52; i++){
        if(i % 4 == 0) std::cout << "\n";
        std::cout << cardDeck[i].first << cardDeck[i].second << std::endl;
    }
    std::cout << "\n";

    drawCards(cardSet, cardDeck);
    printCardSet(cardSet);

    return 0;
}