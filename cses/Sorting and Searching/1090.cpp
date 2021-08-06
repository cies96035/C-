#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, a, b) for(int i = a; i < b; i++)

const int MAX_N = 2e5 + 5;
int n, x;
int p[MAX_N];
int cnt;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    
    cin >> n >> x;
    rep(i, 0, n){
        cin >> p[i];
    }
    sort(p, p + n);
    for(int i = 0, j = n - 1; i <= j;){
        if(i != j && p[i] + p[j] <= x){
            cnt++, i++, j--;
        }else{
            cnt++, j--;
        }
    }
    cout << cnt << '\n';
    return 0;
}