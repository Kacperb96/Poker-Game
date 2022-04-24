#include "Game.hpp"


int main(){
    std::cout << "Main" << std::endl;
        Card c1, c2, c3, c4, c5;
    c1.first = Colour::clubs;
    c1.second = Figures::K;

    c2.first = Colour::clubs;
    c2.second = Figures::A;

    c3.first = Colour::clubs;
    c3.second = Figures::Q;

    c4.first = Colour::clubs;
    c4.second = Figures::J;

    c5.first = Colour::diamonds;
    c5.second = Figures::three;

    CardDeck deck {};
    deck.push_back(c1);
    deck.push_back(c2);
    deck.push_back(c3);
    deck.push_back(c4);
    deck.push_back(c5);

    std::cout << "Is flush " << std::boolalpha << isFlush(deck);
    std::cout << std::endl;

    return 0;
}