#include "Game.hpp"

int main(){
    std::cout << "Hello from Main" << std::endl;
    std::cout << "__________________________________\n\n";
    CardSet setCard;
    drawCards(setCard);
    printCardSet(setCard);
    std::cout << "__________________________________\n\n";
    
    for(int i = 0; i < creatingCardDeck().size(); i++){
        std::cout << creatingCardDeck()[i].first << creatingCardDeck()[i].second << std::endl; 
    }

    return 0;
}