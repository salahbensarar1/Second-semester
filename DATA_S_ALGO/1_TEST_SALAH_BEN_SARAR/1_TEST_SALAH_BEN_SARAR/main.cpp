//
//  main.cpp
//  1_TEST_SALAH_BEN_SARAR
//
//  Created by Salah Ben Sarar on 12/4/2023.
//

#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
using namespace std;

struct Student{

    string name;
    int scholarship;
    int prog;
    int algo;
    
};

void display_student(Student s);

int main(int argc, const char * argv[]) {
    srand((unsigned int)time(NULL));
    cout<<"how many student you wanna enter but less than 15"<<endl;
    int size;
    cin>>size;
    Student s[size];
    if(size<=15){
        for(int i =0;i<size;i++){
            cout<<"Student "<<i+1<<endl;
            cout<<"Name : \t";
            cin>>s[i].name;
            cout<<"Scholarship : \t";
            cin>>s[i].scholarship;
            s[i].prog=(rand() % 90) + 5;
            s[i].algo=(rand() % 100) + 0;
        }
       
        for(int i =0 ; i<size;i++){
            cout<<"\nStudent "<<i+1<<endl;
            display_student(s[i]);}
        
        int avrg_P=0,avrg_A=0;
        for(int i=0;i<size;i++){
            avrg_P+=s[i].prog;
            avrg_A+=s[i].algo;
        }
        if (avrg_P>avrg_A)
            cout<<"Programming has a better average"<<endl;
        else if (avrg_P<avrg_A)
            cout<<"Algorithme has a better average"<<endl;
        else cout<<"Programming and Algorithme has the same average"<<endl;
        
        int min=0;
        for(int i =1; i<size;i++)
        {
            if (s[i].scholarship<s[min].scholarship)
                min=i;
            
        }
        cout<<"The student : "<<s[min].name<<" has the fewest scholarshipe :"<<s[min].scholarship<<endl;
        
        
        int count = 0;
        while (count<size && s[count].algo!=100)
            count++;
        if(count<size) cout<<"Yes there is a 100-point test from Algorithme"<<endl;
        else if(count == size) cout<<"No there is no 100-point test from Algorithme"<<endl;
        
        int cmp=0; //The 7th
        for(int i = 0;i<size;i++ ){
            if((s[i].prog < 50) && (s[i].algo<50))
                cmp++;
        }
        
        if(cmp == 0) cout<<"None below 50%"<<endl;
        else if (cmp>0) cout<< cmp <<" are below 50%"<<endl;
        
        ofstream file;
        file.open("best.txt");
        Student newS;
        if (file.is_open()) {
            
            
            
            for(int i=0;i<size-1;i++)
            {
                for(int j=i+1;j<size;j++)
                {
                    
                    if(s[i].algo+s[i].prog<s[j].algo+s[j].prog)
                    {
                        
                        newS = s[i];
                        s[i] = s[j];
                        s[j] = newS;}}
                file<<newS.name<<"\t"<<(newS.algo)+(newS.prog)<<endl;
                
            }
            file.close();
         
        }
        
        
    }
    else exit(-1);//system("pause");
    
    //(rand() % 5) + 1
    return 0;
}

void display_student(Student s){
    
    cout<<"Name : "<< s.name <<endl;
    cout<<"Scholarship : "<< s.scholarship <<endl;
    cout<<"Prog : "<< s.prog <<endl;
    cout<<"Algo : "<< s.algo <<endl;
    
    
    
    return;
}
