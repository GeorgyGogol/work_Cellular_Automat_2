#include "pch.h"
#include "CellLevels.h"

TEST(CellLevelsTests, CreateDefault)
{
    CellLevels levels;

    EXPECT_EQ(levels.Altitude, 0);
    EXPECT_EQ(levels.LiquidCount, 0);
    EXPECT_EQ(levels.isLiquidUnderground, true);
}

TEST(CellLevelsTests, Create_1)
{
    CellLevels levels{1, 2, false};

    EXPECT_EQ(levels.Altitude, 1);
    EXPECT_EQ(levels.LiquidCount, 2);
    EXPECT_EQ(levels.isLiquidUnderground, false);
}

TEST(CellLevelsTests_functions, fSurfaceLevel)
{
    ASSERT_EQ(SurfaceLevel(CellLevels()), 0) << "At zero level must be zero";
    EXPECT_EQ(SurfaceLevel(CellLevels{ 2, 0, true }), 2);
    EXPECT_EQ(SurfaceLevel(CellLevels{ 2, 3, true }), 3);
    EXPECT_EQ(SurfaceLevel(CellLevels{ -2, 2, false }), 0);
    EXPECT_EQ(SurfaceLevel(CellLevels{ 1, 0, false }), 1);
}
