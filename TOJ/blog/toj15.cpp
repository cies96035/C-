#include<iostream>
#include<algorithm>
using namespace std;

struct meow//�C���߫}����� 
{
    string name;
    int old,work;
};

//�P�_���� 
bool cmp(const meow &a, const meow &b)
{
    //��¾�� 
    if(a.work>b.work)return 0;
    else if(a.work<b.work)return 1;
    
    //¾��ۦP��~�� 
    if(a.work==5)
    {
        if(a.old<b.old)return 1;
        else if(a.old>b.old)return 0;
    }
    else
    {
        if(a.old<b.old)return 0;
        else if(a.old>b.old)return 1;
    }
    
    //¾��~�֬ۦP��W�l�r��� 
    if(a.name>b.name)return 0;
    if(a.name<b.name)return 1;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    //�h������ 
    int N,M;
    while(cin>>N>>M)
    {
        meow cat[10000];
        for(int i=0;i<N;i++)
        {
            string work;
            cin>>cat[i].name>>work>>cat[i].old;
            
            //��¾���ഫ���Ʀr����n�P�_ 
            if(work[0]=='e')cat[i].work=1;
            else if(work[0]=='n')cat[i].work=2;
            else if(work[0]=='k')cat[i].work=3;
            else if(work[0]=='w')cat[i].work=4;
            else if(work[0]=='a')cat[i].work=5;
            else if(work[0]=='m')cat[i].work=6;
            else if(work[0]=='d')cat[i].work=7;
            else if(work[0]=='l')cat[i].work=8;
        }
        
        //�Ƨ� 
        sort(cat,cat+N,cmp);
        
        //��X 
        for(int i=0;i<M&&i<N;i++)
            cout<<cat[i].name<<endl;
    }
    return 0;
}
