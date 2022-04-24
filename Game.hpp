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

auto lambdaFlushClubs = [](Card& c){
    if(c.first == 3) return true;
};

bool isFlush(CardDeck& deck){
    return (std::all_of(deck.begin(), deck.end(), lambdaFlushClubs));
}