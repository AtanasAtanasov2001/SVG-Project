#pragma once
#include "Shape.h"

class Circle : public Shape
{
    private:
    double r; // radius

    public:
    //BIG 4
    Circle();
    Circle(int new_x, int new_y,double r_, char* color_);
    Circle& operator= (Circle& other);

    //methods 
    double getRadius();
    double getPerimeter();
    double getArea();
    double getVolume();
    void setRadius(double r_);

    void saveToFile(char* fileName);
    void print();

};