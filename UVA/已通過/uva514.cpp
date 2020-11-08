#include<iostream>
#include<stack>
using namespace std;

#define Maxn 1200
int arr[Maxn];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int n;
    while(cin>>n&&n)
    {
        while(cin>>arr[0]&&arr[0])
        {
            int s=0;
            stack<int> rail;
            for(int i=1;i<n;i++)
                cin>>arr[i];

            for(int i=1;i<=n;i++)
            {
                rail.push(i);
                while(!rail.empty()&&(rail.top()==arr[s]))
                {
                    rail.pop();
                    s++;
                }
            }
            if(rail.empty())
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
        cout<<'\n';
    }
    return 0;
}