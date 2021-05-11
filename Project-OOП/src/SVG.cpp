#include "../Headers/SVG.h"
#include "Menu.cpp"
#include <iostream>
#include <fstream>

void SVG::addFigure(Shape& figure)
{
    figures.push_back(&figure);
}

Shape SVG::createFigure() const
{
    int x,y;
    String color;
    size_t r,width,height;
    String typeOfShape;

    std::cout << "Enter the new shape's type: ";
    std::cin >> typeOfShape;

    std::cout << "Enter the new shape's coordinates: ";
    std::cin >> x >> y; 

    std::cout << "Enter the color of your shape: ";
    std::cin >> color;

    if(typeOfShape == "Rectangle" )
    {
        std::cout << "Enter the width and height of your rectangle: ";
        std::cin >> width >> height;
        return Rectangle(x,y,width,height,color.getData());
    }
    else if (typeOfShape == "Circle")
    {
        std::cout << "Enter your circle's radius: ";
        std::cin >> r;
        return Circle(x,y,r,color.getData());
    }
    else
    {
        return Line(x,y, color.getData());
    }
}
void SVG::saveToFile(char* fileName)
{
    std::ofstream out (fileName);
    out << "<svg>" << std::endl;
    out.close();
    for (size_t i = 0; i < figures.getSize(); i++)
    {
        figures[i]->saveToFile(fileName);
    }
    std::ofstream outEnd(fileName,std::ofstream::app);

    outEnd << "</svg>";
    outEnd.close();
}

void SVG::loadFromFile(Vector<Shape>* fig,char* fileName)
{
  
    std::ifstream in(fileName);
    char line[256];
   
    while(!in.eof())
    {
        char name[16];
        in >> name;
        if(strcmp(name,"<rectangle") == 0)
        {
            char current[64];
            in >>  current;
            while (strcmp (current, "/>") != 0)
            {
                String key;
                String value;
                size_t i = 0;
                for (; current[i] != '='; i++)
                {
                    key.push_back(current[i]);
                }
                i++;
                for (; current[i] != '\0'; i++)
                {
                    value.push_back(current[i]);
                }
                std::cout << key << '=' << value;
                
                in >>  current;

            }
            std::cout << std::endl << "--------------------" <<std::endl;
        }
        else if(strcmp(name,"<circle") == 0)
        {
            char current[64];
            in >>  current;
            while (strcmp (current, "/>") != 0)
            {
                String key;
                String value;
                size_t i = 0;
                for (; current[i] != '='; i++)
                {
                    key.push_back(current[i]);
                }
                i++;
                for (; current[i] != '\0'; i++)
                {
                    value.push_back(current[i]);
                }
                std::cout << key << '=' << value;
                
                in >>  current;

            }
            std::cout<< std::endl << "--------------------" <<std::endl;
        }
        else if(strcmp(name,"<line") == 0)
        {
            char current[64];
            in >>  current;
            while (strcmp (current, "/>") != 0)
            {
                String key;
                String value;
                size_t i = 0;
                for (; current[i] != '='; i++)
                {
                    key.push_back(current[i]);
                }
                i++;
                for (; current[i] != '\0'; i++)
                {
                    value.push_back(current[i]);
                }
                std::cout << key << '=' << value ;
                
                in >>  current;

            }
            std::cout << std::endl << "--------------------" <<std::endl;
        }
    }
}
void SVG::start()
{
    int flag;
    do
    {
        std::cout << "Enter: ";
        command = "";
        std::cin >> command;
        for(int i = 0; i < menu.getSize(); i++)
        {
            if(command == menu[i])
            {
                flag = i;
                break;
            }
        }
        switch(flag)
        {
            case 0: 
            {

                break;
            }
            case 1:
            {
               
                break;
            }
            case 2:
            {
                saveToFile("figures.svg");
                std::cout << "Successfully saved figures.svg" << std::endl;
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                this->loadFromFile (fig,"figures.svg");
                break;
            }
            case 5:
            {
                break;
            }
            case 6:
            {
                break;
            }
            case 7:
            {
                Shape temp = createFigure();
                addFigure(temp);
                break;
            }
            case 8:
            {

                break;
            }
            case 9:
            {
                std::cout <<  "The following commands are supported:" << std::endl
                          <<  "Open <file>	opens <file>" << std::endl
                          <<  "Close - closes currently opened file" << std::endl
                          <<  "Save - saves the currently open file" << std::endl
                          <<  "Saveas <file> - saves the currently open file in <file>" << std::endl
                          <<  "Print - prints all the figures in the file - <file>" << std::endl
                          <<  "Within <option> - shows all the figures present inside a given region. The user can manipulate region trough <option> (either a circle or a rectangle)" << std::endl
                          <<  "Erase <number> - deletes the figure, present at the given <number> from the file"<< std::endl
                          <<  "Create - creates a new figure" << std::endl
                          <<  "Translate [<n>] - translates the figure with number <n>, if no <n> is given, translates all figures"<<std::endl
                          <<  "Help - prints this information" << std::endl
                          <<  "Exit - exists the program" << std::endl;
                          break;
            }
            case 10:
            {
                std::cout << "Exiting the program..." << std::endl;   
                break;
            }
            default: "Invalid command";

        }
    }
    while(command != "Exit");
}
    