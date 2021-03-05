#include<iostream>
using namespace std;

int N;
int ans;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> N;
    while(N){
        ans = ans * 2 + (N & 1);
        N /= 2;
    }
    cout << ans << '\n';
    return 0;
}