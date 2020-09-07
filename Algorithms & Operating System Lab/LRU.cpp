#include<iostream>
using namespace std;

struct process
{
	int pid;
	int pri;
};

int countpri = 0;

int main()
{
	int fno;
	int pfault = 0;
	int phit = 0;
	int temp = 0;
	int check = 0;
	int min = -1;
	int size = 0;
	int opt[100];
	int optn = -1;
	cout<<"\n Enter the frame size: ";
	cin>>fno;
	int frame[fno];
	int oframe[fno];
	int prio[fno];
	
	for(int i=0; i<fno; i++)
	{
			frame[i] = -1;
			prio[i] = -1;
			oframe[i] = -1;
	}
	cout<<"\n Frame state: \n";
	for(int i=0; i<fno; i++)
	{
		cout<<" "<<frame[i];
	}
	cout<<"\n\n";
	cout<<"\n Enter the Sequence of processes: (Input -1 to end the sequence)\n";
	while(temp!=-1)
	{	
		check = 0;
		cout<<" -> ";cin>>temp;
		if(temp!=-1)
		{
			for(int i=0; i<fno; i++)
			{	
				if(frame[i]==temp)
				{	
					check = 1;
					phit++;
					countpri++;
					prio[i] = countpri++;
					cout<<"\n PAGE HIT!!";
				}
			}
			if(check==0)
			{	
				min = 10000;
				int minindex;
				for(int i=0; i<fno; i++)
				{
					if(prio[i]<=min)
					{
						min = prio[i];
						minindex = i;
					}
				}
				frame[minindex] = temp;
				pfault++;
				countpri++;
				prio[minindex] = countpri++;
				cout<<"\n PAGE FAULT!!";
			}
			cout<<"\n Frame state: \n";
			for(int i=0; i<fno; i++)
			{
				cout<<" "<<frame[i];
			}
			cout<<"\n\n";
			
			//for Optimal Page Replacement Algorithm
			optn++;
			opt[optn] = temp;
			
		}
	}
	cout<<"\n\n LRU Page Replacement: ";
	cout<<"\n\n No. of Page Faults: "<<pfault;
	cout<<"\n No. of Page Hits: "<<phit;
	
	int inc = 0;
	int ophit = 0;
	int opfault = 0;
	while(inc<=optn)
	{
		
		cout<<"\n\n -> "<<opt[inc]<<"\n";
		check = 0;
		int empty = 0;
		for(int i=0; i<fno; i++)
		{
			if(oframe[i]==opt[inc])
			{
				cout<<"\n PAGE HIT";
				ophit++;
				check = 1;	
			}	
		}
		if(check==0)
		{	cout<<"\n PAGE FAULT";	
			opfault++;
			for(int i=0; i<fno; i++)
			{
				if(oframe[i]==-1&&empty==0)
				{
					oframe[i] = opt[inc];
					empty = 1;	
				}
			}
			if(empty==0)
			{
				int lateindex[fno];
				int last=-1;
				for(int i=0; i<fno; i++)
				{	int done =0;
					lateindex[i] = optn+1;
					for(int j = inc; j<=optn; j++)
					{
						if(oframe[i]==opt[j]&&done==0)
						{	
							done =1;
							lateindex[i] = j;
							if(lateindex[i]>=lateindex[i-1]&&i>0)
								last = i;	
						}
					}
					if(done==0)
						last = i;
				}
				oframe[last] = opt[inc];
			}	
		}
		cout<<"\n Optimal Frame state: \n";
		for(int i=0; i<fno; i++)
		{
			cout<<" "<<oframe[i];
		}
		inc++;	
	}
	cout<<"\n\n Optimal Page Replacement: ";
	cout<<"\n No. of Page Faults: "<<opfault;
	cout<<"\n No. of Page Hits: "<<ophit;
}
