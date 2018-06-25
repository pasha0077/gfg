#include <iostream>
#include <string>
#include <stack>
using namespace std;

void GetNGE_Linear(int* a, int n)
{
	string out = "-1";
	stack<int> s;
	s.push(a[n-1]);

	for(int i = n - 2; i >= 0; i--)
	{
		while(!s.empty() && a[i] > s.top())
			s.pop();
		if(s.empty())
			out = "-1 " + out;
		else
			out = std::to_string(s.top()) + " " + out;
		s.push(a[i]);
	}
	cout << out;
}

void GetNGE(int* a, int n)
{
	for(int i = 0; i < n; i++)
	{
		int j = i + 1;
		while(j++ < n)
			if(a[j-1] > a[i])
				break;
		if(j > n)
			cout << -1 << " ";
		else
			cout << a[j-1] << " ";
	}
}
			
int main(int argc, char* argv[])
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		GetNGE_Linear(a, n);
		cout << "\n";
	}
}
