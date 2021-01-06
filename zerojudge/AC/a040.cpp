#include<iostream>
#include<
using namespace std;

int pow(int x,int p)//x^p
{
    int s=1;
    for(int i=0;i<p;i++)
        s*=x;
    return s;
}

bool amstrong(int x)
{
    int sum=0;
    int t=x,p=0;
    while(t)
    {
        p++;
        t/=10;
    }
    t=x;
    while(t)
    {
        sum+=pow(t%10,p);
        t/=10;
    }
    return sum==x;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n,m;
    cin>>n>>m;
    bool flg=1;
    for(int i=n;i<=m;i++)
    {
        if(amstrong(i))
        {
            if(flg)
            {
                cout<<i;
                flg=0;
            }
            else
            {
                cout<<' '<<i;
            }
        }
    }
    if(flg)
        cout<<"none";
    cout<<'\n';

    return 0;
}