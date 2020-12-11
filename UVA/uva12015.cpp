#include<iostream>
#include<algorithm>
using namespace std;

struct WEB
{
    int v, ID;
    string web;
};

bool cmp(WEB a, WEB b)
{
    if(a.v != b.v)
        return a.v > b.v;
    else
        return a.ID < b.ID;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    int T;
    cin >> T;
    for(int Case = 1 ; Case <= T ; Case++)
    {
        WEB W[11];
        W[10].v = -1;
        for(int i = 0 ; i < 10 ; i++)
        {
            cin >> W[i].web >> W[i].v;
            W[i].ID = i;
        }
        sort(W , W + 10 , cmp);
        cout << "Case #" << Case << ":\n";
        for(int j = 0 ; j < 10 ; j++)
        {
            cout << W[j].web << '\n';
            if( W[j].v != W[j+1].v )
                break;
        }
    }
    return 0;
}