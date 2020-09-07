//Week 1
//DFS & BFS Traversal
#include<iostream>
using namespace std;

int q[100],qs=100,frnt=-1,rear=-1;

void push(int val)
{
	if(rear==qs-1)
	{
		cout<<"\nOVERFLOW ERROR!\n";
		return;
	}
	else
	{
		if(frnt==-1)
			frnt=0;
		rear++;
		q[rear]=val;
	}
}

int pop()
{
	if(frnt==-1 || frnt>rear)
	{
    	cout<<"\nUNDERFLOW ERROR!\n";
    	return -1;
	}
	else
	{
		int ret=q[frnt];
		frnt++;
		return ret;
	}
}

int empty()
{
	if(frnt==-1 || frnt>rear)
	{
    	return 1;
	}
	else
	{
		return 0;
	}
}

struct node
{
    node* next;
    int vertex;
};

node* buildnode(int v)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

struct Graph
{
    node** adjancey;
    int nvert;
};

Graph* buildgraph(int vertices)
{
    Graph* grph = (Graph*)malloc(sizeof(Graph));
    grph->nvert = vertices;
    grph->adjancey = (node**)malloc(vertices * sizeof(node*));
    for (int i = 0; i < vertices; i++)
        grph->adjancey[i] = NULL;
 
    return grph;
}

void edge(Graph* grph, int strt, int end)
{
    node* newNode = buildnode(end);
    newNode->next = grph->adjancey[strt];
    grph->adjancey[strt] = newNode;
 
    newNode = buildnode(strt);
    newNode->next = grph->adjancey[end];
    grph->adjancey[end] = newNode;
}

void printlist(Graph* grph)
{	
	cout<<"\nAdjacency List representation of the Graph is:\n\n";
    for (int x = 0; x< grph->nvert; x++)
    {
        node* tmp = grph->adjancey[x];
        cout<<x<<"| ";
        while (tmp)
        {
            cout<<"-> "<<tmp->vertex;
            tmp = tmp->next;
        }
        cout<<"\n";
    }
}
int isedge(Graph* grph,int x,int y)
{
	node* tmp= grph->adjancey[x];
	while(tmp)
	{
		if(tmp->vertex==y)
			return 1;
		else
			tmp = tmp->next;
	}
	return 0;
}

void dfs(Graph* grph, int v, int visited[], int ver)
{
	cout<<v<<" ";
	visited[v]=1;
	for(int j=0;j<ver;j++)
		if(visited[j]==0&&isedge(grph,v,j)==1)
			dfs(grph,j,visited,ver);
	
}

void bfs(Graph* grph, int v, int visited2[], int ver)
{
	cout<<v<<" ";
	visited2[v]=1;
	node* tmp = grph->adjancey[v];
	while(tmp)
	{	
		if(visited2[tmp->vertex]==0)
		{
			visited2[tmp->vertex]=1;
			push(tmp->vertex);
		}
		tmp=tmp->next;
	}
	if(empty()==0)
		bfs(grph,pop(),visited2,ver);
}

int main()
{
	int ver,edg,x,y;
    cout<<"Enter the no. of vertices: ";
    cin>>ver;
    int visited[ver],visited2[ver];
    cout<<"\nVertices Created! V = {";
    for(int i=0;i<ver;i++)
    {	
    	visited[i]=0;
    	visited2[i]=0;
    	if(i==ver-1)
    		cout<<i<<"}\n";
    	else
    		cout<<i<<",";
	}
    Graph* grph = buildgraph(ver);
    cout<<"\nEnter the no. of edges: ";
    cin>>edg;
    cout<<"\nEnter edges: \n";
    for(int i=0;i<edg;i++)
    {
    	cin>>x>>y;
    	if(x<edg&&y<edg&&x>=0&&y>=0)
    		edge(grph,x,y);
    	else
    	{
			cout<<"\nError! Vertex doesnot exist, Enter again\n";
    		i--;
    	}
	}
    printlist(grph);
    cout<<"\n\nEnter starting vertex: ";
    int src;
    cin>>src;
    if(src>=0&&src<edg)
    {
		cout<<"\nDFS from vertex "<<src<<" is: ";
    	dfs(grph,src,visited,ver);
    	cout<<"\nBFS from vertex "<<src<<" is: ";
    	bfs(grph,src,visited2,ver);
	}
	else
		cout<<"\nVertex doesnot exist!";
    return 0;
}
