#include "io.h"

static OpenIt::Action GetAction(OpenIt::Axis axis) // Получаем действие для выполнения при нажатии клавиши.
{
    char ch;
    OpenIt::Action dir = OpenIt::Action::STAY;
    while(dir == OpenIt::Action::STAY && std::cin >> ch)
    {
        if(ch == 'o')
            dir = OpenIt::Action::OPENCELL;
        else
        {
            if(axis == OpenIt::Axis::HORIZONTAL)
            {
                switch(ch)
                {
                    case 'a' : 
                        dir = OpenIt::Action::LEFT;
                        break;
                    case 'd' :
                        dir = OpenIt::Action::RIGHT;
                        break;
                    default: 
                        dir = OpenIt::Action::STAY;
                        break;
                }
            }
            else
            {
                switch(ch)
                {
                    case 'w' :
                        dir = OpenIt::Action::UP;
                        break;
                    case 's' :
                        dir = OpenIt::Action::DOWN;
                        break;
                    default : 
                        dir = OpenIt::Action::STAY;
                        break;
                } 
            }
        }
    }
    return dir;
}

static void DrawField(const Field &obj, const Player *player)
{
    fflush(stdout);
    uint8_t index = obj.GetIndex(obj.GetCoordinates());
    uint8_t cmp1 = 0;
    uint8_t cmp2 = 0;
    uint8_t cmp3 = 0;
    thearray tempArr = obj.GetField();
    const wchar_t cell[2][7][2] = {{LT, H, H, H, H ,H, RT},{LB, H, H, H, H, H, RB}};
    const wchar_t tcell[2][7][2] = {{TLT, TH, TH, TH, TH, TH, TRT},{TLB, TH, TH, TH, TH, TH, TRB}};
    thearray::const_iterator cit = tempArr.cbegin();
    thearray::const_iterator cend = tempArr.cend();
    std::cout << std::string(100,'\n'); // Супер джуниор метод отчистки консоли.
    _setmode(_fileno(stdout),_O_U16TEXT);
    while(cit != cend)
    {
        std::wcout << "Player 1: " << player[0].GetScore() << "          " << "Player 2: " << player[1].GetScore() << '\n';
        for(uint8_t i = 0; i < FIELD_LENGTH; ++i)
        {
            if(cmp1 != index)
            {
                for(uint8_t j = 0; j < 7; ++j)
                {
                    std::wcout << cell[0][j];
                }
            }
            else
            {
                for(uint8_t j = 0; j < 7; ++j)
                {
                    std::wcout << tcell[0][j];
                }
            }
            ++cmp1;
        }
        std::wcout << '\n';

        for(uint8_t i = 0; i < FIELD_LENGTH; ++i)
        {
            if(cmp2 != index)
            {
                for(uint8_t j = 0; j < 7; ++j)
                {
                    std::wcout << V << " " << *cit++ << "  " << V;
                }
            }
            else
            {
                for(uint8_t j = 0; j < 7; ++j)
                {
                    std::wcout << TV << "  " << *cit++ << "  " << TV;
                }
            }
            ++cmp2;   
        }
        std::wcout << '\n';
        
        for(uint8_t i = 0; i < FIELD_LENGTH; ++i)
        {
            if(cmp3 != index)
            {
                for(uint8_t j = 0; j < 7; ++j)
                {
                    std::wcout << cell[1][j];
                }
            }
            else
            {
                for(uint8_t j = 0; j < 7; ++j)
                {
                    std::wcout << tcell[1][j];
                }
            }
            ++cmp3;
        }       
    }
    fflush(stdout);
    _setmode(_fileno(stdout),_O_TEXT);

}

