#pragma once
#include "Shape.h"


class Circle : public Shape
{
    private:
    double r; // radius

    public:
    //BIG 4
    Circle();
    Circle(int new_x, int new_y, double r_);
    Circle(int new_x, int new_y, double r_, char* color_);
    Circle& operator= (Circle& other);

    //methods 
    double getRadius() const;
    double getPerimeter() const;
    double getArea() const;
    void setRadius(double r_);
    bool within(int x_, int y_, int width_, int height_);
    bool within(int x_, int y_, int r_);
    String getType() const;
    void saveToFile(char* fileName);
    void print();

};