#include "../Headers/SVG.h"
#include "Menu.cpp"
#include <iostream>
#include <fstream>

SVG::SVG()
{
    this->filename = nullptr;
}
SVG::~SVG()
{
    this->figures.destroy();
    this->commands.destroy();
    delete[] this->filename;
}
void SVG::addFigure(Shape* figure)
{
    figure->saveToFile(filename);
    figures.push_back(figure);
}

Shape* SVG::createFigure()
{
    int x,y;
    String color;
    size_t r,width,height,x1,y1;
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
        return new Rectangle(x,y,width,height,color.getData());
    }
    else if (typeOfShape == "Circle")
    {
        std::cout << "Enter your circle's radius: ";
        std::cin >> r;
        return  new Circle(x,y,r,color.getData());
    }
    else
    {
        std::cout << "Enter the other dot, that forms the line: ";
        std::cin >> x1 >> y1;
        return new Line(x,y,x1,y1 ,color.getData());
    }
}
void SVG::saveToFile()
{
    if(this->filename != nullptr)
    {
        std::ofstream out (this->filename);
        out << "<svg>" << std::endl;
        out.close();
        for (size_t i = 0; i < figures.getSize(); i++)
        {
            figures[i]->saveToFile(this->filename);
        }
        std::ofstream outEnd(this->filename,std::ofstream::app);

        outEnd << "</svg>";
        outEnd.close();
    }
    else
    {
        std::cout << "No opened file exists!"<< std::endl;
    }
}

void SVG::loadFromFile()
{
    if(this->filename != nullptr)
    {
        std::ifstream in(this->filename);
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
    else
    {
        std::cout << "No opened file exists!"<<std::endl;
    }
}

Vector<Shape*> SVG::within(Rectangle& newShape)
{
    Vector<Shape*> figures_within;
    for (size_t i = 0; i < figures.getSize(); i++)
    {
        if (figures[i]->within(newShape.getX(),newShape.getY(),newShape.getWidth(),newShape.getHeight()))
        {
            figures_within.push_back(figures[i]);
        }
    }
    return figures_within;
}
Vector<Shape*> SVG::within(Circle& newShape)
{
    Vector<Shape*> figures_within;
    for (size_t i = 0; i < figures.getSize(); i++)
    {
        if (figures[i]->within(newShape.getX(),newShape.getY(),newShape.getRadius()))
        {
            figures_within.push_back(figures[i]);
        }
    }
    return figures_within;
}
void SVG::translate()
{
    char* answer;
    int number;
    std::cout << "Would you like to translate a sigle figure or the whole vector?"<<std::endl;
    std::cin >> answer;
    if (strcmp(answer, "Single Figure") == 0)
    {
        int new_x, new_y;
        std::cout << "Enter the number of the figure you would like to translate:"<<std::endl;
        std::cin >> number;
        std::cout << "Enter the new coordinates for your figure:" << std::endl;
        std::cout <<"vertical:";
        std::cin >> new_x ;
        std::cout << std::endl;
        std::cout <<"horizontal:";
        std::cin >> new_y ;
        std::cout << std::endl;
        figures[number]->translate(new_x,new_y);
        figures[number]->print();
    }
    else
    {
        int new_x, new_y;
        std::cout << "Enter the new coordinates for your figures:" << std::endl;
        std::cout <<"vertical:";
        std::cin >> new_x ;
        std::cout << std::endl;
        std::cout <<"horizontal:";
        std::cin >> new_y ;
        std::cout << std::endl;
        Vector<Shape*> newVec;
        for (size_t i = 0; i < figures.getSize(); i++)
        {
            figures[i]->translate(new_x,new_y);
            newVec.push_back(figures[i]);
        }
        std::cout << "Translated all figures" << std::endl;
        for (size_t i = 0; i < newVec.getSize(); i++)
        {
           newVec[i]->print();
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
            case 0: //Open
            {
                char filename_[64];
                std::cout << "Enter the name of the file you want to save your figures to: ";
                std::cin >> filename_;
                this->filename = new char[strlen(filename_)+ 1];
                strcpy(this->filename,filename_);
                //loadfromfile 
                std::cout << "Successfully opened " << this->filename << std::endl;
                break;
            }
            case 1: //Close
            {   
                //delete the vector
                std::cout << "Successfully closed " << this->filename<<std::endl;
                this->filename = nullptr;
                break;
            }
            case 2://Save
            {
                saveToFile();
                std::cout << "Successfully saved figures.svg" << std::endl;
                break;
            }
            case 3://Saveas
            {
                char* filename_;
                std::cout << "Enter the name of the file you want to save your figures to: ";
                std::cin >> filename_;
                //zadeli poveche pamet za filename!!!
                strcpy(filename_, this->filename);
                saveToFile();
                break;
            }
            case 4://print
            {
                //metod print!
                //loadfrom file da ne printira!!
                this->loadFromFile();
                break;
            }
            case 5://within
            {   
                String type;
                std::cout <<"Is the entered figure a rectangle or circle?" << std::endl;
                std::cin >> type;
                if(type == "Rectangle")
                {
                    int x_rec,y_rec,width_rec,height_rec;
                    std::cout << "Please, enter your rectangle's parameters!"<<std::endl;
                    std::cin >> x_rec >> y_rec >> width_rec >> height_rec;

                    Rectangle newFigure(x_rec,y_rec,width_rec,height_rec);
                    Vector<Shape*> v = within(newFigure);
                    for (size_t i = 0; i < v.getSize(); i++)
                    {
                        v[i]->print();
                    }
                }
                if(type == "Circle")
                {
                    int x_circle,y_circle,radius;
                    std::cout << "Please, enter your circle's parameters!"<<std::endl;
                    std::cin >> x_circle >> y_circle >> radius;

                    Circle newFigure(x_circle,y_circle,radius);
                    Vector<Shape*> v = within(newFigure);
                    for (size_t i = 0; i < v.getSize(); i++)
                    {
                        v[i]->print();
                    }
                }
                break;
            }
            case 6://erase
            {
                int position;
                std::cout <<"Enter the position of the desired figure, to be erased: ";
                std::cin >> position;
                delete[] this->figures[position];
                this->figures.pop_desired(position);
                break;
            }
            case 7://create
            {
                //addfigure ne tryabva da raboti po file-a!!
                addFigure(createFigure());
                break;
            }
            case 8://translate
            {
                //test
                translate();
                break;
            }
            case 9://help
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
            case 10://exit
            {
                std::cout << "Exiting the program..." << std::endl;   
                break;
            }
            default: "Invalid command";

        }
    }
    while(command != "Exit");
}
    