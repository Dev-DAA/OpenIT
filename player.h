#include <memory>
#include <utility>
#include "field.h"

#ifndef PLAYER_H
#define PLAYER_H

enum Status{Empty = 0,Winner, Loser, Draw};// Статус игрока по ходу(Empy) и концу игры(Winner, Loser, Draw).

class Player 
{
    protected:
        std::shared_ptr<Field> m_gameField = nullptr;
    public:
        Player() = default;

        void SetPlayerToField(std::shared_ptr<Field> field); // Предоставляем игроку доступ к полю field; Доступ будут иметь оба игрока через std::shared_ptr;

        Cell *GetCurrentPos(); // Возвращаем указатель на текущую позицию. Используется для открытия ячейки в классе Game.


        virtual void SetStatus(Status nstatus)=0;//?
        virtual Status GetStatus()=0;//?
        virtual bool IsLineEmpty() = 0;
        virtual void AddScore(int nscore) =0;//?
        virtual int GetScore() = 0;//?
        virtual void Move() =0;
        virtual ~Player();
};

#endif