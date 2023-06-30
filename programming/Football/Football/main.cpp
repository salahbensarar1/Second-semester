//
//  main.cpp
//  Football
//
//  Created by Salah Ben Sarar on 10/5/2023.
//

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
//**********************************************************************
struct Matche{
    int round;
    string teamH;
    string teamA;
    int scoreT1;
    int scoreT2;
    int scoreT1Half;
    int scoreT2Half;
};
//**********************************************************************
void displayArr(Matche *array, int size);
//**********************************************************************
int main(int argc, const char * argv[]) {
salah:cout<<"Data reading from the files"<<endl;
    ifstream file("match.txt");
    // check if file was opened successfully
    if (!file.is_open()) {
        cout << "Failed to open file." << endl;
        return 1;
    }
    // read data from file
    string line;
    while (getline(file, line)) {
        cout << line <<endl;
    }
    file.close();
cout<<"how many elements you want from the file "<<endl;
   int size;
   cin>>size;
   Matche *array= new Matche[size];
       ifstream input("match.txt");
       // check if file was opened successfully
       if (!input.is_open()) {
           cout << "Failed to open file." << endl;
           return 1;
       }
    string firstLine;
    if(size<112){
        getline(input,firstLine);//avoiding the first line
        for(int i = 0 ; i<size ; i++)
        {
            input>>array[i].round;
            input>>array[i].scoreT1;
            input>>array[i].scoreT2;
            input>>array[i].scoreT1Half;
            input>>array[i].scoreT2Half;
            input>>array[i].teamA;
            input>>array[i].teamH;

//            cin.ignore();
            
        }
    }
    input.close();
    
displayArr(array, size);
    delete []array;
    return 0;
}
//**********************************************************************
void displayArr(Matche *array, int size){
    if (array)
    for (int i = 0; i < size; i++) {
    cout << array[i].round << " " << array[i].scoreT1 << " " << array[i].scoreT2 << " " << array[i].teamH << " "<<array[i].teamA<<" "<<array[i].scoreT1Half<<" "<<array[i].scoreT2Half<<endl;
//        cout<<array[i].teamH << " "<<array[i].teamA<<endl;
        
       }
    else {cout<<"No allocation founded -_- \n"; exit(-1);}
    
}

Matche* search_round(Matche *array,int size,int round){
    
    Matche* m = nullptr;
    int j=0;
    for(int i=0;i<size;i++)
    {
        if((array+i)->round==round)
            array[i] = m[j];
        j++;
    }
    
    return m;
}
