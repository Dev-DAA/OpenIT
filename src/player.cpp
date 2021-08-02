#include "player.h"

#include <iostream>

Player::Player(OpenIt::Axis ncursor) : m_cursor(ncursor)
{
}

void Player::SetScore()
{
    m_score = 0;
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
