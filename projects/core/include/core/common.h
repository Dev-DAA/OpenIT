/**
 * @file Common.h
 * @author Dmitrii Ivanov (idma88@yandex.ru)
 * @author Denis Koinash (den.koinash@gmail.com)
 * @author Aleksandr Kohanyuk (shurik_k73@mail.ru)
 * @brief Определение общих перечислений, псевдонимов и констант
 */
#pragma once

#include <cstdint>

namespace OpenIT {
/**
 * @brief Координаты
 */
struct Position
{
  /// Горизонтальная координата
  int8_t x;
  /// Вертикальная координата
  int8_t y;
};

/**
 * @brief Оператор сравнения позиций
 *
 * @param current Текущая позиция
 * @param other   Позиция для сравнения
 * @return Возвращает true если координаты совпадают, иначе false
 */
bool
operator==(const Position current, const Position other);

/**
 * @brief Уровни сложности
 *
 * Значение уровня соответствует глубине поиска
 *
 * @note Не проводите оптимизации с целью замены значений на 0-based
 */
enum class Difficulty
{
  EASY   = 1, ///< Легкий уровень сложности
  MEDIUM = 2, ///< Средний уровень сложности
  HARD   = 3, ///< Высокий уровень сложности
};

/**
 * @brief Оси, вдоль которых можно передвигать каретку
 */
enum class Axis
{
  X, ///< Горизонтальная ось
  Y, ///< Вертикальная ось
};

/// Псевдоним типа для уникальных идентификаторов
using IdValue = uint64_t;
/// Псевдоним типа для значений ячеек
using CellValue = int8_t;
/// Псевдоним типа для счёта игрока
using ScoreValue = int16_t;

/// Количество игроков
static const uint8_t PLAYER_COUNT = 2;
/// Размер игрового поля
static const uint8_t FIELD_SIZE = 8;
/// Минимальное значение в ячейке
static const CellValue ABS_MIN_VALUE = 1;
/// Максимальное значение в ячейке
static const CellValue ABS_MAX_VALUE = 11;
/// Значение пустой ячейки
static const CellValue EMPTY_CELL = 0;

} // namespace OpenIT