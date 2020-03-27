#include<iostream>
#include<algorithm>
using namespace std;

struct meow//每隻貓咪的資料 
{
    string name;
    int old,work;
};

//判斷順序 
bool cmp(const meow &a, const meow &b)
{
    //比職位 
    if(a.work>b.work)return 0;
    else if(a.work<b.work)return 1;
    
    //職位相同比年齡 
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
    
    //職位年齡相同比名子字典序 
    if(a.name>b.name)return 0;
    if(a.name<b.name)return 1;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    //多筆測資 
    int N,M;
    while(cin>>N>>M)
    {
        meow cat[10000];
        for(int i=0;i<N;i++)
        {
            string work;
            cin>>cat[i].name>>work>>cat[i].old;
            
            //把職位轉換成數字比較好判斷 
            if(work[0]=='e')cat[i].work=1;
            else if(work[0]=='n')cat[i].work=2;
            else if(work[0]=='k')cat[i].work=3;
            else if(work[0]=='w')cat[i].work=4;
            else if(work[0]=='a')cat[i].work=5;
            else if(work[0]=='m')cat[i].work=6;
            else if(work[0]=='d')cat[i].work=7;
            else if(work[0]=='l')cat[i].work=8;
        }
        
        //排序 
        sort(cat,cat+N,cmp);
        
        //輸出 
        for(int i=0;i<M&&i<N;i++)
            cout<<cat[i].name<<endl;
    }
    return 0;
}
