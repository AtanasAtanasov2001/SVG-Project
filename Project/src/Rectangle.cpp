#include "../Headers/Rectangle.h"
#include <iostream>
#include <fstream>

//default constructor
Rectangle::Rectangle(){}
Rectangle::Rectangle(int new_x, int new_y,int new_width,int new_height)
{
     move(new_x, new_y);
    setWidth(new_width);
    setHeight(new_height);
}
//constructor
Rectangle::Rectangle(int new_x, int new_y,int new_width,int new_height, char* color_)
{
    move(new_x, new_y);
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
Rectangle& Rectangle::operator=(const Rectangle& other)
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
    return *this;
}
//setters and getters

int Rectangle::getWidth()const {return width;}
int Rectangle::getHeight()const {return height;}
void Rectangle::setWidth(int new_width) {width = new_width;}
void Rectangle::setHeight(int new_height) {height = new_height;}

double Rectangle :: getPerimeter() const
{
    return ((2 * width) + (2 * height));
}
double Rectangle ::  getArea() const
{
    return (width * height);
}

bool Rectangle::within(int x_, int y_, int width_, int height_)
{
    return(this->getX() >= x_ && this->getY() >= y_ && 
      (this->getX() + this->getWidth()) <= (x_ + width_) &&
      (this->getY() + this->getHeight()) <= (y_ + height_));    
}
bool Rectangle::within(int x_, int y_, int r_)
{
    Line distance1(x_, y_, this->getX(), this->getY());
    Line distance2(x_, y_, this->getX(), (this->getY() + this->getHeight()));
    Line distance3(x_, y_, (this->getX() + this->getWidth()), (this->getY() + this->getHeight()));
    Line distance4(x_, y_, (this->getX() + this->getWidth()), this->getY());

    return (distance1.getLength() <= r_ && distance2.getLength() <r_ && 
            distance3.getLength() <= r_ &&distance4.getLength() < r_);

}
String Rectangle::getType() const
{
    String type = "Rectangle";
    return type;
}
void Rectangle::saveToFile(char* fileName)
{
    std::ofstream out (fileName, std::ofstream::app);
    out << "    <rectangle " << "x=\"" << getX() << "\" " << "y=\"" << getY() << "\" " << "width=\"" << getWidth() 
    << "\" "<< "heigth=\"" << getHeight() << "\" "<< "fill=\"" << getColor() << "\" />" << std::endl;
    out.close();
}
//print
void Rectangle::print()
{
    std::cout << "The rectangle that you inputed is at: " << getX() << ", " << getY() <<
    " with width: " << getWidth() << ", height: " << getHeight() <<", color: " << getColor() << std::endl;
    std::cout << "It's  perimeter is : " << getPerimeter() << " and area: " << getArea() << std::endl;
}
