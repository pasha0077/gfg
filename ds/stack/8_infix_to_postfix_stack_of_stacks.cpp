#include <iostream>
#include <stack>
using namespace std;

int GetOpPri(char c)
{
	if(c == '^')
		return 6;
	else if(c == '*')
		return 5;
	else if(c == '/')
		return 4;
	else if(c == '+')
		return 3;
	else if(c == '-')
		return 3;
	else if(c == ')')
		return 1;
	else if(c == '(')
		return 7;
	else
		return 0;
}

bool IsOperand(char c)
{
	return !(c == '^' || c == '*' || c == '/' || c == '+' || c == '-' || c == '(' || c == ')');
}

bool IsHigher(char first, char second)
{
	return GetOpPri(first) > GetOpPri(second);
}



int main(int argc, char* argv[])
{
	int t;
	string out;
	cin >> t;
	while(t--)
	{
		string str;
		cin >> str;
		cin.ignore();
		stack<stack<char>> sos;
		sos.push(*(new stack<char>));
		for( int i = 0; i < str.length(); i++)
		{
			char c = str[i];
			//string out;
			if (c == '(')
			{
				sos.push(*(new stack<char>));
				continue;
			}
			else if (c == ')')
			{
				while(!sos.top().empty())
				{
					out += sos.top().top();
					sos.top().pop();
				}
				sos.pop();
			}
			else if(IsOperand(c))
				out += c;
			else
			{
				if(sos.top().empty() || IsHigher(c, sos.top().top()) || sos.top().top() == '(')
					sos.top().push(c);
				else
				{
					while(sos.top().size() != 0 && sos.top().top() != '(' && !IsHigher(c, sos.top().top()))
					{
						out += sos.top().top();
						sos.top().pop();
					}
					sos.top().push(c);
				}
			}
		}
		while(!sos.top().empty())
		{
			out += sos.top().top();
			sos.top().pop();
		}
		cout << out << endl;

	}
}
