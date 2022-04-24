#include <gtest/gtest.h>
#include "Game.hpp"

class DeckOfCardsFixture : public testing::Test{
    public:
        void SetUp();
    protected:
        Card c1, c2, c3, c4, c5;
        CardSet flushSet;
        CardSet onePairSet;
        CardSet twoPairSet;
};

void DeckOfCardsFixture::SetUp(){
    flushSet = {std::make_pair(Colour::Clubs, Figures::Ace), std::make_pair(Colour::Clubs, Figures::King),
    std::make_pair(Colour::Clubs, Figures::Queen), std::make_pair(Colour::Clubs, Figures::Jack), std::make_pair(Colour::Clubs, Figures::Ten)};

    onePairSet = {std::make_pair(Colour::Diamonds, Figures::Ace), std::make_pair(Colour::Clubs, Figures::Ace)};

    twoPairSet = {std::make_pair(Colour::Diamonds, Figures::Ace), std::make_pair(Colour::Hearts, Figures::Ace),
    std::make_pair(Colour::Spades, Figures::King), std::make_pair(Colour::Clubs, Figures::King)};
};

TEST_F(DeckOfCardsFixture, IsTwoPair){
    EXPECT_EQ(twoPair(twoPairSet), true);
    Card c = std::make_pair(Colour::Hearts, Figures::Three);

    twoPairSet.pop_back();
    twoPairSet.push_back(c);

    EXPECT_EQ(twoPair(twoPairSet), false);
}

TEST_F(DeckOfCardsFixture, IsOnePair){
    EXPECT_EQ(onePair(onePairSet), true);
    Card c = std::make_pair(Colour::Diamonds, Figures::King);
    
    onePairSet.pop_back();
    onePairSet.push_back(c);

    EXPECT_EQ(onePair(onePairSet), false);
}

TEST_F(DeckOfCardsFixture, IsFlush){
    EXPECT_EQ(flush(flushSet), true);
    Card c = std::make_pair(Colour::Diamonds, Figures::Six);

    flushSet.pop_back();
    flushSet.push_back(c);
    
    EXPECT_EQ(flush(flushSet), false);
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}