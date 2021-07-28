#include "game.h"

#include <iostream>

void Game::SetWinner() // Присвоение статуса игрокам в конце игры и вывод информации на экран.
{
    if (m_players[0].GetScore() > m_players[1].GetScore())
    {
        m_winner = OpenIt::Winner::Player1;
    }
    else if (m_players[0].GetScore() < m_players[1].GetScore())
    {
        m_winner = OpenIt::Winner::Player2;
    }
    else
    {
        m_winner = OpenIt::Winner::Draw;
    }
}
OpenIt::Winner Game::GetWinner() const
{
    if (m_winner == OpenIt::Winner::Player1)
    {
        std::cout << "And the winner is: Player 1" << '\n';
    }
    else if (m_winner == OpenIt::Winner::Player2)
    {
        std::cout << "And the winner is: Player 2" << '\n';
    }
    else
    {
        std::cout << "Draw!" << '\n';
    }

    return m_winner;
}

void Game::NewGame() // Инициализация поля, установка статуса winner в Empty.
{
    m_field.InitField();
    m_winner = OpenIt::Winner::Empty;
}

void Game::PlayGame() // Основная логика игры.
{
    OpenIt::Action action = OpenIt::Action::STAY;
    int16_t      nscore       = 0; // Используется при присвоении значения открытой ячейки.
    unsigned int activePlayer = 0; // Индекс текущего игрока.
    while (m_winner == OpenIt::Winner::Empty)
    {
        OpenIt::Axis grantedDirection = m_players[activePlayer].GrantedDirection(); // Получаем разрешённое направление движения.

        IO::Render(m_field,m_players); // Отрисовываем поле в начале игры.
        
        if (m_field.IsLineEmpty(grantedDirection)) // Проверяем наличие неоткрытых ячеек у активного игрока (по горизонтали\вертикали).
        {
            break; // Если все ячейки в строке\столбце открыты - выходим из цикла и объявляем победителя.
        }

        action  = IO::GetAction(); // Ждём нажатия клавиши, соответствующей одному из возможных действий игрока.

        if (action == OpenIt::Action::OPENCELL)
        {
            nscore = m_field.Open(); // Открываем ячейку, присваивая её содержимое переменной nscore.
            if (nscore)
            {
                m_players[activePlayer].AddScore(nscore); // Увеличиваем счёт действующего игрока на nscore.
                activePlayer = (activePlayer + 1) % 2; // Если значение ячейки было ненулевым - передаём ход игроку 2.
            }
        }
        else
        {
            // Проверяем разрешённое направление движения и нажатую клавишу. Например, горизонтальное направление и клавиши для движения влево\вправо.
            if((grantedDirection == OpenIt::Axis::HORIZONTAL && (action == OpenIt::Action::LEFT || action == OpenIt::Action::RIGHT)) ||
                (grantedDirection == OpenIt::Axis::VERTICAL && (action == OpenIt::Action::UP || action == OpenIt::Action::DOWN)))
            {
                m_field.Move(action);
            }
        }
    }
    SetWinner(); // Устанавливаем победителя.
    GetWinner(); // Выводим информацию о победителе на экран.
}
