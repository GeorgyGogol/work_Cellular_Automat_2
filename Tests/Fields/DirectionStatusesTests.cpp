#include "pch.h"
#include "DirectionsStatuses.h"
#include <vector>

class testClass 
    : protected DirectionsStatuses
{
    typedef DirectionsStatuses Base;

public:
    testClass(int val) : DirectionsStatuses(val) {}

    int Count_GetStatus = 0;
    int Count_SetStatus = 0;

    bool getStatus(int direction) {
        ++Count_GetStatus;
        return Base::getStatus(direction);
    }

    void setStatus(int direction, bool status) {
        ++Count_SetStatus;
        Base::setStatus(direction, status);
    }

    //Direction getDirection(int rawDirection) const override;
};

TEST(DirectionStatusesTest, Base)
{
    DirectionsStatuses dirs(4);

    for (int i = 0; i < dirs.getRawDirections(); ++i) {
        EXPECT_TRUE(dirs.getStatus(i)) << "Fail at " << i;
    }

    dirs.setStatus(1, false);
    ASSERT_FALSE(dirs.getStatus(1));
}

TEST(DirectionStatusesTest, CopyAssignConstructor)
{
    DirectionsStatuses dirsOne(8);
    DirectionsStatuses dirsTwo(dirsOne);

    ASSERT_EQ(dirsTwo.getRawDirections(), dirsOne.getRawDirections());
    for (int i = 0; i < dirsTwo.getRawDirections(); ++i) {
        EXPECT_EQ(dirsTwo.getDirection(i), dirsOne.getDirection(i));
    }
}

TEST(DirectionStatusesTest, CopyAssignOperator)
{
    DirectionsStatuses dirsOne(8);
    DirectionsStatuses dirsTwo(0);

    dirsTwo = dirsOne;

    ASSERT_EQ(dirsTwo.getRawDirections(), dirsOne.getRawDirections());
    for (int i = 0; i < dirsTwo.getRawDirections(); ++i) {
        EXPECT_EQ(dirsTwo.getDirection(i), dirsOne.getDirection(i));
    }
}

TEST(DirectionStatusesTest, MoveAssignConstructor)
{
    FAIL();
}

TEST(DirectionStatusesTest, MoveAssignOperator)
{
    FAIL();
}

TEST(DirectionStatusesTest, SetStatuses)
{
    testClass dirs(4);
    int settersRealCall = 0;

    int range_min = -2, range_max = 8;
    for (int i = range_min; i < range_max; ++i) {
        dirs.setStatus(i, false);
    }
    settersRealCall += range_max - range_min;
    ASSERT_EQ(dirs.Count_SetStatus, settersRealCall);

    for (int i = 0; i < 4; ++i){
        EXPECT_FALSE(dirs.getStatus(i));
    }
    ASSERT_EQ(dirs.Count_GetStatus, 4);

    range_min = 2, range_max = 4;
    for (int i = range_min; i < range_max; ++i) {
        dirs.setStatus(i, true);
    }
    settersRealCall += range_max - range_min;
    ASSERT_EQ(dirs.Count_SetStatus, settersRealCall);

    bool statusesMap[] = {false, false, true, true};
    for (int i = 0; i < 4; ++i)
    {
        EXPECT_EQ(dirs.getStatus(i), statusesMap[i]);
    }
    ASSERT_EQ(dirs.Count_GetStatus, 8);
}

TEST(DirectionStatusesTest, GetDirection)
{
    DirectionsStatuses dirs(4);
    dirs.setStatus(3, false);
    Direction dir;

    dir = dirs.getDirection(1);
    ASSERT_EQ(dir.Azimuth, 1);
    ASSERT_TRUE(dir.Access);

    dir = dirs.getDirection(3);
    ASSERT_EQ(dir.Azimuth, 3);
    ASSERT_FALSE(dir.Access);

}

