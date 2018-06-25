#include <iostream>
#include <stack>
using namespace std;

void FindStockSpan(int* a, int n)
{
	stack<int> s;
	cin >> a[0];
	s.push(0);
	cout << 1 << " ";
	for(int i = 1; i < n; i++)
	{
		cin >> a[i];
		while(!s.empty() && a[s.top()] <= a[i])
			s.pop();
		cout << (s.empty() ? i+1 : i - s.top()) << " ";
		s.push(i);
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
		FindStockSpan(a, n);
		cout << "\n";
	}
	return 0;
}
