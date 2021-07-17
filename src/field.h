#ifndef FIELD_H
#define FIELD_H

#include <array>
#include <memory>

#define FIELD_LENGTH 8
#define FIELD_HEIGHT 8

typedef std::array<int8_t, FIELD_LENGTH * FIELD_HEIGHT> thearray;

enum class Direction
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    STAY
};
enum class Check
{
    LINE,
    COLUMN
};

class Field // Класс Поле, состоящий из FIELD_LENGTH * FIELD_HEIGHT ячеек.
{
  private:
    const uint8_t m_length = FIELD_LENGTH;
    const uint8_t m_height = FIELD_HEIGHT;
    thearray      m_playground;
    struct Coordinates
    {
        uint8_t x = 0;
        uint8_t y = 0;
    };


  public:
    Coordinates m_coordinates;

    Field();
    ~Field() = default;

    uint8_t GetIndex(uint8_t x, uint8_t y) const; // Получаем индекс в массиве на основе переданных координат.

    void InitField(); // Инициализируем ячейки поля рандомными значениями m_value от -/+1 до -/+11.
                      // Устанавливаем текущую позицию на середину поля.

    thearray GetField(); // Возвращаем копию игрового поля для новой игры и внесения изменений в ячейки.

    uint8_t GetPosX()const; // Возвращаем координату х.
    uint8_t GetPosY()const; // Возвращаем координату у.

    bool IsLineEmpty(Check line) const; // Проверяем строку\столбец на наличие неоткрытых ячеек.

    void Move(Direction direction); // Смещение курсора в указанном направлении.

    int16_t Open();
};

#endif