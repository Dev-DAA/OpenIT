#include "player.h"

#include <iostream>

Player::Player(OpenIt::Axis ncursor) : m_cursor(ncursor)
{
}

int16_t Player::GetScore() const
{
    return m_score;
}

void Player::AddScore(int16_t nscore)
{
    m_score += nscore;
}

OpenIt::Axis Player::GrantedDirection() const
{
    return m_cursor;
}

/*OpenIt::Direction Player::GetDirection(char ch) const // Получаем направление движения курсора при нажатии клавиши.
{
    OpenIt::Direction dir;
    OpenIt::Axis      gdir = GrantedDirection();
    if (gdir == OpenIt::Axis::HORIZONTAL)
    {
        ch == 'a'   ? dir   = OpenIt::Direction::LEFT // ВЫ ХОТИТЕ СКАЗАТЬ, ЧТО ЭТО БОЛЕЕ ЧИТАБЕЛЬНО? :)
        : ch == 'd' ? dir = OpenIt::Direction::RIGHT
                    : dir = OpenIt::Direction::STAY;
    }
    else
    {
        ch == 'w'   ? dir   = OpenIt::Direction::UP
        : ch == 's' ? dir = OpenIt::Direction::DOWN
                    : dir = OpenIt::Direction::STAY;
    }
    return dir;
}*/
