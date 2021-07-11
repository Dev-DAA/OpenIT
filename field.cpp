#include <iostream>
#include "field.h"

Field::Field()
{
    for(unsigned int i = 0; i < m_size; ++i)
    {
        unsigned int cellValue = rand() % 11 + 1;
        unsigned int cellSign = rand() % 2;
        cellSign == 1 ? m_playground[i] = cellValue : m_playground[i] = -cellValue;
        std::cout << i <<" "<< m_playground[i] << "\n";
    }
    std::cout << "playground size: " << m_playground.size() << '\n';
    m_currentPos = m_playground.begin();
    std::cout << "before placement: " << *m_currentPos << '\n';
    m_currentPos += FIELD_SIZE*FIELD_SIZE/2 + FIELD_SIZE/2;
    std::cout <<"after placement: "<< *m_currentPos << '\n';
}

Field::Field(const Field &obj)
{
    std::cout << "a copy constructor was used\n";
    m_playground = obj.m_playground;
    m_currentPos = obj.m_currentPos;
}

Field & Field::operator=(const Field &obj)
{
    m_playground = obj.m_playground;
    m_currentPos = obj.m_currentPos;
    return *this;    
}

/*void Field::InitField() // Инициализируем ячейки поля рандомными значениями m_value от 1 до 11 и m_color Red\Green. Устанавливаем текущую позицию m_curretntPos на середину поля.
{
    for(uint8_t i = 0; i < m_size; ++i){
        uint8_t cellValue = rand() % 11 + 1;
        uint8_t cellSign = rand() % 2;
        cellSign == 1 ? m_playground[i] = cellValue : m_playground[i] = -cellValue;
    }
        m_currentPos = m_playground.begin() + FIELD_SIZE*FIELD_SIZE/2 + FIELD_SIZE/2; 
}*/

citerator Field::GetInitialPosition()const // Возвращаем итератор на начало игрового поля.
{
    return m_playground.cbegin();
}

std::ptrdiff_t Field::GetPosition() // Считаем разницу между текущим положением на поле и его началом. Ипользуется в методе Move() для расчёта границ линии\колонны.
{
    std::ptrdiff_t result = m_currentPos - GetInitialPosition();
    return result;
}