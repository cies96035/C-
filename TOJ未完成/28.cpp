#include<iostream>
#include<cstring>
using namespace std;

int main() {
    int N,M,ans=0;
    cin>>N>>M;
    bool fight[N]={0};
    while(M--)
    {
        int a,b;
        cin>>a>>b;
        if(!fight[a])
        {
            fight[a]++;
            ans++;
        }
        if(!fight[b])
        {
            fight[b]++;
            ans++;
        }
    }
    cout<<ans<<endl;
    
    return 0;
}
