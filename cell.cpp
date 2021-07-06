#include "cell.h"

Cell::Cell(size_t _v, Color _c) : m_value(_v), m_color(_c){}

std::pair<size_t, Color> Cell::GetCell()const // Формирование "пары" с информацией о текущей ячейке.
{
    return std::make_pair(m_value,m_color);
}

void Cell::SetCellValue() // Установка нулевого значения и серого цвета после открытия ячейки.
{ 
    m_value = 0;
    m_color = Grey;
}

bool Cell::IsOpened()const // Проверка ячейки на состояние открыта(true)\закрыта(false).
{
    std::pair<size_t, Color> apair = GetCell();
    return apair.first == 0 && apair.second == Grey;
}

size_t Cell::OpenCell() // Открываем ячейку, запоминаем её значение и устанавливаем состояние "открыта".
{
    size_t currentValue;
    std::pair<size_t,Color> apair = GetCell();
    apair.second == Red ? currentValue = - apair.first : apair.first;
    SetCellValue();
    return currentValue;
}