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
#include <utility>

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

/*
2) implement a RECURSIVE variadicHelper Function and a Wrapper class.

3) your variadicHelper function needs to be a Recursive Variadic Template Function.
    The recursion works by removing the first element from the Variadic Template Parameter Pack, doing something with it, and calling VariadicHelper with the rest of the Pack.

6) make the body of both variadicHelper functions instantiate a Wrapper instance, which wraps the first function argument, and call the 'print()' member function of the Wrapper class.

7) Then, recursively call VariadicHelper.

9) be sure to forward your variadicHelper function arguments correctly and use Forwarding/R-Value references, as opposed to passing by const-ref or by copy.
*/

template<typename Type>
struct Wrapper
{
    Wrapper(Type&& t) : val(std::move(t)) 
    { 
        std::cout << "Wrapper(" << typeid(val).name() << ")" << std::endl; 
    }

 /*
 5) add a print() function to the Wrapper stub.
 */

    void print()
    {
        std::cout << "Wrapper::print(" << val << ")" << std::endl;
    }
private:
    Type val;
};

/*
8) You will need to specialize the Wrapper class template to work with the Point class.
*/

template<>
void Wrapper<Point>::print()
{
    std::cout << "Wrapper::print(" << val.toString() << ")" << std::endl;
}

template<typename T, typename ...Args>
void variadicHelper(T&& first, Args&& ... everythingElse)
{
    Wrapper wrapper( std::forward<T>(first) );
    wrapper.print();
    variadicHelper( std::forward<Args>(everythingElse)... );
}

/*
4) You'll need to write this single-template-parameter version of variadicHelper along with the variadic-template version of VariadicHelper.
*/

template<typename T>
void variadicHelper(T&& first)
{
    Wrapper wrapper( std::forward<T>(first) );
    wrapper.print();    
}

int main()
{
    variadicHelper( 3, std::string("burgers"), 2.5, Point{3.f, 0.14f} );
}
