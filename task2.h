#ifndef TASK2_H
#define TASK2_H

#include <iostream>



class Fruit
{
public:
    Fruit(){}
    Fruit(const std::string& n, const std::string& c) :
        name(n), color(c){}

    const std::string& GetName() const { return name; }
    const std::string& GetColor() const { return color; }

private:
    std::string name;
    std::string color;
};

class Apple : public Fruit
{
public:
    Apple(const std::string& c) :
        Fruit("apple", c){}

    Apple(const std::string & a, const std::string& c) :
        Fruit( a , c){}
};

class Banana : public Fruit
{
public:
    Banana() :
        Fruit("banana", "yellow"){}
};

class GrannySmith : public Apple
{
public:
    GrannySmith() :
        Apple("Granny Smith","green"){}
};

void task2()
{
        Apple a("red");
        Banana b;
        GrannySmith c;

        std::cout << "My " << a.GetName() << " " << a.GetColor() << ".\n";
        std::cout << "My " << b.GetName() << " " << b.GetColor() << ".\n";
        std::cout << "My " << c.GetName() << " " << c.GetColor() << ".\n";
}



#endif // TASK2_H
