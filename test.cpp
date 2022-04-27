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
    flushSet = {std::make_pair(Figures::Ace, Colour::Clubs), std::make_pair(Figures::King, Colour::Clubs),
    std::make_pair( Figures::Queen, Colour::Clubs), std::make_pair(Figures::Jack, Colour::Clubs), std::make_pair(Figures::Ten, Colour::Clubs)};

    onePairSet = {std::make_pair(Figures::Ace, Colour::Diamonds), std::make_pair(Figures::Three, Colour::Clubs),
    std::make_pair(Figures::Queen, Colour::Spades), std::make_pair(Figures::Six, Colour::Clubs), std::make_pair(Figures::Three, Colour::Clubs)};

    twoPairSet = {std::make_pair(Figures::Ace, Colour::Diamonds), std::make_pair(Figures::Ace, Colour::Hearts),
    std::make_pair(Figures::King, Colour::Spades), std::make_pair(Figures::King, Colour::Clubs), std::make_pair(Figures::Jack, Colour::Clubs)};
};

TEST_F(DeckOfCardsFixture, IsTwoPair){
    EXPECT_EQ(twoPair(twoPairSet), true);
    Card c = std::make_pair(Figures::King, Colour::Hearts);

    twoPairSet.pop_back();
    twoPairSet.push_back(c);

    EXPECT_EQ(twoPair(twoPairSet), false);
}

TEST_F(DeckOfCardsFixture, IsOnePair){
    EXPECT_EQ(onePair(onePairSet), true);
    Card c = std::make_pair(Figures::Jack, Colour::Diamonds);
    
    onePairSet.pop_back();
    onePairSet.push_back(c);

    EXPECT_EQ(onePair(onePairSet), false);
}

TEST_F(DeckOfCardsFixture, IsFlush){
    EXPECT_EQ(flush(flushSet), true);
    Card c = std::make_pair(Figures::Six, Colour::Diamonds);

    flushSet.pop_back();
    flushSet.push_back(c);
    
    EXPECT_EQ(flush(flushSet), false);
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}