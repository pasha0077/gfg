#include<iostream>
#include <stack>
using namespace std;

bool IsOpening(char in)
{
	return (in == '{' || in == '(' || in == '[');
}

bool IsMatching(char a, char b)
{
	if (a == '{')
		return b == '}';
	else if(a == '(')
		return b == ')';
	else if (a == '[')
		return b == ']';
}

int main()
{
	int n;
	cin >> n;
	cin.ignore();
	while(n--)
	{
		string in;
		getline(cin,in);
		stack<char> s;
		bool balanced = true;
		for(int i = 0; i< in.length(); i++)
		{
			if(IsOpening(in[i]))
				s.push(in[i]);
			else
			{
				if(s.empty())
				{
					balanced = false;
					break;
				}
				else
				{
					if(IsMatching(in[i],s.top()))
						s.pop();
					else
					{
						balanced = false;
						break;
					}
				}
			}
		}
		if(s.empty() && balanced)
			cout << "balanced\n";
		else
			cout << "not balanced\n";
	}
	return 0;
 }
