#include<iostream>
using namespace std;
#define MAX 1010
string M1[MAX],M2[MAX];
bool solve(int n)
{
    int P[MAX];
    for(int i=0;i<n;i++)
    {
        P[i]=M1[0][i];
    }
    for(int i=1;i<n;i++)
    {
        
        int t=M1[i][0]^P[0];
        if(t==1)
        for(int j=1;j<n;j++)
        {
            if(M1[i][j]==P[j])
                return false;
        }
        else
        {
        for(int j=1;j<n;j++)
        {
            if(M1[i][j]!=P[j])
                return false;
        }
        }
        
    }
    return true;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int t;
    int n;
    cin>>t;
    while(t--)
    {
        cin>>n;
        for(int i=0;i<n;i++)
            cin>>M1[i];
        for(int i=0;i<n;i++)
        {
            cin>>M2[i];
            for(int j=0;j<n;j++)
            {
                if(M1[i][j]==M2[i][j])
                    M1[i][j]=0;
                else
                    M1[i][j]=1;
                
            }
        }
        
        if(solve(n))
            cout<<"YES\n";
        else
        {
            cout<<"NO\n";
        }
        
        

    }
    return 0;
}