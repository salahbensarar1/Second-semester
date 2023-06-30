
#include <iostream>
#include <fstream>
#include <ctime>
#include <iomanip>
using namespace std;
struct lottery
{
    int week, price[4], num[5];
};

int main(int argc, const char * argv[]) {
    const int wcount = 52;
    lottery lotto[wcount];
    int i=0, j=0;
    ifstream in("lottery.txt");
    if(in.fail()) {cerr<<"error";exit(1);}
    cout << "\n Lotteries in 2022" << endl;
    while (!in.eof())
    {
        in >> lotto[i].week;
        for(j=0;j<4;j++)
            in >> lotto[i].price[j];
        for(j=0;j<5;j++)
            in >> lotto[i].num[j];
        cout << setw(3) << lotto[i].week << setw(12) << lotto[i].price[0] << setw(8) << lotto[i].price[1] << setw(6) << lotto[i].price[2] << setw(5) << lotto[i].price[3];
        for(j=0;j<5;j++)
            cout << setw(3) << lotto[i].num[j];
        cout << endl;
        i++;
     }
    in.close();
    
    //search by lottery number
    int lottery_Number;
    cout<<" can you enter the lottery number (1-90)"<< endl;
    cin>>lottery_Number;
    if ( lottery_Number >= 1 && lottery_Number <= 90 )
    {
        bool check=false;
            for(int i = 0 ; i < wcount ; i++)
            {
                for(int j = 0 ; j < 5;j++)
                {
                    if (lotto[i].num[j]==lottery_Number) {
                        check = true;
                        cout<<" The " <<lotto[i].week << "  it was drawn " <<endl;
                    }
                }
            }
        if (!check)
            cout << "The number " << lottery_Number << " was not drawn in any of the 5 weeks.\n";
    }
    
    //Odd Even numbers part
    int oddCount = 0;
    int evenCount = 0;
    for (int i = 0; i < wcount; i++)
        for (int j = 0; j < 6; j++)
            if (lotto[i].num[j] % 2 != 0)
                oddCount++;
            else evenCount++;
    if(evenCount>2 || oddCount>2)
        cout << "Odd or even numbers have been drawn more than once." << endl;
    else  cout << "Odd or even numbers have not been drawn more than once." << endl;
    
    // Sort the lotto by winnings
    for (int i = 0; i < wcount; i++) {
            for (int j = i+1; j < wcount; j++) {
                int sum_i = lotto[i].price[0] + lotto[i].price[1] + lotto[i].price[2] + lotto[i].price[3];
                int sum_j = lotto[j].price[0] + lotto[j].price[1] + lotto[j].price[2] + lotto[j].price[3];
                if (sum_i < sum_j) {
                    lottery temp = lotto[i];
                    lotto[i] = lotto[j];
                    lotto[j] = temp;
                }
            }
        }
    // Find the three highest paying two matches and write their details to a file
    int max_winnings = 0;
    ofstream outfile("besttwomatches.txt");

    for (int i = 0; i < wcount; i++) {
        for (int j = i+1; j < wcount; j++) {
            int sum = lotto[i].price[1] + lotto[j].price[1];
            if (sum > max_winnings) {
                max_winnings = sum;
            }
        }
    }

    // Print the three highest paying two matches to the console and write them to a file
    int count = 0;
    for (int i = 0; i < wcount; i++) {
        for (int j = i+1; j < wcount; j++) {
            int sum = lotto[i].price[1] + lotto[j].price[1];
            if (sum == max_winnings && count < 3) {
                cout << "Week of draw: " << lotto[i].week << ", " << lotto[j].week << endl;
                cout << "Winnings: $" << sum << endl;

                outfile << "Week of draw: " << lotto[i].week << ", " << lotto[j].week << endl;
                outfile << "Winnings: $" << sum << endl;
                count++;
            }
        }
    }

    cout << endl;
    return 0;
}

