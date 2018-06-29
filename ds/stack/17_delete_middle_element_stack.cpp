#include <iostream>
#include <stack>
using namespace std;

void DeleteMiddle(stack<int>& s)
{
	static int n = 0;
	static int curr = 0;
	if(!s.empty())
	{
		n++;
		int t = s.top();
		s.pop();
		DeleteMiddle(s);
		curr++;
		if(curr != (n/2 + n%2))
		{
			cout << t << " " ;
			s.push(t);
		}
	}
}

int main(int argc, char*[])
{
	int n;
	cin >> n;
	stack<int> s;
	for(int i = 0; i < n; i++)
	{
		int t;
		cin >> t;
		s.push(t);
	}
	DeleteMiddle(s);
	cout << "\n";
}
