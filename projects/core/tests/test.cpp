#include <core/game.h>
#include <core/player.h>
#include <gtest/gtest.h>

using namespace OpenIT;

#if DEPRECATED
TEST(TestGame, Constructor)
{
  // ToDo Constractor test
  Game game;

  ASSERT_EQ(true, true);
}
#endif // DEPRECATED

TEST(TestGame, Start_Check)
{
  Game game;

  game.Start();

  Position carriage = { FIELD_SIZE / 2, FIELD_SIZE / 2 };

  ASSERT_EQ(game.GetCarriage(), carriage);
  ASSERT_EQ(game.GetActivePlayer(), 0);
  ASSERT_EQ(game.IsGameOver(), false);
}

TEST(TestGame, AddPlayer_Check)
{
  Game game;

  Player first;

  Player second;

  Player third;

  game.Start();

  ASSERT_EQ(game.AddPlayer(second), true);
  ASSERT_EQ(game.AddPlayer(first), true);
  ASSERT_EQ(game.AddPlayer(third), false);
}

TEST(TestGame, RemotePlayer_Check)
{
  Game game;

  Player first;

  Player second;

  game.Start();

  game.AddPlayer(first);
  game.AddPlayer(second);

  ASSERT_EQ(game.RemovePlayer(1), true);
  ASSERT_EQ(game.RemovePlayer(1), false);
  ASSERT_EQ(game.RemovePlayer(0), true);
  ASSERT_EQ(game.RemovePlayer(0), false);
}

TEST(TestGame, Player_SetNames)
{
  Player first;

  Player second;

  std::string firstName = "MrFirst";

  std::string secondName = "MsSecond";

  first.SetNickname(firstName);

  second.SetNickname(secondName);

  ASSERT_EQ(first.GetNickname(), firstName);
  ASSERT_EQ(second.GetNickname(), secondName);
}