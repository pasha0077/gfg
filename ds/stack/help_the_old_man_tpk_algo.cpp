#include <iostream>
#include <map>
using namespace std;

map<int,int> pow2 = {{0,1}, {1,2}, {2,4}, {3,8}, {4,16}, {5,32}, {6,64}, {7,128}, {8,256}, {9, 512}, {10,1024}};

int FindBlock(int step);
int StepsOfBlock(int block, int TotalBlocks);
void PrintMove(int Steps, int TotalBlocks, int Block);
int main()
{
	int T;
	cin >>T;
	for(int i = 0; i < T; i++)
	{
		int N, n, b, s;
		cin >> N >> n;
		b = FindBlock(n);
		s = StepsOfBlock(b, n);
		PrintMove(s, N, b);
	}
	return 0;
}

int FindBlock(int n)
{
	int x = 1;
	for (int i = 1; i < 11; i++)
	{
		if (!((n ^ x) & x))
			return i;
		x <<= 1;
	}
	exit(-1);
}		

int StepsOfBlock(int b, int n)
{
	int pow = pow2.at(b);
	int out = n/pow;

	if (n%pow)
		return out+1;
	else
		return out;
}
void PrintMove(int s, int N, int b)
{
	switch(s%3)
	{
	case 0:
		if(N%2 == b%2) 
			cout << 2 << " " << 1 << "\n";
		else
			cout << 3 << " " << 1 << "\n";
		break;
	case 1:
		if(N%2 == b%2) 
			cout << 1 << " " << 3 << "\n";
		else
			cout << 1 << " " << 2 << "\n";
		break;
	case 2:
		if(N%2 == b%2) 
			cout << 3 << " " << 2 << "\n";
		else
			cout << 2 << " " << 3 << "\n";
		break;
	}
}	
