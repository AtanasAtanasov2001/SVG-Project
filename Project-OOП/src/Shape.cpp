
#include <iostream>
#include "../Headers/Shape.h"
#include <cstring>

Shape::Shape(){}
//constructor
Shape::Shape(int x_, int y_)
{
    move(x_,y_);
}

//getters and setters

int Shape::getX() {return x ;}
int Shape::getY() {return y ;}

char* Shape::getColor()
{
    return color;
}

void Shape::setX(int new_x) {x = new_x;}
void Shape::setY(int new_y) {y = new_y;}

void Shape::setColor(char* color_)
{
    color = color_;
}
void Shape::setColor(const char* color_)
{
    strcpy(color,color_);
}

//the default figure goes to the given coordinates
void Shape::move(int new_x,int new_y)
{
    setX(new_x);
    setY(new_y);
}

//the translation
void Shape::translate(int trans_x,int trans_y)
{
    move(getX() + trans_x, getY() + trans_y);
}


