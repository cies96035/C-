#include <iostream>
using namespace std;

int x,y,T,t;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin>>T;
    while(T--)
    {
        cin>>x>>y;
        cin>>t;
        bool way[4]={0};
        for(int i=0,tmp;i<t;i++)
        {
            cin>>tmp;
            way[tmp]=1;
        }
        /*part1*/
        if(x==0)
        {
            if(y%2)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else if(y==0)
        {
            if(x%2)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else
        {
            if(way[0]==1&&way[1]==1&&way[2]==0&&way[3]==0&&(x+y+1)%2)
                cout<<"NO\n";
            else
                cout<<"YES\n";
        }
        
        /*part2*/
        if(way[2])
            cout<<max(x,y);
        else
            cout<<x+y<<endl;

        /*part3*/
        if(way[0]&&way[1]&&way[3])
        {
            int t=(x+y)+y
        }
    }
    return 0;
}