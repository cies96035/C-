#include<iostream>
using namespace std;

struct Node{
    int cnt;
    int id;
    Node *nextNode;
};

Node *Insert(Node *curNode, int cnt, int id){
    Node *n = new Node;
    n->nextNode = curNode->nextNode;
    curNode->nextNode = n;
    n->cnt = cnt;
    n->id = id;
    return n;
}

void Delete(Node *curNode, Node *delNode){
    curNode->nextNode = delNode->nextNode;
    delete delNode;
}

int n, k, Cnt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    cin >> k;
    Node *CurrentNode = new Node;
    Node *CntNode;
    CurrentNode->nextNode = CurrentNode;
    CurrentNode->id = 1;
    CurrentNode->cnt = k;

    for(int i = 2; i <= n; i++){
        cin >> k;
        CurrentNode = Insert(CurrentNode, k, i);
    }

    CurrentNode = CurrentNode->nextNode;

    for(int i = n; i > 1; i--){
        Cnt = ( CurrentNode->cnt + i - 2)% i;
        CntNode = CurrentNode;
        for(int j = 0; j < Cnt; j++){
            CntNode = CntNode->nextNode;
        }
        Delete(CntNode, CntNode->nextNode);
        CurrentNode = CntNode->nextNode;
    }
    cout << CurrentNode->id << '\n';
    
    
    return 0;
}
