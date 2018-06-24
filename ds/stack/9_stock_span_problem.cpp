#include <iostream>
using namespace std;

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
		{
			cin >> a[i];
			int out = 1;

			for(int j = i-1; j >= 0 && a[j] <= a[i]; j--)
				out++;
			cout << out << " ";
		}
		cout << "\n";
	}
}
