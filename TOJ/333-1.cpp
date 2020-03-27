#include<iostream>
using namespace std;

typedef long long ll;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int N,input,S=0;
    bool add=1;
    cin>>N;
    int ans=0;
    for(int i=0;i<N;i++)
    {
        cin>>input;
        if(!add&&input>S)
            ans-=S,add=!add;
        else if(add&&input<=S)
            ans+=S,add=!add;
        S=input;
    }
    if(add)ans+=input;
    cout<<ans<<'\n';
    return 0;
}
