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

string InfixToPostfix(string& str, int& i)
{
	string out;
	stack<char> s;
	while(i < str.length())
	{
		char c = str[i];
		
		if(c == '(')
		{
			i++;
			out += InfixToPostfix(str, i);
			continue;
		}
		else if(c == ')')
		{
			while(s.size())
			{
				out += s.top();
				s.pop();
			}
			i++;
			return out;
		}

		if(IsOperand(c))
			out += c;
		else
		{
			if(s.empty() || IsHigher(c, s.top()) || s.top() == '(')
				s.push(c);
			else
			{
				while(s.size() != 0 && s.top() != '(' && !IsHigher(c, s.top()))
				{
					out += s.top();
					s.pop();
				}
				//if (s.size() > 0 && s.top() == '(')
					//s.pop();
				//else
					s.push(c);
			}

		}
		i++;
	}
	while(s.size())
	{
		out += s.top();
		s.pop();
	}
	return out;
}

int main(int argv, char* argc[])
{
	int t;
	cin >> t;
	while(t--)
	{
		string strinfix;
		cin >> strinfix;
		//cin.ignore();
		//cout << strinfix << endl;
		int i = 0;
		cout << InfixToPostfix(strinfix, i) << endl;
	}
	return 0;
}
