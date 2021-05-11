#include "../Headers/Circle.h"
#include <iostream>
#include <fstream>

Circle::Circle(){}

Circle::Circle(int new_x, int new_y,double r_, char* color_)
{
    setX(new_x);
    setY(new_y);
    setRadius(r_);
    setColor(color_);
}


Circle& Circle :: operator=(Circle& other)
{
    if(this != &other)
    {
        delete this;
        x = other.getX();
        y = other.getY();
        r = other.getRadius();
        color = other.getColor();
    }
    
}

double Circle :: getRadius(){return r;}

double Circle :: getPerimeter()
{
    return 3.14 * (2*r);
}

double Circle :: getArea()
{
    return 3.14 * (r*r);
}
double Circle :: getVolume()
{
    return ((4/3) * 3.14 * (r*r*r));
}
void Circle ::setRadius(double r_)
{
    r = r_;
}
void  Circle :: print()
{
    std::cout << "The Circle that you inputed is at: " << getX() << "," << getY() <<
    " with radius:" << getRadius() << ", color: "<< getColor() << ", Perimetre:  "<< getPerimeter() << ", Area: " << getArea() << "and Volume: " << getVolume() 
    << std::endl;
}

void Circle::saveToFile(char* fileName)
{
    std::ofstream out(fileName, std::ofstream::app);
    out << "    <circle " << "x=\"" << getX() << "\" " << "y=\"" << getY() << "\" " << "radius=\"" << getRadius() 
    << "\" "<< "fill=\"" << getColor() << "\" />" << std::endl;
    out.close();
}