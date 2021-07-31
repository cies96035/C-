#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int n, five, cnt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    five = 5;
    cin >> n;
    while(five <= n){
        cnt += n / five;
        five *= 5;
    }
    cout << cnt << '\n';
    return 0;
}