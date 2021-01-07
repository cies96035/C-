#include<iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int T,Case=1;
    while(cin>>T && T)
    {
        int tmp,sum=0;
        for(int i=0;i<T;i++)
        {
            cin>>tmp;
            if(tmp)
                sum++;
            else
                sum--;
        }
        cout<<"Case "<<Case++<<": "<<sum<<'\n';
    }
    return 0;
}