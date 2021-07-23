#include "io.h"

static OpenIt::Action GetAction() // Получаем действие для выполнения при нажатии клавиши.
{
    char ch;
    OpenIt::Action dir = OpenIt::Action::STAY;
    while(dir == OpenIt::Action::STAY && std::cin >> ch)
    {
        switch(ch)
        {
            case 'a' : 
                dir = OpenIt::Action::LEFT;
                break;
            case 'd' :
                dir = OpenIt::Action::RIGHT;
                break;
            case 'w' :
                dir = OpenIt::Action::UP;
                break;
            case 's' :
                dir = OpenIt::Action::DOWN;
                break;
            case 'o' :
                dir = OpenIt::Action::OPENCELL;
            default :
                dir = OpenIt::Action::STAY;
                break;
        } 
    }
    return dir;
}

