#include <memory>
#include <array>
#ifndef FIELD_H
#define FIELD_H

#define FIELD_SIZE 2
typedef std::array<int,FIELD_SIZE*FIELD_SIZE>::iterator iterator;
typedef std::array<int,FIELD_SIZE*FIELD_SIZE>::const_iterator citerator;

class Field // Класс Поле, состоящий из FIELD_SIZE * FIELD_SIZE ячеек.
{
    private:
        const uint8_t m_size = FIELD_SIZE*FIELD_SIZE;
        std::array<int, FIELD_SIZE*FIELD_SIZE> m_playground;
    public:
        iterator m_currentPos;

    public:
        Field();
        Field(const Field &);
        Field& operator=(const Field &obj);

        void InitField(); // Инициализируем ячейки поля рандомными значениями m_value от 1 до 11 и m_color Red\Green. Устанавливаем текущую позицию m_curretntPos на середину поля.

        citerator GetInitialPosition()const; // Возвращаем указатель на начало игрового поля.

        std::ptrdiff_t GetPosition(); // Считаем разницу между текущим положением на поле и его началом. Ипользуется в методе Move() для расчёта границ линии\колонны.

        ~Field(){}
};

#endif