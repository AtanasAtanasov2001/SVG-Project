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
    int getX();
    int getY();
    char* getColor();


    void setX(int new_x);
    void setY(int new_y);
    void setColor(char* color_);
    void setColor(const char* color_);
    

    void move(int new_x,int new_y);// moves the default shape - coord 0,0 to the actual place
    void translate(int trans_x,int trans_y);// it's the translation of the newly created figure
    
    virtual void saveToFile(char* fileName){};
};