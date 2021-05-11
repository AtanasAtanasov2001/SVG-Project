#pragma once
#include "Shape.h"
#include "Rectangle.h"
#include "Line.h"
#include "Circle.h"
#include "Vector.h"
#include "Menu.h"


class SVG : public Menu
{
    private:
    Vector<Shape*> figures;
    Vector<Shape>* fig;
    Vector<String> commands;

    public:
    SVG(){};

    void addFigure(Shape& figure);
    Shape createFigure () const;
    void saveToFile(char* fileName);
    void loadFromFile(Vector<Shape>* fig,char*fileName);

    Vector<Shape> within(Shape& figure);
    Vector<Shape> erase(int position);
    Vector<Shape> translate(size_t position, int new_x, int new_y);

    void start();
};


