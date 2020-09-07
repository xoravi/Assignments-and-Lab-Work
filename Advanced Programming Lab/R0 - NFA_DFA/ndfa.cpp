#include<iostream>
#include<fstream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

string redup(string s)
{
	string p;
    bool num[10];
    memset(num,false,10);
    for(int i=0;i<s.size();i++)
    {
        if(num[s.at(i)-'0']==false)
        {
            num[s.at(i)-'0']=true;
            p.push_back(s.at(i));
        }
    }
    string temp = "";
    sort(p.begin(),p.end());
	if(p.size()>1)
	{
		for(int i=0;i<p.size();i++)
		{
			if(p[i]!='Q')
				temp+=p[i];
		}
		return temp;
	}
	return p;
}

int srch(string* s, string a, int len)
{
	for(int i=0; i<len+1; i++)
	{
		if(s[i]==a)
			return 1;
	}
	return 0;
}

string finalapp(string fa, string final, string news[], int N)
{
	for(int i=0; i<=fa.length(); i++)
	{
		for(int j=0; j<=final.length(); j++)
		{
			//cout<<"\nvalue of news[stoi(fa)-N][i]: "<<news[stoi(fa)-N][i];
			//cout<<"\nvalue of news[stoi(fa)-N]: "<<news[stoi(fa)-N];
			//cout<<"\nvalue of final: "<<final;
			if(news[stoi(fa)-N][i]==final[j])
			{
				//cout<<"\nhit";
				final += final + fa;
				final = redup(final);
				return final;
			}
		}
	}
	return final;
}

int main()
{
	ifstream inf;
	string s = "filenfa.txt";
	cout<<"\nEnter automata file name: ";
	cin>>s;
	inf.open(s,ios::in);
	if(!inf.is_open())
	{
		cout<<"\nERROR! Unable to open \"file.txt\" \n";
	}
	else
	{
		int N, M, F, T, tempo;
		int x, y, nt, ntsum=0, temp, nfacheck=0;
		inf>>N>>M>>F;
		
		if(N<1||M<1||F<1)
		{
			cout<<"\nERROR! Value for N/M/F should be greater than 0\n";
			return 0;
		}

		string fa[100][100], final="";
		
		for(int i=0;i<100;i++)
			for(int j=0;j<100;j++)
				fa[i][j] = "Q";

		for(int i=0; i<N; i++)
			fa[i][0] = to_string(i);
				
		for(int i=0; i<F; i++)
		{
			inf>>tempo;
			final += to_string(tempo);
		}
		cout<<final;
		
		inf>>T;
		
		if(T==0)
			nfacheck=1;
		
		while(!inf.eof())
		{
			inf>>x>>y>>nt;
			ntsum=ntsum+nt;

			if(nt>1||y==0)
				nfacheck = 1;
				
			for(int i=0; i<nt; i++)
			{
				inf>>temp;
				if(fa[x][y]=="Q")
					fa[x][y] = to_string(temp);
				else
					fa[x][y] += to_string(temp);
			}
		}
		
		if(ntsum!=M*N)
			nfacheck=1;
		
		if(nfacheck==0)
			cout<<"\nGiven automata is a DFA.\n";
			
		else
			cout<<"\nGiven automata is a NFA.\n";
			
  		inf.close();
	//*************************************************************************************************************
	
		string news[100];
		int cnew=0, newN=N;
		
		for(int i=0; i<newN; i++)
		{
			for(int j=1; j<M+1; j++)
			{
				if(fa[i][j].length()>1 && srch(news,fa[i][j],cnew)==0)
				{
					news[cnew] = fa[i][j];
					fa[newN][0] = fa[i][j];
					int lens = fa[i][j].length();
					for(int x=1; x<M+1; x++)
					{
						for(int y=0; y<lens; y++)
						{
							int temp = int(fa[i][j][y]) - 48;
							
							if(fa[newN][x] == "Q")
								fa[newN][x] = fa[temp][x];
	   						else
								fa[newN][x] += fa[temp][x];
							fa[newN][x] = redup(fa[newN][x]);

						}
					}
					newN++;cnew++;
					//cout<<newN;
				}
			}
		}
		cout<<"\n Original: ";
		for(int i=0;i<newN;i++)
		{
			cout<<endl;
			for(int j=0;j<M+1;j++)
				cout<<fa[i][j]<<'\t';
		}

		int newstate = N;
		int check[cnew];
		for(int i=0; i<cnew; i++)
			check[i]=0;

		for(int i=0; i<newN; i++)
		{
			for(int j=0; j<M+1; j++)
			{
				for(int k=0; k<cnew; k++)
				{
					if(fa[i][j]==news[k])
					{
						if(check[k]==0)
						{
							check[k]=newstate;
							fa[i][j] = to_string(newstate);
							newstate++;
							final = finalapp(fa[i][j], final, news, N);
						}
						else
						{
							fa[i][j] = to_string(check[k]);
							final = finalapp(fa[i][j], final, news, N);
						}
					}
				}
				if(fa[i][j]=="Q")
				{
					fa[i][j] = to_string(N + cnew);
				}
			}
		}
		cout<<"\n Updated: ";
		for(int i=0;i<newN;i++)
		{
			cout<<endl;
			for(int j=0;j<M+1;j++)
				cout<<fa[i][j]<<'\t';
		}
		
		cout<<"\n final: "<<final;
		
		ofstream onf;
		onf.open("rslt.txt",ios::out);
		onf<<N+cnew+1<<" "<<M<<"\n"<<final.length();
		for(int i=0; i<final.length(); i++)
			onf<<" "<<final[i];
		onf<<"\n"<<newN;
		for(int i=0; i<newN; i++)
		{
			for(int j=1; j<M+1; j++)
			{
				onf<<"\n"<<i<<" "<<j<<" "<<fa[i][j].length();
				for(int k=0; k<fa[i][j].length(); k++)
				{
						onf<<" "<<fa[i][j][k];
						//cout<<"\n fa[k] is: "<<fa[i][j][k];
				}
				
			}
		}
		
		onf.close();
	}

}
