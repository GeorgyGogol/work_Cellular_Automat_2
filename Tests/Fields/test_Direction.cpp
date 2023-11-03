#include "pch.h"
#include "Direction.h"

TEST(DirectionTests, Base)
{
    Direction dir(8);

    ASSERT_EQ(dir.Azimuth, 8);
    ASSERT_EQ(dir.Access, true);

    dir = Direction(4, false);
    ASSERT_EQ(dir.Azimuth, 4);
    ASSERT_EQ(dir.Access, false);

    ASSERT_EQ(int(dir), 4) << "Operator int is not worked";
    ASSERT_EQ(bool(dir), false) << "Operator bool is not work";
}

