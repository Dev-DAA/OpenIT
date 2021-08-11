#include <iostream>
#include <cctype>

#include "game.h"

int main()
{
    Game game;
    while (true)
    {   
        system("cls");
        game.PlayGame();
        std::cout << "Do you want to play one more time? y/n\n";
        int answer;
        answer = _getch();
        if (tolower(answer) != 'y')
        {
            break;
        }
        
    }
    return 0;
}
