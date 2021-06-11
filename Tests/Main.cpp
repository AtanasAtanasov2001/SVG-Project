#define DOCTEST_CONFIG_IMPLEMENT

 
#include "../Project/Headers/String.h"
#include "../Project/Headers/Vector.h"
#include "../Project/Headers/Line.h"
#include "../Project/Headers/Circle.h"
#include "../Project/Headers/Rectangle.h"

#include "../Project/src/String.cpp"
#include "../Project/src/Line.cpp"
#include "../Project/src/Circle.cpp"
#include "../Project/src/Rectangle.cpp"


#include "doctest.h"

//---------------VECTOR-TESTS--------------
TEST_CASE("Insertion in an empty vector")
{
    Vector<int> v;
    CHECK(v.getSize()==0);
    v.push_back(1); 
    CHECK(v.getSize()==1);
    CHECK(v[0]==1);
}

TEST_CASE("Insertion of multiple elements")
{
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    CHECK(v.getSize() == 6);
    CHECK(v[0]==1);
    CHECK(v[2]==3);
    CHECK(v[5]==6);

}
TEST_CASE("Removing the first/last/desired element")
{
    Vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);

    v.pop_back();
    v.pop_front();
    CHECK(v.getSize() == 4);
    CHECK(v[0] == 2);
    CHECK(v[2] == 4);
    CHECK(v[3] == 5);

    v.pop_desired(2);
    CHECK(v.getSize() == 3);
    CHECK(v[0] == 2);
    CHECK(v[2] == 5);

}
TEST_CASE("Functionallity of operator=")
{
    Vector<int> v1;
    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);
    Vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    CHECK(v1 = v2);
    Vector<int> v3;
    v2.push_back(1);
    CHECK(v2=v3);
   
}
//---------------CIRCLE-TESTS--------------
TEST_CASE("Getters and Setters")
{
    Circle c1;
    c1.setX(2);
    c1.setY(3);
    c1.setRadius(3);

    CHECK(c1.getX() == 2);
    CHECK(c1.getY() == 3);
    CHECK(c1.getRadius() == 3);
    CHECK(c1.getPerimeter() == 18.84);
    CHECK(c1.getArea() == 28.26);
    CHECK(c1.getType() == "Circle");
}
TEST_CASE("Within functions")
{
    //due to the existance of a rectangle class in the doctest library i will manualy create a rectangle with 4 parametres!!!
    int rectangle_x(0),rectangle_y(0),rectangle_width(30),rectangle_height(30);
    
    //figures that i tested in the main and work!!
    Circle c1(5,5,6,"Blue");
    Circle c2(6,4,6,"silver");
    Line liniika(4,6,6,8,"green");

    CHECK(liniika.within(rectangle_x,rectangle_y,rectangle_width,rectangle_height));//line within rectangle
    CHECK(liniika.within(c2.getX(), c2.getY(), c2.getRadius()));//line within circle
    CHECK (c1.within(rectangle_x,rectangle_y,rectangle_width,rectangle_height));//circle within rectangle
    Circle bigCircle(4,3,3);
    Circle smallCircle(4,2,1);
    CHECK (smallCircle.within(bigCircle.getX(), bigCircle.getY(), bigCircle.getRadius()));//circle within circle

    //as for the rectangle within rectangle and circle i have tested them in the main!!
}
//---------------RECTANGLE-TESTS-----------

//---------------LINE-TESTS----------------
TEST_CASE("Setters and Getters")
{
    Line l;
    l.setX(3);
    l.setY(3);
    l.setLineX(6);
    l.setLineY(7);

    CHECK(l.getLineX() == 6);
    CHECK(l.getLineY() == 7);
    CHECK(l.getLength() == 5);
    CHECK(l.getPerimeter() == 5);
    CHECK(l.getArea() == 0);
    CHECK(l.getType() == "Line");
}
int main()
{
    doctest::Context().run();
    return 1;
}