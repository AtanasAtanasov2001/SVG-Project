#pragma once
#include "Shape.h"

struct Line : public Shape
{
    public:
    Line();
    Line(int x_, int y_, char* color_);
    Line& operator=(Line& other);

    void saveToFile(char* fileName);
    void print();
};


