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

TEST_F(FieldTest, IsCoordinateCentered)
{
    EXPECT_EQ(field.GetIndex(field.GetCoordinates()),FIELD_LENGTH*FIELD_LENGTH/2 + FIELD_HEIGHT/2); 
}

TEST_F(FieldTest, CheckMove)
{
    uint8_t expectedIndex = 0;
    int8_t counter = 0;
    bool moved = 0;
    OpenIt::Action dir = OpenIt::Action::RIGHT;
    uint8_t length  = FIELD_LENGTH;
    uint8_t height = FIELD_HEIGHT;
    while(true)
    {
        uint8_t central = length*length/2+height/2;
        while(true)
        {
            moved = field.Move(dir);
            dir == OpenIt::Action::RIGHT ? counter +=1 : counter -=1;
            expectedIndex = field.GetIndex(field.GetCoordinates());
            if(moved)
            {
                EXPECT_EQ(central+counter, expectedIndex);
                if(dir == OpenIt::Action::RIGHT && counter == 0){
                    dir = OpenIt::Action::DOWN;
                    break;
                }
            }
            else
            {
                if(dir == OpenIt::Action::RIGHT)
                {
                    ASSERT_NE(central + counter, expectedIndex);
                    EXPECT_EQ(central + counter -1, expectedIndex);
                    counter -=1;
                    dir = OpenIt::Action::LEFT;
                }
                else
                {
                    ASSERT_NE(central + counter -1, expectedIndex);
                    EXPECT_EQ(central + counter, expectedIndex);
                    counter +=1;
                    dir = OpenIt::Action::RIGHT;
                }
            }
        }
        while(true)
        {
            moved = field.Move(dir);
            dir == OpenIt::Action::UP ? counter +=1 : counter -=1;
            expectedIndex = field.GetIndex(field.GetCoordinates());
            if(moved)
            {
                EXPECT_EQ(central + counter*length, expectedIndex);

            }
            else
            {
                if(dir == OpenIt::Action::DOWN)
                {
                    ASSERT_NE(central+counter*length, expectedIndex);
                    EXPECT_EQ(central+(counter-1)*length,expectedIndex);
                    counter -=1;
                    dir = OpenIt::Action::UP;
                }
                else
                {
                    ASSERT_NE(central+counter*length,expectedIndex);
                    EXPECT_EQ(central+(counter+1)*length,expectedIndex);
                }

            }

        }
    }





}


