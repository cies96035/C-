#include<iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int n;
    cin>>n;
    int t;
    while(n--)
    {
        cin>>t;
        int tt=t/2020;
        int ttt=t-tt*2020;
        if(tt>=ttt)
            cout<<"YES\n";
        else
        {
            cout<<"NO\n";
        }
        
    }
    return 0;
}