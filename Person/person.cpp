#include<iostream>
#include<string>
#include "person.h"
Person::Person(string name, int age, string gender){
    this->name=name;
    this->age=age;
    this->gender=gender;
}
string Person::get_name(){
    return name;
}
void Person::set_name(string name){
    this->name=name;
}
int Person::get_age(){
    return age;
}
void Person::set_age(int age){
    this->age=age;
}
