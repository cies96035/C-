#include<bits/stdc++.h>
using namespace std;
using ld = long double;
using ll = long long;

#define rep(i, a, b) for(int i = a; i < b; i++)

const int INF = 0x3fffffff;
const int MAX_N = 605;
int n;
ld a[MAX_N];
ld prea[MAX_N];
int Q, q;
map<int,map<int,map<int,ld>>> DP;

ld calcV(ld A){
    return sqrtl( A * A * A / 36 / acos(-1) );
}
ld FindAns(int l, int r, int k){
    // cout << l << ' ' << r << ' ' << k << endl;
    if(DP[l][r][k] > 0){
        // cout << DP[l][r][k] << endl; 
        return DP[l][r][k];
    }
    if(k > 0){
        ld Min = INF;
        for(int i = l + 1; i < r; i++){
            Min = min(Min, calcV(prea[i] - prea[l]) + FindAns(i, r , k - 1));
        }
        // cout << Min << endl; 
        return DP[l][r][k] = Min;
    }else{
        // cout << (DP[l][r][k] = calcV(prea[r] - prea[l]) )<< endl; 
        return DP[l][r][k] = calcV(prea[r] - prea[l]);
    }
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    // cout << calcV(19) << endl;
    // cout << calcV(38) << endl;
    // cout << calcV(57) << endl;
    // cout << calcV(19 * 4) << endl;
    // cout << calcV(19 * 5) << endl;
    // cout << calcV(19 * 6) << endl;
    cin >> n;
    prea[0] = 0;
    rep(i, 0, n){
        cin >> a[i];
        prea[i + 1] = prea[i] + a[i];
    }
    cin >> Q;
    while(Q--){
        cin >> q;
        cout << fixed << setprecision(10) << FindAns(0, n, q - 1) << '\n';
    }
    return 0;
}