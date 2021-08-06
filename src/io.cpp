#include "io.h"

#include <string>

#include "../cppconlib/include/conmanip.h"

OpenIt::Action IO::GetAction() // Получаем действие для выполнения при нажатии клавиши.
{
    std::string ch;
    while (true)
    {
        getline(std::cin, ch);
        switch (ch[0])
        {
            case 'a':
                return OpenIt::Action::LEFT;
            case 'd':
                return OpenIt::Action::RIGHT;
            case 'w':
                return OpenIt::Action::UP;
            case 's':
                return OpenIt::Action::DOWN;
            case 'o':
                return OpenIt::Action::OPENCELL;
            case '=':
                return OpenIt::Action::EXIT;
            case 'n':
                return OpenIt::Action::NEWGAME;
        }
    }
}

void IO::Render(const Field& obj, const Player* player)
{
    system("cls"); // Супер джуниор метод отчистки консоли.
    uint8_t length = FIELD_LENGTH; // Константа для отрисовки счёта игроков при изменяющемся поле. 
    conmanip::console_out_context ctxout(conmanip::console_cleanup_options::restore_all);
    conmanip::console_out         conout(ctxout); // Класс console_out из conmanip.h отвечает за цвет цифр на экране консоли.
    uint8_t                       indexCursor = obj.GetIndex(obj.GetCoordinates());
    thearray                      tempArr     = obj.GetField();
    fflush(stdout);
    _setmode(_fileno(stdout), _O_U16TEXT); // Переключам вывод на Юникод для отрисовки таблицы.

    if(length <=2) // Выравниваем вывод очков каждого игрока относительно ширины игрового поля.
    {
        std::wcout << std::left
                   << std::setw(3*(FIELD_LENGTH/2)) << "1: " << player[0].GetScore()
                   << std::setw(7*FIELD_LENGTH-8) << " " << std::left
                   << std::setw(3*(FIELD_LENGTH/2)) << "2: " << player[1].GetScore() << '\n';        
    }
    else if(length < 5 && length > 2)
    {
        std::wcout << std::left
                   << std::setw(5*(FIELD_LENGTH/3)) << "P 1: " << player[0].GetScore()
                   << std::setw(7*FIELD_LENGTH-12) << " " << std::left
                   << std::setw(5*(FIELD_LENGTH/3)) << "P 2: " << player[1].GetScore() << '\n';
    }
    else
    {
        std::wcout << std::left
                   << std::setw(10*(FIELD_LENGTH/5)) << "Player 1: " << player[0].GetScore()
                   << std::setw(7*FIELD_LENGTH-22) << " " << std::left
                   << std::setw(10*(FIELD_LENGTH/5)) << "Player 2: " << player[1].GetScore() << '\n';   
    }

    for (auto row = 0; row < FIELD_HEIGHT; ++row)
    {
        // Рисуем верхние части рамок
        for (auto col = 0; col < FIELD_LENGTH; ++col)
        {
            if (indexCursor == row * FIELD_LENGTH + col)
                std::wcout << TLT_C << TH_L << TH_L << TH_L << TH_L << TH_L << TRT_C;
            else
                std::wcout << LT_C << H_L << H_L << H_L << H_L << H_L << RT_C;
        }
        std::wcout << '\n';

        // Рисуем центральные части рамок. Если значение массива < 0, то раскрашиваем в красный цвет, иначе - зелёный.
        for (auto col = 0; col < FIELD_LENGTH; ++col)
        {
            auto index = row * FIELD_LENGTH + col;
            std::wcout << (indexCursor == index ? TV_L : V_L) << " ";
            tempArr[index] > 0 ? conout.settextcolor(conmanip::console_text_colors::green)
                               : conout.settextcolor(conmanip::console_text_colors::red);
            tempArr[index] != 0 ? std::wcout << std::setw(3) << tempArr[index] << " "
                                : std::wcout << std::setw(4) << " ";
            conout.resetcolors();
            std::wcout << (indexCursor == index ? TV_L : V_L);
        }
        std::wcout << '\n';

        // Рисуем нижние части рамок
        for (auto col = 0; col < FIELD_LENGTH; ++col)
        {
            if (indexCursor == row * FIELD_LENGTH + col)
                std::wcout << TLB_C << TH_L << TH_L << TH_L << TH_L << TH_L << TRB_C;
            else
                std::wcout << LB_C << H_L << H_L << H_L << H_L << H_L << RB_C;
        }
        std::wcout << '\n';
    }
    fflush(stdout);
    _setmode(_fileno(stdout), _O_TEXT);
}
