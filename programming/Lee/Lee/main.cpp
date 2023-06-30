
#include <iostream>
#include <fstream>
using namespace std;

struct fruit{
    string name;
    int Weight;
    int price;
};
//*****************************************************************
class Mrkt
{
    private :
    fruit Arr[8];
    int number;
public:
    Mrkt(string filename);
    int Get_number();
    int Sum();
    string Max();

    
    };
//*****************************************************************
int main() {
    string F = "fruits.txt";
    Mrkt Market(F);
    cout << "The numberers" << Market.Get_number()<<endl;
    cout<<"The max is "<< Market.Max()<<endl;
    cout<<"The Sum weight is "<< Market.Sum()<<endl;
    
    
}

//*****************************************************************
Mrkt::Mrkt(string filename)
{
    ifstream file(filename);
    number = 0;
    string fline;
    if (file.fail()) { cout << "Error"; system("PAUSE");}
    getline(file,fline);
        while (!file.eof()) {
            file>>Arr[number].name;
            file>>Arr[number].Weight;
            file>>Arr[number].price;
            number++;
        }
        file.close();
    }

int Mrkt::Get_number(){
    return number;
}
int Mrkt::Sum(){
    
    int s=0;
    for(int i=0;i<number;i++)
    {
        s=Arr[i].Weight+s;
    }
    
    return s;
}
string Mrkt::Max(){
    int max=0;
    for(int i =1;i<number;i++)
    {
        if(Arr[max].price<Arr[i].price)
            max=i;
    }
    return Arr[max].name;
}
