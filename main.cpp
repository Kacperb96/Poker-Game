#include "Game.hpp"

int main(){
    std::cout << "Hello from Main" << std::endl;
    std::cout << "__________________________________\n\n";
    CardSet setCard;
    drawCards(setCard);
    printCardSet(setCard);
    std::cout << "__________________________________\n\n";

    return 0;
}