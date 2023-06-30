//
//  Rectangle.cpp
//  oop1
//
//  Created by Salah Ben Sarar on 3/5/2023.
//

#include "Rectangle.hpp"
Rectangle::Rectangle(){
    a=0;
    b=0;
    
}
void Rectangle::setA(int a){
    this->a=a;
}
void Rectangle::setB(int b){
    this->b=b;
}
int Rectangle::getA(){
    return a;
}
int Rectangle::getB(){
    return b;
}
int Rectangle::area(){
    return a*b;
}
int Rectangle::perimeter(){
    return 2*(a+b);
}
