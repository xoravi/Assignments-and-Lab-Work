#include<bits/stdc++.h>
#include<vector>
using namespace std;

class Bank
{
	int n,m;
	int **maxim;
	int **alloc;
	int **need;
	int *resr;
	int *avail;
	int *work;
	int *safe;
	bool *finish;
	
	public:
	
		Bank(int n,int m)
		{
			int k;
			this->n=n;
			this->m=m;
			maxim= new int *[n];
			alloc= new int *[n];
			need = new int *[n];
			for(k=0;k<n;++k)
			{
				maxim[k]= new int[m];
				alloc[k]= new int[m];
				need[k]= new int[m];
			}
			resr = new int[m];
			avail = new int[m];
			work = new int[m];
			safe = new int[n];
			finish = new bool[n];
			
		}
		void get_resr();
		void get_max();
		void get_alloc();
		void set_avail();
		void prin();
		int chek(int ,int *);
		void Deadlock();
};
void Bank:: get_resr()
{		
	//cout<<"get_resr()";
	int i,a;
	for(i=0;i<m;++i)
	{
		//cout<<"		i="<<i;
		//cin>>a;
		cin>>resr[i];
		//resr[i]=a;
	}
}

void Bank:: get_max()
{
	//cout<<"get_max()";
	int i,j,id,v;
	for(i=0;i<n;++i)
	{
		//cin>>id;
		for(j=0;j<m;++j)
		{
			//cout<<"	j="<<j;			
			//cin>>v;
			cin>>maxim[i][j];
			//maxim[i][j]=v;			
		}
	}
}

void Bank:: get_alloc()
{
	int i,j,id,v;
	
	for(i=0;i<n;++i)
	{
		//cin>>id;
		for(j=0;j<m;++j)
		{
			//cin>>v;
			cin>>alloc[i][j];
			//alloc[i][j]=v;
		}
	}
	for(i=0;i<n;++i)
	{
		//cin>>id;
		for(j=0;j<m;++j)
		{
			v=maxim[i][j]-alloc[i][j];
			need[i][j]=v;
		}
	}
	
	
}
void Bank:: set_avail()
{
	int i,j,sum;
	for(j=0;j<m;++j)
	{
		sum=0;
		for(i=0;i<n;++i)
		{
			sum+=alloc[i][j];
			//cout<<"sum="<<sum<<endl;
		}
		avail[j]=resr[j] - sum;
	}
}
void Bank:: prin()
{
	
	int i,j;
	cout<<"----------resr--------\n";
	for(j=0;j<m;++j)
	{
		cout<<resr[j]<<"	";
	}
	cout<<endl;
	cout<<"-----maxim------\n";
	for(i=0;i<n;++i)
	{
		for(j=0;j<m;++j)
		{
			cout<<maxim[i][j]<<"	";
		}
		cout<<endl;
	}
	cout<<"-----alloc------\n";
	for(i=0;i<n;++i)
	{
		for(j=0;j<m;++j)
		{
			cout<<alloc[i][j]<<"	";
		}
		cout<<endl;
	}
	cout<<"-----need------\n";
	for(i=0;i<n;++i)
	{
		for(j=0;j<m;++j)
		{
			cout<<need[i][j]<<"	";
		}
		cout<<endl;
	}
	cout<<"----------avail--------\n";
	for(j=0;j<m;++j)
	{
		cout<<avail[j]<<"	";
	}
	cout<<endl;
}
int Bank:: chek(int i,int *work)
{
	int j;
	for(j=0;j<m;++j)
	{
		if(need[i][j]> work[j])
			return 0;
	}
	return 1;
}
void Bank:: Deadlock()
{
	//work=avail;
	
	int count=0,loc,i,j,flag;
	for(i=0;i<m;++i)
	{
		work[i]=avail[i];
	}
	while(1)
	{
		flag=0;
		for(i=0;i<n;++i)
		{
			//if(finish[i]==false && need[i]<= work)
			if(finish[i]==false && chek(i,work) )
			{
				flag=1;
				safe[count]=i;
				++count;
				loc=i;
				cout<<"  loc="<<loc<<endl;
				break;
			}
		}
		if (flag==0)// no precess 
		{
			cout<<"Deadlock\n";
			exit(0);
		}
		
		finish[loc]=true;
		cout<<"----------work------\n";
		for(j=0;j<m;++j)
		{
			work[j] += alloc[loc][j];
			cout<<"	"<<work[j];
		}
		cout<<endl;
		if(count==n)
		{
			cout<<"Safe \n";
			break;
		}
		
	
	}	
	cout<<"-----------Safe Sequence--------------\n";
	for(i=0;i<n;++i)
	{
		cout<<"	  P"<<safe[i];
	}
	cout<<endl;
}

int main()
{
	int n,m;
	
	cout<<"ENter #processes & #resources:\n";
	cin>>n>>m;
	Bank b(n,m);
	cout<<"  Enter #resources avalaible of each type:\n";
	b.get_resr();
	//cout<<" Enter Process_id & maximum need:\n";
	cout<<"  Enter maximum need:\n";
	b.get_max();
	cout<<"  Enter  allocated resources to each process :\n";
	b.get_alloc();
	b.set_avail();
	b.prin();	
	b.Deadlock();
	return 0;
}