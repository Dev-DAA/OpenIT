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
    char         ch;               // Используется при обработке ввода с клавиатуры.
    int16_t      nscore       = 0; // Используется при присвоении значения открытой ячейки.
    unsigned int activePlayer = 0; // Индекс текущего игрока.
    while (m_winner == OpenIt::Winner::Empty)
    {
        // Проверяем наличие неоткрытых ячеек у активного игрока (по горизонтали\вертикали).
        if (m_field.IsLineEmpty(m_players[activePlayer].GrantedDirection())) 
        {
            break; // Если все ячейки в строке\столбце открыты - выходим из цикла и объявляем победителя.
        }

        std::cin >> ch;

        if (ch == 'o')
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
            // gdir - разрешённое направление движения (HORIZONTAL\VERTICAL).
            OpenIt::Axis gdir = m_players[activePlayer].GrantedDirection();
            OpenIt::Action dir;
            if(gdir == OpenIt::Axis::HORIZONTAL) 
            {
                // Если по горизонтали, то обрабатываем клавиши 'a' и 'd'.
                dir = (ch == 'a' ? OpenIt::Action::LEFT : ch == 'd' ? OpenIt::Action::RIGHT : OpenIt::Action::STAY); 
            }
            else
            {
                // По вертикали - 'w' & 's'.
                dir = (ch == 'w' ? OpenIt::Action::UP : ch == 's' ? OpenIt::Action::DOWN : OpenIt::Action::STAY);
            }
            m_field.Move(dir);
        }
    }
    SetWinner(); // Устанавливаем победителя.
    GetWinner(); // Выводим информацию о победителе на экран.
}
