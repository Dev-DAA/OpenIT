#include "playerone.h"


void PlayerOne::SetStatus(Status nstatus) // Устанавливаем статус игрока 1 перед началом игры(Empty) и в конце игры(Winner,Loser,Draw).
{
    m_status = nstatus;
}

Status PlayerOne::GetStatus() // Получаем информацию о статусе игрока 1.
{
    return m_status;
}

void PlayerOne::AddScore(int nscore) // Прибавляем\убавляем счёт игрока 1 в зависимости от цвета открытой ячейки.
{
    m_score +=nscore;
}

int PlayerOne::GetScore() const // Информация о счёте игрока 1.
{
    return m_score;
}

bool PlayerOne::IsLineEmpty() const // Перед каждым ходом проверяем строку на наличие неоткрытых ячеек.
{
    std::ptrdiff_t index = m_gameField->GetPosition();
    unsigned int numLine = index/FIELD_SIZE;
    for(unsigned int i = FIELD_SIZE*numLine; i < FIELD_SIZE*(numLine+1); ++i){
        if(!m_gameField->m_currentPos[i].IsOpened())
            return false;
        }
    return true;
}

void PlayerOne::Move(char ch) // Определеяем границы строки, в которой может перемещаться игрок 1 и в зависимости от клавиш 'a', 'd' шагаем влево\вправо.
{
    unsigned int numLine = m_gameField->GetPosition()/FIELD_SIZE;
    Cell *initialPosition = m_gameField->GetInitialPosition();
    if(ch == 'a' && m_gameField->m_currentPos != initialPosition+numLine*FIELD_SIZE)
    {
        m_gameField->m_currentPos -=1;
    }
    if(ch == 'd' && m_gameField->m_currentPos != initialPosition+numLine*FIELD_SIZE+7)
    {
        m_gameField->m_currentPos +=1;
    }
    //initialPosition = nullptr; нужно ли занулять этот указатель?
}
