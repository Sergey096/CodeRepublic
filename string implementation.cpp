#include <iostream>
#include "Header.h"

string& string::operator = (const string& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
     this->capacity = rhs.capacity;
     this->size = rhs.size;
     delete this->p;
     this->p = new char[capacity];

     for (int i = 0; i < this-> size; ++i) 
     {
         this->p[i] = rhs.p[i];    
     }
     return *this;
}

string string::operator + (const string& rhs)
{
    string tmp;
    tmp.capacity = this->capacity + rhs.capacity;
    tmp.size = this->size + rhs.size;
    for (int i = 0; i < size; ++i)
    {
        tmp.p[i] = this->p[i];
    }
    for (int i = 0; i < rhs.size; ++i)
    {
        tmp.p[size + 1] = rhs.p[i];
    }
    return tmp;
}

string::string(const string &rhs)
{
    size = rhs.size;
    p = new char[size];
    
}

string::string() :capacity{ 3 }, size{ 0 }, p{ new char[capacity] }
{

}
void string::push_back(char value)
{
    if (capacity = size)
    {
        capacity *= 2;
        char* tmp = new char[capacity];
        for (int i = 0; i < size; ++i)
        {
            tmp[i] = p[i];
        }
        delete[]p;
        p = tmp;
        tmp = nullptr;
    }
    p[size] = value;
    ++size;
}

void string::push_front(char value)
{
    if (capacity = size)
    {
        capacity *= 2;
        char* tmp = new char[capacity];
        tmp[0] = value;
        for (int i = 0; i < size; ++i)
        {
            tmp[i +1] = p[i];
        }
        delete[]p;
        p = tmp;
        tmp = nullptr;
        ++size;
    }
      
}

void string::pop_back()
{
    if (size != 0)
    {
        size = size - 1;
        p[size] = '/0';
    }
}

void string::pop_front()
{
    if (size != 0)
    {
        char* tmp = new char[capacity];
        for (int i = 0; i < size ; ++i)
        {
            tmp[i] = p[i + 1];
            
        }
        delete[]p;
        --size;
    }

}

string::string(int size, int capacity)
{
    this->capacity = capacity;
    this->size = size;
    //this-> p = p ;
   
}


