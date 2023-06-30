//
//  main.cpp
//  TEST_FILE
//
//  Created by Salah Ben Sarar on 25/4/2023.
//

#include <iostream>
#include <fstream>
using namespace std;
void display(int *tab, int size);
int main(int argc, const char * argv[]) {
    cout<<"how many elements you want from the file "<<endl;
    int size;
    cin>>size;
    int *array= new int[size];
    string line;
    string filename = "file.txt";
    ifstream input(filename);
    if(size<6)
        if(input.is_open())
    for(int i = 0 ; i<size ; i++)
    {
//        getline(input,line,' ');
        
        input>>array[i];
//        input.ignore();
    }
    display(array, size);
    
    delete []array;
    return 0;
}

void display(int *tab, int size){
    
    for(int j=0;j<size;j++)
        cout<<tab[j]<<"  ";
    return;
}
