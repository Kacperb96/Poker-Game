#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <ctime>

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

inline std::ostream& operator<<(std::ostream& os, const Colour colour)
{
  switch(colour){
        case Spades:
            os << "\xe2\x99\xa4"; break;
        case Hearts:
            os << "\xe2\x99\xa5"; break;
        case Diamonds:
            os << "\xe2\x99\xa3"; break;
        case Clubs:
            os << "\xe2\x99\xa2"; break;
        }
    return os;
}

using Card = std::pair<Figures, Colour>;
using CardSet = std::vector<Card>;

short countCards(CardSet);
bool onePair(CardSet&);
bool twoPair(CardSet&);
bool threeOfAKind(CardSet&);
bool flush(CardSet&);
bool straight(CardSet&);
bool fullHouse(CardSet&);
bool quads(CardSet&);
bool straightFlush(CardSet&);
bool royalFlush(CardSet&);
CardSet drawCards();