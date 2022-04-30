#include "Game.hpp"

int main(){
    std::cout << "Hello from Main" << std::endl;
    CardSet cardSet1;
    CardSet cardSet2;
    CardSet cardDeck = creatingCardDeck();
    
    drawCards(cardSet1, cardDeck);
    drawCards(cardSet2, cardDeck);
    std::cout << "First set" << std::endl;
    printCardSet(cardSet1);
    std::cout << std::endl;
    std::cout << "Second set" << std::endl;
    printCardSet(cardSet2);
    std::cout << "\n";

    return 0;
}