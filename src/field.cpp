#include "field.h"

#include <iostream>

Field::Field()
{
    InitField();
}

uint8_t Field::GetIndex(uint8_t x, uint8_t y) const // Получаем индекс в массиве на основе переданных координат.
{
    return m_length * y + x;
}

uint8_t Field::GetIndex(const Field::Coordinates& obj) const // Получаем индекс на основе переданной структуры.
{
    return m_length * obj.y + obj.x;
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

thearray Field::GetField() const // Возвращаем копию игрового поля для отрисовки.
{
    return m_playground;
}

Field::Coordinates Field::GetCoordinates() const // Возвращаем координаты курсора в виде структуры.
{
    return m_coordinates;
}

bool Field::IsLineEmpty(OpenIt::Axis line) const // Проверяем строку/столбец на наличие неоткрытых ячеек.
{
    if (line == OpenIt::Axis::HORIZONTAL)
    {
        for (uint8_t i = 0; i < m_length; ++i)
        {
            if (m_playground[GetIndex(i, m_coordinates.y)]) return false;
        }
        return true;
    }
    else
    {
        for (uint8_t j = 0; j < m_height; ++j)
        {
            if (m_playground[GetIndex(m_coordinates.x, j)]) return false;
        }
        return true;
    }
}

void Field::Move(OpenIt::Action direction) // Перемещение по горизонтали/вертикали в зависимости от действующего игрока.
{
    if (direction == OpenIt::Action::LEFT && m_coordinates.x > 0)
    {
        m_coordinates.x -= 1;
    }
    if (direction == OpenIt::Action::RIGHT && m_coordinates.x < (m_length - 1))
    {
        m_coordinates.x += 1;
    }
    if (direction == OpenIt::Action::UP && m_coordinates.y > 0)
    {
        m_coordinates.y -= 1;
    }
    if (direction == OpenIt::Action::DOWN && m_coordinates.y < (m_height - 1))
    {
        m_coordinates.y += 1;
    }
}

int8_t Field::Open() // Открытие ячейки, получение её содержимого, выставление статуса "открыта".
{
    uint8_t index = GetIndex(m_coordinates.x, m_coordinates.y);
    int8_t  value = m_playground[index];
    if (value)
    {
        m_playground[index] = 0;
    }
    return value;
}