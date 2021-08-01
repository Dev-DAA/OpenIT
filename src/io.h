#ifndef IOCLASS_H
#define IOCLASS_H

#include <fcntl.h> // _O_U16TEXT
#include <io.h>    // _setmode, _fileno
#include <iomanip>
#include <iostream>
#include <string>

#include "common.h"
#include "player.h"

#define LT_C L"\x250C" // Left-Top corner
#define RT_C L"\x2510" // Right-Top corner
#define LB_C L"\x2514" // Left-Bottom corner
#define RB_C L"\x2518" // Right-Bottom corner
#define H_L  L"\x2500" // Horizontal
#define V_L  L"\x2502" // Vertical

#define TLT_C L"\x2554" // Thick Left-Top corner
#define TRT_C L"\x2557" // Thick Right-Top corner
#define TLB_C L"\x255A" // Thick Left-Bottom corner
#define TRB_C L"\x255D" // Thick Right-Bottom corner
#define TH_L  L"\x2550" // Thick Horizontal
#define TV_L  L"\x2551" // Thick Vertical

class IO
{
  public:
    IO() = default;
    static OpenIt::Action GetAction(); // Получаем действие для выполнения при нажатии клавиши.

    static void Render(const Field&, const Player*); // Отрисовываем игровое поле.

    ~IO() = default;
};

#endif