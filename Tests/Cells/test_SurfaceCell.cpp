#include "pch.h"
#include "SurfaceCell.h"
#include "CellLevels.h"

class SurfaceCellTests : public ::testing::Test
{
protected:
    CellLevels ZeroLevel, AnotherLevel;

    void SetUp()
    {
        // AnotherLevel
        AnotherLevel.Altitude = 2;
        AnotherLevel.LiquidCount = 1;
    }

};

TEST_F(SurfaceCellTests, Constructors_Default)
{
    ASSERT_NO_THROW(SurfaceCell create_cell) << "Default construct is not worked";
    
    SurfaceCell cell;

    EXPECT_EQ(cell.getAltitude(), ZeroLevel.Altitude) << "Altitude is not default";
    EXPECT_EQ(cell.getLiquidCount(), ZeroLevel.LiquidCount) << "LiquidCount is not default";
}

TEST_F(SurfaceCellTests, Constructors_1)
{
    SurfaceCell cell(AnotherLevel);

    ASSERT_EQ(cell.getAltitude(), AnotherLevel.Altitude);
    ASSERT_EQ(cell.getLiquidCount(), AnotherLevel.LiquidCount);
}

TEST_F(SurfaceCellTests, Altitude)
{
    SurfaceCell cell;

    cell.setAltitude(5);
    EXPECT_EQ(cell.getAltitude(), 5) << "Altitude settes is not work";

    cell.changeAltitude(-2);
    EXPECT_EQ(cell.getAltitude(), 3) << "Altitude changer is not work";
}

TEST_F(SurfaceCellTests, Liquid)
{
    SurfaceCell cell;

    cell.setLiquidCount(5);
    EXPECT_EQ(cell.getLiquidCount(), 5) << "Liquid settes is not work";

    cell.changeLiquidCount(-2);
    EXPECT_EQ(cell.getLiquidCount(), 3) << "Liquid changer is not work";
}

