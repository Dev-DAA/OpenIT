#ifndef COMMON_H
#define COMMON_H

namespace OpenIt
{
    // Возможные направления движения игрока.
    enum class Direction
    {
        UP,
        DOWN,
        LEFT,
        RIGHT,
        STAY
    };

    // Используется для проверки строки/столбца на неоткрытые ячейки.
    enum class Axis
    {
        HORIZONTAL,
        VERTICAL
    };

    // Присвоение статуса перед началом и в конце игры.
    enum class Winner
    {
        Empty,
        Player1,
        Player2,
        Draw
    };

} // namespace OpenIt
#endif