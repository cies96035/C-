#include<iostream>
using namespace std;

#define alpha_size 26

struct Node
{
    string mean;
    Node *alpha[alpha_size]={NULL};
}root;

string Word,Mean;

void Node_Init(Node *node)
{
    for(int i=0;i<alpha_size;i++)
    {
        if(node->alpha[i]!=NULL)
        {
            Node_Init(node->alpha[i]);
            delete node->alpha[i];
            node->alpha[i]=NULL;
        }
    }
    return;
}

void Init()
{
    Node_Init(&root);
    return;
}

void Node_InsertWord(Node *&node,int index)
{
    //cout<<word[index]<<"   "<<node<<endl;//Before
    if(node==NULL)node=new Node;
    //cout<<word[index]<<"   "<<node<<endl;//After
    if(index==Word.size())
    {
        node->mean=Mean;
        return;
    } 
    Node_InsertWord(node->alpha[Word[index]-'A'],index+1);
}

void InsertWord(string word,string mean)
{
    Node *rt=&root;
    Mean=mean;
    Word=word;
    Node_InsertWord(rt->alpha[word[0]-'A'],1);
    return;
}

string Node_Ask(Node *&node,int index)
{
    //cout<<word[index]<<"   "<<node<<endl;
    if(node==NULL)return "Not found!";
    if(index==Word.size())
        return node -> mean.empty() ? "Not found!" : node->mean;
    return Node_Ask(node->alpha[Word[index]-'A'],index+1);
}

string Ask(string word)
{
    Node *rt=&root;
    Word=word;
    return Node_Ask(rt->alpha[word[0]-'A'],1);
}

int main()
{
	InsertWord("ABC","AB");
	InsertWord("AB","B");
	cout<<Ask("ABC")<<endl;
return 0;
}
