#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 1010;

int s, n;
pii dragon[MAX_N];
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> s >> n;
    rep(i, 0, n){
        cin >> dragon[i].first >> dragon[i].second;
    }
    sort(dragon, dragon + n);
    rep(i, 0, n){
        if(s > dragon[i].first){
            s += dragon[i].second;
        }else{
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}