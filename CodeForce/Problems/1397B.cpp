#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 100100;
const ll VERY_LARGE = 1e12;
int n;
ll a[MAX_N];
ll Min = 1e18;
ll tryC(ll c){
    ll sum = 0;
    ll ci = 1;
    for(int i = 0; i < n; i++){
        if(ci > VERY_LARGE){
            return 1e18;
        }
        sum += abs(a[i] - ci);
        ci *= c;
    }
    return sum;
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a, a + n);
    for(int c = 1; c < 4e4; c++){
        Min = min(tryC(c), Min);
    }
    cout << Min << '\n';
    return 0;
}