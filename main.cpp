#include "Game.hpp"

int main(){
    std::cout << "\n";
    CardSet cardSet1;
    CardSet cardDeck = creatingCardDeck();
    
    drawCards(cardSet1, cardDeck, 5);

    std::cout << "First set" << std::endl;
    printCardSet(cardSet1);
    changeCards(cardSet1, cardDeck);
    std::cout << std::endl;
    std::cout << "Final cards set\n";
    printCardSet(cardSet1);
    std::cout << cardsCombination(cardSet1);
    
    return 0;
}