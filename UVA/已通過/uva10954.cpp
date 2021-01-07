#include<iostream>
#include<queue>
using namespace std;

typedef priority_queue<int,vector<int>,greater<int> > pqi;

int topandpop(pqi &P)
{
    int p = P.top();
    P.pop();
    return p;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    int T;
    while(cin>>T&&T)
    {
        pqi PriQ;
        int tmp, sum=0;
        for(int i=0; i<T; i++)
        {
            cin>>tmp;
            PriQ.push(tmp);
        }
        while(PriQ.size()>1)
        {
            tmp = topandpop(PriQ) + topandpop(PriQ);
            PriQ.push(tmp);
            sum += tmp;
        }
        cout<<sum<<'\n';
    }
    return 0;
}