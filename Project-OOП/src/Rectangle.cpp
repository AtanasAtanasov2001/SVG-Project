
#include "../Headers/Rectangle.h"
#include <iostream>
#include <fstream>

//default constructor
Rectangle::Rectangle(){}

//constructor
Rectangle::Rectangle(int new_x, int new_y,int new_width,int new_height, char* color_)
{
    setX(new_x);
    setY(new_y);
    setWidth(new_width);
    setHeight(new_height);
    setColor(color_);
}

// Rectangle::Rectangle(int new_width,int new_height, const char* color_)
// {
//     move(getX(), getY());
//     setWidth(new_width);
//     setHeight(new_height);
//     setColor(color_);
// }

//operator =
Rectangle& Rectangle :: operator=(Rectangle& other)
{
     if(this != &other)
    {
        delete this;
        x = other.getX();
        y = other.getY();
        width = other.getWidth();
        height = other.getHeight();
        color = other.getColor();
    }
}
//setters and getters

int Rectangle::getWidth(){return width;}
int Rectangle::getHeight(){return height;}
void Rectangle::setWidth(int new_width) {width = new_width;}
void Rectangle::setHeight(int new_height) {height = new_height;}

double Rectangle :: getPerimeter()
{
    return ((2 * width) + (2 * height));
}
double Rectangle ::  getArea()
{
    return (width * height);
}
//print
void Rectangle::print()
{
    std::cout << "The rectangle that you inputed is at: " << getX() << "," << getY() <<
    " with width: " << getWidth() << ", height: " << getHeight() <<", color: " << getColor() << std::endl;
    std::cout << "It's  perimetre is : " << getPerimeter() << " and area: " << getArea() << std::endl;
}

void Rectangle::saveToFile(char* fileName)
{
    std::ofstream out (fileName, std::ofstream::app);
    out << "    <rectangle " << "x=\"" << getX() << "\" " << "y=\"" << getY() << "\" " << "width=\"" << getWidth() 
    << "\" "<< "heigth=\"" << getHeight() << "\" "<< "fill=\"" << getColor() << "\" />" << std::endl;
    out.close();
}