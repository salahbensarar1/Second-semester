//
//  Group.hpp
//  oop1
//
//  Created by Salah Ben Sarar on 3/5/2023.
//

#ifndef Group_hpp
#define Group_hpp

#include <stdio.h>
#include <iostream>
#include <ctime>
using namespace std;
class Group{
private: int marks[20] ,size=20;
    
    public :
    Group();
    void intialise(int x,int y);
    void display();
    double average();
    int counter();
};
#endif /* Group_hpp */
