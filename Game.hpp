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
            os << "\xe2\x99\xa6"; break;
        case Clubs:
            os << "\xe2\x99\xa7"; break;
        }
    return os;
}

inline std::ostream& operator<<(std::ostream& os, const Figures figure)
{
  switch(figure){
        case Ace:
            os << "A"; break;
        case King:
            os << "K"; break;
        case Queen:
            os << "Q"; break;
        case Jack:
            os << "J"; break;
        case Ten:
            os << "10"; break;
        case Nine:
            os << "9"; break;
        case Eight:
            os << "8"; break;
        case Seven:
            os << "7"; break;
        case Six:
            os << "6"; break;
        case Five:
            os << "5"; break;
        case Four:
            os << "4"; break;
        case Three:
            os << "3"; break;
        case Two:
            os << "2"; break;
    }
    return os;
}

using Card = std::pair<Figures, Colour>;
using CardSet = std::vector<Card>;


CardSet creatingCardDeck();
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
void drawCards(CardSet&);
void printCardSet(CardSet&);