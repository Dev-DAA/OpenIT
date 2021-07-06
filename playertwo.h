#include "player.h"
#ifndef PLAYERTWO_H
#define PLAYERTWO_H

class PlayerTwo : public Player // Второй игрок с таким же набором параметров, но переписанными вирутальными методами из базового класса.
{
    private:
        Status m_status = Empty;
        int m_score = 0;
    public:
        PlayerTwo() : Player(){}

        void SetStatus(Status nstatus);

        Status GetStatus();
        
        void AddScore(int nscore);

        int GetScore() const; 

        bool IsLineEmpty() const; // У игрока 2, перемещающегося по вертикали, идёт проверка колонны на наличие неоткрытых ячеек.

        void Move(char ch); // Игрок 2 двигается по вертикали, вирутальный метод Move переписан.

        ~PlayerTwo(){};
};



#endif