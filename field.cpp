#include "field.h"

#include <iostream>

Field::Field()
{
    for (uint8_t i = 0; i < m_length * m_height; ++i)
    {
        uint8_t cellValue = rand() % 11 + 1;
        uint8_t cellSign  = rand() % 2;
        cellSign == 1 ? m_playground[i] = cellValue : m_playground[i] = -cellValue;
    }
    m_coordinates.x = m_length / 2;
    m_coordinates.y = m_height / 2;
}

void Field::InitField() // Инициализируем ячейки поля рандомными значениями от +/-1 до +/-11.
                        // Устанавливаем текущие координаты на середину поля.
{
    for (uint8_t i = 0; i < m_length * m_height; ++i)
    {
        uint8_t cellValue = rand() % 11 + 1;
        uint8_t cellSign  = rand() % 2;
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
    if (line == Check::HORIZONTAL)
    {
        for (uint8_t i = 0; i < m_length; ++i)
        {
            if (!(m_playground[m_coordinates.y * m_length + i] == 0)) return false;
        }
        return true;
    }
    else
    {
        for (uint8_t j = 0; j < m_height; ++j)
        {
            if (!(m_playground[j * m_length + m_coordinates.x] == 0)) return false;
        }
        return true;
    }
}

void Field::Move(Who who, Direction direction)
{
    if (who == Who::PLAYER1)
    {
        if (direction == Direction::LEFT && m_coordinates.x > 0)
        {
            m_coordinates.x -= 1;
        }
        if (direction == Direction::RIGHT && m_coordinates.x < m_length)
        {
            m_coordinates.x += 1;
        }
    }
    else
    {
        if (direction == Direction::UP && m_coordinates.y > 0)
        {
            m_coordinates.y -= 1;
        }
        if (direction == Direction::DOWN && m_coordinates.y < m_height)
        {
            m_coordinates.y += 1;
        }
    }
}

int8_t Field::Open()
{
    int8_t value = m_playground[m_length * m_coordinates.y + m_coordinates.x];
    m_playground[m_length * m_coordinates.y + m_coordinates.x] = 0;
    return value;
}