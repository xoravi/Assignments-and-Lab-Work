//Name: Ravi Sahni
//Faculty No.: 17 COB 085
//Enrol. No.: GJ 7718
//Serial No.: 24
//Objective: Compute a+b+c-d where a,b,c and d are integers. Take the integer inputs in a C/C++ program and perform the required operation in a subroutine in assembly language.

//Compilation Instructions (Ubuntu):
// $ nasm -felf64 func.asm
// $ g++ -c main.cpp
// $ g++ -o outfile func.o main.o
// $ ./outfile

#include <iostream>
extern "C" int sum_sub(int a, int b, int c, int d);
using namespace std;

int main()
{	
	int a,b,c,d;
	cout<<"\n Enter the values:\n a: ";
	cin>>a;
	cout<<" b: ";
	cin>>b;
	cout<<" c: ";
	cin>>c;
	cout<<" d: ";
	cin>>d;
	cout<<"\n a+b+c-d = "<<sum_sub(a,b,c,d)<<endl;
	return 0;
}
