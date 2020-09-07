//Program to sort a Linked List without data swaping
#include<iostream>
#include<stdlib.h>                          //Required Header Files
using namespace std;
struct node                                 //Structure "node" definition
{	int data;
	node *next;
}*head,*a,*b,*temp,*prv;                    //Creation of required node pointers
int main()                                  //main() body
{	int n,i;
	cout<<"\nEnter the number of Elements: ";
	cin>>n;
	head = (node*)malloc(sizeof(node));     //Allocating memory in heap
	head->next=NULL;
	a=head;
	for(i=0;i<n;i++)                        //Creation and Input of Data in Linked List
	{	a->next = (node*)malloc(sizeof(node));
		a=a->next;
		cout<<"\nEnter Element "<<i+1<<": ";
		cin>>a->data;
		a->next=NULL;
	}
	a = head->next;
	cout<<"\n\n\nEntered Linked List: ";
	while(a)                                //Printing of Linked List
	{	cout<<a->data<<"   ";
		a=a->next;
	}
	for(i=0;i<n-1;i++)                      //Sorting of Data in Linked List
	{	for(prv=head,a=head->next;a->next!=NULL;a=a->next,prv=prv->next)
		{	b=a->next;
			if((a->data>b->data))
			{
				prv->next=b;
				temp=b->next;
				a->next=temp;
				b->next=a;
				a=b;
			}
		}
	}

	a = head->next;
	cout<<"\n\nSorted Linked List: ";
	while(a)                                //Printing of Sorted Linked List
	{	cout<<a->data<<"   ";
		a=a->next;
	}
	cout<<"\n\n";
    return 0;
}
