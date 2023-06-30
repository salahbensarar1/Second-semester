//
//  main.cpp
//  Footbal  OOP
//
//  Created by Salah Ben Sarar on 10/5/2023.
//

#include <iostream>
#include <fstream>
#include "Soccer.hpp"
using namespace std;
int main(int argc, const char * argv[]) {
    
    string filename="team.txt";
    Soccer s(filename);
    cout<<" The number of the players is  "<<s.Get_N()<<endl;
    return 0;
}
