//
//  Rectangle.hpp
//  oop1
//
//  Created by Salah Ben Sarar on 3/5/2023.
//

#ifndef Rectangle_hpp
#define Rectangle_hpp

#include <stdio.h>

class Rectangle{
private: int a,b;
public:
    Rectangle();
    void setA(int );
    void setB(int );
    int getA(void);
    int getB(void);
    int area();
    int perimeter();
};

#endif /* Rectangle_hpp */
