#include<iostream>
#include<stack>
using namespace std;
void push(int a);
bool isFull(int n);
bool isEmpty();
int pop();
int getMin();
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty()){
			pop();
		}
		while(!isFull(n)){
			cin>>a;
			push(a);
		}
		cout<<getMin()<<endl;
	}
}


/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function(s) below*/
void push(int a)
{
	int temp;
	if (s.empty())
	{
		s.push(a);
		s.push(a);
	}
	else
	{
		temp = s.top();
		s.pop();
		if(temp<a)
		{
			s.push(a);
			s.push(temp);
		}
		else
		{
			s.push(temp);
			s.push(a);
		}
	}
	 //add code here.
}
bool isFull(int n)
{
	return s.size() == n+1;
	 //add code here.
}
bool isEmpty()
{
	return s.empty();
	//add code here.
}
int pop()
{
	int temp = s.top();
	s.pop();
	return temp;
	//add code here.
}
int getMin()
{
	int temp = s.top();
	s.pop();
	return temp;
   //add code here.
}
