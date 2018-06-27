#include <iostream>
#include <stack>
using namespace std;

int FindMaxProduct(int a[], int n)
{
	int p[n], max = 0;
	stack<int> l, r;
	for(int i = 0; i < n; i++)
	{
		while(!l.empty() && a[l.top()] <= a[i])
			l.pop();
		if(l.empty())
			p[i] = 0;
		else
			p[i] = l.top() + 1;
		l.push(i);
	}

	for(int i = n - 1; i >= 0; i--)
	{
		while(!r.empty() && a[r.top()] <= a[i])
			r.pop();
		if(r.empty())
			p[i] = 0;
		else
			p[i] *= (r.top() + 1);
		r.push(i);
		if(p[i] > max)
			max = p[i];
	}
	return max;
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
		cout << FindMaxProduct(a, n) << "\n";
	}
}
