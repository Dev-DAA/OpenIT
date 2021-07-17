#include "player.h"

#ifndef GAME_H
#define GAME_H
enum class Winner{Empty, Player1, Player2, Draw};

class Game // Класс Игра с полями Основное Игровое Поле и двумя игроками.
{
    private:
        Field m_field;
        Player m_playerone = MoveCursor::HORIZONTALLY;
        Player m_playertwo = MoveCursor::VERTICALLY;
        Winner winner = Winner::Empty;
        // An object of IO class goes here;

    public:
        Game() = default;
        ~Game() = default;

        void NewGame(); // Инициализация поля, установка статуса winner в Empty.
        
        void playGame(); // Основная логика игры. 

        Winner getWinner()const; // Вывод информации о победителе на экран.

        void setWinner(); // Присвоение статуса в конце игры.
};

#endif