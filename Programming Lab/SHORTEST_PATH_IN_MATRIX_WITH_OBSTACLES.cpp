//SHORTEST PATH IN MATRIX WITH OBSTACLES
#include<iostream>
#include<time.h>
#include<stdlib.h>
using namespace std;
int ma=100;
struct cor
{	int x,y;
};
cor q2[100];
int front2=-1;
int rear2=-1;
void insrt2(cor c)
{	if(front2==(rear2+1)%ma)
		cout<<"\nQ OVERFLOW";
	else
	{	rear2=(rear2+1)%ma;
		q2[rear2]=c;
	}
}
cor delte2()
{	if(front2==rear2)
	{	cor c;c.x=-1;c.y=-1;
		return c;
	}
	else
	{	front2=(front2+1)%ma;
		cor c;
		c=q2[front2];
		
		return c;
	}
}
cor s[100];
int top=-1;
void push(cor c)
{	if(top==ma-1)
		cout<<"\nStack OVERFLOW";
	else
	{	top++;
		s[top]=c;
	}
}
cor pop()
{	cor c;
	if(top==-1)
	{	cout<<"\nStack UNDERFLOW";
		c.x=-1;c.y=-1;return c;
	}
	else
	{	c=s[top];
		top--;
		return c;
	}
}
int main()
{	int n,strtx,strty,endx,endy,obn;
	cout<<"\nEnter the Size (n):\n";
	cin>>n;
	cout<<"\nEnter START coordinates:\n";
	cin>>strtx>>strty;
	cout<<"\nEnter END coordinates:\n";
	cin>>endx>>endy;
	if(strtx>=n||strty>=n||endx>=n||endy>=n)
	{	cout<<"\nWrong Input";
		return 0;
	}
	cor c;
	c.x=strtx;c.y=strty;
	int a[n][n];
	for(int i=0;i<n;i++)
	{	for(int j=0;j<n;j++)
			a[i][j]=0;
	}
	a[c.x][c.y]=1;
	insrt2(c);
	cout<<"\nEnter no. of Obstacles:\n";
	cin>>obn;
	srand(time(0));
	for(int i=0;i<obn;i++)
	{	int x=rand()%n;
		int y=rand()%n;
		if(a[x][y]==-1||(x==strtx&&y==strty)||(x==endx&&y==endy))
			i--;
		else
			a[x][y]=-1;		
	}
	cout<<"\nMatrix is:\n";
	for(int i=0;i<n;i++)
	{	cout<<endl<<"[\t";
		for(int j=0;j<n;j++)
		{	if(i==strtx&&j==strty)
				cout<<"S\t";
			else if(i==endx&&j==endy)
				cout<<"E\t";
			else
				cout<<a[i][j]<<'\t';
		}
		cout<<"]";
	}
	c=delte2();
	while(c.x!=-1)
	{	if(c.x==endx&&c.y==endy)
			break;
		if(c.y<n-1&&a[c.x][c.y+1]==0)
		{	a[c.x][c.y+1]=a[c.x][c.y]+1;
			cor c2;
			c2.x=c.x; c2.y=c.y+1;
			insrt2(c2);
		}
		if(c.x<n-1&&a[c.x+1][c.y]==0)
		{	a[c.x+1][c.y]=a[c.x][c.y]+1;
			cor c2;
			c2.x=c.x+1; c2.y=c.y;
			insrt2(c2);
		}
		if(c.y>0&&a[c.x][c.y-1]==0)
		{	a[c.x][c.y-1]=a[c.x][c.y]+1;
			cor c2;
			c2.x=c.x; c2.y=c.y-1;
			insrt2(c2);
		}
		if(c.x>0&&a[c.x-1][c.y]==0)
		{	a[c.x-1][c.y]=a[c.x][c.y]+1;
			cor c2;
			c2.x=c.x-1; c2.y=c.y;
			insrt2(c2);
		}
		c=delte2();
	}
	cout<<"\n\nDetermining Path:\n";
	for(int i=0;i<n;i++)
	{	cout<<endl<<"[\t";
		for(int j=0;j<n;j++)
			cout<<a[i][j]<<'\t';
		cout<<"]";
	}
	if(a[endx][endy]!=0)
		cout<<"\n\nShortest Distance: "<<a[endx][endy]-1<<endl;
	else
	{	cout<<"\nNo Path Possible\n";
		return 0;
	}
	int check=0;
	c.x=endx;c.y=endy;
	int val=a[endx][endy];
	rear2=front2;
	while(1)
	{	rec:
		check=0;
		if(a[c.x][c.y]==1)
			break;
		if(a[c.x-1][c.y]==val-1&&a[c.x-1][c.y]!=-1&&c.x>0)
		{	a[c.x][c.y]='#';
			push(c);
			c.x--;val--;check=1;
			goto rec;
		}
		if(a[c.x][c.y-1]==val-1&&a[c.x][c.y-1]!=-1&&c.y>0)
		{	a[c.x][c.y]='#';
			push(c);
			c.y--;val--;check=1;
			goto rec;
		}
		if(a[c.x+1][c.y]==val-1&&a[c.x+1][c.y]!=-1&&c.x<n-1)
		{	a[c.x][c.y]='#';
			push(c);
			c.x++;val--;check=1;
			goto rec;
		}
		if(a[c.x][c.y+1]==val-1&&a[c.x][c.y+1]!=-1&&c.y<n-1)
		{	a[c.x][c.y]='#';
			push(c);
			c.y++;val--;check=1;
			goto rec;
		}
		if(check==0)
		{	a[c.x][c.y]=-1;
			cor c=pop();
			//c.x++;
			goto rec;
		}
	}
	cout<<"\nShortest Path: ";
	while(top!=-1)
	{	cor cp;
		cp=pop();
		cout<<"("<<cp.x<<","<<cp.y<<")"<<" ";
	}
	cout<<"\n\nPath is: (shown in #)\n";
	for(int i=0;i<n;i++)
	{	cout<<endl<<"[\t";
		for(int j=0;j<n;j++)
		{	if(a[i][j]==-1)
			{	cout<<-1<<'\t';
				continue;
			}
			if(a[i][j]==1)
			{	cout<<'S'<<'\t';
				continue;
			}
			if(i==endx&&j==endy)
			{	cout<<'E'<<'\t';continue;
			}
			if(a[i][j]!=(int)'#')
			{	cout<<" "<<'\t';continue;
			}
			else
				cout<<(char)a[i][j]<<'\t';
		}	
		cout<<"]";
	}
}

