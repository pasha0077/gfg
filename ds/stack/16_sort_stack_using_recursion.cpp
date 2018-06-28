#include <iostream>
#include <stack>
using namespace std;
void SortedInsert(stack<int>& s, int temp)
{
	if(!s.empty() && s.top() < temp)
	{
		int temp2 = s.top();
		s.pop();
		SortedInsert(s,temp);
		s.push(temp2);
	}
	else 
	{
		s.push(temp);
	}
}

void SortStack(stack<int>& s)
{
	if(!s.empty())
	{
		int temp = s.top();
		s.pop();
		SortStack(s);
		SortedInsert(s, temp);
	}
}

int main(int argc, char* argv[])
{
	int n;
	stack<int> s;
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int temp;
		cin >> temp;
		s.push(temp);
	}
	SortStack(s);
	while(!s.empty())
	{
		cout <<s.top() << " ";
		s.pop();
	}
}
