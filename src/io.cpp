#include "io.h"

OpenIt::Action IO::GetAction() // Получаем действие для выполнения при нажатии клавиши.
{
    char ch;
    while (true)
    {
        std::cin >> ch;
        switch (ch)
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
    conmanip::console_out_context ctxout(conmanip::console_cleanup_options::restore_all);
    conmanip::console_out conout(ctxout);
    fflush(stdout);
    uint8_t  indexCursor = obj.GetIndex(obj.GetCoordinates());
    thearray tempArr     = obj.GetField();
    system("cls"); // Супер джуниор метод отчистки консоли.
    _setmode(_fileno(stdout), _O_U16TEXT);

    std::wcout << "Player 1: " << player[0].GetScore() << "          "
               << "Player 2: " << player[1].GetScore() << '\n';

    for (auto row = 0; row < FIELD_HEIGHT; ++row)
    {
        // Рисуем верхние части рамок
        for (auto col = 0; col < FIELD_LENGTH; ++col)
        {
            if (indexCursor == row * FIELD_LENGTH + col)
                std::wcout << TLT << TH << TH << TH << TH << TH << TRT;
            else
                std::wcout << LT << H << H << H << H << H << RT;
        }
        std::wcout << '\n';

        // Рисуем центральные части рамок
        for (auto col = 0; col < FIELD_LENGTH; ++col)
        {
            auto index = row * FIELD_LENGTH + col;
            std::wcout << (indexCursor == index ? TV : V) << " ";
            tempArr[index] > 0 ? conout.settextcolor(conmanip::console_text_colors::green)
                               : tempArr[index] < 0 ? conout.settextcolor(conmanip::console_text_colors::red)
                                                    : conout.settextcolor(conmanip::console_text_colors::white);
            std::wcout << std::setw(3) << tempArr[index] << " ";
            conout.resetcolors();
            std::wcout << (indexCursor == index ? TV : V);
        }
        std::wcout << '\n';

        // Рисуем нижние части рамок
        for (auto col = 0; col < FIELD_LENGTH; ++col)
        {
            if (indexCursor == row * FIELD_LENGTH + col)
                std::wcout << TLB << TH << TH << TH << TH << TH << TRB;
            else
                std::wcout << LB << H << H << H << H << H << RB;
        }
        std::wcout << '\n';
    }
    fflush(stdout);
    _setmode(_fileno(stdout), _O_TEXT);
}
