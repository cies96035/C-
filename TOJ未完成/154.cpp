#include <iostream>
#include <algorithm>
using namespace std;

struct Num
{
    int value,index;
};

bool cmp(Num x,Num y)
{
    return (x.value>y.value)||(x.value==y.value&&x.index<y.index);
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        Num num[N];
        long long cost=0;
        for(int i=0;i<N;i++)
        {
            cin>>num[i].value;
            num[i].index=i+1;
        }
        sort(num,num+N,cmp);
        for(int i=0;i<N;i++)
        {
            cost+=num[i].value*(i+1);
            cout<<num[i].index;
            if(i!=N-1)cout<<' ';
            else cout<<'\n';
        }
        cout<<cost<<'\n';
    }
}
