#include "Game.hpp"

int main(){
    std::cout << "Hello from Main" << std::endl;
    CardSet cardSet = {std::make_pair(King, Spades),
    std::make_pair(Queen, Clubs),
    std::make_pair(Six, Clubs),
    std::make_pair(Ace, Diamonds),
    std::make_pair(Jack, Diamonds)};

    return 0;
}