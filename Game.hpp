#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

enum Colour{
    Spades,
    Hearts,
    Diamonds,
    Clubs
};

enum Figures{
    Ace,
    King,
    Queen,
    Jack,
    Ten,
    Nine,
    Eight,
    Seven,
    Six,
    Five,
    Four,
    Three,
    Two
};

using Card = std::pair<Colour, Figures>;
using CardSet = std::vector<Card>;

bool isFlush(CardSet&);