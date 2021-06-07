#pragma once
#include "Shape.h"
#include "Line.h"
class Rectangle : public Shape
{
    private:
    int width;
    int height;
   
    public:
    Rectangle();
    Rectangle(int new_x, int new_y,int width_,int height_);
    Rectangle(int new_x, int new_y,int width_,int height_, char* color_);
    // Rectangle(int new_width,int new_height, const char* color_);

    Rectangle& operator=(const Rectangle& other);

    int getWidth() const;
    int getHeight()const ;
    
    void setWidth(int new_width);
    void setHeight(int new_height);

    double getPerimeter()const;
    double getArea()const;

    bool within(int x_, int y_, int width_, int height_);
    bool within(int x_, int y_, int r_);
    String getType() const;
    void saveToFile(char* fileName);
    void print();
};