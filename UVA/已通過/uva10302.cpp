#include<iostream>
using namespace std;
#define MAXN 55000
typedef unsigned long long ull;
ull Table[MAXN];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    Table[0]=0;
    for(ull i=1;i<MAXN;i++)
        Table[i]=Table[i-1] + i * i * i;

    int N;
    while(cin>>N)
        cout<<Table[N]<<'\n';
    return 0;
}