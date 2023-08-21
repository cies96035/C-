#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ld = long double;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 1e2 + 5;
int t, n;
int arr[MAX_N];
bool check(int k){
    map<int, int> aset;
    rep(i, 0, n){
        aset[arr[i]]++;
    }
    rvep(i, k, 1){
        if(aset.empty() || i < aset.begin()->first){
            return false;
        }
        auto tmp = --aset.upper_bound(i);
        tmp->second--;
        if(!tmp->second) aset.erase(tmp);


        aset.begin()->second--;
        if(!aset.begin()->second) aset.erase(aset.begin());
    }
    return true;
    
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> t;
    while(t--){
        cin >> n;
        rep(i, 0, n){
            cin >> arr[i];
        }
        int l = -1, r = 1e9, mid;
        while(l < r){
            mid = (l + r) >> 1;
            if(check(mid)){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        cout << l - 1 << '\n';
    }
    return 0;
}