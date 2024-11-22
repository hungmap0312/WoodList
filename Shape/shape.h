#pragma once
#include<string>
using namespacestd;
class Shape{
    string color;
    bool filled;
public:
    Shape(string, bool);
    string getColor();
    void setColor(string);
    bool isFilled();
    void setFilled(bool);
    double getArea();
    double getPerimeter();
    void display();
};
