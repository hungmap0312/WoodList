#include<iostream>
#include<string>
using namespace std;
class Shape{
    string color;
    int filled;
public:
    Shape(string color, int filled){
        this->color=color;
        this->filled=filled;
    }
    string getColor(){
        return color;
    }
    void setColor(string color){
        this->color=color;
    }
    int isFilled(){
        return filled;
    }
    void setFilled(int filled){
        this->filled=filled;
    }
    virtual double getArea()=0;
    virtual double getPerimeter()=0;
    virtual void display(){
        cout<<"Hinh co mau: "<<color<<endl;
        if(isFilled()){
            cout<<"Hinh da to mau "<<color<<endl;
        }
        else cout<<"Hinh chua to mau"<<endl;
    }
};
class Circle:public Shape{
    double radius;
public:
    Circle(string color, int filled, double radius):Shape(color, filled){
        this->radius=radius;
    }
    void setRadius(){
        this->radius=radius;
    }
    double getRadius(double radius){
        return radius;
    }
    double getArea(){
        return radius*radius*3.14;
    }
    double getPerimeter(){
        return 2*3.14*radius;
    }
    void display(){
        Shape::display();
        cout<<"Ban kinh cua hinh tron la: "<<radius<<endl;
        cout<<"Dien tich hinh tron la: "<<getArea()<<endl;
        cout<<"Chu vi hinh tron la: "<<getPerimeter()<<endl;
    }
};
class Square:public Shape{
    double side;
public:
    Square(string color, int filled, double side):Shape(color, filled){
        this->side=side;
    }
    void setSide(double side){
        this->side=side;
    }
    double getSide(){
        return side;
    }
    double getArea(){
        return side*side;
    }
    double getPerimeter(){
        return 4*side;
    }
    void display(){
        Shape::display();
        cout<<"Canh cua hinh vuong la: "<<side<<endl;
        cout<<"Dien tich hinh vuong la: "<<getArea()<<endl;
        cout<<"Chu vi hinh vuong la: "<<getPerimeter()<<endl;
    }
};
class Rectangle:public Shape{
private:
    double width;
    double height;
public:
    Rectangle(string color, int filled, double width, double height):Shape(color, filled){
        this->width=width;
        this->height=height;
    }
    double getWidth(){
        return width;
    }
    void setWidth(double width){
        this->width=width;
    }
    double getHeight(){
        return height;
    }
    void setHeight(double height){
        this->height=height;
    }
    double getArea(){
        return width*height;
    }
    double getPerimeter(){
        return 2*(height+width);
    }
    void display(){
        Shape::display();
        cout<<"Chieu dai hinh chu nhat la: "<<height<<endl;
        cout<<"Chieu rong hinh chu nhat la: "<<width<<endl;
        cout<<"Dien tich hinh chu nhat la: "<<getArea()<<endl;
        cout<<"Chu vi hinh chu nhat la: "<<getPerimeter()<<endl;
    }
};
int main(){
    Circle c("red", 1, 3);
    Square s("blue", 0, 2);
    Rectangle r("white", 4, 7, 11);
    c.display();
    s.display();
    r.display();
}
