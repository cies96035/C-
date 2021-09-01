#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define x first
#define y second
const int MAX_N = 2e5 + 5;
int n;
pii a[MAX_N];

void solve(){
    vector<int> t{a[0].y};
    rep(i, 1, n){
        if(a[i].y >= t.back()){
            t.emplace_back(a[i].y);
        }else{
            *upper_bound(t.begin(), t.end(), a[i].y) = a[i].y;
        }
    }
    cout << t.size() << '\n';
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    rep(i, 0, n){
        cin >> a[i].x >> a[i].y;
    }
    sort(a, a + n);
    solve();
    return 0;
}