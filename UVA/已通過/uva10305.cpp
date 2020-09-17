#include<iostream>
#include<cstring>
#include<queue>
using namespace std;

#define Maxn 200
//connected[i][j] -> i before j
bool connected[Maxn][Maxn];
//parents[i] ->ｉparents' amount
int parents[Maxn];
//n numbers m order
int n,m;
//correct output
bool first;

//for test
void print()
{
    cout<<"connnected:\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<connected[i][j]<<' ';
        }
        cout<<endl;
    }
    cout<<"parents:\n";
    for(int i=0;i<n;i++)
    {
        cout<<parents[i]<<' ';
    }
    cout<<endl;
}

//out put the node which doesnt have any parents
bool order()
{
    queue<int> s;
    for(int i=0;i<n;i++)
        if(parents[i]==0)
            s.push(i);
    if(s.empty())
        return false;
    while(!s.empty())
    {
        if(!first)
            cout<<' ';
        else
            first=false;
        cout<<s.front()+1;

        for(int j=0;j<n;j++)
            if(connected[s.front()][j])
                parents[j]--;
        parents[s.front()]=-1;
        s.pop();
    }
    return true;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin>>n>>m&&n)
    {
        first=1;
        memset(connected,0,sizeof(bool)*Maxn*Maxn);
        memset(parents,0,sizeof(parents));
        for(int i=0;i<m;i++)
        {
            int a,b;
            cin>>a>>b;
            a--;
            b--;
            connected[a][b]=1;
            parents[b]++;
        }

        while(order());
        cout<<'\n';
    }
    return 0;
}
