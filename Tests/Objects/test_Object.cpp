#include "pch.h"
#include "Object.h"
#include <memory>

class ObjectTests : public ::testing::Test
{
protected:
    ObjectData_s data_s;
    ObjectData data;
    Object* TestObject;

    void SetUp()
    {
        // data_s
        data_s.Existance = 10;

        // data
        data.Existance = 20;

        TestObject = new Object(data_s);
    }

    void TearDown()
    {
        delete TestObject;
    }

};

/* TEST_F(ObjectTests, Constructors_new_ds) {
    Object* Ptr;

    ASSERT_NO_THROW(Ptr = new Object(data_s)) << "Constructor with ObjectData_s not worked!";

    EXPECT_EQ(Ptr->getExistancePointsMax(), data_s.Existance);
    EXPECT_EQ(Ptr->getExistancePoints(), data_s.Existance);

    ASSERT_NO_THROW(delete Ptr);
}

TEST_F(ObjectTests, Constructors_new_d) {
    Object* Ptr;

    ASSERT_NO_THROW(Ptr = new Object(data)) << "Constructor with ObjectData not worked!";

    EXPECT_EQ(Ptr->getExistancePointsMax(), data.Existance);
    EXPECT_EQ(Ptr->getExistancePoints(), data.Existance);

    ASSERT_NO_THROW(delete Ptr);
} */

TEST_F(ObjectTests, ConstructorsRef) {
    Object o1(data);
    Object o2(data_s);

    SUCCEED();
}

TEST_F(ObjectTests, ObjectReference) {
    Object o1(data);
    
    Object o2 = o1;
    ASSERT_NE(&o2 == &o1);
    EXPECT_EQ(o2 == o1);
}

TEST_F()
{

}

TEST_F(ObjectTests, Existance) {
    Object o(data_s);

    o.addExistancePoints(5);
    ASSERT_EQ(o.getExistancePoints(), o.getExistancePointsMax()) << "Value cannot be more than max";
    ASSERT_EQ(o.isExists(), true) << "Object must exists";

    o.addExistancePoints(-data_s.Existance);
    ASSERT_EQ(o.getExistancePoints(), 0);
    ASSERT_EQ(o.isExists(), false) << "Object must not exists";

    ASSERT_NO_THROW(o.addExistancePoints(-1));
    ASSERT_EQ(o.getExistancePoints(), 0);

    o.addExistancePoints(2);
    ASSERT_EQ(o.getExistancePoints(), 2);
}

TEST_F(ObjectTests, testDamage) {
    std::unique_ptr<Object> o1(new Object(data_s));
    std::unique_ptr<Object> o2(new Object(data));

    ASSERT_NO_THROW(o1->SendDamage(o2.get(), 10));
    EXPECT_EQ(o2->getExistancePoints(), data.Existance - 10);
    EXPECT_EQ(o1->getExistancePoints(), data_s.Existance - 10);
}

