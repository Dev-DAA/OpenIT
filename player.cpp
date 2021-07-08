#include <memory>
#include <utility>
#include "player.h"

void Player::SetPlayerToField(std::shared_ptr<Field> field) // Предоставляем игроку доступ к полю field; Доступ будут иметь оба игрока через std::shared_ptr;
{
    m_gameField = field;
}

iterator Player::GetCurrentPos() // Возвращаем указатель на текущую позицию. Используется для открытия ячейки в классе Game.
{
    return m_gameField->m_currentPos;
}

bool Player::IsLineEmpty(bool who) const
{
    std::ptrdiff_t index = m_gameField->GetPosition();
    if(who == 0)
    {
        
        uint8_t numLine = index/FIELD_SIZE;
        for(unsigned int i = FIELD_SIZE*numLine; i < FIELD_SIZE*(numLine+1); ++i){
            if((!m_gameField->m_currentPos[i] == 0))
                return false;
            }
        return true;
    }
    else
    {
        unsigned int numColon = index % FIELD_SIZE;
        for(unsigned int i = 0; i < FIELD_SIZE; ++i){
            if(!(m_gameField->m_currentPos[FIELD_SIZE*i + numColon] == 0))
                return false;
        }
        return true;
    }
}

void Player::AddScore(int8_t nscore)
{
    m_score +=nscore;
}

int16_t Player::GetScore() const
{
    return m_score;
}
void Player::Move(bool who, char ch){
    citerator initialPosition = m_gameField->GetInitialPosition();
    if(who == 0)
    {
        uint8_t numLine = m_gameField->GetPosition()/FIELD_SIZE;
        if(ch == 'a' && m_gameField->m_currentPos != initialPosition+numLine*FIELD_SIZE)
        {
            m_gameField->m_currentPos -=1;
        }
        if(ch == 'd' && m_gameField->m_currentPos != initialPosition+numLine*FIELD_SIZE+7)
        {
            m_gameField->m_currentPos +=1;
        }
    }
    else
    {
        uint8_t numColon = m_gameField->GetPosition() % FIELD_SIZE;
        if(ch == 'w' && m_gameField->m_currentPos != initialPosition + numColon)
        {
            m_gameField->m_currentPos -=1;
        }
        if(ch == 's' && m_gameField->m_currentPos != initialPosition + (FIELD_SIZE-1)* FIELD_SIZE + numColon)
        {
            m_gameField->m_currentPos +=1;
        }
    }
}  