#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct jump{
    string name;
    int Lng_jump;
    int Team_num;
};


int main(int argc, const char * argv[]) {
    
    
    jump Jump[12];
    
    
        
    
    ifstream output("jumps.txt");
    int N_jp=0;
    if (output.is_open()) {
        while (!output.eof() && N_jp < 12) {
             getline(output, Jump[N_jp].name, ' ');
             output >> Jump[N_jp].Lng_jump;
            output >> Jump[N_jp].Team_num;
             output.ignore();
             
             N_jp++;
           }
    }
    for(int i =0 ; i<12;i++){
        cout<<Jump[i].name<<"\t"<<Jump[i].Lng_jump<<"\t"<<Jump[i].Team_num<<endl;
    }
        
        
        output.close();
    
    
    int avr=0;
    for(int i=0;i<12;i++){
        avr+=Jump[i].Lng_jump;
    }
    avr/=12;
    cout<<"The average of the longest jumps is :"<<avr<<endl;
    
    
    
    int max=0;
    for (int i=1;i<12; i++) {
        if ( Jump[i].Lng_jump > Jump[max].Lng_jump ) {
            max = i;
        }
    }
    cout<<"Then "<<Jump[max].name<<" has the longest jump :"<<Jump[max].Lng_jump<<endl;
    
    
    int cmp=0;
    for(int i =0 ; i<12;i++)
    {
        if(Jump[i].Lng_jump==0) cmp++;
    }
    if (cmp==0) cout<<"No one reach the 0 as a result"<<endl;
    else cout<<cmp<<" Reach the 0 as a result"<<endl;
    
    
    
    int min=0;
    for (int i=1;i<12; i++) {
        if ( Jump[i].Lng_jump < Jump[min].Lng_jump ) {
            min = i;
        }
    }
    cout<<"Then "<<Jump[min].name<<" has the shortest jump :"<<Jump[min].Lng_jump<<endl;
    
    
    ofstream input;
    
    input.open("average.txt");
    
    if (input.is_open()) {
        input<<" The average of the jumps of long jumpers "<<avr<<endl;
    }
    input.close();
    
    
    return 0;
}
