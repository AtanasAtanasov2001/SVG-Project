#pragma once
#include "String.h"
#include "../src/String.cpp"


struct Shape
{
    int x; // indicates RIGHT
    int y; //indicates DOWN
    char* color;

    Shape();
    Shape(int x_,int y_);
    int getX()const ;
    int getY() const ;
    char* getColor()const ;


    void setX(int new_x);
    void setY(int new_y);
    void setColor(char* color_);
    void setColor(const char* color_);
    
    virtual double getPerimeter()const  = 0;
    virtual double getArea()const = 0;

    void move(int new_x,int new_y);// moves the default shape - coord 0,0 to the actual place
    void translate(int trans_x,int trans_y);// it's the translation of the newly created figure
    
    virtual bool within(int x_, int y_, int width_, int height_) = 0;
    virtual bool within(int x_, int y_, int r_) = 0;
    virtual String getType() const = 0;
    virtual void saveToFile(char* fileName) = 0;
    virtual void print() = 0;

};