#include "field.h"

void Field::InitField() // Инициализируем ячейки поля рандомными значениями m_value от 1 до 11 и m_color Red\Green. Устанавливаем текущую позицию m_curretntPos на середину поля.
{
    for(uint8_t i = 0; i < m_size; ++i){
        uint8_t cellValue = rand() % 11 + 1;
        uint8_t cellSign = rand() % 2;
        cellSign == 1 ? m_playground[i] = cellValue : m_playground[i] = -cellValue;
    }
        m_currentPos = m_playground.begin() + FIELD_SIZE*FIELD_SIZE/2 + FIELD_SIZE/2; 
}

citerator Field::GetInitialPosition() const // Возвращаем указатель на начало игрового поля.
{
    return m_playground.cbegin();
}

std::ptrdiff_t Field::GetPosition() const // Считаем разницу между текущим положением на поле и его началом. Ипользуется в методе Move() для расчёта границ линии\колонны.
{
    return m_currentPos - m_playground.cbegin();
}