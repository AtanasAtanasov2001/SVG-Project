#pragma once
#include "String.h"
#include "Vector.h"

class Menu
{
    protected:
    Vector<String> menu;
    String command;

    public:
    Menu();
    virtual void start() = 0;
};