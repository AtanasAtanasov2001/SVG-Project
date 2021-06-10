#include "../Headers/Circle.h"
#include <iostream>
#include <fstream>

Circle::Circle(){}
Circle::Circle(int new_x, int new_y,double r_)
{
    move(new_x, new_y);
    setRadius(r_);
}
Circle::Circle(int new_x, int new_y,double r_, char* color_)
{
    move(new_x, new_y);
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

double Circle :: getRadius() const{return r;}

double Circle :: getPerimeter() const
{
    return 3.14 * (2*r);
}

double Circle :: getArea()const
{
    return 3.14 * (r*r);
}
void Circle ::setRadius(double r_)
{
    r = r_;
}
bool Circle::within(int x_, int y_, int width_, int height_)
{
    return ((this->getX() >= x_ && this->getY() >= y_) && 
            (this->getX() + this->getRadius()) <= x_ + width_ &&
            (this->getX() - this->getRadius()) >= x_ &&
            (this->getY() + this->getRadius()) <= y_ + height_ &&
            (this->getY() - this->getRadius()) >= y_);    
}
bool Circle::within(int x_, int y_,int r_)
{
    Line distance1(x_, y_, this->getX(), this->getY());
    
    return ((distance1.getLength() + this->getRadius()) <= r_);

}

String Circle::getType() const
{
    String type = "Circle";
    return type;
}
void Circle::saveToFile(char* fileName)
{
    std::ofstream out(fileName, std::ofstream::app);
    out << "    <circle " << "x=\"" << getX() << "\" " << "y=\"" << getY() << "\" " << "radius=\"" << getRadius() 
    << "\" "<< "fill=\"" << getColor() << "\" />" << std::endl;
    out.close();
}
void  Circle :: print()
{
    std::cout << "The Circle that you inputed is at: " << getX() << "," << getY() <<
    " with radius: " << getRadius() << ", color: "<< getColor() << ", Perimetre:  "<< getPerimeter() << ", Area: " << getArea()
    << std::endl;
}
