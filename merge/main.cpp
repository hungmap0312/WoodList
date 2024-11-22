#include <iostream>
using namespace std;

void mode1(int arr[]){
    cout<<"Nhung nam khong co nguoi nao duoc sinh ra: ";
    for(int i = 0; i <= 51; i++){
        if(arr[i] == 0){
            cout<<1920 + i<<" ";
        }
    }
    cout<<endl;
}

void mode2(int arr[]){
    int count = 0;
    for(int i = 0; i <= 51; i++){
        if(arr[i] <= 10){
            count++;
        }
    }
    cout<<"So luong nhung nam co so nguoi sinh ra khong qua 10"<<count<<endl;
}

void mode3(int arr[]){
    int total = 0;
    for(int i = 0; i <= 14; i++){
        total += arr[i];
    }
    cout<<"Tong so nguoi tren 50 tuoi vao nam 1985: "<<total;
}

int main(){
    int a[51] = {23, 78, 0, 12, 99, 0, 45, 67, 88, 34, 0, 5, 72, 41, 19, 85, 14, 61, 27, 0, 76, 49, 93, 4, 82, 11, 55, 97, 22, 0, 31, 46, 0, 66, 39, 53, 24, 81, 0, 29, 8, 74, 1, 15, 60, 0, 32, 7, 30, 95, 42};
    mode1(a);
    mode2(a);
    mode3(a);
}
