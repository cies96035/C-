#include<iostream>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    string str;
    int N[100],ns=0;
    int len=0;
    N[0]=0;
    while(getline(cin,str))
    {
        if(str=="")
        {
            for(int i=1;i<=ns;i++)
            {
                for(int j=0;j<len;j++)
                {
                    if(j >= len - N[i] && j<len-N[i-1])
                        cout<<'*';
                    else 
                        cout<<'.';
                }
            cout<<'\n';
            }
            cout<<'\n';
            ns=0;
            N[0]=0;
            len=0;
        }
        else
        {
            ns++;
            len=str.size();
            N[ns]=N[ns-1];
            for(int i=0;i<str.size();i++)
            {
                if(str[i]=='*')
                N[ns]++;
            }
        }
    }
    if(ns!=1)
    {
        for(int i=1;i<=ns;i++)
            {
                for(int j=0;j<len;j++)
                {
                    if(j >= len - N[i] && j<len-N[i-1])
                        cout<<'*';
                    else 
                        cout<<'.';
                }
            cout<<'\n';
            }
            cout<<'\n';
    }
    return 0;
}