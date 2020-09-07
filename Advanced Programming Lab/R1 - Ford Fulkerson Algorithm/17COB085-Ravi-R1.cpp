//Name: RAVI SAHNI
//Faculty No.: 17 COB 085
//Enrollment No.: GJ 7718
//Serial No.: 024
//Course Code: COC3960 (Advanced Computing Lab)
//Experiment R1: Given a flow network, W.A.P. to find the maximum flow using FORD-FULKERSON Algorithm

#include <iostream>
using namespace std;

int frnt=-1, rear=-1, q_size=100;

void enQ(int val, int q[])
{
	if(rear==q_size-1)
		cout<<"\nERROR! OVERFLOW\n";

	else
	{
		rear++;
		q[rear]=val;
	}
}

int deQ(int q[])
{
	if(frnt==rear)
		cout<<"\nERROR! UNDERFLOW\n";
		
	else
	{
		int val;
		val=q[0];
		for(int i=0; i<=rear; i++)
		{
			q[i]=q[i+1];
		} 
		rear--;
		return val;
	}
}

bool check_if_emp(int q[])
{
	if(frnt==rear)
		return true;
		
	return false;
}

bool breadth_first(int grph[20][20], int sr, int tr, int root[], int v)
{ 
    int q[30], visted[20]={0};
    enQ(sr,q);
    visted[sr]=1; root[sr]=-1;
   
    while(!check_if_emp(q))
    {
        int k = deQ(q);
        for (int i=0; i<v; i++)
        {
            if(visted[i]==0 && grph[k][i]>0)
            {
                enQ(i,q);
                root[i]=k;
                visted[i]=1;
            }
        }
    }
	if(visted[tr]==1)
		return true;
    else
    	return false;
}

int ford_fulk(int ingrph[20][20], int sr, int tr, int v)
{ 
    int residue[20][20], k, l, flow_max=0, root[20];;
	for(k=0; k<v; k++)
    {
		for(l=0; l<v; l++)
			residue[k][l]=ingrph[k][l];
	}
  
    while(breadth_first(residue,sr,tr,root,v))
    { 
        int flow_in_path=9999;
        for (l=tr; l!=sr; l=root[l])
        { 
            k=root[l];
            flow_in_path=min(flow_in_path,residue[k][l]);
        } 

        for (l=tr; l!=sr; l=root[l])
        { 
            k=root[l];
            residue[k][l] -= flow_in_path;
            residue[l][k] += flow_in_path;
        } 
        flow_max += flow_in_path;
    } 
    return flow_max;
}

int main()
{
	int v,ingrph[20][20]={{0}},sr, de, strt, end;
	cout<<"\nENTER THE NO. OF NODES: ";
	cin>>v;

	cout<<"\nNODES GENERATED! \nNodes: ";
	for(int i=0;i<v;i++)
		cout<<i<<" ";

	cout<<"\nENTER SOURCE NODE: ";
	cin>>strt;
	cout<<"\nENTER DESTINATION NODE: ";
	cin>>end;
	
	cout<<"\n\nENTER THE FLOW NETWORK:\nINPUT -1 TO EXIT\n";
	while(true)
	{
		cout<<"\nSource Node: ";
		cin>>sr;
		if(sr==-1)
			break;
		cout<<"Destination Node: ";
		cin>>de;
		if(de==-1)
			break;
		cout<<"Weight: ";
		cin>>ingrph[sr][de];
	}
	
	cout<<"\nADJACENCY MATRIX:\n";
	for(int i=0; i<v; i++)
	{
		cout<<"\n";
		for(int j=0; j<v; j++)
			cout<<ingrph[i][j]<<"\t";
	}
	
	cout<<"\n\nMAXIMUM FLOW in the given flow network: "<<ford_fulk(ingrph,strt,end,v);
	return 0;
}
