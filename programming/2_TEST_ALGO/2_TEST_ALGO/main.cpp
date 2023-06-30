//
//  main.cpp
//  2_TEST_ALGO
//
//  Created by Salah Ben Sarar on 17/5/2023.
//

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

struct phone{
    string manufacturer;
    string type;
    int rom;
    int ram;
    int battery;
    int price;
};
phone select_Algo(phone *phones,int size,string type);
phone search_Algo(phone *phones,int size,int ram);
int Max(phone *phones,int size);
bool Decision(phone *phones,int size);
void Sort(phone *arr, int size);
int main(int argc, const char * argv[]) {
    cout<<"how many elements you want from the file "<<endl;
       int size;
       cin>>size;
       phone *phones= new phone[size];
    //3
    ifstream input("phones.txt");
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
                input>>phones[i].manufacturer;
                input>>phones[i].type;
                input>>phones[i].rom;
                input>>phones[i].ram;
                input>>phones[i].battery;
                input>>phones[i].price;
            

    
                
            }
        }
    for(int i=0;i<size;i++)
    {
        cout<<phones[i].manufacturer<<setw(20)<<phones[i].type<<setw(10)<<phones[i].rom<<setw(10)<<phones[i].ram<<setw(10)<<phones[i].battery<<setw(10)<<phones[i].price<<endl;
        
    }
    cout<<"Please what phone you want search"<<endl;
    string type;
    cin>>type;
    phone data =select_Algo(phones, size, type);
    cout<<"THE PHONE DATA \n"<<data.manufacturer<<setw(20)<<data.type<<setw(10)<<data.rom<<setw(10)<<data.ram<<setw(10)<<data.battery<<setw(10)<<data.price<<endl;
    cout<<"Please what RAM you want search"<<endl;
    int ram;
    cin>>ram;
    data=search_Algo(phones,size,ram);
    cout<<"THE PHONE DATA \n"<<data.manufacturer<<setw(20)<<data.type<<setw(10)<<data.rom<<setw(10)<<data.ram<<setw(10)<<data.battery<<setw(10)<<data.price<<endl;
    
    Sort(phones, size);
    cout<<"Sorting part"<<endl;
    for(int i=0;i<size;i++)
    {
        cout<<phones[i].manufacturer<<setw(20)<<phones[i].type<<setw(10)<<phones[i].rom<<setw(10)<<phones[i].ram<<setw(10)<<phones[i].battery<<setw(10)<<phones[i].price<<endl;
        
    }
    
    if(Decision(phones, size))
        cout<<"Yes there's a phone with a price greater than 1000 $"<<endl;
    else cout<<"No there's No phone with a price greater than 1000 $"<<endl;
    
    int max =  Max(phones, size);
    cout<<"The higher price is the phone "<<phones[max].type<<" with  "<<phones[max].price<<endl;;
    return 0;
}
phone select_Algo(phone *phones,int size,string type)
{
    phone data;
    int i=0;
    while (phones[i].type != type && i<size ) {
        i++;
    }
    if(i < size)  data = phones[i];
    else{ cout<<type<<" is not founded"<<endl; exit(-1);}
   
    return data;
}
phone search_Algo(phone *phones,int size,int ram)
{
    phone data;
    int i=0;
    while (phones[i].ram != ram && i<size ) {
        i++;
    }
    if(i < size)  data = phones[i];
    else{ cout<<ram<<" is not founded"<<endl; exit(-1);}
   
    return data;
}
bool Decision(phone *phones,int size)
{
    int i=0;
    while (phones[i].price<1000 && i<size) {
        i++;
    }
    if (i==size) return false;
    else return true;
        
    
}
int Max(phone *phones,int size)
{
    int max=0;
    for(int i=1;i<size;i++)
    {
        if(phones[max].price<phones[i].price)
            max=i;
    }
    return max;
}
void Sort(phone *arr, int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (arr[j].price > arr[j + 1].price) {
                
                phone temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
