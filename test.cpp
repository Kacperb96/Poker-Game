#include <gtest/gtest.h>
#include "Game.hpp"

class DeckOfCardsFixture : public testing::Test{
    public:
        void SetUp();
    protected:
        Card c1, c2, c3, c4, c5;
};

void DeckOfCardsFixture::SetUp(){
    c1.first = Colour::Clubs;
    c1.second = Figures::King;

    c2.first = Colour::Clubs;
    c2.second = Figures::Ace;

    c3.first = Colour::Clubs;
    c3.second = Figures::Queen;

    c4.first = Colour::Clubs;
    c4.second = Figures::Jack;

    c5.first = Colour::Clubs;
    c5.second = Figures::Three;
};

TEST_F(DeckOfCardsFixture, IsFlush){
    CardDeck deck {c1, c2, c3, c4, c5};

    EXPECT_EQ(isFlush(deck), true);
    Card c6;
    c6.first = Colour::Diamonds;
    c6.second = Figures::Six;

    deck.pop_back();
    deck.push_back(c6);
    
    EXPECT_EQ(isFlush(deck), false);
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}