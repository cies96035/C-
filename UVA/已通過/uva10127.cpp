#include<iostream>
using namespace std;

int N;
int RE(int s)
{
    if(s == 1)
        return 1;
    for(int i=0; i<10; i++)
        if( (s + i * N) % 10 == 1 )
            return RE( (s + i * N) / 10) + 1;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> N)
        cout<<RE(N)<<'\n';
    return 0;
}