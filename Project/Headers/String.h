#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
class String
{
    private:
    
    size_t length;

    void copy(const String&);
    void destroy();
    char* data;
    public:
    
    //the big 4
    String();
    String(const char*);
    String(const String&);

    String& operator= (const char*);
    String& operator= (const String&);
    ~String();
 
    //access
    bool isEmpty() const;
    size_t Length() const;
    char* getData() const;
   
    //char* operator[](size_t);
    char operator[](size_t) const;
    bool operator==(String& other) const;
    bool operator==(const char* other) const;
    bool operator!=(String& other) const;
    bool operator!=(const char* other) const;
    int castToInt() const;
    void push_back(const char);
    String& pop_back();
    friend std::ostream& operator<< (std::ostream& out, const String&);
    friend std::istream& operator>> (std::istream& in, String& other);

};