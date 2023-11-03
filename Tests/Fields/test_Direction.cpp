#include "pch.h"
#include "Direction.h"

TEST(DirectionTests, Base)
{
    Direction dir(8);

    ASSERT_EQ(dir.Azimuth, 8);
    ASSERT_TRUE(dir.Access);

    dir = Direction(4, false);
    ASSERT_EQ(dir.Azimuth, 4);
    ASSERT_FALSE(dir.Access);

    ASSERT_EQ(int(dir), 4) << "Operator int is not worked";
    ASSERT_FALSE(bool(dir)) << "Operator bool is not work";

}

TEST(DirectionTests, EqualOperators)
{
    Direction dir(4, true);

    ASSERT_TRUE(dir == Direction(4, true));
    ASSERT_TRUE(dir == Direction(4, false));
    
    ASSERT_FALSE(dir == Direction(3, true));
    ASSERT_FALSE(dir == Direction(3, false));

    ASSERT_TRUE(dir != Direction(2, true));
    ASSERT_TRUE(dir != Direction(2, false));
}


