#ifndef GAME_H
#define GAME_H

#include "player.h"

class Game // Класс Игра с полями Основное Игровое Поле и двумя игроками.
{
  private:
    Field          m_field;
    Player         m_players[2] = { Player(OpenIt::Axis::HORIZONTAL), Player(OpenIt::Axis::VERTICAL) };
    OpenIt::Winner m_winner       = OpenIt::Winner::Empty;
    // An object of IO class goes here.

  public:
    Game()  = default;
    ~Game() = default;

    void NewGame(); // Инициализация поля, установка статуса winner в Empty.

    void PlayGame(); // Основная логика игры.

    OpenIt::Winner GetWinner() const; // Вывод информации о победителе на экран.

    void SetWinner(); // Присвоение статуса в конце игры.
};

#endif