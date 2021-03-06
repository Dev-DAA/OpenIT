#include "field.h"

#include <iostream>

Field::Field()
{
    InitField();
}

uint8_t Field::GetIndex(uint8_t x, uint8_t y) // Получаем индекс в массиве на основе переданных координат.
{
    return m_length * y + x;
}
void Field::InitField() // Инициализируем ячейки поля рандомными значениями от +/-1 до +/-11.
                        // Устанавливаем текущие координаты на середину поля.
{
    for (uint8_t i = 0; i < m_length * m_height; ++i)
    {
        uint8_t cellValue               = rand() % 11 + 1;
        uint8_t cellSign                = rand() % 2;
        cellSign == 1 ? m_playground[i] = cellValue : m_playground[i] = -cellValue;
    }
    m_coordinates.x = m_length / 2;
    m_coordinates.y = m_height / 2;
}

thearray Field::GetField() // Возвращаем копию игрового поля для новой игры и внесения изменений в ячейки.
{
    return m_playground;
}

Field::Сoordinates Field::GetPos() // Возвращаем текущее положение курсора.
{
    return m_coordinates;
}

bool Field::IsLineEmpty(Check line) const // Проверяем строку/столбец на наличие неоткрытых ячеек.
{
    if (line == Check::LINE)
    {
        for (uint8_t i = 0; i < m_length; ++i)
        {
            if (m_playground[GetIndex(i,m_coordinates.y)]) return false;
        }
        return true;
    }
    else
    {
        for (uint8_t j = 0; j < m_height; ++j)
        {
            if (m_playground[GetIndex(m_coordinates.x,j)]) return false;
        }
        return true;
    }
}

void Field::Move(Direction direction) // Перемещение по горизонтали/вертикали в зависимости от действующего игрока.
{
        if (direction == Direction::LEFT && m_coordinates.x > 0)
        {
            m_coordinates.x -= 1;
        }
        if (direction == Direction::RIGHT && m_coordinates.x < m_length)
        {
            m_coordinates.x += 1;
        }
        if (direction == Direction::UP && m_coordinates.y > 0)
        {
            m_coordinates.y -= 1;
        }
        if (direction == Direction::DOWN && m_coordinates.y < m_height)
        {
            m_coordinates.y += 1;
        }
}

int8_t Field::Open() // Открытие ячейки, получение её содержимого, выставление статуса "открыта".
{
    int8_t value = m_playground[GetIndex(m_coordinates.x,m_coordiantes.y)];
    m_playground[GetIndex(m_coordinates.x,m_coordiantes.y)] = 0;
    return value;
}