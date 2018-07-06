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

int main(int argc, char* argv[])
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		UsingDCC(n);
		cout << "\n";
		//UsingStack(n);
	}
}
