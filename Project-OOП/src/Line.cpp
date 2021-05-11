#pragma once
#include "../Headers/Line.h"
#include <iostream>
#include <fstream>

Line :: Line(){}

Line :: Line(int x_, int y_,char* color_)
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
void Line::print()
{
    std::cout << "The Line that you inputed is at: " << getX() << "," << getY() <<
    "with color:" << getColor() << std::endl;
   
}

void Line::saveToFile(char* fileName)
{
    std::ofstream out(fileName, std::ofstream::app);
    out << "    <line " << "x=\"" << getX() << "\" " << "y=\"" << getY() << "\" " << "fill=\"" << getColor() << "\" />" << std::endl;
    out.close();
}