#include<iostream>
#include<string>
#include "Shape"
Shape::Shape(string color, bool filled){
    this->color=color;
    this->filled=filled;
}
string Shape::getColor(){
    return color;
}
void Shape::setColor(string color){
    this->color=color;
}
bool
