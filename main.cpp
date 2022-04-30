#include "Game.hpp"

int main(){
    int counter{0};
    std::cout << "\n";
    CardSet cardSet1;
    CardSet cardSet2;
    CardSet cardDeck = creatingCardDeck();
    
    drawCards(cardSet1, cardDeck);
    std::this_thread::sleep_for(std::chrono::seconds(1));
    drawCards(cardSet2, cardDeck);

    std::cout << "First set" << std::endl;
    printCardSet(cardSet1);
    std::cout << cardsCombination(cardSet1);
    std::cout << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "Second set" << std::endl;
    printCardSet(cardSet2);
    std::cout << cardsCombination(cardSet2);

    /*for(int i = 0; i < cardDeck.size(); i++){
        std::cout << cardDeck[i].first << cardDeck[i].second << " ";
    }*/
    std::cout << "\n";

    return 0;
}