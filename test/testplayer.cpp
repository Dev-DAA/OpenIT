#include "../googletest/googletest/include/gtest/gtest.h"
#include "../src/player.h"

// Объявляем экземлпяр класса Player.
class PlayerTest : public ::testing::Test
{
  protected:
    Player players[2] = { Player(OpenIt::Axis::HORIZONTAL), Player(OpenIt::Axis::VERTICAL) };
};

TEST_F(PlayerTest, InitialScore)
{
    // Проверяем равенство счёта нулю при инициализации.
    ASSERT_EQ(players[0].GetScore(), 0);
    ASSERT_EQ(players[1].GetScore(), 0);
}

TEST_F(PlayerTest, AddScoreGetScore) // Тестируем метод добавления очков к текущему счёту.
{
    // Тестируем игрока 1.
    players[0].AddScore(5);
    EXPECT_EQ(players[0].GetScore(), 5);
    players[0].AddScore(9);
    EXPECT_EQ(players[0].GetScore(), 14);
    players[0].AddScore(-4);
    EXPECT_EQ(players[0].GetScore(), 10);
    players[0].AddScore(-11);
    EXPECT_EQ(players[0].GetScore(), -1);
    players[0].AddScore(-7);
    EXPECT_EQ(players[0].GetScore(), -8);
    players[0].AddScore(11);
    EXPECT_EQ(players[0].GetScore(), 3);

    // Тестируем игрока 2.
    players[1].AddScore(11);
    EXPECT_EQ(players[1].GetScore(), 11);
    players[1].AddScore(3);
    EXPECT_EQ(players[1].GetScore(), 14);
    players[1].AddScore(-8);
    EXPECT_EQ(players[1].GetScore(), 6);
    players[1].AddScore(-11);
    EXPECT_EQ(players[1].GetScore(), -5);
    players[1].AddScore(-8);
    EXPECT_EQ(players[1].GetScore(), -13);
    players[1].AddScore(11);
    EXPECT_EQ(players[1].GetScore(), -2);
}

TEST_F(PlayerTest, SetScore) // Тестируем метод обнуление очков игрока.
{
    players[0].AddScore(11);
    players[1].AddScore(-9);
    EXPECT_EQ(players[0].GetScore(), 11);
    EXPECT_EQ(players[1].GetScore(), -9);
    players[0].SetScore();
    players[1].SetScore();
    ASSERT_EQ(players[0].GetScore(), 0);
    ASSERT_EQ(players[1].GetScore(), 0);
}

TEST_F(PlayerTest, GrantedDirection) // Тестируем корректность возврата направления хода.
{
    ASSERT_EQ(players[0].GrantedDirection(), OpenIt::Axis::HORIZONTAL);
    ASSERT_EQ(players[1].GrantedDirection(), OpenIt::Axis::VERTICAL);
}