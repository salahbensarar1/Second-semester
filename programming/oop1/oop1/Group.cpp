//
//  Group.cpp
//  oop1
//
//  Created by Salah Ben Sarar on 3/5/2023.
//

#include "Group.hpp"

using namespace std;
Group::Group()
{
    srand((unsigned int)time(NULL));
    for (int i=0; i<20; i++) {
        marks[i]=rand()%5+1;
    }
}

void Group::display()
{
    for (int i=0;i<20; i++) {
        cout<<" Element "<<i+1<<" = "<<marks[i]<<endl;
    }
}
double Group::average()
{
    int sum=0;
    for(int i=0;i<20;i++)
        sum+=marks[i];
    return double(sum)/20;
}

int Group::counter()
{
    int count=0;
    
    for(int i=0;i<20;i++){
        if(marks[i]==5) count++;
    }
    
    return count;
}
void Group::intialise(int x,int y)
{
    srand((unsigned int)time(NULL));
    for (int i=0; i<20; i++) {
        marks[i]=rand()%y+x;
    }
}
