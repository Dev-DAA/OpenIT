#include "../googletest/googletest/include/gtest/gtest.h"
#include "../src/field.h"

// Объявляем экземлпяр класса Field.
class FieldTest : public ::testing::Test
{
  protected:
    Field field;
};

// Проверяем ячейки поля на ненулевое значение после инициализации.
TEST_F(FieldTest, IsEqualToZero)
{
    thearray temparr = field.GetField();
    for (uint8_t i = 0; i < FIELD_LENGTH * FIELD_HEIGHT; ++i)
        EXPECT_NE(temparr[i], 0);
}

// Проверяем корректное расположение координаты в начале игры.
// Она должна быть по центру.
TEST_F(FieldTest, IsCoordinateCentered)
{
    EXPECT_EQ(field.GetIndex(field.GetCoordinates()), FIELD_LENGTH * FIELD_LENGTH / 2 + FIELD_HEIGHT / 2);
}

// Проверяем возможность ходов влево\вправо, вверх\вниз с выходом за пределы поля.
// Данный тест провeряет поле начиная с середины и до верхнего левого угла.
/*
    Например, имеем игровое поле 5х5 с координатой в центре (2:2) (индекс 12).
    0 1 2 3 4
  0 # # # # #
  1 # # # # #
  2 # # o # #
  3 # # # # #
  4 # # # # #

  Наша задача проверить возможность хода по горизонтали в обоих направлениях.
  Затем делаем то же самое для вертикального направления.

Начинаем движение вправо, на каждом шаге проверяя был ли сделан ход и равенство ожидаемого индекса текущему.
    0 1 2 3 4
  0 # # # # #
  1 # # # # #
  2 # # # o #
  3 # # # # #
  4 # # # # #
  Как видим, ход вправо возможен и расчётный индекс 13 должен соответствовать полученному из метода GetIndex();

    0 1 2 3 4
  0 # # # # #
  1 # # # # #
  2 # # # # o
  3 # # # # #
  4 # # # # #

  14 == 14.
  Делаем ещё один шаг вправо.
    0 1 2 3 4
  0 # # # # #
  1 # # # # #
  2 # # # # # o
  3 # # # # #
  4 # # # # #

  Поскольку изменяется координата х, то индекс равен 15.
  Проверяем, что курсор не сдвинулся в след за индексом. 14 != 15;

  Возвращаем индекс на предыдущее положение и начинаем движение влево,
  проверяя его возможность и сравнивая расчётный индекс полученному из метода GetIndex();
    0 1 2 3 4
  0 # # # # #
  1 # # # # #
  2 # # # o #
  3 # # # # #
  4 # # # # #

    0 1 2 3 4
  0 # # # # #
  1 # # # # #
  2 # # o # #
  3 # # # # #
  4 # # # # #

И так далее до конца пределов поля. Затем также проверяем на невозможность выхода за пределы.

      0 1 2 3 4
  0   # # # # #
  1   # # # # #
  2 o # # # # #
  3   # # # # #
  4   # # # # #

Возвращаем индекс на середину и повторяем те жа шаги только для направления вниз и вверх.
Таким образом, в результате теста мы проверили строку+столбец.
    0 1 2 3 4
  0 # # + # #
  1 # # + # #
  2 + + + + +
  3 # # + # #
  4 # # + # #

Далее смещаем центр по диагонали вверх влево и проверяем строку+столбец.

    0 1 2 3 4
  0 # # + # #
  1 # o + # #
  2 + + + + +
  3 # # + # #
  4 # # + # #
В результате проверки получим следующий результат:
    0 1 2 3 4
  0 # + + # #
  1 + + + + +
  2 + + + + +
  3 # + + # #
  4 # + + # #
Смещаем центр ещё раз влево вверх.
    0 1 2 3 4
  0 o + + # #
  1 + + + + +
  2 + + + + +
  3 # + + # #
  4 # + + # #
И проверяем последнюю строку+столбец. В результате:

    0 1 2 3 4
  0 + + + + +
  1 + + + + +
  2 + + + + +
  3 + + + # #
  4 + + + # #
Строки 3 и 4 проверены частично и только по вертикали. Столбцы 3 и 4 проверены частично только по горизонтали.
Поэтому их необходимо проверить по горизонтали\вертикали соответственно.
    0 1 2 3 4
  0 + + + ? ?
  1 + + + ? ?
  2 + + + ? ?
  3 ? ? ? # #
  4 ? ? ? # #
*/
TEST_F(FieldTest, MoveWithBiasToUpperLeftCorner)
{
    uint8_t expectedIndex = 0; // Ожидаемый индекс, получаемый из метода GetIndex();
    int8_t counter = 0; // Счётчик, используемый для расчёта индекса для сравнения.
    bool           moved = 0;                   // Был ход или нет.
    OpenIt::Action dir = OpenIt::Action::RIGHT; // Начальное направление движения - вправо.
    uint8_t        length    = FIELD_LENGTH;
    int8_t         iterative = length / 2; // Используется для расчёта центр. положения и как счётчик смещения влево вверх.
    while (true)
    {
        uint8_t central = length * iterative + iterative; // Рассчитываем центральное положение курсора.
        while (true)
        {
            moved = field.Move(dir); // Движемся в указанном направлении.
            dir == OpenIt::Action::RIGHT ? counter += 1 : counter -= 1; // + или - счётчик в зависимости от направл.
            expectedIndex = field.GetIndex(field.GetCoordinates()); // Получаем ожидаемый индекс.
            if (moved)
            {
                EXPECT_EQ(central + counter, expectedIndex); // Если ход сделан, проверяем равенство.
                if (dir == OpenIt::Action::RIGHT && counter == 0) // Если проверили всю строку - движемся вниз.
                {
                    dir = OpenIt::Action::DOWN;
                    break;
                }
            }
            else
            {
                if (dir == OpenIt::Action::RIGHT) // Если хода не было и направление "вправо", то...
                {
                    ASSERT_NE(central + counter, expectedIndex); // Проверяем невыход за пределы
                    EXPECT_EQ(central + counter - 1, expectedIndex); // Проверяем, expectedIndex остался в рамках поля.
                    counter -= 1;               // Возвращаем счётчик в рамки поля.
                    dir = OpenIt::Action::LEFT; // Меняем направление на "влево"
                }
                else
                {
                    ASSERT_NE(central + counter, expectedIndex);
                    EXPECT_EQ(central + counter + 1, expectedIndex);
                    counter += 1;
                    dir = OpenIt::Action::RIGHT; // Идём вправо до центральной координаты.
                    if (counter == 0) // Если проверена самая верхняя строка, движемся вниз по самому левому стобцу.
                    {
                        dir = OpenIt::Action::DOWN;
                        break;
                    }
                }
            }
        }
        while (true) // Тот же алгоритм для проверки столбца.
        {
            moved = field.Move(dir);
            dir == OpenIt::Action::DOWN ? counter += 1 : counter -= 1;
            expectedIndex = field.GetIndex(field.GetCoordinates());
            if (moved)
            {
                EXPECT_EQ(central + counter * length, expectedIndex);
                if (dir == OpenIt::Action::DOWN && counter == 0)
                {
                    dir = OpenIt::Action::RIGHT;
                    break;
                }
            }
            else
            {
                if (dir == OpenIt::Action::DOWN)
                {
                    ASSERT_NE(central + counter * length, expectedIndex);
                    EXPECT_EQ(central + (counter - 1) * length, expectedIndex);
                    counter -= 1;
                    dir = OpenIt::Action::UP;
                }
                else
                {
                    ASSERT_NE(central + counter * length, expectedIndex);
                    EXPECT_EQ(central + (counter + 1) * length, expectedIndex);
                    counter += 1;
                    dir = OpenIt::Action::DOWN;
                    if (counter == 0)
                    {
                        break;
                    }
                }
            }
        }
        iterative -= 1; // Как только строка+столбец проверены, двигаемся по диагонали вверх влево.
        if (iterative >= 0)
        {
            field.Move(OpenIt::Action::LEFT);
            field.Move(OpenIt::Action::UP);
        }
        else
        {
            break;
        }
    }
}
// Тестирование строк и столбцов со смещением в нижнюю правую часть поля (См. пояснение к предыдущему тесту).
TEST_F(FieldTest, MoveWithBiasToLowerRightCorner)
{
    uint8_t        expectedIndex = 0;
    bool           moved         = 0;
    int8_t         counter       = 0;
    uint8_t        length        = FIELD_LENGTH;
    uint8_t        iterative     = length / 2;
    uint8_t        central       = 0;
    OpenIt::Action dir           = OpenIt::Action::RIGHT;

    while (true)
    {
        central = length * iterative + iterative;
        while (true)
        {
            moved         = field.Move(dir);
            expectedIndex = field.GetIndex(field.GetCoordinates());
            dir == OpenIt::Action::RIGHT ? counter += 1 : counter -= 1;
            if (moved)
            {
                EXPECT_EQ(central + counter, expectedIndex);
                if (dir == OpenIt::Action::RIGHT && counter == 0)
                {
                    dir = OpenIt::Action::DOWN;
                    break;
                }
            }
            else
            {
                if (dir == OpenIt::Action::RIGHT)
                {
                    ASSERT_NE(central + counter, expectedIndex);
                    EXPECT_EQ(central + counter - 1, expectedIndex);
                    counter -= 1;
                    dir = OpenIt::Action::LEFT;
                    if (counter == 0)
                    {
                        dir = OpenIt::Action::UP;
                        break;
                    }
                }
                else
                {
                    ASSERT_NE(central + counter, expectedIndex);
                    EXPECT_EQ(central + counter + 1, expectedIndex);
                    counter += 1;
                    dir = OpenIt::Action::RIGHT;
                }
            }
        }
        while (true)
        {
            moved         = field.Move(dir);
            expectedIndex = field.GetIndex(field.GetCoordinates());
            dir == OpenIt::Action::DOWN ? counter += 1 : counter -= 1;
            if (moved)
            {
                EXPECT_EQ(central + length * counter, expectedIndex);
                if (dir == OpenIt::Action::DOWN && counter == 0)
                {
                    dir = OpenIt::Action::RIGHT;
                    break;
                }
            }
            else
            {
                if (dir == OpenIt::Action::DOWN)
                {
                    ASSERT_NE(central + length * counter, expectedIndex);
                    EXPECT_EQ(central + length * (counter - 1), expectedIndex);
                    counter -= 1;
                    dir = OpenIt::Action::UP;
                    if (counter == 0)
                    {
                        break;
                    }
                }
                else
                {
                    ASSERT_NE(central + length * counter, expectedIndex);
                    EXPECT_EQ(central + length * (counter + 1), expectedIndex);
                    counter += 1;
                    dir = OpenIt::Action::DOWN;
                }
            }
        }
        iterative += 1;
        if (iterative < length)
        {
            field.Move(OpenIt::Action::RIGHT);
            field.Move(OpenIt::Action::DOWN);
        }
        else
        {
            break;
        }
    }
}

// Тест на открытие ячейки, корректность полученного значения и проверка пустой строки\столбца.
TEST_F(FieldTest, OpenCellAndLineEmptyness)
{
    const uint8_t  length    = FIELD_LENGTH;
    const uint8_t  height    = FIELD_HEIGHT;
    OpenIt::Action dir       = OpenIt::Action::RIGHT;
    bool           moved     = 0;
    int8_t         cellValue = 0;
    OpenIt::Axis   axis      = OpenIt::Axis::HORIZONTAL;
    // uint8_t expectedIndex = 0;

    while (true)
    {
        cellValue = field.Open(); // Открываем текущую ячейку.
        // expectedIndex = field.GetIndex(field.GetCoordinates());
        // EXPECT_EQ(36,expectedIndex);
        if (cellValue) // Если значение отличное от нуля получено, то..
        {
            ASSERT_NE(cellValue, 0);
            EXPECT_GE(cellValue, -11);
            EXPECT_LE(cellValue, 11); // Проверяем не неравенство нулю и на [-11 >= cellValue <= 11].
        }
        else
        {
            ASSERT_EQ(cellValue, 0); // Если ячейка уже была открыта до этого, проверяем на нуль.
            if (field.IsLineEmpty(axis))
            {
                if (axis == OpenIt::Axis::HORIZONTAL)
                {
                    axis = OpenIt::Axis::VERTICAL;
                    dir =
                        OpenIt::Action::DOWN; // Если все ячейки в строке открыты, задаём вертикальное направление вниз.
                }
                else
                {
                    break; // Если все ячейки в столбце открыты, то завершаем проверку.
                }
            }
        }

        moved = field.Move(dir); // Делаем ход.

        if (!moved) // Меняем направление при достижении границ поля.
        {
            if (dir == OpenIt::Action::RIGHT)
            {
                dir = OpenIt::Action::LEFT;
            }
            else if (dir == OpenIt::Action::LEFT)
            {
                dir = OpenIt::Action::RIGHT;
            }
            else if (dir == OpenIt::Action::DOWN)
            {
                dir = OpenIt::Action::UP;
            }
            else
            {
                dir = OpenIt::Action::DOWN;
            }
        }
    }
}
