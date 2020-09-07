#include<iostream>
using namespace std;
  
struct phil
{
	int left, right;
};

struct chop
{
	int picked;
};
 
int finished = 0;
  
void DPP(int philno, phil philosopher[], chop remainchop[],int n)
{
	if(philosopher[philno].left==100 && philosopher[philno].right==100)
        cout<<"Philosopher No."<<philno+1<<" completed the dinner\n";
	else if(philosopher[philno].left==1 && philosopher[philno].right==1)
	{
        cout<<"Philosopher No."<<philno+1<<" completed the dinner\n";
 		philosopher[philno].left = philosopher[philno].right = 100;
        int otherchop = philno-1;
        if(otherchop== -1)
            otherchop=(n-1);
        remainchop[philno].picked = remainchop[otherchop].picked = 0;
        cout<<"Philosopher No."<<philno+1<<" released chopstick "<<philno+1<<" and "<<otherchop+1<<"\n";
        finished++;
    }
    else if(philosopher[philno].left==1 && philosopher[philno].right==0)
	{
        if(philno==(n-1))
		{
            if(remainchop[philno].picked==0)
			{
                cout<<"Philosopher No. "<<philno+1<<" took chopstick "<<philno+1<<"\n";
                remainchop[philno].picked = philosopher[philno].right = 1;
            }
			else
                cout<<"Philosopher No. "<<philno+1<<" is waithing for chopstick "<<philno+1<<"\n";
        }
		else
		{
            int temp = philno;
            philno--; 
            if(philno==-1)
                philno=(n-1);
 			if(remainchop[philno].picked==0)
			{
                cout<<"Philosopher No. "<<temp+1<<" took chopstick "<<philno+1<<"\n";
                remainchop[philno].picked = philosopher[temp].right = 1;
            }
			else
                cout<<"Philosopher No. "<<temp+1<<" is waithing for chopstick "<<philno+1<<"\n";
        }
    }
    else if(philosopher[philno].left==0)
	{
        if(philno==(n-1))
		{
            if(remainchop[philno-1].picked==0)
			{
                cout<<"Philosopher No. "<<philno+1<<" took chopstick "<<philno<<"\n";
				remainchop[philno-1].picked = philosopher[philno].left = 1;
            }
			else
				cout<<"Philosopher No. "<<philno+1<<" is waithing for chopstick "<<philno<<"\n";
                        
        }
		else
		{
            if(remainchop[philno].picked == 0)
			{
                cout<<"Philosopher No. "<<philno+1<<" took chopstick "<<philno+1<<"\n";
				remainchop[philno].picked = philosopher[philno].left = 1;
            }
			else
                cout<<"Philosopher No. "<<philno+1<<" is waithing for chopstick "<<philno<<"\n";                
        }
    }
}
int main()
{	
	int n;
	cout<<"Enter the no. of Philosophers: ";
	cin>>n;
	phil philosopher[n];
	chop remainchop[n];
	for(int i=0;i<n;i++)
        remainchop[i].picked=philosopher[i].left=philosopher[i].right=0;
 
	while(finished<n)
	{
		for(int i=0;i<n;i++)
            DPP(i, philosopher, remainchop, n);
		cout<<"Philosopher finished dinner: "<<finished<<"\n\n";
	}
	return 0;
}
