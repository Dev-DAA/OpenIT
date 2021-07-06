#include <memory>
#include "cell.h"
#ifndef FIELD_H
#define FIELD_H

#define FIELD_SIZE 8

class Field // Класс Поле, состоящий из FIELD_SIZE * FIELD_SIZE ячеек.
{
    private:
        const size_t m_size = FIELD_SIZE*FIELD_SIZE;
        std::unique_ptr<Cell[]> m_playground = std::unique_ptr<Cell[]>(new Cell[m_size]);
    public:
        Cell *m_currentPos;

    public:
        Field() = default;

        void InitField(); // Инициализируем ячейки поля рандомными значениями m_value от 1 до 11 и m_color Red\Green. Устанавливаем текущую позицию m_curretntPos на середину поля.

        Cell * GetInitialPosition(); // Возвращаем указатель на начало игрового поля.

        std::ptrdiff_t GetPosition() const; // Считаем разницу между текущим положением на поле и его началом. Ипользуется в методе Move() для расчёта границ линии\колонны.

        ~Field(){}
};

#endif