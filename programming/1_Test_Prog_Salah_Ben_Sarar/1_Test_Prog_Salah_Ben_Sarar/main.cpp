//
//  main.cpp
//  1_Test_Prog_Salah_Ben_Sarar
//
//  Created by Salah Ben Sarar on 12/4/2023.
//

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct jump{
    string name;
    int L_jump;
    int T_num;
};


int main(int argc, const char * argv[]) {
    
    
    jump *J = new jump[12];
    
    
        
    
    ifstream file("jumps.txt");
    int num_jump=0;
    if (file.is_open()) {
        while (!file.eof() && num_jump < 12) {
             getline(file, J[num_jump].name, ' ');
             file >> J[num_jump].L_jump;
            file >> J[num_jump].T_num;
             file.ignore();
             
             ++num_jump;
           }
    }
    for(int i =0 ; i<12;i++){
        cout<<(J+i)->name<<"\t"<<(J+i)->L_jump<<"\t"<<(J+i)->T_num<<endl;
    }
        
        
        file.close();
    
    //2- average of jumps
    int avr=0;
    for(int i=0;i<12;i++){
        avr+=(J+i)->L_jump;
    }
    avr/=12;
    cout<<"\nThe average of the longest jumps is :"<<avr<<endl;
    
    //3-longest jump
    
    int max=0;
    
    for (int i=1;i<12; i++) {
        if ( (J+i)->L_jump > (J+max)->L_jump ) {
            max = i;
        }
    }
    cout<<"Then "<<(J+max)->name<<" has the longest jump :"<<(J+max)->L_jump<<endl;
    
    //4- how many have reached 0 RESULT
    int cmp=0;
    for(int i =0 ; i<12;i++)
    {
        if((J+i)->L_jump==0) cmp++;
    }
    if (cmp==0) cout<<"No one reach the 0 as a result"<<endl;
    else cout<<cmp<<" Reach the 0 as a result"<<endl;
    
    //5-SHORTEST jump
    
    int min=0;
    for (int i=1;i<12; i++) {
        if ( (J+i)->L_jump < (J+min)->L_jump ) {
            min = i;
        }
    }
    cout<<"Then "<<(J+min)->name<<" has the shortest jump :"<<(J+min)->L_jump<<endl;
    
    //6-File handling
    ofstream fl;
    
    fl.open("average.txt");
    
    if (fl.is_open()) {
        fl<<" The average of the jumps of long jumpers is : "<<avr<<endl;
    }
    fl.close();
    
    delete []J;
    return 0;
}
