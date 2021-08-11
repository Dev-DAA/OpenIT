#ifndef PLAYER_H
#define PLAYER_H

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

    void SetScore(); // Обнуляем счёт игрока при новой игре.

    void AddScore(int16_t nscore); // Увеличение счёта игрока на nscore очков.

    OpenIt::Axis GrantedDirection() const; // Получаем разрешённое направление движения.
};

#endif