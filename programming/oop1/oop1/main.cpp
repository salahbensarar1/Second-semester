//
//  main.cpp
//  oop1
//
//  Created by Salah Ben Sarar on 3/5/2023.
//

#include <iostream>
#include "Rectangle.hpp"
#include "Group.hpp"
#include <ctime>

using namespace std;
int main(int argc, const char * argv[]) {
    
//    Group G;
//    Group G2;
//    G2.~Group();
//    int x,y;
//    cout<<"Group 1"<<endl;
//    cout<<"X and Y ?"<<endl;
//    cin>>x>>y;
//    G.intialise(x, y);
//    G.display();
//    cout<<"The average is "<< G.average()<<endl;
//    cout<<"The number of the 5th is "<< G.counter()<<endl;
//    cout<<"Group 2"<<endl;
//    cout<<"X and Y ?"<<endl;
//    cin>>x>>y;
//    G2.intialise(x, y);
//    G2.display();
//    cout<<"The average is "<< G2.average()<<endl;
//    cout<<"The number of the 5th is "<< G2.counter()<<endl;
//
//
    
    salah:cout<<"Szia"<<endl;
    int choice,distance;
    cout<<"Enter the value"<<endl;
    cin>>distance;
    if(0<=distance && distance<=20) cout<<"Stop"<<endl;
    else if(distance>20 && distance<=40) cout<<"Very Close"<<endl;
    else if(distance>40 && distance<=80) cout<<"Getting Closer"<<endl;
    else if(distance>80 && distance<=120) cout<<"Object Is Far"<<endl;
    else cout<<"No object"<<endl;
    
    cout<<"Enter the goto value"<<endl;
    cin>>choice;
    if(choice ==1) goto salah;
    return 0;
}
//int min(int array[20])
//{
//    return 0;
//}
