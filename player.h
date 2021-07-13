#include <memory>
#include <utility>
#include "field.h"

#ifndef PLAYER_H
#define PLAYER_H

enum class MoveCursor{HORIZONTALLY, VERTICALLY}; // Разрешённое направление движения курсора.

class Player 
{
    private:
        int16_t m_score = 0;
        MoveCursor m_cursor;
    public:
        Player(); 
        ~Player(){};

        int16_t GetScore() const; // Получаем текущий счёт игрока.

        void AddScore(int16_t nscore); // Увеличение счёта игрока на nscore очков.

        MoveCursor GrantedDirection(Who who) const; // Получаем разрешённое направление движения курсора.
};

#endif