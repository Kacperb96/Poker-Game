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

using Card = std::pair<Figures, Colour>;
using CardSet = std::vector<Card>;

bool onePair(CardSet&);
bool twoPair(CardSet&);
bool ThreeOfAKind(CardSet&);
bool flush(CardSet&);
bool straight(CardSet&);