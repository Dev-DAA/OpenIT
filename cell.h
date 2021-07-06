#include <utility>
#ifndef CELL_H
#define CELL_H

enum Color{Red=1,Green,Grey};

class Cell // Ячейка с полями m_value(значение), m_color(цвет).
{
    private:
        size_t m_value;
        Color m_color;
    public:
        Cell() = default;
        Cell(size_t _v, Color _c);

        std::pair<size_t, Color> GetCell()const; // Формирование "пары" с информацией о текущей ячейке.

        void SetCellValue(); // Установка нулевого значения и серого цвета после открытия ячейки.

        bool IsOpened()const; // Проверка ячейки на состояние открыта(true)\закрыта(false).

        size_t OpenCell(); // Открываем ячейку, запоминаем её значение и устанавливаем состояние "открыта".

    ~Cell(){}
};

#endif