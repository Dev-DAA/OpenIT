#include <memory>
#include <utility>
#include "field.h"

#ifndef PLAYER_H
#define PLAYER_H

class Player 
{
    private:
        int16_t m_score;
        std::shared_ptr<Field> m_gameField = nullptr;
    public:
        Player() = default; 
        Player(std::shared_ptr<Field>field);
        Player(Player &&obj);
        Player &operator=(Player &&obj);

        //void SetPlayerToField(std::shared_ptr<Field> field); // Предоставляем игроку доступ к полю field; Доступ будут иметь оба игрока через std::shared_ptr;

        iterator GetCurrentPos() const; // Возвращаем указатель на текущую позицию. Используется для открытия ячейки в классе Game.

        bool IsLineEmpty(bool who) const;
        void AddScore(int8_t nscore);
        int16_t GetScore() const;
        void Move(bool who, char ch);
        ~Player(){};
};

#endif