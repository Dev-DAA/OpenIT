#include "../src/field.h"
#include "../googletest/googletest/include/gtest/gtest.h"

class FieldTest : public ::testing::Test
{
    protected:
        Field field;
};

TEST_F(FieldTest, IsEqualToZero)
{
    thearray temparr = field.GetField(); 
    for(uint8_t i = 0; i < FIELD_LENGTH*FIELD_HEIGHT; ++i)
        EXPECT_NE(temparr[i],0);
}

TEST_F(FieldTest, CheckMove)
{
    uint8_t expectedIndex = field.GetIndex(field.GetCoordinates());
    EXPECT_EQ(10, expectedIndex);
    OpenIt::Action action = OpenIt::Action::RIGHT;
    field.Move(action);
    expectedIndex = field.GetIndex(field.GetCoordinates());
    EXPECT_EQ(11, expectedIndex);
    action = OpenIt::Action::RIGHT;
    field.Move(action);
    expectedIndex = field.GetIndex(field.GetCoordinates());
    ASSERT_NE(12,expectedIndex); //  Добавить равенство по границам.
    action = OpenIt::Action::LEFT;
    field.Move(action);
    field.Move(action);
    field.Move(action);
    field.Move(action);
    expectedIndex = field.GetIndex(field.GetCoordinates());
    EXPECT_EQ(8,expectedIndex);
    field.Move(action);
    expectedIndex = field.GetIndex(field.GetCoordinates());
    EXPECT_NE(7,expectedIndex);
    action = OpenIt::Action::DOWN;
    field.Move(action);
    expectedIndex = field.GetIndex(field.GetCoordinates());
    EXPECT_EQ(12,expectedIndex);
    field.Move(action);
    expectedIndex = field.GetIndex(field.GetCoordinates());
    ASSERT_NE(16,expectedIndex);
    action = OpenIt::Action::UP;
    field.Move(action);
    field.Move(action);
    expectedIndex = field.GetIndex(field.GetCoordinates());
    EXPECT_EQ(4,expectedIndex);
    field.Move(action);
    expectedIndex = field.GetIndex(field.GetCoordinates());
    EXPECT_EQ(0,expectedIndex);
    field.Move(action);
    expectedIndex = field.GetIndex(field.GetCoordinates());
    ASSERT_NE(4294967295,expectedIndex);  
}

TEST_F(FieldTest, IsCoordinateCentered)
{
    EXPECT_EQ(field.GetIndex(field.GetCoordinates()),FIELD_LENGTH*FIELD_LENGTH/2 + FIELD_HEIGHT/2); 
}

