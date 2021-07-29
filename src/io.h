#ifndef IO_H
#define IO_H

#include <iostream>
#include <fcntl.h> // _O_U16TEXT
#include <io.h>    // _setmode, _fileno
#include <string>
#include <iomanip>

#include "player.h"
#include "common.h"
#include "../cppconlib/include/conmanip.h"

#define LT  L"\x250C" // Left-Top corner
#define RT  L"\x2510" // Right-Top corner
#define LB  L"\x2514" // Left-Bottom corner
#define RB  L"\x2518" // Right-Bottom corner
#define H   L"\x2500" // Horizontal
#define V   L"\x2502" // Vertical

#define TLT L"\x2554" // Thick Left-Top corner
#define TRT L"\x2557" // Thick Right-Top corner
#define TLB L"\x255A" // Thick Left-Bottom corner
#define TRB L"\x255D" // Thick Right-Bottom corner
#define TH  L"\x2550" // Thick Horizontal
#define TV  L"\x2551" // Thick Vertical


class IO
{
    public:
        IO() = default;
        static OpenIt::Action GetAction(); // Получаем действие для выполнения при нажатии клавиши.
        
        static void Render(const Field &, const Player *);     // Отрисовываем игровое поле. 

    ~IO() = default;
};

#endif