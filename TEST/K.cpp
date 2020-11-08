#include<iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int T;
    cin>>T;
    while(T--)
    {
        int sum=0;
        int n,m;
        cin>>n;
        while(cin>>m&&m!=0)
        {
            if(n*2<m)
            {
                sum+=m-n*2;
            }
            n=m;
        }
        cout<<sum<<'\n';
    }
    return 0;
}