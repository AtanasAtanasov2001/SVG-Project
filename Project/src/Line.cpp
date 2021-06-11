#pragma once
#include "../Headers/Line.h"
#include <iostream>
#include <fstream>
#include <cmath>

Line :: Line(){}

Line::Line(int x1,int y1, int x2,int y2):line_x(x2), line_y(y2)
{
    move(x1,y1);
}
Line :: Line(int x_, int y_,int x1, int y1,char* color_) : line_x(x1), line_y(y1)
{
    move(x_,y_);
    setColor(color_);
}

Line& Line :: operator=(Line& other)
{
     if(this != &other)
    {
        delete this;
        x = other.getX();
        y = other.getY();
        color = other.getColor();
    }
}
void Line::setLineX(int new_line_x){this->line_x = new_line_x;}
void Line::setLineY(int new_line_y){this->line_y = new_line_y;}
int Line::getLineX()const{return this->line_x;}
int Line::getLineY()const{return this->line_y;}

double Line::getLength()const
{
    double sbor = pow((abs(this->x - this->line_x)), 2) + pow((abs(this->y - this->line_y)), 2);
    return sqrt(sbor);
}

double Line::getPerimeter()const {return getLength();}
double Line::getArea()const {return 0;}

bool Line::within(int x_, int y_, int width_, int height_)
{
    return ((this->getX() >= x_ && this->getY() >= y_) && 
            (this->getLineX() >= x_ && this->getLineY() >= y_) &&
            (this->getX() <= x_ + width_  && this->getLineX() <= x_ + width_) &&
            (this->getY() <= y_ + height_ && this->getLineY() <= y_ + height_));    
} 
bool Line::within(int x_, int y_, int r_)
{
    Line distance1(x_, y_, this->getX(), this->getY());
    Line distance2(x_, y_, this->getLineX(), this->getLineY());

    return (distance1.getLength() <= r_ && distance2.getLength() <= r_);
}
String Line::getType() const
{
    String type = "Line";
    return type;
}
void Line::saveToFile(char* fileName)
{
    std::ofstream out(fileName, std::ofstream::app);
    out << "    <line " << "x=\"" << getX() << "\" " << "y=\"" << getY() << "\" " << "x1=\"" << getLineX() << "\" "
     << "y1=\"" << getLineY() << "\" " << "fill=\"" << getColor() << "\" />" << std::endl;
    out.close();
}
void Line::print()
{
    std::cout << "The Line that you inputed is at: " << getX() << "," << getY() << " with length: " << getLength()<<
    " and color: " << getColor() << std::endl;
   
}