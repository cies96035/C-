#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
#define rep(i, a, b) for(int i = a; i < b; i++)
#define rrep(i, a, b) for(int i = a; i <= b; i++)
#define rvep(i, a, b) for(int i = a; i >= b; i--)

const int MAX_N = 2e5 + 5;
int k, n;
int arr[MAX_N];
pll DP[MAX_N]; //num + index
bool used[MAX_N];
int BIT[MAX_N];
bool vised[MAX_N];
void update(int x){
    while(x < MAX_N){
        BIT[x]++;
        x += x & -x;
    }
    return;
}
int query(int x){
    int sum = 0;
    while(x){
        sum += BIT[x];
        x -= x & -x;
    }
    return sum;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> k;
    rep(i, 0, n){
        cin >> arr[i];
    }

    rvep(i, n - 1, 0){
        DP[i] = {-(query(k) - query(arr[i])), i};
        if(!vised[ arr[i] ]){
            update(arr[i]);
            vised[ arr[i] ] = true;
        }
    }
    // rep(i, 0, n){
    //     cout << DP[i].first << ' ';
    // }cout << endl;

    sort(DP, DP + n);
    bool flg = false;
    int pos = -1;
    rep(i, 0, n){
        if(!used[ arr[DP[i].second] ] && pos < DP[i].second){
            if(!flg){
                flg = true;
            }else{
                cout << ' ';
            }
            pos = DP[i].second;
            // cout << pos << endl;
            // cout << pos << endl;
            cout << arr[DP[i].second];
            used [ arr[DP[i].second] ] = true;
        }
    }
    cout << '\n';
    return 0;
}