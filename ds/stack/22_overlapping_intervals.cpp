#include <iostream>
#include <map>
using namespace std;

void UsingMap(int n)
{
	map<int, int> m;
	for(int i = 0; i < n; i++)
	{
		int k, v;
		cin >> k >> v;
		if(m.find(k) == m.end())
			m[k] = v;
		else
		{
			if(v > m[k])
				m[k] = v;
		}
	}
	
	map<int, int>::iterator j, i = m.begin();
	while(i != m.end())
	{
		j = i++;
		if(i == m.end())
			break;
		if(j->second >= i->first)
		{
			if(i->second > j->second)
				m[j->first] = i->second;
			m.erase(i);
			i = m.begin();
		}
	}
	i = m.begin();
	while(i != m.end())
	{
		cout << i->first << " " << i->second << " ";
		i++;
	}
}

int main(int argc, char* argv[])
{
	int t;
	cin >> t;
	while(t--)
	{

		int n;
		cin >> n;
		UsingMap(n);
	}
}
