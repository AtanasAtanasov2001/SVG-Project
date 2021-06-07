#pragma once
#include "../Headers/Menu.h"
#include <iostream>
#include <cstring>

Menu::Menu()
{
    menu.push_back("Open");//0
    menu.push_back("Close");//1
    menu.push_back("Save");//2
    menu.push_back("Saveas");//3
    menu.push_back("Print");//4
    menu.push_back("Within");//5
    menu.push_back("Erase");//6
    menu.push_back("Create");//7
    menu.push_back("Translate");//8
    menu.push_back("Help");//9
    menu.push_back("Exit");//10
}
