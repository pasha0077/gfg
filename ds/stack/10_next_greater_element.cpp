#include <iostream>
using namespace std;

void GetNGE(int* a, int n)
{
	for(int i = 0; i < n; i++)
	{
		int j = i + 1;
		while(j++ < n)
			if(a[j-1] > a[i])
				break;
		if(j > n)
			cout << -1 << " ";
		else
			cout << a[j-1] << " ";
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
		int a[n];
		for(int i = 0; i < n; i++)
			cin >> a[i];
		GetNGE(a, n);
		cout << "\n";
	}
}
