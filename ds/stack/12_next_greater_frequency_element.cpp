#include <iostream>
#include <map>
#include <stack>
#include <string>
using namespace std;

bool PrintNGFE(int a[], int& n)
{
	map<int, int> freq;
	stack<int> s;
	string out = "";
	for(int i = 0; i < n; i++)
		++freq[a[i]];
	for(int i = n - 1; i >= 0; i--)
	{
		while(!s.empty() && freq[s.top()] <= freq[a[i]])
			s.pop();
		
		if(s.empty())
		{
			out = "-1 " + out; 
			s.push(a[i]);
			continue;
		}
		else
		{
			out = std::to_string(s.top()) + " " + out;
		}
		s.push(a[i]);
	}
	cout << out << "\n";
}

int main(int argc, char* argv[])
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		PrintNGFE(a, n);
	}
}
