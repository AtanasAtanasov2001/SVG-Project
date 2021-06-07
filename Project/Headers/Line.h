#pragma once
#include "Shape.h"

struct Line : public Shape
{
    private:
    int line_x;
    int line_y;
    public:
    Line();
    Line(int x1,int y1, int x2,int y2);
    Line(int x_, int y_, int x1, int y1,char* color_);
    Line& operator=(Line& other);

    void setLineX(int line_x);
    void setLineY(int line_y);
    int getLineX()const;
    int getLineY()const;

    double getLength()const;
    double getPerimeter()const ;
    double getArea()const ;

    bool within(int x, int y, int width, int height);
    bool within(int x, int y, int r);
    String getType() const;
    void saveToFile(char* fileName);
    void print();
};


