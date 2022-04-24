#include <gtest/gtest.h>
#include "Game.hpp"

class DeckOfCardsFixture : public testing::Test{
    public:
        void SetUp();
    protected:
        Card c1, c2, c3, c4, c5;
        CardDeck flushDeck{c1, c2, c3, c4, c5};
};

void DeckOfCardsFixture::SetUp(){
    c1 = std::make_pair(Colour::Clubs, Figures::Ace);
    c2 = std::make_pair(Colour::Clubs, Figures::King);
    c3 = std::make_pair(Colour::Clubs, Figures::Queen);
    c4 = std::make_pair(Colour::Clubs, Figures::Jack);
    c5 = std::make_pair(Colour::Clubs, Figures::Ten);
};

TEST_F(DeckOfCardsFixture, IsFlush){
    EXPECT_EQ(isFlush(flushDeck), true);
    Card c6;
    c6 = std::make_pair(Colour::Diamonds, Figures::Six);

    flushDeck.pop_back();
    flushDeck.push_back(c6);
    
    EXPECT_EQ(isFlush(flushDeck), false);
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}