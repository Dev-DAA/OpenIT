#include "game.h"

#include <iostream>

void Game::SetWinner() // Присвоение статуса игрокам в конце игры и вывод информации на экран.
{
    if (m_players[0].GetScore() > m_players[1].GetScore())
    {
        winner = OpenIt::Winner::Player1;
    }
    else if (m_players[0].GetScore() < m_players[1].GetScore())
    {
        winner = OpenIt::Winner::Player2;
    }
    else
    {
        winner = OpenIt::Winner::Draw;
    }
}
OpenIt::Winner Game::GetWinner() const
{
    if (winner == OpenIt::Winner::Player1)
    {
        std::cout << "And the winner is: Player 1" << '\n';
    }
    else if (winner == OpenIt::Winner::Player2)
    {
        std::cout << "And the winner is: Player 2" << '\n';
    }
    else
    {
        std::cout << "Draw!" << '\n';
    }

    return winner;
}

void Game::NewGame() // Инициализация поля, установка статуса winner в Empty.
{
    m_field.InitField();
    winner = OpenIt::Winner::Empty;
}

void Game::PlayGame() // Основная логика игры.
{
    char         ch;
    int16_t      nscore       = 0;
    unsigned int activePlayer = 0;
    while (winner == OpenIt::Winner::Empty)
    {
        if (m_field.IsLineEmpty(m_players[activePlayer].GrantedDirection()))
        {
            SetWinner();
        }

        std::cin >> ch;

        if (ch == 'o')
        {
            nscore = m_field.Open();
            if (nscore)
            {
                m_players[activePlayer].AddScore(nscore);
                activePlayer = (activePlayer + 1) % 2;
            }
        }
        else
        {
            m_field.Move(m_players[activePlayer].GetDirection(ch));
        }
    }
    GetWinner();
}
