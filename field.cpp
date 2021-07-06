#include "field.h"

void Field::InitField() // Инициализируем ячейки поля рандомными значениями m_value от 1 до 11 и m_color Red\Green. Устанавливаем текущую позицию m_curretntPos на середину поля.
{
    for(size_t i = 0; i < m_size; ++i){
        size_t cellValue = rand() % 11 + 1;
        size_t cellColor = rand() % 2 + 1;
        cellColor == 1 ? m_playground[i] = Cell(cellValue,Red) : m_playground[i] = Cell(cellValue,Green);
    }
        m_currentPos = m_playground.get() + FIELD_SIZE*FIELD_SIZE/2 + FIELD_SIZE/2; 
}

Cell * Field::GetInitialPosition() // Возвращаем указатель на начало игрового поля.
{
    return m_playground.get();
}

std::ptrdiff_t Field::GetPosition() const // Считаем разницу между текущим положением на поле и его началом. Ипользуется в методе Move() для расчёта границ линии\колонны.
{
    return m_currentPos - m_playground.get();
}