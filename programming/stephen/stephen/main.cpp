//
//  main.cpp
//  stephen
//
//  Created by Salah Ben Sarar on 17/5/2023.
//

#include <iostream>
#include <iomanip>
using namespace std;

class Car{
private:
    string brand;
    string color;
    int km;
public:
    Car();
    void setB(string brand);
    void setC(string color);
    void setK(int km);
    string getB();
    string getC();
    int getK();
    int Total_km(Car *array,int size);
    };

//*********************************************************
int main(int argc, const char * argv[]) {
//
    
    cout<<"Hi how many car you want to register"<<endl;
    int size;
    cin>>size;
    Car *array=new Car[size];
    string brand,color;
    int km;
    for(int i=0;i<size;i++)
    {
        cout<<"Car ["<<i+1<<"] :"<<endl;
        cout<<"\t\t 1- Brand :";
        cin>>brand;
        array[i].setB(brand);
        cout<<"\t\t 2- Color :";
        cin>>color;
        array[i].setC(color);
        cout<<"\t\t 3- Km :";
        cin>>km;
        array[i].setK(km);
        
    }
    cout<<"Display part"<<endl;
    for(int i =0;i<size;i++)
    {
        cout<<setw(10)<<array[i].getB()<<setw(10)<<array[i].getC()<<setw(10)<<array[i].getK()<<endl;
        
        
    }

    cout<<"The total of km is :"<<array[0].Total_km(array, size)<<endl;
  delete[] array;
    return 0;
}
Car::Car(){
    brand="Renault";
    color="Blue";
    km=100;
    
}
//***************************************************************
void Car::setB(string brand){
    this->brand=brand;
}
void Car::setC(string color){
    this->color=color;
}
void Car::setK(int km){
    this->km=km;
}
//***************************************************************
string Car::getB(){
    
    return brand;
}
string Car::getC(){
    
    return color;
}
int Car::getK(){
    
    return km;
}
//***************************************************************

int Car::Total_km(Car *array,int size)
{
    int sum=0;
    for(int i=0;i<size;i++)
    {
        sum=sum+array[i].getK();
        
    }
    
//    sum++; / sum=sum+1;
//    sum+=13; / sum=sum+13;
    
    return sum;
}
