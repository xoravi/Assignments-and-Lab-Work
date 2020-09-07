#include<iostream>
using namespace std;
int ma=9;
int q[9];
int front=-1;
int rear=-1;
void insrt(int val)
{	if(front==(rear+1)%ma)
		cout<<"\nOVERFLOW";
	else
	{
		rear=(rear+1)%ma;
		q[rear]=val;
	}
}
void delte()
{	if(front==rear)
		cout<<"\nUNDERFLOW";
	else
	{	front=(front+1)%ma;
	}
}
void prnt()
{	int i=front+1;
	while(i!=(rear+1)%ma)
	{	cout<<q[i]<<"\t";
		i=(i+1)%ma;
	}
	
}
int main()
{
	for(int i=0;i<8;i++)
		insrt(i);
	for(int i=0;i<6;i++)
		delte();
	for(int i=0;i<6;i++)
		insrt(i);	
	prnt();
}
