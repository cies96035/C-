#include<iostream>
using namespace std;

struct Data
{
    int v;
    bool operator < (Data a) {
        return v<a.v;
    }
};

struct Node
{
	Node* LC;
    Node* RC;
    Node* parent;
    Data data;
    bool color;
    // 0 -> red
    // 1 -> black
};

Node *NIL;

Node *LeftRotate(Node *A) //return new root
{
    Node *B = A->RC;
    A->RC = B->LC;
    A->RC->parent = A;
    B->LC = A;
    B->LC->parent = B;
    B->parent = A->parent;
    return B;
}

Node *RightRotate(Node *B)
{
    Node *A = B->LC;
    B->LC = A->RC;
    B->LC->parent = B;
    A->RC = B;
    A->RC->parent = A;
    A->parent = B->parent;
    return A;
}

Node *NewNode(Data data)
{
    Node *n;
    n->color = 0;
    n->data = data;
    n->LC = n->RC = NIL;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    NIL = new Node;
    NIL->color = 1;
    return 0;
}