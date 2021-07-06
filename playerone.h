#include "player.h"
#ifndef PLAYERONE_H
#define PLAYERONE_H

class PlayerOne : public Player // Первый игрок с полями "статус" и "счёт".
{
    private:
        Status m_status = Empty;
        int m_score = 0;
    public:

        PlayerOne() : Player(){}

        void SetStatus(Status nstatus); // Устанавливаем статус игрока 1 перед началом игры(Empty) и в конце игры(Winner,Loser,Draw).

        Status GetStatus(); // Получаем информацию о статусе игрока 1.

        void AddScore(int nscore); // Прибавляем\убавляем счёт игрока 1 в зависимости от цвета открытой ячейки.

        int GetScore() const; // Информация о счёте игрока 1.

        bool IsLineEmpty() const; // Перед каждым ходом проверяем строку на наличие неоткрытых ячеек.

        void Move(char ch); // Определеяем границы строки, в которой может перемещаться игрок 1 и в зависимости от клавиш 'a', 'd' шагаем влево\вправо.

        ~PlayerOne(){};
};

#endif