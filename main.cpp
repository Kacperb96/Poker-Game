#include "Game.hpp"

int main(){
    std::cout << "\n";
    CardSet cardSet1;
    CardSet cardDeck = creatingCardDeck();
    
    drawCards(cardSet1, cardDeck);
    std::this_thread::sleep_for(std::chrono::seconds(1));

    std::cout << "First set" << std::endl;
    printCardSet(cardSet1);
    changeCards(cardSet1);
    std::cout << std::endl;
    std::cout << cardsCombination(cardSet1);
    
    return 0;
}