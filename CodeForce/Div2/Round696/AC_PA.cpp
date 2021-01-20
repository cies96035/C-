#include<iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int T;
    cin>>T;
    int n;
    string k;
    while(T--)
    {
        cin>>n;
        cin>>k;
        int l=-1;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j>=0;j--)
            {
                if(k[i]+j-'0'!=l)
                {
                    l=k[i]+j-'0';
                    cout<<j;
                    break;
                }
            }
        }
        cout<<'\n';
    }
    return 0;
}