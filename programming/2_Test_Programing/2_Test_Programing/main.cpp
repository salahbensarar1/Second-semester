//
//  main.cpp
//  2_Test_Programing
//
//  Created by Salah Ben Sarar on 17/5/2023.
//

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;
//******************************************************************
struct Fruit{
    string name;
    int kg;
    int price;
};
//******************************************************************
class Market
{
    private :
    Fruit *array;
    int numb;
public:
    Market(string filename);
    int Get_N();
    int Sum_weight();
    string Max_price();
    void Display();
    ~Market();
    
    };
//******************************************************************
Market::Market(string filename)
{
    ifstream inp(filename);
    numb = 0;
    if (inp.fail()) { cout << "Error -_-\n"; exit(1); }
//    int i=0;
        array = new Fruit[numb];
            while (!inp.eof()) {
                inp>>array[numb].name;
                inp>>array[numb].kg;
                inp>>array[numb].price;
                numb++;
            }
            inp.close();
    }
//******************************************************************

int Market::Get_N()
{
    return numb;
}

//******************************************************************
string Market::Max_price(){
    int max=0;
    for(int i =1;i<numb;i++)
    {
        if(array[max].price<array[i].price)
            max=i;
    }
    return array[max].name;
}

//******************************************************************
Market::~Market(){
    delete []array;
}
//******************************************************************
void Market::Display()
{
    cout << "Fruits Data:"<<endl;
    for (int i = 0; i < numb; i++)
    {
        cout << array[i].name <<"\t"<<array[i].kg<<"\t"<<array[i].price<<endl;
    }
    cout <<"\n";
}
//******************************************************************
int Market::Sum_weight()
{
    int sum=0;
    for(int i=0;i<numb;i++)
    sum+=array[i].kg;
    
    return sum;
}
//******************************************************************
int main(int argc, const char * argv[]) {
    
    string file = "fruits.txt";
    Market M(file);
    cout << "The numbers of fruits :" << M.Get_N()<<endl;
    M.Display();
    cout<<"The max is "<< M.Max_price()<<endl;
    cout<<"The Sum weight is "<< M.Sum_weight()<<endl;
    return 0;
}
