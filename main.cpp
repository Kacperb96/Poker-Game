#include "Game.hpp"

int main(){
    std::cout << "Hello from Main" << std::endl;
    CardSet twoPairSet = {std::make_pair(Colour::Spades, Figures::Ace), std::make_pair(Colour::Spades, Figures::Ace),
    std::make_pair(Colour::Spades, Figures::Ten), std::make_pair(Colour::Spades, Figures::Ten), std::make_pair(Colour::Spades, Figures::King)};

    std::cout << std::boolalpha << flush(twoPairSet) << std::endl;

    return 0;
}