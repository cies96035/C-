#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 2e5 + 5;
int n;
pll mov[MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    rep(i, 0, n){
        cin >> mov[i].second >> mov[i].first;
    }
    sort(mov, mov + n);
    int endTime = 0, cnt = 0;
    rep(i, 0, n){
        if(mov[i].second >= endTime){
            cnt++;
            endTime = mov[i].first;
        }
    }
    cout << cnt << '\n';
    return 0;
}
