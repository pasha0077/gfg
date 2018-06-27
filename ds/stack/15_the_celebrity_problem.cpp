#include	<bits/stdc++.h>
using namespace std;
#define MAX 100

int getId(int M[MAX][MAX],int n);

int main()
{
	int T;
	cin >> T;
	int M[MAX][MAX];
	while(T--)
	{
		int N;
		cin >> N;
		memset(M,0,sizeof M);
		for(int i=0;i<N;i++)
		{
			for(int j=0;j<N;j++)
			{
				cin>>M[i][j];
			}
		}
		cout<<getId(M,N)<<endl;
	}
}

int getId(int M[MAX][MAX], int n)
{
	int u = 0;
	for(int i = 1; i < n ; i++)
	{
		if(i == u)
			continue;
			
		if(M[u][i])
			 u = i;
	}
	
	bool ret = true;
	for(int i = 0; i < n ; i++)
	{
		if(i == u)
			 continue;
		ret = ret && M[u][i] == 0 && M[i][u] == 1;
	}
	return ret ? u : -1;
}
