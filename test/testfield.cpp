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

TEST_F(FieldTest, MoveWithBiasToUpperLeftCorner)
{
    uint8_t expectedIndex = 0;
    int8_t counter = 0;
    bool moved = 0;
    OpenIt::Action dir = OpenIt::Action::RIGHT;
    uint8_t length  = FIELD_LENGTH;
    //uint8_t height = FIELD_HEIGHT;
    int8_t iterative = length/2;
    while(true)
    {
        uint8_t central = length*iterative + iterative;
        std::cout << "CENTRAL INDEX IS " << central << '\n';
        while(true)
        {
            std::cout << "HORIZONTAL\n";
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
                    ASSERT_NE(central + counter, expectedIndex);
                    EXPECT_EQ(central + counter +1, expectedIndex);
                    counter +=1;
                    dir = OpenIt::Action::RIGHT;
                    if(counter == 0)
                    {
                        dir = OpenIt::Action::DOWN;
                    }

                }
            }
        }
        while(true)
        {
            std::cout << "VERTICAL\n";
            moved = field.Move(dir);
            dir == OpenIt::Action::DOWN ? counter +=1 : counter -=1;
            expectedIndex = field.GetIndex(field.GetCoordinates());
            if(moved)
            {
                EXPECT_EQ(central + counter*length, expectedIndex);
                if(dir == OpenIt::Action::DOWN && counter == 0)
                {
                    dir = OpenIt::Action::RIGHT;
                    break;
                }
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
                    counter +=1;
                    dir = OpenIt::Action::DOWN;
                }
            }
        }
        iterative -=1;
        field.Move(OpenIt::Action::LEFT);
        field.Move(OpenIt::Action::UP);
        char ch;
        std::cout << "One round has passed. Please, let another round go\n";
        std::cin >> ch;
        if(ch != 'y')
            break;
        if(iterative < 0)
        {
            break;
        }
    }
}


