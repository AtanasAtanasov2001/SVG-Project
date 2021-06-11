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
    Vector<Shape*> figures;//the vector that holds all the figures.
    Vector<String> commands;
    char* filename;

    public:
    SVG();
    ~SVG();
    void addFigure(Shape* figure);
    Shape* createFigure ();
    void saveToFile();
    void loadFromFile();
    void print();

    Vector<Shape*> within(Rectangle& newShape);
    Vector<Shape*> within(Circle& newShape);
    void translate();
    
    void start();
};


