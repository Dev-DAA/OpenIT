#include <memory>
#include <utility>
#include <iostream>
#include "player.h"

Player::Player(MoveCursor mcursor) : m_cursor(mcursor){}

int16_t Player::GetScore() const
{
    return m_score;
}

void Player::AddScore(int16_t nscore)
{
    m_score += nscore;
}

MoveCursor Player::GrantedDirection(Who who) const
{
    who == PLAYER1 ? return HORIZONTALLY : return VERTICALLY;
}

  