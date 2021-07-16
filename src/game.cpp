#include "game.h"
#include <iostream>

void Game::setWinner() // Присвоение статуса игрокам в конце игры и вывод информации на экран.
{
    if (m_playerone.GetScore() > m_playertwo.GetScore())
    {
        winner = Winner::Player1;
    }
    else if (m_playerone.GetScore() < m_playertwo.GetScore())
    {
        winner = Winner::Player2;
    }
    else
    {
        winner = Winner::Draw;
    }
}
Winner Game::getWinner() const
{
    std::cout << "And the winner is: " << static_cast<int>(winner) << '\n';
    return winner;
}

void Game::NewGame() // Инициализация поля, установка статуса winner в Empty.
{
    m_field.InitField();
    winner = Winner::Empty;
}

void Game::playGame() // Основная логика игры.
{
    bool flag = 0; // Значение flag определяет кто сейчас ходит.
    char ch;
    int16_t nscore = 0;
    while (winner == Winner::Empty)
    {
        if (flag == 0)
        {
            std::cout << "The 1st player's turn!\n";
            if (!m_field.IsLineEmpty(Check::LINE)) // Проверка на неоткрытые ячейки.
            {
                while (std::cin >> ch && flag == 0)
                {
                    if (ch == 'a' || ch == 'd') // Если в ch 'a' или 'd' - движемся в соответсвующих направлениях.
                    {
                        m_playerone.Move(0,ch);
                    }
                    if (ch == 'o') // Если 'o', то проверяем ячейку на статус "открыта", открываем, считываем значение, добавляем в счёт игрока. Помечаем ячейку как "открыта".
                    {
                        currentPos = m_playerone.GetCurrentPos();
                        if (!*currentPos)
                        {
                            nscore = *currentPos;
                            m_playerone.AddScore(nscore);
                            *currentPos = 0;
                            flag = 1; // Если открыли ячейку и получили значение, то ход переходит ко второму игроку.
                        }
                    }
                }
            }
            else // Если все ячейки на линии открыты, то выявляем победителя.
            {
                setWinner();
            }
        }
        else // То же самое для второго игрока с ходом по вертикали.
        {
            std::cout << "The 2nd player's turn!\n";
            if (!m_playertwo.IsLineEmpty(1))
            {
                while (std::cin >> ch && flag == 1)
                {
                    if (ch == 'w' || ch == 's')
                    {
                        m_playertwo.Move(1,ch);
                    }
                    if (ch == 'o')
                    {
                        currentPos = m_playertwo.GetCurrentPos();
                        if (!*currentPos)
                        {
                            nscore = *currentPos;
                            m_playertwo.AddScore(nscore);
                            *currentPos = 0;
                            flag = 0;
                        }
                    }
                }
            }
            else
            {
                setWinner();
            }
        }
    }
    getWinner();
}
