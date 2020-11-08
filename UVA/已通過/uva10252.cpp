#include<iostream>
using namespace std;

string a,b;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    while(getline(cin,a))
    {
        getline(cin,b);
        
        int Aalpha[26]={0},Balpha[26]={0};

        for(int i=0;i<a.size();i++)
            Aalpha[a[i]-'a']++;

        for(int i=0;i<b.size();i++)
            Balpha[b[i]-'a']++;

        for(int i=0;i<26;i++)
        {
            char c=i+'a';
            int x=min(Aalpha[i],Balpha[i]);
            while(x--)
                cout<<c;
        }
        cout<<'\n';
    }
    return 0;
}