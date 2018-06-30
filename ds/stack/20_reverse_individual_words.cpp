/*Given a string str, we need to print reverse of individual words.*/

#include <iostream>
#include <stack>
using namespace std;

void PrintReverse(string& s)
{
	stack<char> sc;
	for(int i = 0; i < s.length(); i++)
	{
		if(s[i] != ' ')
			sc.push(s[i]);
		else
		{
			while(!sc.empty())
			{
				cout << sc.top();
				sc.pop();
			}
			cout << " ";
		}
	}	
	while(!sc.empty())
	{
		cout << sc.top();
		sc.pop();
	}
}

void PrintReverse2()
{
	string s;
	cin >> s;
	while(s != "\n")
	{
		for(int i = s.length() - 1; i >= 0; i--)
			cout << s[i];
		cin >> s;
		if(s != "\n") cout << " ";
	}
}

int main(int argc, char* argv[])
{
	string s;
	//PrintReverse2();
	getline(cin, s);
	PrintReverse(s);
}
