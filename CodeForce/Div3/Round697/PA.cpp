#include<iostream>
using namespace std;
typedef long long ll;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    ll n;
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n;
        while(n%2==0)
            n/=2;
        if(n!=1)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
        
    }
    return 0;
}