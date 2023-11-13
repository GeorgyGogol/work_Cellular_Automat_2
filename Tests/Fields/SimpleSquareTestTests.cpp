#include "pch.h"
#include "SimpleSquareTestField.h"

class SimpleSquareTestTests : public testing::Test
{
protected:
    SimpleSquareTestField* pField;
    int Height, Width;

    void SetUp()
    {
        Height = 5;
        Width = 5;

        pField = new SimpleSquareTestField(Height, Width);
    }

    void TearDown()
    {
        delete pField;
    }

};

TEST_F(SimpleSquareTestTests, Base)
{
    ASSERT_EQ(pField->getHeight(), Height);
    ASSERT_EQ(pField->getWidth(), Width);
    ASSERT_EQ(pField->getWidth(3), Width);
}

TEST_F(SimpleSquareTestTests, CellsGetter)
{
    ASSERT_EQ(pField->getCellAt(1, 1), 0);
    ASSERT_EQ(pField->getCellAt(2, 2), 0);
}

TEST_F(SimpleSquareTestTests, CallsSetter)
{
    pField->setCellAt(2, 1, 2);
    ASSERT_EQ(pField->getCellAt(2, 1), 2);
}

TEST_F(SimpleSquareTestTests, DirectionsForPoint_pure_correct)
{
    DirectionsStatuses dirs = pField->getDirectionsForPoint(1, 1);
    for (int i = 0; i < dirs.getRawDirections(); ++i) {
        EXPECT_EQ(dirs.getDirection(i), Direction(i, true));
    }
}

TEST_F(SimpleSquareTestTests, DirectionsForPoint_correct)
{
    for (int y = 1; y < 1 + 3; ++y) {
        for (int x = 1; x < 1 + 3; ++x) {
            if (y == 2 && x == 2) continue;
            pField->setCellAt(x, y, 5);
        }
    }
    pField->setCellAt(2, 1, 1);

    DirectionsStatuses dirs = pField->getDirectionsForPoint(2, 2);

    EXPECT_TRUE(dirs.getDirection(0).Access);
    EXPECT_EQ(dirs.getDirection(0), Direction(0, true));

    for (int i = 1; i < dirs.getRawDirections(); ++i) {
        EXPECT_EQ(dirs.getDirection(i), Direction(i, false));
    }
}

TEST_F(SimpleSquareTestTests, DirectionsForPoint_uncorrect)
{
    DirectionsStatuses dirs = pField->getDirectionsForPoint(100, 100);
    ASSERT_FALSE(dirs.isValide());
    EXPECT_EQ(dirs.getRawDirections(), 0);
}

