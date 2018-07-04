#include <iostream>
using namespace std;

template<class T>
class node 
{
	node<T> *lc, *rc, *parent;
	T data;
public:
	node(){lc = NULL; rc = NULL; parent = NULL; data();}
	
	node(T dat)
	{
		data = dat;
		lc = NULL;
		rc = NULL;
	}

	void insert(T data)
	{
		this.insert(new node<T>(data));
	}
		
	void insert(node<T>* node)
	{
		if (node == NULL)
			cout << "Empty node inserted" << endl;

		if(node->GetData() >= data)
		{
			if(rc != NULL)
				rc->insert(node);
			else
				rc = node;
		}
		else
		{
			if(lc != NULL)
				lc->insert(node);
			else
				lc = node;
		}
	}
	node<T>* left() {return lc;}
	node<T>* right() {return rc;}
	T GetData() {return data;}
};

template<class T>
class tree
{
	node<T>* rootnode;
public:
	tree(): rootnode(NULL) {}

	void insert(T t)
	{
		insert(new node<T>(t));
	}

	void insert(node<T>* n)
	{
		if(rootnode != NULL)
			rootnode->insert(n);
		else
			rootnode = n;
	}

	node<T>* root()
	{
		return rootnode;
	}
};
