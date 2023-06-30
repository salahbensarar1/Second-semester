//
//  main.cpp
//  votes
//
//  Created by Salah Ben Sarar on 3/5/2023.
//

#include <iostream>
#include <fstream>
using namespace std;
struct party{
    string pname,shortname;
    int numvotes;
};
struct candidats{
    string name,party;
    int votes,cons;
};

int main(int argc, const char * argv[]) {
    ifstream in("votes.txt");
    if(in.fail()) {cerr<<"error";exit(1);}
    cout << "\n votes " << endl;
    while (!in.eof())
    {
//        
    }
    return 0;
}
