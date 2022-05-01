#include <gtest/gtest.h>
#include "Game.hpp"

class DeckOfCardsFixture : public testing::Test{
    public:
        void SetUp();
        void changeCardFromSet(CardSet&, Card&);

    protected:
        Card c1, c2, c3, c4, c5;
        CardSet straightSet;
        CardSet flushSet;
        CardSet onePairSet;
        CardSet twoPairSet;
        CardSet threeOfaKindSet;
        CardSet fullHouseSet;
        CardSet quadsSet;
        CardSet straightFlushSet;
        CardSet royalFlushSet;
        CardSet testFlush;
};

void DeckOfCardsFixture::changeCardFromSet(CardSet& cardSet, Card& c){
    cardSet.pop_back();
    cardSet.push_back(c);
}

void DeckOfCardsFixture::SetUp(){
    royalFlushSet = {std::make_pair(Figures::Jack, Colour::Diamonds), std::make_pair(Figures::King, Colour::Diamonds),
    std::make_pair(Figures::Ace, Colour::Diamonds), std::make_pair(Figures::Ten, Colour::Diamonds), std::make_pair(Figures::Queen, Colour::Diamonds)};

    straightFlushSet = {std::make_pair(Figures::Nine, Colour::Spades), std::make_pair(Figures::Six, Colour::Spades),
    std::make_pair(Figures::Seven, Colour::Spades), std::make_pair(Figures::Eight, Colour::Spades), std::make_pair(Figures::Ten, Colour::Spades)};

    quadsSet = {std::make_pair(Figures::Ace, Colour::Clubs), std::make_pair(Figures::Ace, Colour::Diamonds),
    std::make_pair(Figures::Seven, Colour::Diamonds), std::make_pair(Figures::Ace, Colour::Hearts), std::make_pair(Figures::Ace, Colour::Spades)};

    fullHouseSet = {std::make_pair(Figures::Jack, Colour::Diamonds), std::make_pair(Figures::Jack, Colour::Clubs),
    std::make_pair(Figures::Queen, Colour::Clubs), std::make_pair(Figures::Queen, Colour::Diamonds), std::make_pair(Figures::Queen, Colour::Hearts)};

    straightSet = {std::make_pair(Figures::Nine, Colour::Spades), std::make_pair(Figures::Six, Colour::Diamonds),
    std::make_pair(Figures::Seven, Colour::Clubs), std::make_pair(Figures::Eight, Colour::Clubs), std::make_pair(Figures::Ten, Colour::Hearts)};

    flushSet = {std::make_pair(Figures::Ace, Colour::Clubs), std::make_pair(Figures::King, Colour::Clubs),
    std::make_pair(Figures::Queen, Colour::Clubs), std::make_pair(Figures::Two, Colour::Clubs), std::make_pair(Figures::Ten, Colour::Clubs)};

    threeOfaKindSet = {std::make_pair(Figures::Two, Colour::Diamonds), std::make_pair(Figures::Three, Colour::Hearts),
    std::make_pair(Figures::Jack, Colour::Spades), std::make_pair(Figures::Jack, Colour::Hearts), std::make_pair(Figures::Jack, Colour::Diamonds)};

    onePairSet = {std::make_pair(Figures::Ace, Colour::Diamonds), std::make_pair(Figures::Three, Colour::Clubs),
    std::make_pair(Figures::Queen, Colour::Spades), std::make_pair(Figures::Six, Colour::Clubs), std::make_pair(Figures::Three, Colour::Clubs)};

    twoPairSet = {std::make_pair(Figures::Ace, Colour::Diamonds), std::make_pair(Figures::Ace, Colour::Hearts),
    std::make_pair(Figures::King, Colour::Spades), std::make_pair(Figures::King, Colour::Clubs), std::make_pair(Figures::Jack, Colour::Clubs)};
};

TEST_F(DeckOfCardsFixture, CardsCombinationChecking){
    EXPECT_EQ(cardsCombination(onePairSet), "One Pair\n");
    EXPECT_EQ(cardsCombination(twoPairSet), "Two pair\n");
    EXPECT_EQ(cardsCombination(threeOfaKindSet), "Three of a kind\n");
    EXPECT_EQ(cardsCombination(straightSet), "Straight\n");
    EXPECT_EQ(cardsCombination(flushSet), "Flush\n");
    EXPECT_EQ(cardsCombination(fullHouseSet), "Full house\n");
    EXPECT_EQ(cardsCombination(quadsSet), "Four of a kind\n");
    EXPECT_EQ(cardsCombination(straightFlushSet), "Straight flush\n");
    //EXPECT_EQ(cardsCombination(royalFlushSet), "Royal flush\n");
}

TEST_F(DeckOfCardsFixture, IsTwoPair){
    EXPECT_EQ(twoPair(twoPairSet), 3);
    Card c = std::make_pair(Figures::King, Colour::Hearts);
    changeCardFromSet(twoPairSet, c);
    EXPECT_EQ(twoPair(twoPairSet), 0);
}

TEST_F(DeckOfCardsFixture, IsOnePair){
    EXPECT_EQ(onePair(onePairSet), 2);
    Card c = std::make_pair(Figures::Jack, Colour::Diamonds);
    changeCardFromSet(onePairSet, c);
    EXPECT_EQ(onePair(onePairSet), 0);
}

TEST_F(DeckOfCardsFixture, IsThreeOfAKind){
    EXPECT_EQ(threeOfAKind(threeOfaKindSet), 4);
    Card c = std::make_pair(Figures::Three, Colour::Diamonds);
    changeCardFromSet(threeOfaKindSet, c);
    EXPECT_EQ(threeOfAKind(threeOfaKindSet), 0);
}

TEST_F(DeckOfCardsFixture, IsFlush){
    EXPECT_EQ(flush(flushSet), 6);
    Card c = std::make_pair(Figures::Six, Colour::Diamonds);
    changeCardFromSet(flushSet, c);
    EXPECT_EQ(flush(flushSet), 0);
}

TEST_F(DeckOfCardsFixture, IsStraight){
    EXPECT_EQ(straight(straightSet), 5);
    Card c = std::make_pair(Figures::King, Colour::Diamonds);
    changeCardFromSet(straightSet, c); 
    EXPECT_EQ(straight(straightSet), 0);
}

TEST_F(DeckOfCardsFixture, IsFullHouse){
    EXPECT_EQ(fullHouse(fullHouseSet), 7);
    Card c = std::make_pair(Figures::Ace, Colour::Spades);
    changeCardFromSet(fullHouseSet, c);
    EXPECT_EQ(fullHouse(fullHouseSet), 0);
}

TEST_F(DeckOfCardsFixture, IsQuads){
    EXPECT_EQ(quads(quadsSet), 8);
    Card c = std::make_pair(Figures::Queen, Colour::Spades);
    changeCardFromSet(quadsSet, c);
    EXPECT_EQ(quads(quadsSet), 0);
}

TEST_F(DeckOfCardsFixture, IsStraightFlush){
    EXPECT_EQ(straightFlush(straightFlushSet), 9);
    Card c = std::make_pair(Figures::Queen, Colour::Spades);
    changeCardFromSet(straightFlushSet, c);
    //EXPECT_EQ(straightFlush(straightFlushSet), 0);
}

TEST_F(DeckOfCardsFixture, IsRoyalFlush){
    EXPECT_EQ(royalFlush(royalFlushSet), 10);
    Card c = std::make_pair(Figures::Ten, Colour::Spades);
    changeCardFromSet(royalFlushSet, c);
    EXPECT_EQ(straightFlush(royalFlushSet), 0);
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}