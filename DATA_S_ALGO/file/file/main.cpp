#include <iostream>
#include <fstream>
using namespace std;

int main(void){

ofstream file;
file.open("tuna.txt");
if(file.is_open())
{
   file << "I love tuna and tuna loves me!\n";
    file.close();
}
else
   cout<< "No file has been created!\n";

  return 0;
}
