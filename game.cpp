#include "game.h"
#include <iostream>
std::ostream & Game::getWinner(std::ostream &os) // Присвоение статуса игрокам в конце игры и вывод информации на экран.
{
    if (m_playerone->GetScore() > m_playertwo->GetScore())
    {
        m_playerone->SetStatus(Winner);
        m_playertwo->SetStatus(Loser);
    }
    else if (m_playerone->GetScore() < m_playertwo->GetScore())
    {
        m_playerone->SetStatus(Loser);
        m_playertwo->SetStatus(Winner);
    }
    else
    {
        m_playerone->SetStatus(Draw);
        m_playertwo->SetStatus(Draw);
    }
    os << "Player1: " << m_playerone->GetStatus() << " Player2: " << m_playertwo->GetStatus();
    return os;
}

void Game::startGame() // Инициалиция поля, предоставление доступа к нему игрокам и установка статуса обоих в Empty.
{
    m_mainField = std::shared_ptr<Field>();
    m_mainField->InitField();
    m_playerone->SetPlayerToField(m_mainField);
    m_playertwo->SetPlayerToField(m_mainField);
    m_playerone->SetStatus(Empty);
    m_playertwo->SetStatus(Empty);
}

void Game::playGame() // Основная логика игры.
{
    startGame();
    bool flag = 0; // Значение flag определяет кто сейчас ходит.
    Cell *currentPos = nullptr;
    char ch;
    size_t nscore = 0;
    while (m_playerone->GetStatus() == Empty && m_playertwo->GetStatus() == Empty)
    {
        if (flag == 0)
        {
            if (!m_playerone->IsLineEmpty()) // Проверка на неоткрытые ячейки.
            {
                while (std::cin >> ch && flag == 0)
                {
                    if (ch == 'a' || ch == 'd') // Если в ch 'a' или 'd' - движемся в соответсвующих направлениях.
                    {
                        m_playerone->Move(ch);
                    }
                    if (ch == 'o') // Если 'o', то проверяем ячейку на статус "открыта", открываем, считываем значение, добавляем в счёт игрока. Помечаем ячейку как "открыта".
                    {
                        currentPos = m_playerone->GetCurrentPos();
                        if (!currentPos->IsOpened())
                        {
                            nscore = currentPos->OpenCell();
                            m_playerone->AddScore(nscore);
                            currentPos->SetCellValue();
                            flag = 1; // Если открыли ячейку и получили значение, то ход переходит ко второму игроку.
                        }
                    }
                }
            }
            else // Если все ячейки на линии открыты, то выявляем победителя.
            {
                getWinner(std::cout);
            }
        }
        else // То же самое для второго игрока с ходом по вертикали.
        {
            if (!m_playertwo->IsLineEmpty())
            {
                while (std::cin >> ch && flag == 1)
                {
                    if (ch == 'w' || ch == 's')
                    {
                        m_playertwo->Move(ch);
                    }
                    if (ch == 'o')
                    {
                        currentPos = m_playertwo->GetCurrentPos();
                        if (!currentPos->IsOpened())
                        {
                            nscore = currentPos->OpenCell();
                            m_playertwo->AddScore(nscore);
                            currentPos->SetCellValue();
                            flag = 0;
                        }
                    }
                }
            }
            else
            {
                getWinner(std::cout);
            }
        }
    }
}