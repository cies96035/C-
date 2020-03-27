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
        int A,X,ans=0;
        A=X=1000000000;
        for(int B=1;B<=X;B++)
        {
				ans++;
        }
        cout<<ans<<endl;
    }
}
