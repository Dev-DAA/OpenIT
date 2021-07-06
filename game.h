#include "playerone.h"
#include "playertwo.h"

#ifndef GAME_H
#define GAME_H

class Game // Класс Игра с полями Основное Игровое Поле и двумя игроками.
{
    private:
        std::shared_ptr<Field> m_mainField = nullptr;
        PlayerOne *m_playerone = nullptr;
        PlayerTwo *m_playertwo = nullptr;
    public:
        Game() = default;

        std::ostream & getWinner(std::ostream &os); // Присвоение статуса игрокам в конце игры и вывод информации на экран.
             
        void startGame(); // Инициалиция поля, предоставление доступа к нему игрокам и установка статуса обоих в Empty.

        void playGame(); // Основная логика игры.
 
    ~Game(){}
};

#endif