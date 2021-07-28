#include <iostream>

#include "game.h"

int main()
{
    Game game;
    game.NewGame();
    game.PlayGame();
    std::cout << "ZDRAVSTVUYTE!\n";
    return 0;
}

/* Сыграл по-быстрому игру. Счёт и ходы шли корректно, по крайней мере в этой игре.
    Отрисовка страдает, походу не переключается режим в юникод. Посмотрю сегодня */