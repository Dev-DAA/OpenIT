/**
 * @file Game.cpp
 * @author Dmitrii Ivanov (idma88@yandex.ru)
 * @author Denis Koinash (den.koinash@gmail.com)
 * @brief Определение класса Игра
 */

#include <iterator> // std::next
#include <random>   // std::uniform_int_distribution

#include <core/game.h>

namespace OpenIT {

Game::Game() {}

void
Game::Start()
{
  auto rnd = []() {
    std::random_device              rd;
    std::mt19937                    gen(rd());
    std::uniform_int_distribution<> distrib(-ABS_MAX_VALUE, ABS_MAX_VALUE);

    int8_t value;
    do
      value = distrib(gen);
    while (value == EMPTY_CELL);

    return value;
  };

  m_carriage = { FIELD_SIZE / 2, FIELD_SIZE / 2 };

  m_activePlayer = 0;

  for (auto&& item : m_field)
    item = rnd();

  for (auto&& player : m_players)
    player.m_score = 0;
}

bool
Game::IsGameOver() const
{
  // Горизонтальное перемещение каретки для игрока №1
  if (m_activePlayer == 0) {
    for (int x = 0; x < FIELD_SIZE; ++x)
      if (m_field[x + m_carriage.y * FIELD_SIZE] != EMPTY_CELL) return false;
  }
  // Вертикальное перемещение каретки для игрока №2
  else
    for (int y = 0; y < FIELD_SIZE; ++y)
      if (m_field[m_carriage.x + y * FIELD_SIZE] != EMPTY_CELL) return false;

  return true;
}

IdValue
Game::GetId() const
{
  return m_id;
}

Game::Players
Game::GetPlayers() const
{
  return m_players;
}

uint8_t
Game::GetActivePlayer() const
{
  return m_activePlayer;
}

Game::Scores
Game::GetScores() const
{
  Scores scores;

  for (auto&& item : m_players)
    scores.push_back(item.m_score);

  return scores;
}

Game::Field
Game::GetField() const
{
  return m_field;
}

Position
Game::GetCarriage() const
{
  return m_carriage;
}

bool
Game::AddPlayer(const Player& player)
{
  if (m_players.size() == PLAYER_COUNT) return false;

  m_players.push_back(player);

  return true;
}

bool
Game::RemovePlayer(uint8_t index)
{
  if (index >= m_players.size()) return false;

  m_players.erase(std::next(m_players.begin(), index));

  return true;
}

Position
Game::MoveCarriage(Position pos)
{
  // Горизонтальное перемещение каретки для игрока №1
  if (m_activePlayer == 0) {
    if (pos.y == m_carriage.y && pos.x >= 0 && pos.x < FIELD_SIZE) m_carriage = pos;
  }
  // Вертикальное перемещение каретки для игрока №2
  else {
    if (pos.x == m_carriage.x && pos.y >= 0 && pos.y < FIELD_SIZE) m_carriage = pos;
  }
  return m_carriage;
}

bool
Game::OpenCell()
{
  int cellPos = m_carriage.x + m_carriage.y * FIELD_SIZE;

  if (m_field[cellPos] == EMPTY_CELL) return false;

  std::next(m_players.begin(), m_activePlayer)->m_score += m_field[cellPos];

  m_field[cellPos] = EMPTY_CELL;

  m_activePlayer = (m_activePlayer ? 0 : 1);

  return true;
}

} // namespace OpenIT