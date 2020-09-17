#include <iostream>
using namespace std;

class Tree
{
    public:
    Tree *LC;
    Tree *RC;
    int id;
    Tree()
    {
        RC=LC=NULL;
        id=1;
    }
};
Tree tree;
void create_tree(Tree *root,int k)
{
    if(k==0)
        return;
    root->LC=new Tree;
    root->RC=new Tree;
    root->LC->id=root->id*2;
    root->RC->id=root->id*2+1;
    create_tree(root->LC,k-1);
    create_tree(root->RC,k-1);
    return;
}
void traversal(Tree *root)
{
    if(root!=NULL)
    {
        traversal(root->LC);
        traversal(root->RC);
        cout<<root->id<<' ';
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    create_tree(&tree,3);
    traversal(&tree);
    cout<<endl;

    return 0;
}