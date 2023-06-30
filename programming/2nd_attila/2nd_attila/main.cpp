//
//  main.cpp
//  2nd_attila
//
//  Created by Salah Ben Sarar on 26/4/2023.
//
#include <iostream>
#include <ctime>
#include<math.h>
using namespace std;
//**********************************************************************
bool is_Not_Allocate(int *arr);
void Displaay(int *arr,int taille);
//**********************************************************************


int main(int argc, const char * argv[]) {
    srand((unsigned int)time(NULL));
    int *tab;
    int size;
    cout<<" How many number u need \n";
    cin>>size;
    tab=(int*)malloc(sizeof(int)*size);
    int result[size];
    if(size<=1000)
        
    for(int i=0; i<size ;i++)
    {
        tab[i]=(rand()%11)+2;
        result[tab[i]-2]++;
        
    }
    Displaay(tab, size);
    cout<<"\nRESULT\n"<<endl;
    
    for(int a = 0;a<size;a++){
        cout<<"ARRAY[ "<<a+1<<" ] = "<< result[a]<<endl;
    }
    free(tab);
    return 0;
}
//************************************************************************
bool is_Not_Allocate(int *arr){
    if(arr==NULL)
        return true;
    else return false;
}
//************************************************************************
void Displaay(int *arr,int taille)
{
    if(is_Not_Allocate(arr))
        {
            cout<<"ARRAY Not ALLOCATED -_-\n";
        exit(-1);
        }
    else{
        for(int a = 0;a<taille;a++){
            cout<<"ARRAY[ "<<a+1<<" ] = "<< arr[a]<<endl;
        }
    }
    return;
}
