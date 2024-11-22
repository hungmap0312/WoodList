#include<iostream>
using namespace std;
class Point{
private:
    int x;
    int y;
public:
    void nhap(){
        cout<<"Nhap hoanh do: ";
        cin>>x;
        cout<<endl<<"Nhap tung do: ";
        cin>>y;
    }
    void display(){
     cout<<endl<<"Hoanh do la: "<<x;
     cout<<endl<<"Tung do la: "<<y<<endl;
    }
};
int main(){
    Point p;
    p.nhap();
    p.display();
}
