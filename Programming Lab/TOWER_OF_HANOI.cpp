//Program to solve Tower Of Hanoi using Stacks
#include<iostream>
#include<malloc.h>
#include<cmath>
using namespace std;
struct node
{	int data;
	node *next;
};
class stack
{		node *top = NULL;
		char stname;
		static char name;
	public:
		stack()
		{	stname=name;
			name++;
		}
		void push(int);
		int pop();
		void display();
		char putn()
		{	return stname;
		}
		int peek(){
			if(top == NULL) return -1;
			return top->data;
		}		
};
char stack :: name = 'A';
void stack :: push(int n)
{	node *new_node = (node*)malloc(sizeof(node));
	new_node->data = n;
	new_node->next = top;
	top = new_node;
}
int stack :: pop()
{	node *ptr = top;
	if(top==NULL)
	{	cout<<"\nUNDERFLOW ERORR!!";
		return -1;
	}
	else
	{	int pop_num = ptr->data;
		top = top->next;
		free(ptr);
		return pop_num;
	}
}
void stack :: display()
{	node *ptr=top;
	cout<<" Stack "<<putn()<<" ->";
	if(ptr==NULL)
		cout<<" EMPTY";
	else
	{	while(ptr!=NULL)
		{	cout<<" "<<ptr->data;
			ptr=ptr->next;
		}
	}
}
void hanoi(int n,stack &A, stack &B, stack &C)
{	cout<<"stacks state begining: "<<A.peek()<<"\t"<<B.peek()<<"\t"<<C.peek()<<endl;
	for(int i=1;i<pow(2,n);i++)
	{	
		if(i%3==1){
			if(n%2){
				if((C.peek()>A.peek() || C.peek()==-1) && A.peek()!=-1){
						cout<<"Moving from A to C"<<endl;
						C.push(A.pop());
					}
				else{
						A.push(C.pop());
						cout<<"Moving from C to A"<<endl;
				}
			}
			else{
				if((B.peek()>A.peek() || B.peek()==-1) && A.peek()!=-1)
					B.push(A.pop());
				else
					A.push(B.pop());
			}
			cout<<"Current Status: "<<A.peek()<<"\t"<<B.peek()<<"\t"<<C.peek()<<endl;
		}
		else if(i%3==2){
			if(n%2){
				if((B.peek()>A.peek() || B.peek()==-1) && A.peek()!=-1){
						cout<<"Moving from A to B"<<endl;
						B.push(A.pop());
					}
				else{
						A.push(B.pop());
						cout<<"Moving from B to A"<<endl;
				}
			}
			else{
				if((C.peek()>A.peek() || C.peek()==-1) && A.peek()!=-1){
						cout<<"Moving from A to C"<<endl;
						C.push(A.pop());
					}
				else{
						A.push(C.pop());
						cout<<"Moving from C to A"<<endl;
				}
			}
			cout<<"Current Status: "<<A.peek()<<"\t"<<B.peek()<<"\t"<<C.peek()<<endl;
		}
		else if(i%3==0){
			if((C.peek()>B.peek() || C.peek()==-1) && B.peek()!=-1){
				cout<<"Moving from B to C"<<endl;
				C.push(B.pop());
				cout<<"Current Status: "<<A.peek()<<"\t"<<B.peek()<<"\t"<<C.peek()<<endl;
			}
			else{
				cout<<"Moving from C to B"<<endl;
				B.push(C.pop());
				cout<<"Current Status:  "<<A.peek()<<"\t"<<B.peek()<<"\t"<<C.peek()<<endl;
			}
		}
	}
}	
int main()
{	stack a,b,c;
	int n;
	cout<<"\nEnter the number of Disks: \n";
	cin>>n;
	for(int i=n;i>=1;i--)
		a.push(i);
	hanoi(n,a,b,c);
}
