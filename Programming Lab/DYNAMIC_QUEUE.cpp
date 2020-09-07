#include<iostream>
#include<malloc.h>
using namespace std;
struct node
{	int data;
	node *next;
};
struct queue
{	node *front, *rear;
};
queue* insrt(queue *q,int val)
{	node *new_node=(node*)malloc(sizeof(node));
	new_node->data=val;
	if(q->front==NULL)
	{	q->front=new_node;
		q->rear=new_node;
	}
	else
	{	q->rear->next=new_node;
		q->rear=new_node;
	}
	new_node->next=NULL;
	return q;
}
queue* delte(queue *q)
{	if(q->front==NULL)
		cout<<"\nUNDERFLOW >:( ";
	else
	{	node *ptr=q->front;
		q->front=ptr->next;
		free(ptr);
	}
	return q;
}
void prnt(queue*q)
{	node *ptr=q->front;
	if(ptr==NULL)
		cout<<"EMPTY";
	else
	{	while(ptr->next!=NULL)
		{	cout<<"\t"<<ptr->data;
			ptr=ptr->next;
		}
	}
}
int main()
{	queue *q;
	q=(queue*)malloc(sizeof(queue));
	q->front=NULL;q->rear=NULL;
	for(int i=0;i<5;i++)
		q=insrt(q,i);
	prnt(q);
	for(int i=0;i<6;i++)
		q=delte(q);
	cout<<"\n";
	prnt(q);
}
