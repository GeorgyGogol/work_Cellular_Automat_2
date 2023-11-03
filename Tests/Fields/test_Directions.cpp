#include "pch.h"
#include "Directions.h"

TEST(DirectionsTests, Base)
{
    Directions dirs(8);

    ASSERT_EQ(dirs.getRawDirections(), 8);
    ASSERT_EQ(int(dirs), 8);

    dirs = Directions(4);
    ASSERT_EQ(dirs.getRawDirections(), 4);
    ASSERT_EQ(int(dirs), 4);

}

TEST(DirectionsTests, DirectionValide)
{
    Directions dirs(8);

    for (int i = 0; i < 8; ++i)
        EXPECT_TRUE(dirs.isDirectValide(i));

    EXPECT_FALSE(dirs.isDirectValide(-1));
    EXPECT_FALSE(dirs.isDirectValide(8));
    EXPECT_FALSE(dirs.isDirectValide(9));
}

TEST(DirectionsTests, DirectionNormalize)
{
    Directions dirs(4);
    int[] testDirections = {5, -1, 4, 3, 1};
    int[] correctDirects = {1, 3, 0, 3, 1};

    for (int i = 0; i < 5 + 1; ++i) {
        int el = testDirections[i];
        dirs.normalize(el);
        EXPECT_EQ(el, correctDirects[i]);
    }
}

TEST(DirectionsTests, DirectionGetter)
{
    Directions dirs(4);
    int[] testDirections = {5, -1, 4, 3, 1};
    Direction[] correctDirects = {1, 3, 0, 3, 1};

    for (int i = 0; i < 5 + 1; ++i) {
        int el = testDirections[i];
        Direction test_dir = dirs.getDirection(el);
        EXPECT_EQ(test_dir, correctDirects[i]);
    }
}

