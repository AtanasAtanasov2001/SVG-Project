#pragma once
#include "Shape.h"

class Rectangle : public Shape
{
    private:
    int width;
    int height;
   
    public:
    Rectangle();
    Rectangle(int new_x, int new_y,int width_,int height_, char* color_);
    // Rectangle(int new_width,int new_height, const char* color_);

    Rectangle& operator= (Rectangle& other);
   

    int getWidth();
    int getHeight();
    double getPerimeter();
    double getArea();
   
    void setWidth(int new_width);
    void setHeight(int new_height);

    void print();

    void saveToFile(char* fileName);
};