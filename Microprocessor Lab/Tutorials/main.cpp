//Compilation process 
//Subroutine call  from main.cpp to source.asm file 

// g++ -g -Wall -c main.cpp
// yasm -g dwarf2 -f elf64 source.asm -l source.lst
// g++ -g -no-pie -o main main.o source.o
// ./main

#include<iostream>
using namespace std;
extern "C" void stats(int[],int ,int*);


int main()
{
int arr[4];
int len;
len=4;
int sum=0;
cout<<"Enter the four number's a, b, c and d respectively "<<endl;
for(int i=0;i<len;i++)
{
   cin>>arr[i];
}
stats(arr,len,&sum);
cout<<"the result of a+b+c-d is : "<<sum<<endl;
return 0;
}
