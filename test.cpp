#include <gtest/gtest.h>
#include "Game.hpp"

TEST(Sample, EXAMPLE){
    int i = 1;
    EXPECT_EQ(i, 1);
}

int main(int argc, char** argv){
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}