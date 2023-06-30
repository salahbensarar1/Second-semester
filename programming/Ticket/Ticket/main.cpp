#include <iostream>
#include <fstream>

using namespace std;

struct line{
    string res,cat;
};
static const int lines= 15;
static  const int seats= 20;

bool Free_seat(line *array,int line , int seat);
void is_NotAll(line *array,int size);
int Count_sold(line *array,int size);
float porcentage(line *array,int size);

int main(int argc, const char * argv[]) {
    
    line *Array = (line*) malloc(sizeof(line)*15);
    
    ifstream inp1("reservations.txt");
    if(inp1.fail()) {cerr<<"ERROR 1 -_-"; exit(-1);}
    ifstream inp2("category.txt");
    if(inp2.fail()) {cerr<<"ERROR 2 -_-"; exit(-1);}
    cout <<" Datas "<<endl;
    cout <<"\nReservations"<<setw(30)<<" category "<<endl;
    for(int i =0 ; i<lines ; i++)
    {
        inp1>>(Array+i)->res;
        inp2>>(Array+i)->cat;
        
        cout<<(Array+i)->res<<setw(30)<<(Array+i)->cat<<endl;
    }
    inp1.close();
    inp2.close();
    //free or solded by user's seat
    int l,s;
    do {
        cout<<"Line ?"<<endl;
        cin>>l;
    } while (l<1 || l>lines);
    do {
        cout<<"Seats ?"<<endl;
        cin>>s;
    } while (s<1 || l>seats);
    if(Free_seat(Array, l, s)) cout<<" Free " <<endl;
    if(!(Free_seat(Array, l, s))) cout<<" Sold " <<endl;
    
    //Number of ticket are sold
    cout<< Count_sold(Array, lines) <<" Tickets are sold and these are the "<< porcentage(Array, lines)<<" % of all seats."<<endl;
    
    
    free(Array);
    
    
    return 0;
}


//free or solded by user's seat

bool Free_seat(line *array,int line , int seat)
{
    if((array+line-1)->res[seat-1]=='o')
        return true;
    else return false;
}

//Number of ticket are sold
void is_NotAll(line *array,int size){
    if (!array)
        {
            cout<<" No allocation -_-"<<endl;
            exit(-1);
        }
}
int Count_sold(line *array,int size)
{
    int count=0;
    is_NotAll(array,size);
    for(int i =0; i<lines ; i++){
        for(int j =0; j<seats;j++)
        {
            if((array+i)->res[j]== 'x')
                count++;
        }
    }
    return  count;
}

float porcentage(line *array,int size)
{
    return float(Count_sold(array, size))/(lines*seats)*100;
}
