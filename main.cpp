/*
 Project 9: Part 1/1
 Chapter 5 Part 7 Task

 Create a branch named Part1

Purpose:  This project will teach you about variadic templates and recursive templates, one of the last areas needing discussion while learning C++

 
1) read Instructions.cpp

Make the following program work, which makes use of Variadic templates and Recursion

Once it's working: 
Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
Make a pull request after you make your first commit and pin the pull request link to our DM thread.

send me a DM to check your pull request

 Wait for my code review.
 */

#include <iostream>
#include <string>
#include <typeinfo>

struct Point
{
    Point(float _x, float _y) : x(_x), y(_y) { }
    Point& multiply(float m)
    {
        x *= m;
        y *= m;
        return *this;
    }
    std::string toString() const
    {
        std::string str;
        str +="Point { x: ";
        str += std::to_string(x);
        str += ", y: ";
        str += std::to_string(y);
        str += " }";
        return str;
    }
private:
    float x{0}, y{0};
};

template<typename Type>
struct Wrapper
{
    Wrapper(Type&& t) : val(std::move(t)) 
    { 
        std::cout << "Wrapper(" << typeid(val).name() << ")" << std::endl; 
    }
};

int main()
{
    variadicHelper( 3, std::string("burgers"), 2.5, Point{3.f, 0.14f} );
}


