#ifndef FIELD_H
#define FIELD_H

#include <array>
#include <memory>

#include "common.h"

#define FIELD_LENGTH 4
#define FIELD_HEIGHT 4

typedef std::array<int8_t, FIELD_LENGTH * FIELD_HEIGHT> thearray;

class Field // Класс Поле, состоящий из FIELD_LENGTH * FIELD_HEIGHT ячеек.
{
  public:
    struct Coordinates
    {
        uint8_t x = 0;
        uint8_t y = 0;
    };

  private:
    const uint8_t m_length = FIELD_LENGTH;
    const uint8_t m_height = FIELD_HEIGHT;
    thearray      m_playground;
    Coordinates   m_coordinates;
    uint8_t       GetIndex(uint8_t x, uint8_t y) const; // Получаем индекс в массиве на основе переданных координат.

  public:
    Field();
    ~Field() = default;

    uint8_t GetIndex(const Coordinates& obj) const; // Получаем индекс на основе переданной структуры.

    void InitField(); // Инициализируем ячейки поля рандомными значениями m_value от -/+1 до -/+11.
                      // Устанавливаем текущую позицию на середину поля.

    thearray GetField() const; // Возвращаем копию игрового поля для отрисовки.

    Coordinates GetCoordinates() const; // Возвращаем координаты курсора в виде структуры.

    bool IsLineEmpty(OpenIt::Axis line) const; // Проверяем строку\столбец на наличие неоткрытых ячеек.

    void Move(OpenIt::Action direction); // Смещение курсора в указанном направлении.

    int8_t Open();
};

#endif