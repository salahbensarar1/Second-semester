//
//  Soccer.hpp
//  Footbal  OOP
//
//  Created by Salah Ben Sarar on 10/5/2023.
//

#ifndef Soccer_hpp
#define Soccer_hpp

#include <stdio.h>
#include<iostream>
#include <fstream>
using namespace std;
struct player
{
    string name;
    int born;
    string position;
    int match,shots,goal;
};
class Soccer
{
private:
    int numb;
    player *arr;
public:
    Soccer(string filename);
    ~Soccer();
    void Display();
    int Get_N();
    int Sum_Of_shots();
    player Maxgoal();
    void Youth();
    bool equal();
    
};

#endif /* Soccer_hpp */
