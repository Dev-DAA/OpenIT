#include <memory>
#include <utility>
#include <iostream>
#include "player.h"

Player::Player(std::shared_ptr<Field>field){
    m_gameField = field;
}

Player::Player(Player &&obj){
    m_score = obj.m_score;
    m_gameField = obj.m_gameField;
    obj.m_gameField = nullptr;
}

Player& Player::operator=(Player &&obj)
{
    m_score = obj.m_score;
    m_gameField = obj.m_gameField;
    obj.m_gameField = nullptr;
    return *this;
}

/*void Player::SetPlayerToField(std::shared_ptr<Field> field) // Предоставляем игроку доступ к полю field; Доступ будут иметь оба игрока через std::shared_ptr;
{
    m_gameField = field;
}*/

iterator Player::GetCurrentPos() const // Возвращаем указатель на текущую позицию. Используется для открытия ячейки в классе Game.
{
    return m_gameField->m_currentPos;
}

bool Player::IsLineEmpty(bool who) const
{
    citerator cit = m_gameField->GetInitialPosition();
    std::cout << "IsLineEmpty cit position: " << *cit << '\n';
    iterator it = m_gameField->m_currentPos;
    std::cout << "IsLineEmpty it position: " << *it << '\n';
    std::ptrdiff_t result = it - cit;
    std::cout << "IsLineEmpty difference: " << result << '\n';
    std::ptrdiff_t index = m_gameField->GetPosition();
    std::cout << "the fucking index : " << index << '\n';
    if(who == 0)
    {
        
        uint8_t numLine = index/FIELD_SIZE;
        std::cout << "numLine is: " << numLine << '\n';
        for(unsigned int i = FIELD_SIZE*numLine; i < FIELD_SIZE*(numLine+1); ++i){
            if(!(m_gameField->m_currentPos[i] == 0))
            {
                std::cout << "current line is not empty\n";
                return false;
            }
        }
        std::cout << "A current line is empty\n";
        return true;
    }
    else
    {
        unsigned int numColumn = index % FIELD_SIZE;
        std::cout << "numColumnn is: " << numColumn << '\n';
        for(unsigned int i = 0; i < FIELD_SIZE; ++i){
            if(!(m_gameField->m_currentPos[FIELD_SIZE*i + numColumn] == 0))
            {
                std::cout << "current column is not empty\n";
                return false;
            }
        }
        std::cout << "current column is empty\n";
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