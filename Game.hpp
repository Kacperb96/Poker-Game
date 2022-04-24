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


bool isFlush(CardDeck& deck){
    int counter{ 1 };

    for(int i = 1; i < deck.size(); i++){
        if(deck.at(i - 1).first == deck.at(i).first)
            counter++;
    }

    if(counter == 5) return true;
    else return false;
}