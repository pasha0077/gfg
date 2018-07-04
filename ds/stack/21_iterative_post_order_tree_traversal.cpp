#include <iostream>
#include <stack>
#include "tree.h"
using namespace std;

template<class T>
void UsingOneStack(node<T> *n)
{
	stack<node<T>*> s;
	s.push(n);

	while(!s.empty())
	{
		node<T>* t = s.top();
		
		if(t->right() != NULL)
			s.push(t->right());
		if(t->left() != NULL)
			s.push(t->left());
		if(s.top() != t)
			continue;
		do
		{
			cout << s.top()->GetData() << " ";
			t = s.top();
			s.pop();
		}
		while(!s.empty() && (s.top()->left() == t || s.top()->right() == t));
	}
}

template<class T>
void UsingTwoStacks(node<T>* t)
{
	stack<node<T>*> np, p; //needs processing, processed
	np.push(t);
	
	while(!np.empty())
	{
		node<T>* k;
		k = np.top();
		cout << k->GetData() << " ";
		np.pop();
		p.push(k);
		if(k->left() != NULL)
			np.push(k->left());
		if(k->right() != NULL)
			np.push(k->right());
	}
	cout << endl;
	while(!p.empty())
	{
		cout << p.top()->GetData() << " ";
		p.pop();
	}
}

int main(int argc, char* argv[])
{
	int n, i = 0;
	cin >> n;
	tree<int> t;
	while(i++ < n)
	{
		int data;
		cin >> data;
		t.insert(data);
	}
		
	UsingOneStack(t.root());
}
