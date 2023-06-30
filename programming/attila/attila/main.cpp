
#include <iostream>
#include <ctime>
#include<math.h>
//************************************************************************
using namespace std;
//************************************************************************
bool is_Not_Allocate(int *arr);
void Displaay(int *arr,int taille);
int count_Prime(int *arr,int size);
bool isPrime(int );
int sum_square_prime(int *arr,int taille);
//************************************************************************
int main(int argc, const char * argv[]) {
    srand((unsigned int)time(NULL));

    int *tab;
    int size;
    cout<<" How many number u need \n";
    cin>>size;
    tab=(int*)malloc(sizeof(int)*size);
    if(size<=100)
    for(int i=0; i<size;i++)
    {
        tab[i]=(rand()%499)+2;
    }
//    for (int i = size - 1; i > 0; i--) {
//            // Generate a random index between 0 and i (inclusive)
//            int j = rand() % (i + 1);
//
//            // Swap the elements at indices i and j
//            int temp = tab[i];
//            tab[i] = tab[j];
//            tab[j] = temp;
//        }
    Displaay(tab, size);
    cout<<"Prime Part "<<endl;
    for(int j =0; j<size;j++){
        if (isPrime(tab[j])) {
            cout<<"ARRAY[ "<<j+1<<" ] = "<< tab[j]<<endl;
        }
    }
    
    cout<<"And the sum of the squares of the primes is "<< sum_square_prime(tab,size)<<endl;
    free(tab);
    return 0;
}
//************************************************************************
bool is_Not_Allocate(int *arr){
    if(arr==NULL)
        return true;
    else return false;
}
//************************************************************************
void Displaay(int *arr,int taille)
{
    if(is_Not_Allocate(arr))
        {
            cout<<"ARRAY Not ALLOCATED -_-\n";
        exit(-1);
        }
    else{
        for(int a = 0;a<taille;a++){
            cout<<"ARRAY[ "<<a+1<<" ] = "<< arr[a]<<endl;
        }
    }
    return;
}
//************************************************************************
bool isPrime(int num) {
    if (num <= 1) {
        return false;
    }
    // Check for divisibility from 2 to sqrt(num)
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false;
        }//number/2
    }

    return true;
}
//************************************************************************
int count_Prime(int *arr,int size)
{
    int cnt=0;
    for(int i =0 ;i<size;i++)
    {
        if(isPrime(arr[i]))
            cnt++;
    }
    return cnt;
}
//************************************************************************
int sum_square_prime(int *arr,int taille)
{
    int pow=0,sum=0;
    for(int i=0 ; i<taille;i++)
    {
        if(isPrime(arr[i])){
            pow=powf(arr[i], 2);
            sum+=pow;
        }
    }
    return sum;
}
