#include <iostream>
#include <fstream>
using namespace std;
//************************************************************************************
struct lottery {
    int weekD;
    int Fv_wins;
    int Fr_wins;
    int Th_wins;
    int numbers[6];
};
//************************************************************************************
void displayArr(lottery *array, int size);
void Search_Lott_numb(lottery *array,int size,int lott_number);
int Count_ODD(lottery *array,int size);
int Count_Even(lottery *array,int size);
void sortarray(lottery* array, int size);
//************************************************************************************
int main() {
    salah:cout<<"how many elements you want from the file "<<endl;
    int size;
    cin>>size;
    lottery *array= new lottery[size];
    string line;
    string filename = "lottery.txt";
    ifstream input(filename);
    if(size<52)
        if(input.is_open())
    for(int i = 0 ; i<size ; i++)
    {
//        getline(input,line,' ');
        
        input >> array[i].weekD;
        input >> array[i].Fv_wins ;
        input >> array[i].Fr_wins;
        input >>array[i].Th_wins;
        for (int j = 0; j < 6; j++) {
            input >> array[i].numbers[j];
               
        }
//        input.ignore();
    }
    input.close();
    displayArr(array, size);
//    bool check=false;
    int lottery_Number;
    cout<<" can you enter the lottery number (1-90)"<< endl;
    cin>>lottery_Number;
    if ( lottery_Number >= 1 && lottery_Number <= 90 )
    {
        Search_Lott_numb(array, size, lottery_Number);
    }
    else{
        cout <<"You entred a value not in (1-90)"<<endl;
        cout <<"if u wanna repeat the program press 1"<<endl;
        int gt;
        cin>>gt;
        if (gt==1)
            goto salah;
        exit(-1);
        
    }
    
//Have odd or even numbers been drawn more than once?
    if(Count_ODD(array, size)>2 || Count_Even(array, size)>2)
        cout << "Odd or even numbers have been drawn more than once." << endl;
    else  cout << "Odd or even numbers have not been drawn more than once." << endl;
    
    sortarray(array, size);
    
    int max_winnings = 0;
        ofstream outfile("besttwomatches.txt");

        for (int i = 0; i < 3; i++) {
            int sum = array[i].Fv_wins + array[i].Fr_wins;
            if (sum > max_winnings) {
                max_winnings = sum;
            }

            cout << "Week of draw: " << array[i].weekD << ", Winnings: " << sum <<" HUF "<< endl;
            outfile << "Week of draw: " << array[i].weekD << ", Winnings: " << sum << " HUF "<<endl;
        }
    delete[] array;

    return 0;
}

//************************************************************************************
void displayArr(lottery *array, int size){
    if (array)
    for (int i = 0; i < size; i++) {
           cout << array[i].weekD << " " << array[i].Fv_wins << " " << array[i].Fr_wins << " " << array[i].Th_wins << " ";
           for (int j = 0; j < 6; j++) {
               cout << array[i].numbers[j] << " ";
           }
           cout << endl;
       }
    else {cout<<"No allocation founded -_- \n"; exit(-1);}
    
}

//************************************************************************************
void Search_Lott_numb(lottery *array,int size,int lott_number){
    bool check=false;
    if (array)
        for(int i = 0 ; i < size ; i++)
        {
            for(int j = 0 ; j < 6;j++)
            {
                if (array[i].numbers[j]==lott_number) {
                    check = true;
                    cout<<" The " <<array[i].weekD << "  it was drawn " <<endl;
                }
            }
        }
    if (!check)
        cout << "The number " << lott_number << " was not drawn in any of the 5 weeks.\n";
    
    
    
    return ;
}
//************************************************************************************
int Count_ODD(lottery *array,int size){
    int oddCount = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < 6; j++)
            if (array[i].numbers[j] % 2 != 0)
                oddCount++;
    return oddCount;
}
//************************************************************************************
int Count_Even(lottery *array,int size){
    int evenCount = 0;
    for (int i = 0; i < size; i++)
        for (int j = 0; j < 6; j++)
            if (array[i].numbers[j] % 2 == 0)
                evenCount++;
    return evenCount;
}
//************************************************************************************
void sortarray(lottery* array, int size) {
    // Sort the array by winnings
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (array[j].Fv_wins < array[j+1].Fv_wins) {
                lottery temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
//************************************************************************************
