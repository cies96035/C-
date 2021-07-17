#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 8080;
int t;
int n, a[MAX_N];
bitset<MAX_N> Sum, Ans;
int cnt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        Sum = Ans = 0;
        cnt = 0;
        rep(i, 0, n){
            cin >> a[i];
            Sum <<= a[i];
            Ans |= Sum;
            Sum[ a[i] ] = 1;
        }
        rep(i, 0, n){
            if(Ans[ a[i] ]){
                cnt++;
            }
        }
        cout << cnt << '\n';
    }
    return 0;
}