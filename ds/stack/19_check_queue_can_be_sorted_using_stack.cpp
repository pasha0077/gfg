/*
Given a Queue consisting of first n natural numbers (in random order). 
The task is to check whether the given Queue elements can be arranged 
in increasing order in another Queue using a stack.
*/

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

int main(int argc, char* argv[])
{
	int n, k = 1;
	cin >> n;
	queue<int> q;
	stack<int> s;
	while(n--)
	{
		int t;
		cin >> t;
		if(k == t)
		{
			q.push(k++);
		}
		else
		{
			s.push(t);
		}
		while(!	s.empty() && k == s.top())
		{
			q.push(k++);
			s.pop();
		}
	}
	if(s.size())
		cout << "NO \n";
	else
		cout << "YES \n";
}
