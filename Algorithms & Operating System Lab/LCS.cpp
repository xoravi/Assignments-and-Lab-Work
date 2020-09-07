//Week 3 'Longest Common Subsequence' using Dynamic Programming
#include<iostream>
#include<cstring>
using namespace std;

void LCS(string X, string Y, int m, int n )
{
	int L[m+1][n+1];
	for(int i=0;i<=m;i++)
	{
		for(int j=0;j<=n;j++)
		{
			if(i==0 || j==0)
				L[i][j]=0;
			else if(X[i-1]==Y[j-1])
				L[i][j]=L[i-1][j-1]+1;
			else
				L[i][j]=max(L[i-1][j], L[i][j-1]);
		}
	}
	cout<<"\n Length Of LCS: "<<L[m][n];
	int ind= L[m][n], i=m, j=n;
	char sequence[ind+1];
	while(i>0 && j>0)
	{
		if(L[i][j]==L[i-1][j-1]+1&&L[i][j]!=L[i-1][j]&&L[i][j]!=L[i][j-1])
		{
			sequence[ind-1]=X[i-1];
			i--;
			j--;
			ind--;
		}
	else if(L[i-1][j]>L[i][j-1])
		i--;
	else
		j--;
	}
	sequence[L[m][n]]='\0';
	cout<<"\n LCS: "<<sequence;
}

int main()
{
	string s1,s2;
	cout<<"\n Enter String 1 & 2:\n 1: ";
	cin>>s1;
	cout<<" 2: ";
	cin>>s2;
	int m = s1.length();
	int n = s2.length();
	LCS(s1, s2, m, n);
}
