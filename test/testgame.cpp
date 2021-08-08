#include "../googletest/googletest/include/gtest/gtest.h"
#include "../src/game.h"

// Объявляем экземлпяр класса Game.
class GameTest : public ::testing::Test
{
  protected:
    Game game;
};
