#include <iostream>

#include "game.h"

int main()
{
    Game game;
    while(true)
    {
        game.PlayGame();
        std::cout << "Do you want to play one more time? y/n\n";
        char answer;
        std::cin >> answer;
        if (answer != 'y')
        {
            break;
        }
    }
    return 0;
}
