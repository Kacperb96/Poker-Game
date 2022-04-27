#include <gtest/gtest.h>
#include "Game.hpp"

class DeckOfCardsFixture : public testing::Test{
    public:
        void SetUp();
    protected:
        Card c1, c2, c3, c4, c5;
        CardSet straightSet;
        CardSet flushSet;
        CardSet onePairSet;
        CardSet twoPairSet;
        CardSet threeOfaKindSet;
        CardSet fullHouseSet;
};

void DeckOfCardsFixture::SetUp(){
    fullHouseSet = {std::make_pair(Figures::Jack, Colour::Diamonds), std::make_pair(Figures::Jack, Colour::Clubs),
    std::make_pair(Figures::Queen, Colour::Clubs), std::make_pair(Figures::Queen, Colour::Diamonds), std::make_pair(Figures::Queen, Colour::Hearts)};

    straightSet = {std::make_pair(Figures::Nine, Colour::Spades), std::make_pair(Figures::Six, Colour::Diamonds),
    std::make_pair(Figures::Seven, Colour::Clubs), std::make_pair(Figures::Eight, Colour::Clubs), std::make_pair(Figures::Ten, Colour::Hearts)};

    flushSet = {std::make_pair(Figures::Ace, Colour::Clubs), std::make_pair(Figures::King, Colour::Clubs),
    std::make_pair( Figures::Queen, Colour::Clubs), std::make_pair(Figures::Jack, Colour::Clubs), std::make_pair(Figures::Ten, Colour::Clubs)};

    threeOfaKindSet = {std::make_pair(Figures::Two, Colour::Diamonds), std::make_pair(Figures::Three, Colour::Hearts),
    std::make_pair(Figures::Jack, Colour::Spades), std::make_pair(Figures::Jack, Colour::Hearts), std::make_pair(Figures::Jack, Colour::Diamonds)};

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

TEST_F(DeckOfCardsFixture, IsThreeOfAKind){
    EXPECT_EQ(threeOfAKind(threeOfaKindSet), true);
    Card c = std::make_pair(Figures::Three, Colour::Diamonds);

    threeOfaKindSet.pop_back();
    threeOfaKindSet.push_back(c);

    EXPECT_EQ(threeOfAKind(threeOfaKindSet), false);
}

TEST_F(DeckOfCardsFixture, IsFlush){
    EXPECT_EQ(flush(flushSet), true);
    Card c = std::make_pair(Figures::Six, Colour::Diamonds);

    flushSet.pop_back();
    flushSet.push_back(c);
    
    EXPECT_EQ(flush(flushSet), false);
}

TEST_F(DeckOfCardsFixture, IsStraight){
    EXPECT_EQ(straight(straightSet), true);
    Card c = std::make_pair(Figures::King, Colour::Diamonds);

    straightSet.pop_back();
    straightSet.push_back(c);
    
    EXPECT_EQ(straight(straightSet), false);
}

TEST_F(DeckOfCardsFixture, IsFullHouse){
    EXPECT_EQ(fullHouse(fullHouseSet), true);
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}