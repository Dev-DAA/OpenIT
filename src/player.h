#ifndef PLAYER_H
#define PLAYER_H

#include <memory>
#include <utility>

#include "field.h"

class Player
{
  private:
    int16_t      m_score = 0;
    OpenIt::Axis m_cursor;

  public:
    Player(OpenIt::Axis ncursor);
    ~Player() = default;

    int16_t GetScore() const; // Получаем текущий счёт игрока.

    void AddScore(int16_t nscore); // Увеличение счёта игрока на nscore очков.

    OpenIt::Axis GrantedDirection() const; // Получаем разрешённое направление движения.

    // OpenIt::Direction GetDirection(char ch) const; // Получаем направление движения в зависимости от нажатой клавиши.
};

#endif