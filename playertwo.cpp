#include "playertwo.h"

void PlayerTwo::SetStatus(Status nstatus)
{
     m_status = nstatus;
}

Status PlayerTwo::GetStatus()
{
    return m_status;
}
        
void PlayerTwo::AddScore(int nscore)
{
    m_score += nscore;
}

int PlayerTwo::GetScore() const 
{
    return m_score;
}

bool PlayerTwo::IsLineEmpty() const // У игрока 2, перемещающегося по вертикали, идёт проверка колонны на наличие неоткрытых ячеек.
{
    std::ptrdiff_t index = m_gameField->GetPosition();
    unsigned int numColon = index % FIELD_SIZE;
    for(unsigned int i = 0; i < FIELD_SIZE; ++i){
        if(!m_gameField->m_currentPos[FIELD_SIZE*i + numColon].IsOpened())
            return false;
        }
    return true;
}

void PlayerTwo::Move(char ch) // Игрок 2 двигается по вертикали, вирутальный метод Move переписан.
{
    unsigned int numColon = m_gameField->GetPosition() % FIELD_SIZE;
    Cell *initialPosition = m_gameField->GetInitialPosition();
    if(ch == 'w' && m_gameField->m_currentPos != initialPosition + numColon){
        m_gameField->m_currentPos -=1;
    }
    if(ch == 's' && m_gameField->m_currentPos != initialPosition + (FIELD_SIZE-1)* FIELD_SIZE + numColon){
        m_gameField->m_currentPos +=1;
    }
}
