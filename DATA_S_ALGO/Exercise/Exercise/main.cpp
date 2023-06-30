#include <iostream>
#include <fstream>
#include <ctime>
using namespace std;
struct Student {
    string first_name;
    int F_sGrade;
    int S_sGrade;

 
};

void display_Student(Student s);
double First_S_Average(Student* s, int c);
double Sec_S_Average(Student* s, int c);

 

 

int main(int argc, const char* argv[]) {
    srand((unsigned int)time(NULL));
    cout << "Hey how many student you wanna enter but not more than 12" << endl;
    int size;
    cin >> size;
    Student* s = new Student[size];
    if (size > 12) {
        cout << "The maximum element is 12 " << endl;
        exit(-1);

 

    }

 

    for (int i = 0; i < size; i++) {
        cout << "\n- Student " << i + 1 << " First name" << endl;
        cin >> s[i].first_name;
        s[i].F_sGrade = (rand() % 5) + 1;
        s[i].S_sGrade = (rand() % 5) + 1;
    }

 

    for (int i = 0; i < size; i++) {
        display_Student(s[i]);
    }

 

 

    //how many student in this groupe

 

    cout << " \n - In this group we have " << size << " student" << endl;

 

    //average

 

    cout << " \n - The first semester average is " << First_S_Average(s,size) << endl;

 

    double avrF = First_S_Average(s, size), avrS = Sec_S_Average(s, size);

 

    if (avrF > avrS)
        cout << "\n - The first semester was better" << endl;
    else if (avrS > avrF) { cout << "\n - The Second semester was better" << endl; }
    else cout << "\n - The Second and the First semesters was better" << endl;

 


    //File managing part
    ofstream file;
    file.open("example.txt");
    file << "Dynamic array values :" << endl;
    for (int i = 0; i < size; i++)
    {
        file << " - Student : " << i + 1 << endl;
        file << " - Student First Name : " << s[i].first_name << endl;
        file<<  " - Student First Semester Grade : " << s[i].F_sGrade << endl;
        file << " - Student Second Semester Grade : " << s[i].S_sGrade << endl;
    }
    file.close();
    delete[] s;

 

    return 0;

 

}

 

 

void display_Student(Student s) {

 

    cout << " \n - Student First Name ==>" << s.first_name << endl;
    cout << " - Student First Semester Grade ==>" << s.F_sGrade << endl;
    cout << " - Student Second Semester Grade ==>" << s.S_sGrade << endl;

 

}

 

 

double First_S_Average(Student *s, int c) {

 

    int sumF = 0;
    for (int i = 0; i < c; i++) {
        sumF += s[i].F_sGrade;
    }
    double avr = double(sumF) / c;
    return avr;

 

}

 

 

//Write the semester in which the group's academic result was better.

 

double Sec_S_Average(Student* s, int c) {

 

    int sumF = 0;
    for (int i = 0; i < c; i++) {
        sumF += s[i].S_sGrade;
    }

 

    double avr = double(sumF) / c;
    return avr;

 

}
