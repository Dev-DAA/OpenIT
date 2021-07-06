#include <memory>
#include <utility>
#include "player.h"

void Player::SetPlayerToField(std::shared_ptr<Field> field) // Предоставляем игроку доступ к полю field; Доступ будут иметь оба игрока через std::shared_ptr;
{
    m_gameField = field;
}

Cell * Player::GetCurrentPos() // Возвращаем указатель на текущую позицию. Используется для открытия ячейки в классе Game.
{
    return m_gameField->m_currentPos;
}  