#include<iostream>
#include<math.h>
using namespace std;

int i=0,m,m1,m2;

class set
{
		int data[20];
	public:
		void input(int element,int index);
		void display(int size);
		int retdata(int index)
		{
			return data[index];
		}		
}U,A,B;

void set::input(int element,int index)
{
	data[index]=element;
}

void set::display(int size)
{	
	cout<<"{ ";
	for(i=0;i<size;i++)
	{	
		cout<<data[i]<<" ";
	}
	cout<<"}";
}

void input_set(set &x,int m1,set U1)
{	int n,check=0;
	cout<<"\nEnter elements:\n";
	for(i=0;i<m1;i++)
	{	
		cin>>n;
		for(int j=0;j<m;j++)
		{
			if(U1.retdata(j)==n)
			{
				check=1;
				U1.input(-1,j);
			}	
		}
		if(check==1)
		{
			check=0;
			x.input(n,i);
		}
		else
		{	
			cout<<"\n!!Enter Input from Universal Set!!\nPlease re-enter the last element\n";
			i--;
		}
	}	
}

void AND(set x, set y, int sizex, int sizey)
{	
	cout<<"\n\nA (AND) B: ";
	cout<<"{ ";
	for(i=0;i<sizex;i++)
	{	
		for(int j=0;j<sizey;j++)
		{
			if(x.retdata(i)==y.retdata(j))
				cout<<x.retdata(i)<<" ";
		}
	}
	cout<<"}\n";
}

void OR(set x, set y, int sizex, int sizey)
{	
	int check=0;
	cout<<"\n\nA (OR) B: ";
	cout<<"{ ";
	for(i=0;i<sizex;i++)
	{
		cout<<x.retdata(i)<<" ";
	}
	for(i=0;i<sizey;i++)
	{	check=0;
		for(int j=0;j<sizex;j++)
		{
			if(x.retdata(j)==y.retdata(i))
				check=1;
		}
		if(check==0)
			cout<<y.retdata(i)<<" ";
	}
	cout<<"}\n";
}

void subs(set y,set x,int sizey,int sizex)
{	
	cout<<"{ ";
	int check=0;
	for(i=0;i<sizey;i++)
	{	check=0;
		for(int j=0;j<sizex;j++)
		{	
			if(y.retdata(i)==x.retdata(j))
				check=1;
		}
		if(check==0)
			cout<<y.retdata(i)<<" ";
	}
	cout<<"}\n";
}

void powerset(set x, int size) 
{ 	cout<<"{ ";
    int p=pow(2,size); 
    int c,j; 
    for(c=0;c<p;c++) 
    {	cout<<"{ "; 
    	for(j=0;j<size;j++) 
       	{ 	
        	if(c&(1<<j)) 
          		cout<<x.retdata(j)<<" "; 
       	} 
       cout<<"}  "; 
    } 
    cout<<" }\n";
} 

void menu()
{	
	int c;
	system("cls");
	cout<<"\nUniversal Set: ";U.display(m);
	cout<<"\nSet A: ";A.display(m1);
	cout<<"\nSet B: ";B.display(m2);
	cout<<"\n\nSelect Operation: \n1. A (AND) B \n2. A (OR) B \n3. Compliment of A \n4. Compliment of B \n5. A - B \n6. B - A \n7. Power Set of A \n8. Power Set of B \n9. EXIT \n";
	cin>>c;
	switch(c)
	{	
		case 1:	AND(A,B,m1,m2);
				system("pause");
				menu();
		case 2: OR(A,B,m1,m2);
				system("pause");
				menu();
		case 3: cout<<"\n\nCompliment of A: ";
				subs(U,A,m,m1);
				system("pause");
				menu();
		case 4: cout<<"\n\nCompliment of B: ";
				subs(U,B,m,m2);
				system("pause");
				menu();
		case 5: cout<<"\n\nA - B: ";
				subs(A,B,m1,m2);
				system("pause");
				menu();
		case 6: cout<<"\n\nB - A: ";
				subs(B,A,m2,m1);
				system("pause");
				menu();
		case 7:	cout<<"\n\nPower Set of A: ";
				powerset(A,m1);
				system("pause");
				menu();
		case 8:	cout<<"\n\nPower Set of B: ";
				powerset(B,m2);
				system("pause");
				menu();
		case 9: exit(0);
		default:menu();
	}	
}

int main()
{	
	int n;
	set U1;
	cout<<"\nEnter the size of Universal Set(max 20): ";
	cin>>m;
	cout<<"\nEnter elements:\n";
	for(i=0;i<m;i++)
	{	
		cin>>n;
		U.input(n,i);
	}
	U1=U;
	cout<<"\nUniversal Set is: ";U.display(m);
	cout<<"\n\nEnter the size of Set A: ";
	while(cin>>m1)
	{	if(m1<=m)
			break;
		else
			cout<<"\nSize should be less than or equal to "<<m<<"\n";
	}
	input_set(A,m1,U1);
	cout<<"\nSet A is: ";A.display(m1);	
	cout<<"\n\nEnter the size of Set B: ";
	while(cin>>m2)
	{	if(m2<=m)
			break;
		else
			cout<<"\nSize should be less than or equal to "<<m<<"\n";
	}
	input_set(B,m2,U1);
	cout<<"\nSet B is: ";B.display(m2);	
	menu();
}
