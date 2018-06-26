#include <iostream>
#include <stack>
using namespace std;

void FindNumNGEs(int a[], int n, int b[])
{
	stack<int> s;
	for(int i = n-1; i >= 0; i--)
	{
		while(!s.empty() && a[s.top()] <= a[i])
			s.pop();
		if(s.empty())
			b[i] = 0;
		else
			b[i] = b[s.top()] + 1;
		s.push(i);
	}
}

int main(int argc, char* argv[])
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, q;
		cin >> n >> q;
		int in[n], out[n];
		for(int i = 0; i < n; i++)
			cin >> in[i];
		FindNumNGEs(in, n, out);
		for(int i = 0; i < q; i++)
		{
			cin >> n;
			cout << out[n] << " ";
		}
		cout << "\n";
	}
}
		
