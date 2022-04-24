#include <gtest/gtest.h>
#include "Game.hpp"

TEST(ColourFunction, CheckingIsFlushFunction){
    Card c1, c2, c3, c4, c5;
    c1.first = Colour::clubs;
    c1.second = Figures::K;

    c2.first = Colour::clubs;
    c2.second = Figures::A;

    c3.first = Colour::clubs;
    c3.second = Figures::Q;

    c4.first = Colour::clubs;
    c4.second = Figures::J;

    c5.first = Colour::clubs;
    c5.second = Figures::three;

    CardDeck deck {};
    deck.push_back(c1);
    deck.push_back(c2);
    deck.push_back(c3);
    deck.push_back(c4);
    deck.push_back(c5);

    EXPECT_EQ(isFlush(deck), true);
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}