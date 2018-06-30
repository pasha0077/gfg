/* Given an array arr[] and a number k. 
The task is to delete k elements which are smaller than next element 
(i.e., we delete arr[i] if arr[i] < arr[i+1]) or become smaller than next 
because next element is deleted. */

#include <iostream>
#include <stack>
using namespace std;

void print(stack<int>& s)
{
	if(!s.empty())
	{
		int t = s.top();
		s.pop();
		print(s);
		cout << t << " ";
	}
}

int main(int argc, char* argv[])
{
	int n, k;
	cin >> n >> k;
	int a[n];
	stack<int> s;
	for(int i = 0; i < n; i++)
		cin >> a[i];
	int t = 0;
	for(int i = 0; i < k && t < n; i++, t++)
	{
		if(s.empty())
		{
			if(a[t] > a[t+1])
			{
				s.push(a[t]);
				i--;
			}
		}
		else
		{
			if(s.top() < a[t])
			{
				t--, s.pop();
			}
			else
			{
				i--, s.push(a[t]);
			}
		}
	}
	print(s);
	while(t<n)
		cout << a[t++] << " ";
}
		
