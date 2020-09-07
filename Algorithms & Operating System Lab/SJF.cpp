#include<iostream>
using namespace std;

struct process
{
	int pid;
	int at;
	int bt;
	float pbt = 1;
	int tat;
	int wt;
};

void preSJF(process p[], int n) 
{ 
	cout<<"\n-> Premptive Shortest Job First: \n\n Gantt's Chart: \n";
	int tbt[n];
	for (int i=0; i< n; i++) 
		tbt[i]=p[i].bt;

	int prcssing=n,min=INT_MAX;
	int x=0, shrt=-1, ft; 
	int check=0, chg=0, emp=0;
	float totalwait=0, totaltat=0;
	while (prcssing!=0)
	{ 
		chg=0;
		for (int j=0; j<n;j++)
		{ 	
			if((p[j].at<= x) && (tbt[j]<min)&& tbt[j]>0)
			{	
				check=1;
				min=tbt[j];
				if(shrt!=j)
					chg=1; 
				shrt=j; 
			} 
		}
		if(chg==1)
		{	cout<<" "<<x<<" ";
			cout<<"<---P["<<shrt<<"]--->";
			emp=0;
		} 
		if (check==0)
		{	
			if(emp==0)
			{
				cout<<" "<<x<<" ";
				cout<<"<------>";
			}
			emp=1;
			x++;
			continue; 
		}
		tbt[shrt]--;
		min=tbt[shrt];
		if(min==0)
		{	
			min=INT_MAX;  
			prcssing--;
			check=0; 
			ft=x+1; 
			p[shrt].wt=ft-p[shrt].bt-p[shrt].at;  
		}
		
		x++;
	}
	cout<<" "<<x<<"\n";
	for(int i=0;i<n;i++)
		p[i].tat=p[i].wt+p[i].bt;
	cout<<"\n---------------------------------------------------------------------------------\n";
	cout<<" Process\t Arrival Time\t Burst Time\t Waiting Time\t Turnaround Time\n";
	cout<<"\n---------------------------------------------------------------------------------\n";
	for(int i=0;i<n;i++)
	{
		totalwait=totalwait+p[i].wt;
		totaltat=totaltat+p[i].tat;
		cout<<"\n   P["<<p[i].pid<<"]\t\t   "<<p[i].at<<"\t\t   "<<p[i].bt<<"\t\t   "<<p[i].wt<<"\t\t   "<<p[i].tat;
	}
	cout<<"\n---------------------------------------------------------------------------------\n";
	cout<<"\n\n Average Waiting Time = "<<(totalwait/n);
	cout<<"\n Average Turnaround Time = "<<(totaltat/n)<<"\n";
	
}

void nonpreSJF(process p[], int n) 
{ 
	cout<<"\n-> Non Premptive Shortest Job First: \n\n Gantt's Chart: \n";
	int tbt[n];
	for (int i=0; i< n; i++) 
		tbt[i]=p[i].bt;

	int prcssing=n,min=INT_MAX;
	int x=0, shrt=-1, ft; 
	int check=0, chg=0, emp=0;
	float totalwait=0, totaltat=0;
	while (prcssing!=0)
	{ 
		chg=0;
		for (int j=0; j<n;j++)
		{ 	
			if((p[j].at<= x) && (tbt[j]<min)&& tbt[j]>0)
			{	
				check=1;
				min=tbt[j];
				if(shrt!=j)
					chg=1; 
				shrt=j; 
			} 
		}
		if(chg==1)
		{	cout<<" "<<x<<" ";
			cout<<"<---P["<<shrt<<"]--->";
			emp=0;
		} 
		if(check==0)
		{	
			if(emp==0)
			{
				cout<<" "<<x<<" ";
				cout<<"<------>";
			}
			emp=1;
			x++;
			continue; 
		}
		x=x+tbt[shrt];
		tbt[shrt]=0;
			min=INT_MAX;
			prcssing--;
			check=0; 
			ft=x;
			p[shrt].wt=ft-p[shrt].bt-p[shrt].at;  
	}
	cout<<" "<<x<<"\n";
	for(int i=0;i<n;i++)
		p[i].tat=p[i].wt+p[i].bt;
	cout<<"\n---------------------------------------------------------------------------------\n";
	cout<<" Process\t Arrival Time\t Burst Time\t Waiting Time\t Turnaround Time\n";
	cout<<"\n---------------------------------------------------------------------------------\n";
	for(int i=0;i<n;i++)
	{
		totalwait=totalwait+p[i].wt;
		totaltat=totaltat+p[i].tat;
		cout<<"\n   P["<<p[i].pid<<"]\t\t   "<<p[i].at<<"\t\t   "<<p[i].bt<<"\t\t   "<<p[i].wt<<"\t\t   "<<p[i].tat;
	}
	cout<<"\n---------------------------------------------------------------------------------\n";
	cout<<"\n\n Average Waiting Time = "<<(totalwait/n);
	cout<<"\n Average Turnaround Time = "<<(totaltat/n)<<"\n";
	
}

void predict(process p[], int n, float alpha)
	{
		float tempbt[n];
		cout<<"\n------------------------------------------------------\n";
		cout<<" Process\t Burst Time\t Predicted Burst Time\n";
		cout<<"\n------------------------------------------------------\n";
		for(int i=0; i<n; i++)
		{	tempbt[i] = ((alpha*p[i].bt)+((1-alpha)*p[i].pbt));
			p[i].pbt = tempbt[i];
			cout<<"\n   P["<<p[i].pid<<"]\t\t   "<<p[i].bt<<"\t\t   "<<p[i].pbt;		
		}
		cout<<"\n------------------------------------------------------\n";

	}

int main()
{
	int np;
	cout<<"\n Enter the no. of Processes: ";
	cin>>np;
	process p[np];
	cout<<"\n Enter the value for alpha: ";
	float alp;
	cin>>alp;
	cout<<"\n Enter Details: \n";
	int check = 1;
	while(check==1)
	{
		for(int i=0;i<np;i++)
		{	
			p[i].pid=i;
			cout<<"\n Process ID P["<<i<<"]\n\t Arrival Time: ";
			cin>>p[i].at;
			cout<<"\t Burst Time: ";
			cin>>p[i].bt;	
		}
	preSJF(p, np);
	cout<<"\n";
	nonpreSJF(p, np);
	cout<<"\n";
	predict(p, np, alp);
	cout<<"\n\n To Continue Press 1: ";
	cin>>check;
	}
}
