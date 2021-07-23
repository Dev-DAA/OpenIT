#ifndef IO_H
#define IO_H

#include <iostream>

#include "field.h"
#include "common.h"

class IO
{
    public:
        IO() = default;
        static OpenIt::Action GetAction(); // Получаем действие для выполнения при нажатии клавиши.
        
        static void DrawField(const Field &);     // Отрисовываем игровое поле. 

    ~IO() = default;
};

#endif