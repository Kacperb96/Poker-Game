#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

enum Colour{
    spades,
    hearts,
    diamonds,
    clubs
};

enum Figures{
    A,
    K,
    Q,
    J,
    ten,
    nine,
    eight,
    seven,
    six,
    five,
    four,
    three,
    two
};

using Card = std::pair<Colour, Figures>;
using CardDeck = std::vector<Card>;

void isFlush(CardDeck& deck){
    
}