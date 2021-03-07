#include<iostream>
#include<map>
using namespace std;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int T;
    cin>>T;
    while(T--)
    {
        int N;
        string a;
        map<string,int> M;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            cin>>a>>a;
            if(M.find(a)!=M.end())
                M[a]++;
            else
                M[a]=1;
        }
        int Sum=1;
        for(map<string,int>::iterator i=M.begin() ; i != M.end() ; i++)
            Sum*=i->second+1;
        cout<<Sum-1<<'\n';
    }
    
    return 0;
}