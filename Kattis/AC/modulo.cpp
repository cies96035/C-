#include<iostream>
using namespace std;

bool fortytwo[42];
int N, cnt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    while(cin >> N){
        if(!fortytwo[N % 42]){
            fortytwo[N % 42] = true;
            cnt++;
        }
    }
    cout << cnt << '\n';
    return 0;
}