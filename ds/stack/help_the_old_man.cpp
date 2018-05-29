#include <iostream>
#include <map>
using namespace std;
map<int, int> pow2 = {{0, 1},{1, 2},{2, 4}, {3, 8},{4, 16},{5, 32},{6, 64},{7, 128},{8, 256},{9, 512}, {10, 1024}};

void PrintStep(int s, int d, int c, int N, int n)
{
	if(N>10 || n < pow2.at(N-1))
		PrintStep(s, c, d, N-1, n);
	else if(n == pow2.at(N-1))
		cout << s << " " << d << "\n";        
	else
		PrintStep(c, d, s, N-1, n-pow2.at(N-1));	        
}

int main() 
{
	int T;
	cin >> T;

	for(int i =0 ; i < T; i++)
	{
	    int N, n;
            cin >> N >> n;
            PrintStep(1,3,2,N,n);
        }
	return 0;
}
