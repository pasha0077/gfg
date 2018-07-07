#include <iostream>
#include <stack>
using namespace std;

int findmin(int a[], int min, int max)
{
	int curr = min;
	for(int i = min + 1; i <= max; i++)
	{
		if(a[i] < a[curr])
			curr = i;
	}
	return curr;
}

int GetMinArea(int a[], int min, int max)
{
	if(min > max)
		return 0;
	else if(min == max)
		return a[min];
	else
	{
		int mid = findmin(a, min, max);
		int l = GetMinArea(a, min, mid -1);
		int r = GetMinArea(a, mid+1, max);
		int curr = a[mid] *(max - min +1);
		if(curr > l && curr > r)
			return curr;
		else if(l > curr && l > r)
			return l;
		else
			return r;
	}
}

void UsingDCC(int n)
{
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	cout << GetMinArea(a, 0, n-1);
}

void UsingStack(int n)
{
	int a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int max = 0, last;
	stack<int> s;
	for(int i = 0; i < n; i++)
	{
		if(s.empty() || a[s.top()] <= a[i])
			s.push(i);
		else
		{
			int k = s.top();
			s.pop();
			int l = s.empty() ? -1 : s.top();
			if((i-l-1)*a[k] > max)
				max = (i-l-1)*a[k];
			i--;
		}
	}
	
	if(!s.empty())
		last = s.top() + 1;
	while(!s.empty())
	{
		int curr = s.top();
		s.pop();
		int l = s.empty() ? -1 : s.top();
		if((last - l - 1)*a[curr] > max)
			max = (last - l - 1)*a[curr];
	}
	cout << max << " " ;
}

int main(int argc, char* argv[])
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		//UsingDCC(n);
		UsingStack(n);
		cout << "\n";
	}
}
