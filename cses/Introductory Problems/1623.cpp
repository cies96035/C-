#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

int n;
ll sum, x[20], Min = 0x3fffffff;

void RE(int i, ll s){
    if(i == n || s * 2 > sum){
        Min = min(Min, abs(sum - 2 * s));
        return;
    }
    RE(i + 1, s + x[i]);
    RE(i + 1, s);
}
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n;
    rep(i, 0, n){
        cin >> x[i];
        sum += x[i];
    }
    RE(0, 0);
    cout << Min << '\n';
    return 0;
}