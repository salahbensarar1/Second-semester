//
//  Soccer.cpp
//  Footbal  OOP
//
//  Created by Salah Ben Sarar on 10/5/2023.
//

#include "Soccer.hpp"
Soccer::Soccer(string filename){
    ifstream in(filename);
    if(in.fail()){
        cerr<<"ERROR"<<endl; exit(1);
    }
    
    string s;
    while (!in.eof()) {
        getline(in,s);
        numb++;
    }
    in.close();
    in.open(filename);
    int i=0;
    arr = new player[numb];
    while (!in.eof()) {
        in>>arr[i].name;
        in>>arr[i].born;
        in>>arr[i].position;
        in>>arr[i].match;
        in>>arr[i].shots;
        in>>arr[i].goal;
        i++;
    }
    in.close();
    
}
int Soccer::Get_N(){
    return numb;
}
void Soccer::Display()
{
    
    
    return;
}

int Soccer::Sum_Of_shots(){
    
    
    return 0;
}
player Soccer::Maxgoal()
{
    player p;
    return p;
}
void Soccer::Youth(){
    return;
}

bool Soccer::equal(){
    return true;
}
Soccer::~Soccer(){
    delete []arr;
}
