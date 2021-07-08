#include "player.h"

#ifndef GAME_H
#define GAME_H
enum Winner{Empty, Player1, Player2, Draw};

class Game // Класс Игра с полями Основное Игровое Поле и двумя игроками.
{
    private:
        std::shared_ptr<Field> m_mainField = nullptr;
        Player m_playerone;
        Player m_playertwo;
        Winner winner = Empty;
    public:
        Game() = default;

        Winner getWinner(){return winner;}

        std::ostream & getWinner(std::ostream &os); // Присвоение статуса игрокам в конце игры и вывод информации на экран.
             
        void startGame(); // Инициалиция поля, предоставление доступа к нему игрокам и установка статуса обоих в Empty.

        void playGame(); // Основная логика игры.
 
    ~Game(){}
};

#endif