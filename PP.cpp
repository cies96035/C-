#include<iostream>
using namespace std;

struct Node
{
	int num;
	Node *node;
}root;

void function(Node*& node)
{
	node=new Node;
	return;
}
int main()
{
	cout<<root.node<<endl;
	function(root.node);
	cout<<root.node<<endl;
	root.node=new Node;
	cout<<root.node<<endl;
	return 0;
}

